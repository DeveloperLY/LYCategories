//
//  NSNotificationCenter+LYAdd.m
//  LYCategories
//
//  Created by LiuY on 2017/3/27.
//  Copyright © 2017年 DeveloperLY. All rights reserved.
//

#import "NSNotificationCenter+LYAdd.h"
#import "LYCategoriesMacro.h"

LYSYNTH_DUMMY_CLASS(NSNotificationCenter_LYAdd)

@implementation NSNotificationCenter (LYAdd)

- (void)ly_postNotificationOnMainThread:(NSNotification *)notification {
    [self performSelectorOnMainThread:@selector(postNotification:) withObject:notification waitUntilDone:YES];
}


- (void)ly_postNotificationOnMainThreadName:(NSString *)aName object:(id)anObject {
    NSNotification *notification = [NSNotification notificationWithName:aName object:anObject];
    [self ly_postNotificationOnMainThread:notification];
}


- (void)ly_postNotificationOnMainThreadName:(NSString *)aName object:(id)anObject userInfo:(NSDictionary *)aUserInfo {
    NSNotification *notification = [NSNotification notificationWithName:aName object:anObject userInfo:aUserInfo];
    [self ly_postNotificationOnMainThread:notification];
}

@end
