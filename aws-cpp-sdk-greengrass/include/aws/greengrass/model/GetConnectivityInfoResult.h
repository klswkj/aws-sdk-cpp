﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
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
#include <aws/greengrass/Greengrass_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/greengrass/model/ConnectivityInfo.h>
#include <utility>

namespace Aws
{
template<typename RESULT_TYPE>
class AmazonWebServiceResult;

namespace Utils
{
namespace Json
{
  class JsonValue;
} // namespace Json
} // namespace Utils
namespace Greengrass
{
namespace Model
{
  class AWS_GREENGRASS_API GetConnectivityInfoResult
  {
  public:
    GetConnectivityInfoResult();
    GetConnectivityInfoResult(const AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);
    GetConnectivityInfoResult& operator=(const AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);

    /**
     * Connectivity info array
     */
    inline const Aws::Vector<ConnectivityInfo>& GetConnectivityInfo() const{ return m_connectivityInfo; }

    /**
     * Connectivity info array
     */
    inline void SetConnectivityInfo(const Aws::Vector<ConnectivityInfo>& value) { m_connectivityInfo = value; }

    /**
     * Connectivity info array
     */
    inline void SetConnectivityInfo(Aws::Vector<ConnectivityInfo>&& value) { m_connectivityInfo = std::move(value); }

    /**
     * Connectivity info array
     */
    inline GetConnectivityInfoResult& WithConnectivityInfo(const Aws::Vector<ConnectivityInfo>& value) { SetConnectivityInfo(value); return *this;}

    /**
     * Connectivity info array
     */
    inline GetConnectivityInfoResult& WithConnectivityInfo(Aws::Vector<ConnectivityInfo>&& value) { SetConnectivityInfo(std::move(value)); return *this;}

    /**
     * Connectivity info array
     */
    inline GetConnectivityInfoResult& AddConnectivityInfo(const ConnectivityInfo& value) { m_connectivityInfo.push_back(value); return *this; }

    /**
     * Connectivity info array
     */
    inline GetConnectivityInfoResult& AddConnectivityInfo(ConnectivityInfo&& value) { m_connectivityInfo.push_back(std::move(value)); return *this; }

    /**
     * Response Text
     */
    inline const Aws::String& GetMessage() const{ return m_message; }

    /**
     * Response Text
     */
    inline void SetMessage(const Aws::String& value) { m_message = value; }

    /**
     * Response Text
     */
    inline void SetMessage(Aws::String&& value) { m_message = std::move(value); }

    /**
     * Response Text
     */
    inline void SetMessage(const char* value) { m_message.assign(value); }

    /**
     * Response Text
     */
    inline GetConnectivityInfoResult& WithMessage(const Aws::String& value) { SetMessage(value); return *this;}

    /**
     * Response Text
     */
    inline GetConnectivityInfoResult& WithMessage(Aws::String&& value) { SetMessage(std::move(value)); return *this;}

    /**
     * Response Text
     */
    inline GetConnectivityInfoResult& WithMessage(const char* value) { SetMessage(value); return *this;}

  private:
    Aws::Vector<ConnectivityInfo> m_connectivityInfo;
    Aws::String m_message;
  };

} // namespace Model
} // namespace Greengrass
} // namespace Aws
