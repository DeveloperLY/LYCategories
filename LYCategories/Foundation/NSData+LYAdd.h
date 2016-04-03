//
//  NSData+LYAdd.h
//  LYCategories
//
//  Created by Liu Y on 16/4/3.
//  Copyright © 2016年 CoderYLiu. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSData (LYAdd)

#pragma mark - 加密
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

@end
