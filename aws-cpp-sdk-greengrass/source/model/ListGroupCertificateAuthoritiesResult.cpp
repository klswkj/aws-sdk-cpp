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

#include <aws/greengrass/model/ListGroupCertificateAuthoritiesResult.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/UnreferencedParam.h>

#include <utility>

using namespace Aws::Greengrass::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;
using namespace Aws;

ListGroupCertificateAuthoritiesResult::ListGroupCertificateAuthoritiesResult()
{
}

ListGroupCertificateAuthoritiesResult::ListGroupCertificateAuthoritiesResult(const AmazonWebServiceResult<JsonValue>& result)
{
  *this = result;
}

ListGroupCertificateAuthoritiesResult& ListGroupCertificateAuthoritiesResult::operator =(const AmazonWebServiceResult<JsonValue>& result)
{
  const JsonValue& jsonValue = result.GetPayload();
  if(jsonValue.ValueExists("GroupCertificateAuthorities"))
  {
    Array<JsonValue> groupCertificateAuthoritiesJsonList = jsonValue.GetArray("GroupCertificateAuthorities");
    for(unsigned groupCertificateAuthoritiesIndex = 0; groupCertificateAuthoritiesIndex < groupCertificateAuthoritiesJsonList.GetLength(); ++groupCertificateAuthoritiesIndex)
    {
      m_groupCertificateAuthorities.push_back(groupCertificateAuthoritiesJsonList[groupCertificateAuthoritiesIndex].AsObject());
    }
  }



  return *this;
}
