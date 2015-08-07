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
#include <aws/s3/model/ObjectStorageClass.h>
#include <aws/core/utils/HashingUtils.h>

using namespace Aws::Utils;

static const int STANDARD_HASH = HashingUtils::HashString("STANDARD");
static const int REDUCED_REDUNDANCY_HASH = HashingUtils::HashString("REDUCED_REDUNDANCY");
static const int GLACIER_HASH = HashingUtils::HashString("GLACIER");

namespace Aws
{
namespace S3
{
namespace Model
{
namespace ObjectStorageClassMapper
{
ObjectStorageClass GetObjectStorageClassForName(const Aws::String& name)
{
  int hashCode = HashingUtils::HashString(name.c_str());

  if (hashCode == STANDARD_HASH)
  {
    return ObjectStorageClass::STANDARD;
  }
  else if (hashCode == REDUCED_REDUNDANCY_HASH)
  {
    return ObjectStorageClass::REDUCED_REDUNDANCY;
  }
  else if (hashCode == GLACIER_HASH)
  {
    return ObjectStorageClass::GLACIER;
  }

  return ObjectStorageClass::NOT_SET;
}

Aws::String GetNameForObjectStorageClass(ObjectStorageClass value)
{
  switch(value)
  {
  case ObjectStorageClass::STANDARD:
    return "STANDARD";
  case ObjectStorageClass::REDUCED_REDUNDANCY:
    return "REDUCED_REDUNDANCY";
  case ObjectStorageClass::GLACIER:
    return "GLACIER";
  default:
    return "";
  }
}

} // namespace ObjectStorageClassMapper
} // namespace Model
} // namespace S3
} // namespace Aws
