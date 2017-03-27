//
//  NSUserDefaults+LYAdd.h
//  LYCategories
//
//  Created by LiuY on 2017/3/27.
//  Copyright © 2017年 DeveloperLY. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSUserDefaults (LYAdd)

#pragma mark - iColoudSync

- (void)ly_setValue:(id)value forKey:(NSString *)key iCloudSync:(BOOL)sync;
- (void)ly_setObject:(id)value forKey:(NSString *)key iCloudSync:(BOOL)sync;

- (instancetype)ly_valueForKey:(NSString *)key iCloudSync:(BOOL)sync;
- (instancetype)ly_objectForKey:(NSString *)key iCloudSync:(BOOL)sync;

- (BOOL)ly_synchronizeAlsoiCloudSync:(BOOL)sync;

#pragma mark - 安全操作
+ (NSString *)ly_stringForKey:(NSString *)defaultName;

+ (NSArray *)ly_arrayForKey:(NSString *)defaultName;

+ (NSDictionary *)ly_dictionaryForKey:(NSString *)defaultName;

+ (NSData *)ly_dataForKey:(NSString *)defaultName;

+ (NSArray *)ly_stringArrayForKey:(NSString *)defaultName;

+ (NSInteger)ly_integerForKey:(NSString *)defaultName;

+ (float)ly_floatForKey:(NSString *)defaultName;

+ (double)ly_doubleForKey:(NSString *)defaultName;

+ (BOOL)ly_boolForKey:(NSString *)defaultName;

+ (NSURL *)ly_URLForKey:(NSString *)defaultName;

#pragma mark - WRITE FOR STANDARD

+ (void)ly_setObject:(id)value forKey:(NSString *)defaultName;

#pragma mark - READ ARCHIVE FOR STANDARD

+ (instancetype)ly_arcObjectForKey:(NSString *)defaultName;

#pragma mark - WRITE ARCHIVE FOR STANDARD

+ (void)ly_setArcObject:(id)value forKey:(NSString *)defaultName;

@end
