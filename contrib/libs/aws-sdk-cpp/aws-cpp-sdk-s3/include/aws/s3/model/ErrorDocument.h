/** 
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved. 
 * SPDX-License-Identifier: Apache-2.0. 
 */ 
 
#pragma once 
#include <aws/s3/S3_EXPORTS.h> 
#include <aws/core/utils/memory/stl/AWSString.h> 
#include <utility> 
 
namespace Aws 
{ 
namespace Utils 
{ 
namespace Xml 
{ 
  class XmlNode; 
} // namespace Xml 
} // namespace Utils 
namespace S3 
{ 
namespace Model 
{ 
 
  /**
   * <p>The error information.</p><p><h3>See Also:</h3>   <a 
   * href="http://docs.aws.amazon.com/goto/WebAPI/s3-2006-03-01/ErrorDocument">AWS
   * API Reference</a></p>
   */
  class AWS_S3_API ErrorDocument 
  { 
  public: 
    ErrorDocument(); 
    ErrorDocument(const Aws::Utils::Xml::XmlNode& xmlNode); 
    ErrorDocument& operator=(const Aws::Utils::Xml::XmlNode& xmlNode); 
 
    void AddToNode(Aws::Utils::Xml::XmlNode& parentNode) const; 
 
 
    /** 
     * <p>The object key name to use when a 4XX class error occurs.</p> 
     */ 
    inline const Aws::String& GetKey() const{ return m_key; } 
 
    /** 
     * <p>The object key name to use when a 4XX class error occurs.</p> 
     */ 
    inline bool KeyHasBeenSet() const { return m_keyHasBeenSet; }

    /**
     * <p>The object key name to use when a 4XX class error occurs.</p>
     */
    inline void SetKey(const Aws::String& value) { m_keyHasBeenSet = true; m_key = value; } 
 
    /** 
     * <p>The object key name to use when a 4XX class error occurs.</p> 
     */ 
    inline void SetKey(Aws::String&& value) { m_keyHasBeenSet = true; m_key = std::move(value); } 
 
    /** 
     * <p>The object key name to use when a 4XX class error occurs.</p> 
     */ 
    inline void SetKey(const char* value) { m_keyHasBeenSet = true; m_key.assign(value); } 
 
    /** 
     * <p>The object key name to use when a 4XX class error occurs.</p> 
     */ 
    inline ErrorDocument& WithKey(const Aws::String& value) { SetKey(value); return *this;} 
 
    /** 
     * <p>The object key name to use when a 4XX class error occurs.</p> 
     */ 
    inline ErrorDocument& WithKey(Aws::String&& value) { SetKey(std::move(value)); return *this;} 
 
    /** 
     * <p>The object key name to use when a 4XX class error occurs.</p> 
     */ 
    inline ErrorDocument& WithKey(const char* value) { SetKey(value); return *this;} 
 
  private: 
 
    Aws::String m_key; 
    bool m_keyHasBeenSet; 
  }; 
 
} // namespace Model 
} // namespace S3 
} // namespace Aws 
