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
#include <aws/dynamodb/model/Select.h>
#include <aws/core/utils/HashingUtils.h>

using namespace Aws::Utils;

static const int ALL_ATTRIBUTES_HASH = HashingUtils::HashString("ALL_ATTRIBUTES");
static const int ALL_PROJECTED_ATTRIBUTES_HASH = HashingUtils::HashString("ALL_PROJECTED_ATTRIBUTES");
static const int SPECIFIC_ATTRIBUTES_HASH = HashingUtils::HashString("SPECIFIC_ATTRIBUTES");
static const int COUNT_HASH = HashingUtils::HashString("COUNT");

namespace Aws
{
namespace DynamoDB
{
namespace Model
{
namespace SelectMapper
{
Select GetSelectForName(const Aws::String& name)
{
  int hashCode = HashingUtils::HashString(name.c_str());

  if (hashCode == ALL_ATTRIBUTES_HASH)
  {
    return Select::ALL_ATTRIBUTES;
  }
  else if (hashCode == ALL_PROJECTED_ATTRIBUTES_HASH)
  {
    return Select::ALL_PROJECTED_ATTRIBUTES;
  }
  else if (hashCode == SPECIFIC_ATTRIBUTES_HASH)
  {
    return Select::SPECIFIC_ATTRIBUTES;
  }
  else if (hashCode == COUNT_HASH)
  {
    return Select::COUNT;
  }

  return Select::NOT_SET;
}

Aws::String GetNameForSelect(Select value)
{
  switch(value)
  {
  case Select::ALL_ATTRIBUTES:
    return "ALL_ATTRIBUTES";
  case Select::ALL_PROJECTED_ATTRIBUTES:
    return "ALL_PROJECTED_ATTRIBUTES";
  case Select::SPECIFIC_ATTRIBUTES:
    return "SPECIFIC_ATTRIBUTES";
  case Select::COUNT:
    return "COUNT";
  default:
    return "";
  }
}

} // namespace SelectMapper
} // namespace Model
} // namespace DynamoDB
} // namespace Aws
