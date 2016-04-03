//
//  NSObject+LYAdd.h
//  LYCategories
//
//  Created by Liu Y on 16/4/2.
//  Copyright © 2016年 CoderYLiu. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <objc/runtime.h>

// 动态Get方法
#define categoryPropertyGet(property) return objc_getAssociatedObject(self,@#property);
// 动态Set方法
#define categoryPropertySet(property) objc_setAssociatedObject(self,@#property, property, OBJC_ASSOCIATION_RETAIN_NONATOMIC);

@interface NSObject (LYAdd)

#pragma mark - NSInvocation封装
///=============================================================================
/// @name NSInvocation封装
///=============================================================================

/**
 *  消息发送选择器
 *
 *  @param sel 变量参数列表
 *
 *  @return 消息结果
 */
- (id)performSelector:(SEL)aSelector withObjects:(NSArray *)objects;

@end
