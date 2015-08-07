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
#include <aws/autoscaling/AutoScaling_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSStreamFwd.h>
#include <aws/core/utils/memory/stl/AWSString.h>

namespace Aws
{
namespace Utils
{
namespace Xml
{
  class XmlNode;
} // namespace Xml
} // namespace Utils
namespace AutoScaling
{
namespace Model
{
  /*
    <p>Describes a scheduled update to an Auto Scaling group.</p>
  */
  class AWS_AUTOSCALING_API ScheduledUpdateGroupAction
  {
  public:
    ScheduledUpdateGroupAction();
    ScheduledUpdateGroupAction(const Aws::Utils::Xml::XmlNode& xmlNode);
    ScheduledUpdateGroupAction& operator=(const Aws::Utils::Xml::XmlNode& xmlNode);

    void OutputToStream(Aws::OStream& ostream, const char* location, unsigned index, const char* locationValue) const;
    void OutputToStream(Aws::OStream& oStream, const char* location) const;

    /*
     <p>The name of the group.</p>
    */
    inline const Aws::String& GetAutoScalingGroupName() const{ return m_autoScalingGroupName; }
    /*
     <p>The name of the group.</p>
    */
    inline void SetAutoScalingGroupName(const Aws::String& value) { m_autoScalingGroupNameHasBeenSet = true; m_autoScalingGroupName = value; }

    /*
     <p>The name of the group.</p>
    */
    inline void SetAutoScalingGroupName(const char* value) { m_autoScalingGroupNameHasBeenSet = true; m_autoScalingGroupName.assign(value); }

    /*
     <p>The name of the group.</p>
    */
    inline ScheduledUpdateGroupAction&  WithAutoScalingGroupName(const Aws::String& value) { SetAutoScalingGroupName(value); return *this;}

    /*
     <p>The name of the group.</p>
    */
    inline ScheduledUpdateGroupAction& WithAutoScalingGroupName(const char* value) { SetAutoScalingGroupName(value); return *this;}

    /*
     <p>The name of the scheduled action.</p>
    */
    inline const Aws::String& GetScheduledActionName() const{ return m_scheduledActionName; }
    /*
     <p>The name of the scheduled action.</p>
    */
    inline void SetScheduledActionName(const Aws::String& value) { m_scheduledActionNameHasBeenSet = true; m_scheduledActionName = value; }

    /*
     <p>The name of the scheduled action.</p>
    */
    inline void SetScheduledActionName(const char* value) { m_scheduledActionNameHasBeenSet = true; m_scheduledActionName.assign(value); }

    /*
     <p>The name of the scheduled action.</p>
    */
    inline ScheduledUpdateGroupAction&  WithScheduledActionName(const Aws::String& value) { SetScheduledActionName(value); return *this;}

    /*
     <p>The name of the scheduled action.</p>
    */
    inline ScheduledUpdateGroupAction& WithScheduledActionName(const char* value) { SetScheduledActionName(value); return *this;}

    /*
     <p>The Amazon Resource Name (ARN) of the scheduled action.</p>
    */
    inline const Aws::String& GetScheduledActionARN() const{ return m_scheduledActionARN; }
    /*
     <p>The Amazon Resource Name (ARN) of the scheduled action.</p>
    */
    inline void SetScheduledActionARN(const Aws::String& value) { m_scheduledActionARNHasBeenSet = true; m_scheduledActionARN = value; }

    /*
     <p>The Amazon Resource Name (ARN) of the scheduled action.</p>
    */
    inline void SetScheduledActionARN(const char* value) { m_scheduledActionARNHasBeenSet = true; m_scheduledActionARN.assign(value); }

    /*
     <p>The Amazon Resource Name (ARN) of the scheduled action.</p>
    */
    inline ScheduledUpdateGroupAction&  WithScheduledActionARN(const Aws::String& value) { SetScheduledActionARN(value); return *this;}

    /*
     <p>The Amazon Resource Name (ARN) of the scheduled action.</p>
    */
    inline ScheduledUpdateGroupAction& WithScheduledActionARN(const char* value) { SetScheduledActionARN(value); return *this;}

    /*
     <p>This parameter is deprecated; use <code>StartTime</code> instead.</p>
    */
    inline double GetTime() const{ return m_time; }
    /*
     <p>This parameter is deprecated; use <code>StartTime</code> instead.</p>
    */
    inline void SetTime(double value) { m_timeHasBeenSet = true; m_time = value; }

    /*
     <p>This parameter is deprecated; use <code>StartTime</code> instead.</p>
    */
    inline ScheduledUpdateGroupAction&  WithTime(double value) { SetTime(value); return *this;}

