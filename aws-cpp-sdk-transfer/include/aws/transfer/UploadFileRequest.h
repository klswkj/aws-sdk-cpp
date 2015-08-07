
/*
  * Copyright 2010-2015 Amazon.com, Inc. or its affiliates. All Rights Reserved.
  *
  * Licensed under the Apache License, Version 2.0 (the "License").
  * You may not use this file except in compliance with the License.
  * A copy of the License is located at
  *
  *  http://aws.amazon.com/apache2.0
  *
  * or in the "license" file accompanying this file. This file is distributed
  * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
  * express or implied. See the License for the specific language governing
  * permissions and limitations under the License.
  */

#pragma once

#include <aws/transfer/Transfer_EXPORTS.h>

#include <aws/transfer/S3FileRequest.h>

#include <aws/core/utils/memory/stl/AWSMap.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

#include <aws/s3/model/UploadPartRequest.h>

#include <aws/transfer/TransferClientDefs.h>

#include <fstream>

namespace Aws
{
namespace S3
{
    class S3Client;

    namespace Model
    {
        class CompletedPart;
    }
} // namespace S3

namespace Transfer
{


// PartRequestRecord is an individual piece of a multi part upload.  
// m_partRequest contains the information S3 cares about for the request
// m_buffer is our buffer we used for the request and will reuse when this request is done
// m_partMd5 is to make sure our Md5 matches when the request returns successfully
// m_retries lets us retry the same request using this record in case of a failure 
// up to PART_RETRY_MAX (2 default) attempts
struct AWS_TRANSFER_API PartRequestRecord
{
public:

    PartRequestRecord(const std::shared_ptr<UploadBuffer>& thisBuffer) : m_buffer(thisBuffer),
    m_retries(0)
    { }

    PartRequestRecord() : m_retries(0) { }

    std::shared_ptr<UploadBuffer> m_buffer;
    Aws::S3::Model::UploadPartRequest m_partRequest;
    Aws::Utils::ByteBuffer m_partMd5;
    uint32_t m_retries;
};

class AWS_TRANSFER_API UploadFileRequest : public S3FileRequest, public std::enable_shared_from_this<UploadFileRequest>
{
public:
    UploadFileRequest(const Aws::String& fileName, 
                      const Aws::String& bucketName, 
                      const Aws::String& keyName, 
                      const Aws::String& contentType, 
                      const std::shared_ptr<Aws::S3::S3Client>& s3Client, 
                      bool createBucket);
    ~UploadFileRequest();

    // Progress is currently measured only in parts completed out of total parts
    float GetProgress() const override;

    uint64_t GetFileSize() const;

    // How many parts have we at least begun to upload
    uint32_t GetPartCount() const;

    // Total number of parts we'll be dividing the file into for upload
    uint32_t GetTotalParts() const { return m_totalParts;  }

    // DoneWithRequests is Requested parts == TotalParts (Happens just before the final requests return and IsDone is set when all goes well)
    bool DoneWithRequests() const;

    // This is a 5MB or less upload, we do not want to perform a multi part upload
    bool IsSinglePartUpload() const;

    // Our catch all for "done and we've heard back on all parts" - hearing back on outstanding part uploads after a failure or cancel
    // Is necessary to prevent the smart pointer from going out of scope when a future .get() call has not returned.
    bool ReadyForDelete() const override;

    // How many parts do we have left to start sending (Parts which have begun upload are not considered "remaining" for the purpose of this call)
    uint32_t GetPartsRemaining() const;

    friend class TransferClient;

protected:

    virtual bool DoCancelAction() override;
    virtual void SetDone() override;
private:
    // TransferClient uses these calls
    bool ProcessBuffer(const std::shared_ptr<UploadBuffer>& buffer);
 
    uint64_t ReadNextPart(const std::shared_ptr<UploadBuffer>& buffer, std::shared_ptr<Aws::IOStream>& streamBuf, uint32_t& partNum);

    void AddCompletedPart(PartRequestRecord& partRequest, const Aws::String& eTag);
    void CompleteUpload();
    void HandlePartFailure(const Aws::S3::Model::UploadPartOutcome& thisOutcome, PartRequestRecord& partRequest);

