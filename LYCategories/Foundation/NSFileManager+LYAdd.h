//
//  NSFileManager+LYAdd.h
//  LYCategories
//
//  Created by Liu Y on 16/4/3.
//  Copyright © 2016年 CoderYLiu. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSFileManager (LYAdd)

#pragma mark - 各种路径及URL
///=============================================================================
/// @name 各种路径及URL
///=============================================================================

/**
 *  获取URL
 *
 *  @param directory 指定的directory
 *
 *  @return 得到的URL
 */
+ (NSURL *)documentsURL;


/**
 *  获取Documents目录路径
 *
 *  @return Documents目录路径
 */
+ (NSString *)documentsPath;

/**
 *  获取Library目录URL
 *
 *  @return Library目录URL
 */
+ (NSURL *)libraryURL;

/**
 *  获取Library目录路径
 *
 *  @return Library目录路径
 */
+ (NSString *)libraryPath;

/**
 *  获取Cache目录URL
 *
 *  @return Cache目录URL
 */
+ (NSURL *)cachesURL;

/**
 *  获取Cache目录路径
 *
 *  @return Cache目录路径
 */
+ (NSString *)cachesPath;

/**
 *  获取应用沙盒根路径
 *
 *  @return 应用沙盒根路径
 */
+ (NSString *)homePath;

/**
 *  获取Tmp目录路径
 *
 *  @return Tmp目录路径
 */
+ (NSString *)tmpPath;


#pragma mark - 各种方法
///=============================================================================
/// @name 各种方法
///=============================================================================


/**
 * @brief 判断文件是否存在于沙盒中
 *
 * @param fileName 文件路径名
 *
 * @return 返回YES表示存在，返回NO表示不存在
 */
- (BOOL)isFileExists:(NSString *)filePath;

/**
 * @brief 判断文件是否超时
 *
 * @param filePath 文件路径名
 *
 * @param timeout 限制的超时时间，单位为秒
 *
 * @return 返回YES表示超时，返回NO表示未超时
 */
- (BOOL)isFile:(NSString *)filePath timeout:(NSTimeInterval)timeout;

@end