    /*
     <p>The date and time that the action is scheduled to begin. This date and time can be up to one month in the future.</p> <p>When <code>StartTime</code> and <code>EndTime</code> are specified with <code>Recurrence</code>, they form the boundaries of when the recurring action will start and stop.</p>
    */
    inline double GetStartTime() const{ return m_startTime; }
    /*
     <p>The date and time that the action is scheduled to begin. This date and time can be up to one month in the future.</p> <p>When <code>StartTime</code> and <code>EndTime</code> are specified with <code>Recurrence</code>, they form the boundaries of when the recurring action will start and stop.</p>
    */
    inline void SetStartTime(double value) { m_startTimeHasBeenSet = true; m_startTime = value; }

    /*
     <p>The date and time that the action is scheduled to begin. This date and time can be up to one month in the future.</p> <p>When <code>StartTime</code> and <code>EndTime</code> are specified with <code>Recurrence</code>, they form the boundaries of when the recurring action will start and stop.</p>
    */
    inline ScheduledUpdateGroupAction&  WithStartTime(double value) { SetStartTime(value); return *this;}

    /*
     <p>The date and time that the action is scheduled to end. This date and time can be up to one month in the future.</p>
    */
    inline double GetEndTime() const{ return m_endTime; }
    /*
     <p>The date and time that the action is scheduled to end. This date and time can be up to one month in the future.</p>
    */
    inline void SetEndTime(double value) { m_endTimeHasBeenSet = true; m_endTime = value; }

    /*
     <p>The date and time that the action is scheduled to end. This date and time can be up to one month in the future.</p>
    */
    inline ScheduledUpdateGroupAction&  WithEndTime(double value) { SetEndTime(value); return *this;}

    /*
     <p>The recurring schedule for the action.</p>
    */
    inline const Aws::String& GetRecurrence() const{ return m_recurrence; }
    /*
     <p>The recurring schedule for the action.</p>
    */
    inline void SetRecurrence(const Aws::String& value) { m_recurrenceHasBeenSet = true; m_recurrence = value; }

    /*
     <p>The recurring schedule for the action.</p>
    */
    inline void SetRecurrence(const char* value) { m_recurrenceHasBeenSet = true; m_recurrence.assign(value); }

    /*
     <p>The recurring schedule for the action.</p>
    */
    inline ScheduledUpdateGroupAction&  WithRecurrence(const Aws::String& value) { SetRecurrence(value); return *this;}

    /*
     <p>The recurring schedule for the action.</p>
    */
    inline ScheduledUpdateGroupAction& WithRecurrence(const char* value) { SetRecurrence(value); return *this;}

    /*
     <p>The minimum size of the group.</p>
    */
    inline long GetMinSize() const{ return m_minSize; }
    /*
     <p>The minimum size of the group.</p>
    */
    inline void SetMinSize(long value) { m_minSizeHasBeenSet = true; m_minSize = value; }

    /*
     <p>The minimum size of the group.</p>
    */
    inline ScheduledUpdateGroupAction&  WithMinSize(long value) { SetMinSize(value); return *this;}

    /*
     <p>The maximum size of the group.</p>
    */
    inline long GetMaxSize() const{ return m_maxSize; }
    /*
     <p>The maximum size of the group.</p>
    */
    inline void SetMaxSize(long value) { m_maxSizeHasBeenSet = true; m_maxSize = value; }

    /*
     <p>The maximum size of the group.</p>
    */
    inline ScheduledUpdateGroupAction&  WithMaxSize(long value) { SetMaxSize(value); return *this;}

    /*
     <p>The number of instances you prefer to maintain in the group.</p>
    */
    inline long GetDesiredCapacity() const{ return m_desiredCapacity; }
    /*
     <p>The number of instances you prefer to maintain in the group.</p>
    */
    inline void SetDesiredCapacity(long value) { m_desiredCapacityHasBeenSet = true; m_desiredCapacity = value; }

    /*
     <p>The number of instances you prefer to maintain in the group.</p>
    */
    inline ScheduledUpdateGroupAction&  WithDesiredCapacity(long value) { SetDesiredCapacity(value); return *this;}

  private:
    Aws::String m_autoScalingGroupName;
    bool m_autoScalingGroupNameHasBeenSet;
    Aws::String m_scheduledActionName;
    bool m_scheduledActionNameHasBeenSet;
    Aws::String m_scheduledActionARN;
    bool m_scheduledActionARNHasBeenSet;
    double m_time;
    bool m_timeHasBeenSet;
    double m_startTime;
    bool m_startTimeHasBeenSet;
    double m_endTime;
    bool m_endTimeHasBeenSet;
    Aws::String m_recurrence;
    bool m_recurrenceHasBeenSet;
    long m_minSize;
    bool m_minSizeHasBeenSet;
    long m_maxSize;
    bool m_maxSizeHasBeenSet;
    long m_desiredCapacity;
    bool m_desiredCapacityHasBeenSet;
  };

} // namespace Model
} // namespace AutoScaling
} // namespace Aws
