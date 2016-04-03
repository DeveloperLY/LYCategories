//
//  NSString+LYAdd.h
//  LYCategories
//
//  Created by Liu Y on 16/4/2.
//  Copyright © 2016年 CoderYLiu. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <MobileCoreServices/MobileCoreServices.h>

@interface NSString (LYAdd)

#pragma mark - 判断特殊字符
///=============================================================================
/// @name 判断特殊字符
///=============================================================================

/**
 *  判断字符串是否为空
 *
 *  @return YES 是 NO 不是
 */
- (BOOL)empty;

/**
 *  判断是否为整型
 *
 *  @return YES 是 NO 不是
 */
- (BOOL)isInteger;

/**
 *  判断是否为浮点型
 *
 *  @return YES 是 NO 不是
 */
- (BOOL)isFloat;

/**
 *  判断是否有特殊字符
 *
 *  @return YES 是 NO 不是
 */
- (BOOL)isHasSpecialcharacters;

/**
 *  判断是否含有数字
 *
 *  @return YES 是 NO 不是
 */
- (BOOL)isHasNumder;

#pragma mark - 沙盒路径
///=============================================================================
/// @name 沙盒路径
///=============================================================================

/**
 *  生成缓存目录全路径
 */
- (instancetype)cacheDirectories;

/**
 *  生成文档目录全路径
 */
- (instancetype)docDirectories;

/**
 *  生成临时目录全路径
 */
- (instancetype)tmpDirectories;

#pragma mark - Hash
///=============================================================================
/// @name Hash
///=============================================================================

#pragma mark - 散列函数
/**
 *  计算MD5散列结果
 *
 *  终端测试命令：
 *  @code
 *  md5 -s "string"
 *  @endcode
 *
 *  <p>提示：随着 MD5 碰撞生成器的出现，MD5 算法不应被用于任何软件完整性检查或代码签名的用途。<p>
 *
 *  @return 32个字符的MD5散列字符串
 */
- (NSString *)md5String;

/**
 *  md5加密(16位)
 *
 *  @return 加密后的字符串
 */
- (NSString *)md5String_16;

/**
 *  计算SHA1散列结果
 *
 *  终端测试命令：
 *  @code
 *  echo -n "string" | openssl sha -sha1
 *  @endcode
 *
 *  @return 40个字符的SHA1散列字符串
 */
- (NSString *)sha1String;

/**
 *  计算SHA256散列结果
 *
 *  终端测试命令：
 *  @code
 *  echo -n "string" | openssl sha -sha256
 *  @endcode
 *
 *  @return 64个字符的SHA256散列字符串
 */
- (NSString *)sha256String;

/**
 *  计算SHA384散列结果
 *
 *  @return 加密后的字符串
 */
- (NSString *)sha384String;

/**
 *  计算SHA 512散列结果
 *
 *  终端测试命令：
 *  @code
 *  echo -n "string" | openssl sha -sha512
 *  @endcode
 *
 *  @return 128个字符的SHA 512散列字符串
 */
- (NSString *)sha512String;

#pragma mark - HMAC 散列函数
/**
 *  计算HMAC MD5散列结果
 *
 *  终端测试命令：
 *  @code
 *  echo -n "string" | openssl dgst -md5 -hmac "key"
 *  @endcode
 *
 *  @return 32个字符的HMAC MD5散列字符串
 */
- (NSString *)hmacMD5StringWithKey:(NSString *)key;

/**
 *  计算HMAC SHA1散列结果
 *
 *  终端测试命令：
 *  @code
 *  echo -n "string" | openssl sha -sha1 -hmac "key"
 *  @endcode
 *
 *  @return 40个字符的HMAC SHA1散列字符串
 */
- (NSString *)hmacSHA1StringWithKey:(NSString *)key;

/**
 *  计算HMAC SHA256散列结果
 *
 *  终端测试命令：
 *  @code
 *  echo -n "string" | openssl sha -sha256 -hmac "key"
 *  @endcode
 *
 *  @return 64个字符的HMAC SHA256散列字符串
 */
