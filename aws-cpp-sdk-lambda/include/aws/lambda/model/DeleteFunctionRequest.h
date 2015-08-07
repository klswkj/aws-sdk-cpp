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
#include <aws/lambda/Lambda_EXPORTS.h>
#include <aws/lambda/LambdaRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>

namespace Aws
{
namespace Http
{
    class URI;
} //namespace Http
namespace Lambda
{
namespace Model
{

  /*
  */
  class AWS_LAMBDA_API DeleteFunctionRequest : public LambdaRequest
  {
  public:
    DeleteFunctionRequest();
    Aws::String SerializePayload() const override;

    void AddQueryStringParameters(Aws::Http::URI& uri) const override;


    /*
     <p>The Lambda function to delete.</p> <p> You can specify an unqualified function name (for example, "Thumbnail") or you can specify Amazon Resource Name (ARN) of the function (for example, "arn:aws:lambda:us-west-2:account-id:function:ThumbNail"). AWS Lambda also allows you to specify only the account ID qualifier (for example, "account-id:Thumbnail"). Note that the length constraint applies only to the ARN. If you specify only the function name, it is limited to 64 character in length. </p>
    */
    inline const Aws::String& GetFunctionName() const{ return m_functionName; }
    /*
     <p>The Lambda function to delete.</p> <p> You can specify an unqualified function name (for example, "Thumbnail") or you can specify Amazon Resource Name (ARN) of the function (for example, "arn:aws:lambda:us-west-2:account-id:function:ThumbNail"). AWS Lambda also allows you to specify only the account ID qualifier (for example, "account-id:Thumbnail"). Note that the length constraint applies only to the ARN. If you specify only the function name, it is limited to 64 character in length. </p>
    */
    inline void SetFunctionName(const Aws::String& value) { m_functionNameHasBeenSet = true; m_functionName = value; }

    /*
     <p>The Lambda function to delete.</p> <p> You can specify an unqualified function name (for example, "Thumbnail") or you can specify Amazon Resource Name (ARN) of the function (for example, "arn:aws:lambda:us-west-2:account-id:function:ThumbNail"). AWS Lambda also allows you to specify only the account ID qualifier (for example, "account-id:Thumbnail"). Note that the length constraint applies only to the ARN. If you specify only the function name, it is limited to 64 character in length. </p>
    */
    inline void SetFunctionName(const char* value) { m_functionNameHasBeenSet = true; m_functionName.assign(value); }

    /*
     <p>The Lambda function to delete.</p> <p> You can specify an unqualified function name (for example, "Thumbnail") or you can specify Amazon Resource Name (ARN) of the function (for example, "arn:aws:lambda:us-west-2:account-id:function:ThumbNail"). AWS Lambda also allows you to specify only the account ID qualifier (for example, "account-id:Thumbnail"). Note that the length constraint applies only to the ARN. If you specify only the function name, it is limited to 64 character in length. </p>
    */
    inline DeleteFunctionRequest&  WithFunctionName(const Aws::String& value) { SetFunctionName(value); return *this;}

    /*
     <p>The Lambda function to delete.</p> <p> You can specify an unqualified function name (for example, "Thumbnail") or you can specify Amazon Resource Name (ARN) of the function (for example, "arn:aws:lambda:us-west-2:account-id:function:ThumbNail"). AWS Lambda also allows you to specify only the account ID qualifier (for example, "account-id:Thumbnail"). Note that the length constraint applies only to the ARN. If you specify only the function name, it is limited to 64 character in length. </p>
    */
    inline DeleteFunctionRequest& WithFunctionName(const char* value) { SetFunctionName(value); return *this;}

    /*
     <p>Specifies the version of the Lambda function to delete. If you specify an ARN with version information as the <code>FunctionName</code>, you either don't specify this parameter at all or you must specify the same version that you provided in the <code>FunctionName</code>. To delete the HEAD version you must delete the entire function by not specifying any version in this parameter and not specifying any version in the <code>FunctionName</code>. </p>
    */
    inline const Aws::String& GetVersion() const{ return m_version; }
    /*
     <p>Specifies the version of the Lambda function to delete. If you specify an ARN with version information as the <code>FunctionName</code>, you either don't specify this parameter at all or you must specify the same version that you provided in the <code>FunctionName</code>. To delete the HEAD version you must delete the entire function by not specifying any version in this parameter and not specifying any version in the <code>FunctionName</code>. </p>
    */
    inline void SetVersion(const Aws::String& value) { m_versionHasBeenSet = true; m_version = value; }

    /*
     <p>Specifies the version of the Lambda function to delete. If you specify an ARN with version information as the <code>FunctionName</code>, you either don't specify this parameter at all or you must specify the same version that you provided in the <code>FunctionName</code>. To delete the HEAD version you must delete the entire function by not specifying any version in this parameter and not specifying any version in the <code>FunctionName</code>. </p>
    */
    inline void SetVersion(const char* value) { m_versionHasBeenSet = true; m_version.assign(value); }

    /*
     <p>Specifies the version of the Lambda function to delete. If you specify an ARN with version information as the <code>FunctionName</code>, you either don't specify this parameter at all or you must specify the same version that you provided in the <code>FunctionName</code>. To delete the HEAD version you must delete the entire function by not specifying any version in this parameter and not specifying any version in the <code>FunctionName</code>. </p>
    */
    inline DeleteFunctionRequest&  WithVersion(const Aws::String& value) { SetVersion(value); return *this;}

    /*
     <p>Specifies the version of the Lambda function to delete. If you specify an ARN with version information as the <code>FunctionName</code>, you either don't specify this parameter at all or you must specify the same version that you provided in the <code>FunctionName</code>. To delete the HEAD version you must delete the entire function by not specifying any version in this parameter and not specifying any version in the <code>FunctionName</code>. </p>
    */
    inline DeleteFunctionRequest& WithVersion(const char* value) { SetVersion(value); return *this;}

  private:
    Aws::String m_functionName;
    bool m_functionNameHasBeenSet;
    Aws::String m_version;
    bool m_versionHasBeenSet;
  };

} // namespace Model
} // namespace Lambda
} // namespace Aws