    // The primary lifecycle routine - Create a bucket if needed, Wait for it to propagate, Create a multi part upload if needed, start processing, etc
    bool ContinueUpload();

    bool CreateBucket();
    bool WaitForBucketToPropagate();
    bool CreateMultipartUpload();
    virtual bool IsReady() const override;

    bool HasUploadId() const;
    const Aws::String& GetUploadId() const { return m_uploadId;  }
    // Testing
    void CreateStreamBuffer(std::shared_ptr<Aws::IOStream>& streamBuf) const;

    void DoRetry(PartRequestRecord& partRequest);

    bool RequestPart(uint32_t partId);

    void ReusePart(PartRequestRecord& partRequest);

    void PartReturned(PartRequestRecord& partRequest);
    uint32_t GetPartsReturned() const;
    void SingleUploadComplete();

    bool HandleCreateBucketOutcome(const Aws::S3::Model::CreateBucketRequest& request,
        const Aws::S3::Model::CreateBucketOutcome& createBucketOutcome);

    bool HandleCreateMultipartUploadOutcome(const Aws::S3::Model::CreateMultipartUploadRequest& request,
        const Aws::S3::Model::CreateMultipartUploadOutcome& outcome);

    bool HandleHeadBucketOutcome(const Aws::S3::Model::HeadBucketRequest& request,
        const Aws::S3::Model::HeadBucketOutcome& outcome);

    bool HandleUploadPartOutcome(const Aws::S3::Model::UploadPartRequest& request,
        const Aws::S3::Model::UploadPartOutcome& outcome);

    bool HandleCompleteMultipartUploadOutcome(const Aws::S3::Model::CompleteMultipartUploadRequest& request,
        const Aws::S3::Model::CompleteMultipartUploadOutcome& outcome);

    bool HandlePutObjectOutcome(const Aws::S3::Model::PutObjectRequest& request,
        const Aws::S3::Model::PutObjectOutcome& outcome);

    void AddReadyBuffer(std::shared_ptr<UploadBuffer> buffer);
    bool GetReadyBuffer(std::shared_ptr<UploadBuffer>& buffer);
    bool ProcessAvailableBuffers();

    // Uploads 5mb or less need to perform a single put call - attempting to do a multi part upload with these small 
    // files can cause failures in S3
    bool DoSingleObjectUpload(std::shared_ptr<Aws::IOStream>& streamBuf, uint64_t bytesRead);
    
    bool IsUsingBuffer(const std::shared_ptr<UploadBuffer>& buffer) const;

    void CheckReacquireBuffers();

    void ReleaseResources();

    void SetResourceSet(std::shared_ptr<UploadBufferScopedResourceSetType>& bufferSet);

    std::shared_ptr<UploadBufferScopedResourceSetType > m_resources;

    mutable std::mutex m_fileRequestMutex;

    std::mutex m_resourceMutex;
    std::mutex m_completePartMutex;
    std::mutex m_reuseMutex;
    mutable std::mutex m_pendingMutex;
    std::mutex m_bufferMutex;

    uint64_t m_fileSize;
    uint64_t m_bytesRemaining;

    std::atomic<uint32_t> m_partCount;
    std::atomic<uint32_t> m_partsReturned;

    std::atomic<bool> m_createBucket;
    std::atomic<bool> m_createBucketPending;
    std::atomic<bool> m_bucketCreated;
    std::atomic<bool> m_createMultipartUploadPending;
    std::atomic<bool> m_headBucketPending;
    std::atomic<bool> m_completeMultipartUploadPending;

    bool m_bucketPropagated;

    uint32_t m_totalParts;

    Aws::IFStream m_fileStream;

    Aws::Map<uint32_t, Aws::S3::Model::CompletedPart> m_completedParts;
    Aws::Map<uint32_t, PartRequestRecord> m_pendingParts;

    Aws::List<std::shared_ptr<UploadBuffer> > m_buffersReady;

    Aws::String m_contentType;
    Aws::String m_uploadId;
    uint32_t m_completeRetries;
};

} // namespace Transfer
} // namespace Aws

