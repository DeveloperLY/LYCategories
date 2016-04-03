//
//  NSObject+LYAdd.m
//  LYCategories
//
//  Created by Liu Y on 16/4/2.
//  Copyright © 2016年 CoderYLiu. All rights reserved.
//

#import "NSObject+LYAdd.h"
#import "LYCategoriesMacro.h"

LYSYNTH_DUMMY_CLASS(NSObject_LYAdd)

@implementation NSObject (LYAdd)

#pragma mark - NSInvocation封装

- (id)performSelector:(SEL)aSelector withObjects:(NSArray *)objects {
    NSMethodSignature  *signature = [[self class] instanceMethodSignatureForSelector:aSelector];
    
    if (!signature) {
        NSString *errorInfo = [NSString stringWithFormat:@"%@方法找不到", NSStringFromSelector(aSelector)];
        [NSException exceptionWithName:@"NSInvocation扩展异常" reason:errorInfo userInfo:nil];
    }
    
    NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:signature];
    invocation.target = self;
    invocation.selector = aSelector;
    
    NSUInteger argsCount = signature.numberOfArguments - 2;
    NSUInteger arrCount = objects.count;
    NSUInteger count = MIN(argsCount, arrCount);
    
    for (NSUInteger i = 0; i < count; i++) {
        id obj = objects[i];
        if ([obj isKindOfClass:[NSNull class]]) {
            obj = nil;
        }
        [invocation setArgument:&obj atIndex:i + 2];
    }
    
    [invocation invoke];
    
    id res = nil;
    if (signature.methodReturnLength != 0) {
        [invocation getReturnValue:&res];
    }
    return res;
}

@end
