﻿/*
* Copyright 2010-2016 Amazon.com, Inc. or its affiliates. All Rights Reserved.
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
#include <aws/ec2/model/ResetImageAttributeRequest.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

using namespace Aws::EC2::Model;
using namespace Aws::Utils;

ResetImageAttributeRequest::ResetImageAttributeRequest() : 
    m_dryRun(false),
    m_dryRunHasBeenSet(false),
    m_imageIdHasBeenSet(false),
    m_attribute(ResetImageAttributeName::NOT_SET),
    m_attributeHasBeenSet(false)
{
}

Aws::String ResetImageAttributeRequest::SerializePayload() const
{
  Aws::StringStream ss;
  ss << "Action=ResetImageAttribute&";
  if(m_dryRunHasBeenSet)
  {
    ss << "DryRun=" << m_dryRun << "&";
  }

  if(m_imageIdHasBeenSet)
  {
    ss << "ImageId=" << StringUtils::URLEncode(m_imageId.c_str()) << "&";
  }

  if(m_attributeHasBeenSet)
  {
    ss << "Attribute=" << ResetImageAttributeNameMapper::GetNameForResetImageAttributeName(m_attribute) << "&";
  }

  ss << "Version=2016-09-15";
  return ss.str();
}

