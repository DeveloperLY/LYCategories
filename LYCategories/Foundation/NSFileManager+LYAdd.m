//
//  NSFileManager+LYAdd.m
//  LYCategories
//
//  Created by Liu Y on 16/4/3.
//  Copyright © 2016年 CoderYLiu. All rights reserved.
//

#import "NSFileManager+LYAdd.h"
#import "LYCategoriesMacro.h"

LYSYNTH_DUMMY_CLASS(NSFileManager_LYAdd)

@implementation NSFileManager (LYAdd)

#pragma mark - 各种路径及URL
/**
 *  获取URL
 *
 *  @param directory 指定的directory
 *
 *  @return 得到的URL
 */
+ (NSURL *)URLForDirectory:(NSSearchPathDirectory)directory {
    return [self.defaultManager URLsForDirectory:directory inDomains:NSUserDomainMask].lastObject;
}

/**
 *  获取指定directory的路径
 *
 *  @param directory 指定的directory
 *
 *  @return 得到的路径
 */
+ (NSString *)pathForDirectory:(NSSearchPathDirectory)directory {
    return NSSearchPathForDirectoriesInDomains(directory, NSUserDomainMask, YES)[0];
}

+ (NSURL *)documentsURL {
    return [self URLForDirectory:NSDocumentDirectory];
}

+ (NSString *)documentsPath {
    return [self pathForDirectory:NSDocumentDirectory];
}

+ (NSURL *)libraryURL {
    return [self URLForDirectory:NSLibraryDirectory];
}

+ (NSString *)libraryPath {
    return [self pathForDirectory:NSLibraryDirectory];
}

+ (NSURL *)cachesURL {
    return [self URLForDirectory:NSCachesDirectory];
}

+ (NSString *)cachesPath {
    return [self pathForDirectory:NSCachesDirectory];
}

+ (NSString *)homePath {
    return NSHomeDirectory();
}

+ (NSString *)tmpPath {
    return NSTemporaryDirectory();
}

#pragma mark - 各种方法

- (BOOL)isFileExists:(NSString *)filePath {
    NSFileManager *fileManager = [NSFileManager defaultManager];
    BOOL result = [fileManager fileExistsAtPath:filePath];
    
    return result;
}

- (BOOL)isFile:(NSString *)filePath timeout:(NSTimeInterval)timeout {
    if ([[NSFileManager defaultManager] isFileExists:filePath]) {
        NSError *error = nil;
        NSDictionary *attributes = [[NSFileManager defaultManager] attributesOfItemAtPath:filePath error:&error];
        if (error) {
            return YES;
        }
        if ([attributes isKindOfClass:[NSDictionary class]] && attributes) {
            //  NSLog(@"%@", attributes);
            NSString *createDate = [attributes objectForKey:@"NSFileModificationDate"];
            createDate = [NSString stringWithFormat:@"%@", createDate];
            if (createDate.length >= 19) {
                createDate = [createDate substringToIndex:19];
                NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
                formatter.dateFormat = @"yyyy-MM-dd HH:mm:ss";
                
                NSDate *sinceDate = [formatter dateFromString:createDate];
                NSTimeInterval interval = [[NSDate date] timeIntervalSinceDate:sinceDate];
                return interval <= 0;
            }
        }
    }
    return YES;
}


@end
