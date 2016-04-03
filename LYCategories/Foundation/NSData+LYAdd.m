//
//  NSData+LYAdd.m
//  LYCategories
//
//  Created by Liu Y on 16/4/3.
//  Copyright © 2016年 CoderYLiu. All rights reserved.
//

#import "NSData+LYAdd.h"
#import <CommonCrypto/CommonDigest.h>
#import <CommonCrypto/CommonCrypto.h>
#import "GTMBase64.h"
#import <zlib.h>
#import "LYCategoriesMacro.h"

LYSYNTH_DUMMY_CLASS(NSData_LYAdd)

@implementation NSData (LYAdd)

- (NSString *)md5 {
    unsigned char digest[CC_MD5_DIGEST_LENGTH];
    CC_MD5( self.bytes, (CC_LONG)self.length, digest );
    NSMutableString *result = [NSMutableString stringWithCapacity:CC_MD5_DIGEST_LENGTH *2];
    for(int i =0; i < CC_MD5_DIGEST_LENGTH; i++)
        [result appendFormat:@"%02x", digest[i]];
    return result;
}

- (NSString *)sha1 {
    uint8_t digest[CC_SHA1_DIGEST_LENGTH];
    CC_SHA1(self.bytes, (CC_LONG)self.length, digest);
    NSMutableString* result = [NSMutableString stringWithCapacity:CC_SHA1_DIGEST_LENGTH *2];
    for(int i =0; i < CC_SHA1_DIGEST_LENGTH; i++) {
        [result appendFormat:@"%02x", digest[i]];
    }
    return result;
}

- (NSString *)sha256 {
    uint8_t digest[CC_SHA256_DIGEST_LENGTH];
    CC_SHA1(self.bytes, (CC_LONG)self.length, digest);
    NSMutableString* result = [NSMutableString stringWithCapacity:CC_SHA256_DIGEST_LENGTH *2];
    for(int i =0; i < CC_SHA256_DIGEST_LENGTH; i++) {
        [result appendFormat:@"%02x", digest[i]];
    }
    return result;
}

- (NSString *)sha384 {
    uint8_t digest[CC_SHA384_DIGEST_LENGTH];
    CC_SHA1(self.bytes, (CC_LONG)self.length, digest);
    NSMutableString* result = [NSMutableString stringWithCapacity:CC_SHA384_DIGEST_LENGTH *2];
    for(int i =0; i < CC_SHA384_DIGEST_LENGTH; i++) {
        [result appendFormat:@"%02x", digest[i]];
    }
    return result;
}

- (NSString *)sha512 {
    uint8_t digest[CC_SHA512_DIGEST_LENGTH];
    CC_SHA1(self.bytes, (CC_LONG)self.length, digest);
    NSMutableString* result = [NSMutableString stringWithCapacity:CC_SHA512_DIGEST_LENGTH *2];
    for(int i =0; i < CC_SHA512_DIGEST_LENGTH; i++) {
        [result appendFormat:@"%02x", digest[i]];
    }
    return result;
}

- (NSString *)base64Encode {
    NSString *base64String = [GTMBase64 encodeBase64Data:self];
    return base64String;
}

- (NSString *)base64Decode {
    NSString *base64String = [GTMBase64 decodeBase64Data:self];
    return base64String;
}

- (NSString *)encryptWithKey:(NSString *)key {
    return [self encrypt:self encryptOrDecrypt:kCCEncrypt key:key];
}

- (NSString *)decryptWithKey:(NSString *)key {
    return [self encrypt:self encryptOrDecrypt:kCCDecrypt key:key];
}

/**
 *  加密或解密
 *
 *  @param sText            需要加密或解密的字符串
 *  @param encryptOperation kCCDecrypt 解密 kCCEncrypt 加密
 *  @param key              加密解密需要的key
 *
 *  @return 返回加密或解密之后得到的字符串
 */
- (NSString *)encrypt:(NSData *)lsdata encryptOrDecrypt:(CCOperation)encryptOperation key:(NSString *)key {
    const void *vplainText;
    size_t plainTextBufferSize;
    
    if (encryptOperation == kCCDecrypt) {
        plainTextBufferSize = [lsdata length];
        vplainText = [lsdata bytes];
    } else {
        plainTextBufferSize = [lsdata length];
        vplainText = (const void *)[lsdata bytes];
    }
    
    CCCryptorStatus ccStatus;
    uint8_t *bufferPtr = NULL;
    size_t bufferPtrSize = 0;
    size_t movedBytes = 0;
    
    bufferPtrSize = (plainTextBufferSize + kCCBlockSize3DES) & ~(kCCBlockSize3DES - 1);
    bufferPtr = malloc( bufferPtrSize * sizeof(uint8_t));
    memset((void *)bufferPtr, 0x0, bufferPtrSize);
    
    NSString *initVec = @"shuai";
    const void *vkey = (const void *) [key UTF8String];
    const void *vinitVec = (const void *) [initVec UTF8String];
    
    ccStatus = CCCrypt(encryptOperation,
                       kCCAlgorithm3DES,
                       kCCOptionPKCS7Padding,
                       vkey,
                       kCCKeySize3DES,
                       vinitVec,
                       vplainText,
                       plainTextBufferSize,
                       (void *)bufferPtr,
                       bufferPtrSize,
                       &movedBytes);
    
    NSString *result = nil;
    
    if (encryptOperation == kCCDecrypt) {
        result = [[NSString alloc] initWithData:[NSData dataWithBytes:(const void *)bufferPtr length:(NSUInteger)movedBytes] encoding:NSUTF8StringEncoding] ;
    } else {
        NSData *data = [NSData dataWithBytes:(const void *)bufferPtr length:(NSUInteger)movedBytes];
        result = [GTMBase64 stringByEncodingData:data];
    }
    
    return result;
}

@end
