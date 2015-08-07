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
#include <aws/iam/model/PolicyEvaluationDecisionType.h>
#include <aws/core/utils/HashingUtils.h>

using namespace Aws::Utils;

static const int allowed_HASH = HashingUtils::HashString("allowed");
static const int explicitDeny_HASH = HashingUtils::HashString("explicitDeny");
static const int implicitDeny_HASH = HashingUtils::HashString("implicitDeny");

namespace Aws
{
namespace IAM
{
namespace Model
{
namespace PolicyEvaluationDecisionTypeMapper
{
PolicyEvaluationDecisionType GetPolicyEvaluationDecisionTypeForName(const Aws::String& name)
{
  int hashCode = HashingUtils::HashString(name.c_str());

  if (hashCode == allowed_HASH)
  {
    return PolicyEvaluationDecisionType::allowed;
  }
  else if (hashCode == explicitDeny_HASH)
  {
    return PolicyEvaluationDecisionType::explicitDeny;
  }
  else if (hashCode == implicitDeny_HASH)
  {
    return PolicyEvaluationDecisionType::implicitDeny;
  }

  return PolicyEvaluationDecisionType::NOT_SET;
}

Aws::String GetNameForPolicyEvaluationDecisionType(PolicyEvaluationDecisionType value)
{
  switch(value)
  {
  case PolicyEvaluationDecisionType::allowed:
    return "allowed";
  case PolicyEvaluationDecisionType::explicitDeny:
    return "explicitDeny";
  case PolicyEvaluationDecisionType::implicitDeny:
    return "implicitDeny";
  default:
    return "";
  }
}

} // namespace PolicyEvaluationDecisionTypeMapper
} // namespace Model
} // namespace IAM
} // namespace Aws