- (NSString *)hmacSHA256StringWithKey:(NSString *)key;

/**
 *  计算HMAC SHA512散列结果
 *
 *  终端测试命令：
 *  @code
 *  echo -n "string" | openssl sha -sha512 -hmac "key"
 *  @endcode
 *
 *  @return 128个字符的HMAC SHA512散列字符串
 */
- (NSString *)hmacSHA512StringWithKey:(NSString *)key;

#pragma mark - 文件散列函数

/**
 *  计算文件的MD5散列结果
 *
 *  终端测试命令：
 *  @code
 *  md5 file.dat
 *  @endcode
 *
 *  @return 32个字符的MD5散列字符串
 */
- (NSString *)fileMD5Hash;

/**
 *  计算文件的SHA1散列结果
 *
 *  终端测试命令：
 *  @code
 *  openssl sha -sha1 file.dat
 *  @endcode
 *
 *  @return 40个字符的SHA1散列字符串
 */
- (NSString *)fileSHA1Hash;

/**
 *  计算文件的SHA256散列结果
 *
 *  终端测试命令：
 *  @code
 *  openssl sha -sha256 file.dat
 *  @endcode
 *
 *  @return 64个字符的SHA256散列字符串
 */
- (NSString *)fileSHA256Hash;

/**
 *  计算文件的SHA512散列结果
 *
 *  终端测试命令：
 *  @code
 *  openssl sha -sha512 file.dat
 *  @endcode
 *
 *  @return 128个字符的SHA512散列字符串
 */
- (NSString *)fileSHA512Hash;

#pragma mark - 加密
///=============================================================================
/// @name 加密
///=============================================================================

// base64
/**
 *  base64加密
 *
 *  @return 加密后的字符串
 */
- (NSString *)base64Encode;

/**
 *  base64解密
 *
 *  @return 解密后的字符串
 */
- (NSString *)base64Decode;

// des
/**
 *  DES加密
 *
 *  @param key 加密需要的key
 *
 *  @return 得到加密后的字符串
 */
- (NSString *)encryptWithKey:(NSString *)key;

/**
 *  DES解密
 *
 *  @param key 解密需要的key
 *
 *  @return 得到解密后的字符串
 */
- (NSString *)decryptWithKey:(NSString *)key;
#pragma mark - MIME
///=============================================================================
/// @name MIME
///=============================================================================

- (instancetype)mimeTypeForNetWorkRequest;

- (instancetype)mimeTypeForFileAtPath;

#pragma mark - 时间字符串处理
///=============================================================================
/// @name NSDate
///=============================================================================

/**
 *  秒级时间戳转日期
 *
 *  @return 日期
 */
- (NSDate *)dateValueWithTimeIntervalSince1970;

/**
 *  毫秒级时间戳转日期
 *
 *  @return 日期
 */
- (NSDate *)dateValueWithMillisecondsSince1970;

/**
 *  时间戳转格式化的时间字符串
 *
 *  @param formatString 时间格式
 *
 *  @return 格式化的时间字符串
 */
- (instancetype)timestampToTimeStringWithFormatString:(NSString *)formatString;

#pragma mark - 实用工具
///=============================================================================
/// @name 实用工具
///=============================================================================

/**
 *  返回一个新的UUID字符串
 *
 *  e.g. "D34242E34-2C4E-3A1B-2BE3-F6ADC00W04B3"
 */
+ (NSString *)stringWithUUID;

/**
 *  日期+随机数的字符串（比如为文件命名）
 *
 *  @return 得到的字符串
 */
+ (NSString*)getTimeAndRandomString;

#pragma mark - 正则匹配
///=============================================================================
/// @name 正则匹配
///=============================================================================

/**
 *  匹配Email
 *
 *  @return YES 成功 NO 失败
 */
- (BOOL)isEmail;

