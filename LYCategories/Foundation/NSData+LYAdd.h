//
//  NSData+LYAdd.h
//  LYCategories
//
//  Created by Liu Y on 16/4/3.
//  Copyright © 2016年 DeveloperLY. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSData (LYAdd)

#pragma mark - Hash
/**
 *  md5加密
 *
 *  @return 加密后的字符串
 */
- (NSString *)md5;

/**
 *  sha1加密
 *
 *  @return 加密后的字符串
 */
- (NSString *)sha1;

/**
 *  sha256加密
 *
 *  @return 加密后的字符串
 */
- (NSString *)sha256;

/**
 *  sha384加密
 *
 *  @return 加密后的字符串
 */
- (NSString *)sha384;

/**
 *  sha512加密
 *
 *  @return 加密后的字符串
 */
- (NSString *)sha512;

#pragma mark - Base64

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

#pragma mark - Gzip

/**
 *  @brief  GZIP压缩
 *
 *  @param level 压缩级别
 *
 *  @return 压缩后的数据
 */
- (NSData *)ly_gzippedDataWithCompressionLevel:(float)level;

/**
 *  @brief  GZIP压缩 压缩级别 默认-1
 *
 *  @return 压缩后的数据
 */
- (NSData *)ly_gzippedData;

/**
 *  @brief  GZIP解压
 *
 *  @return 解压后数据
 */
- (NSData *)ly_gunzippedData;

/**
 *  @return 是否压缩成功
 */
- (BOOL)ly_isGzippedData;

#pragma mark - APNSToken
/**
 *  @brief  将APNS NSData类型token 格式化成字符串
 *
 *  @return 整理过后的字符串token
 */
- (NSString *)ly_APNSTokenDataToString;

@end
