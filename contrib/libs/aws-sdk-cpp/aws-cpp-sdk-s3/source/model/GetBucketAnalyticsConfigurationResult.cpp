/** 
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved. 
 * SPDX-License-Identifier: Apache-2.0. 
 */ 
 
#include <aws/s3/model/GetBucketAnalyticsConfigurationResult.h> 
#include <aws/core/utils/xml/XmlSerializer.h> 
#include <aws/core/AmazonWebServiceResult.h> 
#include <aws/core/utils/StringUtils.h> 
 
#include <utility> 
 
using namespace Aws::S3::Model; 
using namespace Aws::Utils::Xml; 
using namespace Aws::Utils; 
using namespace Aws; 
 
GetBucketAnalyticsConfigurationResult::GetBucketAnalyticsConfigurationResult() 
{ 
} 
 
GetBucketAnalyticsConfigurationResult::GetBucketAnalyticsConfigurationResult(const Aws::AmazonWebServiceResult<XmlDocument>& result) 
{ 
  *this = result; 
} 
 
GetBucketAnalyticsConfigurationResult& GetBucketAnalyticsConfigurationResult::operator =(const Aws::AmazonWebServiceResult<XmlDocument>& result) 
{ 
  const XmlDocument& xmlDocument = result.GetPayload(); 
  XmlNode resultNode = xmlDocument.GetRootElement(); 
 
  if(!resultNode.IsNull()) 
  { 
    m_analyticsConfiguration = resultNode; 
  } 
 
  return *this; 
} 
