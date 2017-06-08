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
#include <utility>

namespace Aws
{
namespace Http
{
    class URI;
} //namespace Http
namespace Greengrass
{
namespace Model
{

  /**
   */
  class AWS_GREENGRASS_API ListLoggerDefinitionsRequest : public GreengrassRequest
  {
  public:
    ListLoggerDefinitionsRequest();
    Aws::String SerializePayload() const override;

    void AddQueryStringParameters(Aws::Http::URI& uri) const override;

    /**
     * Specifies the maximum number of list results to be returned in this page
     */
    inline const Aws::String& GetMaxResults() const{ return m_maxResults; }

    /**
     * Specifies the maximum number of list results to be returned in this page
     */
    inline void SetMaxResults(const Aws::String& value) { m_maxResultsHasBeenSet = true; m_maxResults = value; }

    /**
     * Specifies the maximum number of list results to be returned in this page
     */
    inline void SetMaxResults(Aws::String&& value) { m_maxResultsHasBeenSet = true; m_maxResults = std::move(value); }

    /**
     * Specifies the maximum number of list results to be returned in this page
     */
    inline void SetMaxResults(const char* value) { m_maxResultsHasBeenSet = true; m_maxResults.assign(value); }

    /**
     * Specifies the maximum number of list results to be returned in this page
     */
    inline ListLoggerDefinitionsRequest& WithMaxResults(const Aws::String& value) { SetMaxResults(value); return *this;}

    /**
     * Specifies the maximum number of list results to be returned in this page
     */
    inline ListLoggerDefinitionsRequest& WithMaxResults(Aws::String&& value) { SetMaxResults(std::move(value)); return *this;}

    /**
     * Specifies the maximum number of list results to be returned in this page
     */
    inline ListLoggerDefinitionsRequest& WithMaxResults(const char* value) { SetMaxResults(value); return *this;}

    /**
     * Specifies the pagination token used when iterating through a paginated request
     */
    inline const Aws::String& GetNextToken() const{ return m_nextToken; }

    /**
     * Specifies the pagination token used when iterating through a paginated request
     */
    inline void SetNextToken(const Aws::String& value) { m_nextTokenHasBeenSet = true; m_nextToken = value; }

    /**
     * Specifies the pagination token used when iterating through a paginated request
     */
    inline void SetNextToken(Aws::String&& value) { m_nextTokenHasBeenSet = true; m_nextToken = std::move(value); }

    /**
     * Specifies the pagination token used when iterating through a paginated request
     */
    inline void SetNextToken(const char* value) { m_nextTokenHasBeenSet = true; m_nextToken.assign(value); }

    /**
     * Specifies the pagination token used when iterating through a paginated request
     */
    inline ListLoggerDefinitionsRequest& WithNextToken(const Aws::String& value) { SetNextToken(value); return *this;}

    /**
     * Specifies the pagination token used when iterating through a paginated request
     */
    inline ListLoggerDefinitionsRequest& WithNextToken(Aws::String&& value) { SetNextToken(std::move(value)); return *this;}

    /**
     * Specifies the pagination token used when iterating through a paginated request
     */
    inline ListLoggerDefinitionsRequest& WithNextToken(const char* value) { SetNextToken(value); return *this;}

  private:
    Aws::String m_maxResults;
    bool m_maxResultsHasBeenSet;
    Aws::String m_nextToken;
    bool m_nextTokenHasBeenSet;
  };

} // namespace Model
} // namespace Greengrass
} // namespace Aws
