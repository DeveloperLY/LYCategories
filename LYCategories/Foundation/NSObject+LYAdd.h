//
//  NSObject+LYAdd.h
//  LYCategories
//
//  Created by Liu Y on 16/4/2.
//  Copyright © 2016年 DeveloperLY. All rights reserved.
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
 *  @brief消息发送选择器
 *
 *  @param sel 变量参数列表
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

#pragma mark - AddProperty 添加属性
///=============================================================================
/// @name AddProperty 添加属性
///=============================================================================

/**
 *  @brief  catgory runtime实现get set方法增加一个字符串属性
 */
@property (nonatomic, strong) NSString *ly_stringProperty;

/**
 *  @brief  catgory runtime实现get set方法增加一个NSInteger属性
 */
@property (nonatomic, assign) NSInteger ly_integerProperty;

@end
