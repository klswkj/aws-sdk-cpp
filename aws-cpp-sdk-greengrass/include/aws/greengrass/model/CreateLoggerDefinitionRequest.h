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
#include <aws/greengrass/GreengrassRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/greengrass/model/LoggerDefinitionVersion.h>
#include <utility>

namespace Aws
{
namespace Greengrass
{
namespace Model
{

  /**
   */
  class AWS_GREENGRASS_API CreateLoggerDefinitionRequest : public GreengrassRequest
  {
  public:
    CreateLoggerDefinitionRequest();
    Aws::String SerializePayload() const override;

    Aws::Http::HeaderValueCollection GetRequestSpecificHeaders() const override;

    /**
     * The client token used to request idempotent operations.
     */
    inline const Aws::String& GetAmznClientToken() const{ return m_amznClientToken; }

    /**
     * The client token used to request idempotent operations.
     */
    inline void SetAmznClientToken(const Aws::String& value) { m_amznClientTokenHasBeenSet = true; m_amznClientToken = value; }

    /**
     * The client token used to request idempotent operations.
     */
    inline void SetAmznClientToken(Aws::String&& value) { m_amznClientTokenHasBeenSet = true; m_amznClientToken = std::move(value); }

    /**
     * The client token used to request idempotent operations.
     */
    inline void SetAmznClientToken(const char* value) { m_amznClientTokenHasBeenSet = true; m_amznClientToken.assign(value); }

    /**
     * The client token used to request idempotent operations.
     */
    inline CreateLoggerDefinitionRequest& WithAmznClientToken(const Aws::String& value) { SetAmznClientToken(value); return *this;}

    /**
     * The client token used to request idempotent operations.
     */
    inline CreateLoggerDefinitionRequest& WithAmznClientToken(Aws::String&& value) { SetAmznClientToken(std::move(value)); return *this;}

    /**
     * The client token used to request idempotent operations.
     */
    inline CreateLoggerDefinitionRequest& WithAmznClientToken(const char* value) { SetAmznClientToken(value); return *this;}

    /**
     * Information on the initial version
     */
    inline const LoggerDefinitionVersion& GetInitialVersion() const{ return m_initialVersion; }

    /**
     * Information on the initial version
     */
    inline void SetInitialVersion(const LoggerDefinitionVersion& value) { m_initialVersionHasBeenSet = true; m_initialVersion = value; }

    /**
     * Information on the initial version
     */
    inline void SetInitialVersion(LoggerDefinitionVersion&& value) { m_initialVersionHasBeenSet = true; m_initialVersion = std::move(value); }

    /**
     * Information on the initial version
     */
    inline CreateLoggerDefinitionRequest& WithInitialVersion(const LoggerDefinitionVersion& value) { SetInitialVersion(value); return *this;}

    /**
     * Information on the initial version
     */
    inline CreateLoggerDefinitionRequest& WithInitialVersion(LoggerDefinitionVersion&& value) { SetInitialVersion(std::move(value)); return *this;}

    /**
     * name of the logger definition
     */
    inline const Aws::String& GetName() const{ return m_name; }

    /**
     * name of the logger definition
     */
    inline void SetName(const Aws::String& value) { m_nameHasBeenSet = true; m_name = value; }

    /**
     * name of the logger definition
     */
    inline void SetName(Aws::String&& value) { m_nameHasBeenSet = true; m_name = std::move(value); }

    /**
     * name of the logger definition
     */
    inline void SetName(const char* value) { m_nameHasBeenSet = true; m_name.assign(value); }

    /**
     * name of the logger definition
     */
    inline CreateLoggerDefinitionRequest& WithName(const Aws::String& value) { SetName(value); return *this;}

    /**
     * name of the logger definition
     */
    inline CreateLoggerDefinitionRequest& WithName(Aws::String&& value) { SetName(std::move(value)); return *this;}

    /**
     * name of the logger definition
     */
    inline CreateLoggerDefinitionRequest& WithName(const char* value) { SetName(value); return *this;}

  private:
    Aws::String m_amznClientToken;
    bool m_amznClientTokenHasBeenSet;
    LoggerDefinitionVersion m_initialVersion;
    bool m_initialVersionHasBeenSet;
    Aws::String m_name;
    bool m_nameHasBeenSet;
  };

} // namespace Model
} // namespace Greengrass
} // namespace Aws