/**
 *  匹配URL
 *
 *  @return YES 成功 NO 失败
 */
- (BOOL)isUrl;

/**
 *  匹配电话号码
 *
 *  @return YES 成功 NO 失败
 */
- (BOOL)isTelephone;

/**
 *  由英文、字母或数字组成 6-18位
 *
 *  @return YES 验证成功 NO 验证失败
 */
- (BOOL)isPassword;

/**
 *  匹配数字
 *
 *  @return YES 成功 NO 失败
 */
- (BOOL)isNumbers;

/**
 *  匹配英文字母
 *
 *  @return YES 成功 NO 失败
 */
- (BOOL)isLetter;

/**
 *  匹配大写英文字母
 *
 *  @return YES 成功 NO 失败
 */
- (BOOL)isCapitalLetter;

/**
 *  匹配小写英文字母
 *
 *  @return YES 成功 NO 失败
 */
- (BOOL)isSmallLetter;

/**
 *  匹配小写英文字母
 *
 *  @return YES 成功 NO 失败
 */
- (BOOL)isLetterAndNumbers;

/**
 *  匹配中文，英文字母和数字及_
 *
 *  @return YES 成功 NO 失败
 */
- (BOOL)isChineseAndLetterAndNumberAndBelowLine;

/**
 *  匹配中文，英文字母和数字及_ 并限制字数
 *
 *  @return YES 成功 NO 失败
 */
- (BOOL)isChineseAndLetterAndNumberAndBelowLine4to10;

/**
 *  匹配含有汉字、数字、字母、下划线不能以下划线开头和结尾
 *
 *  @return YES 成功 NO 失败
 */
- (BOOL)isChineseAndLetterAndNumberAndBelowLineNotFirstOrLast;

#pragma mark - 计算字符串尺寸
///=============================================================================
/// @name 计算字符串尺寸
///=============================================================================

/**
 *  计算字符串高度 （多行）
 *
 *  @param width 字符串的宽度
 *  @param font  字体大小
 *
 *  @return 字符串的尺寸
 */
- (CGSize)heightWithWidth:(CGFloat)width andFont:(CGFloat)font;

/**
 *  计算字符串宽度
 *
 *  @param height 字符串的高度
 *  @param font  字体大小
 *
 *  @return 字符串的尺寸
 */
- (CGSize)widthWithHeight:(CGFloat)height andFont:(CGFloat)font;

#pragma mark - 检测是否含有某个字符
///=============================================================================
/// @name 检测是否含有某个字符
///=============================================================================

/**
 *  检测是否含有某个字符
 *
 *  @param string 检测是否含有的字符
 *
 *  @return YES 含有 NO 不含有
 */
- (BOOL)containString:(NSString *)string;

/**
 *  是否含有汉字
 *
 *  @return YES 是 NO 不是
 */
- (BOOL)containsChineseCharacter;

#pragma mark - 计算String的字数(中英混合)
///=============================================================================
/// @name 计算String的字数(中英混合)
///=============================================================================

/**
 *  计算string字数
 *
 *  @return 获得的中英混合字数
 */
- (NSInteger)stringLength;


#pragma mark -  email 转换为 774******@qq.com 形式
///=============================================================================
/// @name email 转换为 774******@qq.com 形式
///=============================================================================

/**
 *  email 转换为 774******@qq.com 形式
 *
 *  @return 替换后的字符串
 */
- (NSString *)emailChangeToPrivacy;

#pragma mark - Emoji相关
///=============================================================================
/// @name Emoji相关
///=============================================================================

/**
 *  判断是否是Emoji
 *
 *  @return YES 是 NO 不是
 */
- (BOOL)isEmoji;

/**
 *  判断字符串时候含有Emoji
 *
 *  @return YES 是 NO 不是
 */
- (BOOL)isIncludingEmoji;

/**
 *  移除掉字符串中得Emoji
 *
 *  @return 得到移除后的Emoji
 */
- (instancetype)removedEmojiString;

@end
