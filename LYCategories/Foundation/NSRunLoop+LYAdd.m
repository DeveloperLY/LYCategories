//
//  NSRunLoop+LYAdd.m
//  LYCategories
//
//  Created by LiuY on 2017/3/27.
//  Copyright © 2017年 DeveloperLY. All rights reserved.
//

#import "NSRunLoop+LYAdd.h"
#import "LYCategoriesMacro.h"

LYSYNTH_DUMMY_CLASS(NSData_LYAdd)

NSString * const NSRunloopTimeoutException = @"NSRunloopTimeoutException";

@implementation NSRunLoop (LYAdd)

- (void)ly_performBlockAndWait:(void (^)(BOOL *))block {
    [self ly_performBlockAndWait:block timeoutInterval:10.0];
}

- (void)ly_performBlockAndWait:(void (^)(BOOL *))block timeoutInterval:(NSTimeInterval)timeoutInterval {
    if (!block || timeoutInterval < 0.0) {
        [NSException raise:NSInvalidArgumentException format:@"%lf is invalid for timeout interval", timeoutInterval];
    }
    
    NSDate *startedDate = [NSDate date];
    BOOL finish = NO;
    
    block(&finish);
    
    while (!finish && [[NSDate date] timeIntervalSinceDate:startedDate] < timeoutInterval) {
        @autoreleasepool {
            [self runUntilDate:[NSDate dateWithTimeIntervalSinceNow:.1]];
        }
    }
    
    if (!finish) {
        [NSException raise:NSRunloopTimeoutException format:@"execution of block timed out in performBlockAndWait:."];
    }
}

@end
