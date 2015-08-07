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
#include <aws/elasticmapreduce/model/StepState.h>
#include <aws/core/utils/HashingUtils.h>

using namespace Aws::Utils;

static const int PENDING_HASH = HashingUtils::HashString("PENDING");
static const int RUNNING_HASH = HashingUtils::HashString("RUNNING");
static const int COMPLETED_HASH = HashingUtils::HashString("COMPLETED");
static const int CANCELLED_HASH = HashingUtils::HashString("CANCELLED");
static const int FAILED_HASH = HashingUtils::HashString("FAILED");
static const int INTERRUPTED_HASH = HashingUtils::HashString("INTERRUPTED");

namespace Aws
{
namespace EMR
{
namespace Model
{
namespace StepStateMapper
{
StepState GetStepStateForName(const Aws::String& name)
{
  int hashCode = HashingUtils::HashString(name.c_str());

  if (hashCode == PENDING_HASH)
  {
    return StepState::PENDING;
  }
  else if (hashCode == RUNNING_HASH)
  {
    return StepState::RUNNING;
  }
  else if (hashCode == COMPLETED_HASH)
  {
    return StepState::COMPLETED;
  }
  else if (hashCode == CANCELLED_HASH)
  {
    return StepState::CANCELLED;
  }
  else if (hashCode == FAILED_HASH)
  {
    return StepState::FAILED;
  }
  else if (hashCode == INTERRUPTED_HASH)
  {
    return StepState::INTERRUPTED;
  }

  return StepState::NOT_SET;
}

Aws::String GetNameForStepState(StepState value)
{
  switch(value)
  {
  case StepState::PENDING:
    return "PENDING";
  case StepState::RUNNING:
    return "RUNNING";
  case StepState::COMPLETED:
    return "COMPLETED";
  case StepState::CANCELLED:
    return "CANCELLED";
  case StepState::FAILED:
    return "FAILED";
  case StepState::INTERRUPTED:
    return "INTERRUPTED";
  default:
    return "";
  }
}

} // namespace StepStateMapper
} // namespace Model
} // namespace EMR
} // namespace Aws
