//
//  NSObject+LYAdd.h
//  LYCategories
//
//  Created by Liu Y on 16/4/2.
//  Copyright © 2016年 DeveloperLY. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (LYAdd)

#pragma mark - NSInvocation封装
///=============================================================================
/// @name NSInvocation封装
///=============================================================================

/**
 *  @brief消息发送选择器
 *
 *  @param aSelector 变量参数列表
 *
 *  @return 消息结果
 */
- (id)performSelector:(SEL)aSelector withObjects:(NSArray *)objects;

#pragma mark - AssociatedObject 附加属性
///=============================================================================
/// @name AssociatedObject 附加属性
///=============================================================================

/**
 *  @brief  附加一个Stong对象
 *
 *  @param value 被附加的对象
 *  @param key   被附加对象的key
 */
- (void)ly_associateValue:(id)value withKey:(void *)key;

/**
 *  @brief  附加一个weak对象
 *
 *  @param value 被附加的对象
 *  @param key   被附加对象的key
 */
- (void)ly_weaklyAssociateValue:(id)value withKey:(void *)key;

/**
 *  @brief  根据附加对象的key取出附加对象
 *
 *  @param key 附加对象的key
 *
 *  @return 附加对象
 */
- (id)ly_associatedValueForKey:(void *)key;

#pragma mark - Runtime
///=============================================================================
/// @name Runtime
///=============================================================================

/**
 Exchange methods' implementations.
 
 @param originalMethod Method to exchange.
 @param newMethod Method to exchange.
 */
+ (void)ly_swizzleMethod:(SEL)originalMethod withMethod:(SEL)newMethod;

/**
 Append a new method to an object.
 
 @param newMethod Method to exchange.
 @param klass Host class.
 */
+ (void)ly_appendMethod:(SEL)newMethod fromClass:(Class)klass;

/**
 Replace a method in an object.
 
 @param method Method to exchange.
 @param klass Host class.
 */
+ (void)ly_replaceMethod:(SEL)method fromClass:(Class)klass;

/**
 Check whether the receiver implements or inherits a specified method up to and exluding a particular class in hierarchy.
 
 @param selector A selector that identifies a method.
 @param stopClass A final super class to stop quering (excluding it).
 @return YES if one of super classes in hierarchy responds a specified selector.
 */
- (BOOL)ly_respondsToSelector:(SEL)selector untilClass:(Class)stopClass;

/**
 Check whether a superclass implements or inherits a specified method.
 
 @param selector A selector that identifies a method.
 @return YES if one of super classes in hierarchy responds a specified selector.
 */
- (BOOL)ly_superRespondsToSelector:(SEL)selector;

/**
 Check whether a superclass implements or inherits a specified method.
 
 @param selector A selector that identifies a method.
 @param stopClass A final super class to stop quering (excluding it).
 @return YES if one of super classes in hierarchy responds a specified selector.
 */
- (BOOL)ly_superRespondsToSelector:(SEL)selector untilClass:(Class)stopClass;

/**
 Check whether the receiver's instances implement or inherit a specified method up to and exluding a particular class in hierarchy.
 
 @param selector A selector that identifies a method.
 @param stopClass A final super class to stop quering (excluding it).
 @return YES if one of super classes in hierarchy responds a specified selector.
 */
+ (BOOL)ly_instancesRespondToSelector:(SEL)selector untilClass:(Class)stopClass;

@end
