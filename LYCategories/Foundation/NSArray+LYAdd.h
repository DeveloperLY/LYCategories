//
//  NSArray+LYAdd.h
//  LYCategories
//
//  Created by Liu Y on 16/4/3.
//  Copyright © 2016年 CoderYLiu. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface NSArray (LYAdd)

#pragma mark - 取值
///=============================================================================
/// @name 取值
///=============================================================================

/**
 *  获取数组的第一个元素
 *
 *  @return 取得的元素
 */
- (instancetype)firstObject;

/**
 *  随机取数组里的一个元素
 *
 *  @return 随机取得的元素
 */
- (instancetype)randomObject;

#pragma mark - 数组转字符串
///=============================================================================
/// @name 数组转字符串
///=============================================================================

/**
 *  数组转字符串
 *
 *  @return 数组字符串
 */
- (NSString *)string;

#pragma mark - 数组计算交集和差集
///=============================================================================
/// @name 数组计算交集和差集
///=============================================================================

/**
 *  数组计算交集
 *
 *  @param otherArray 另一个数组
 *
 *  @return 交集数组
 */
- (NSArray *)arrayForIntersectionWithOtherArray:(NSArray *)otherArray;

/**
 *  数组计算差集
 *
 *  @param otherArray 另一个数组
 *
 *  @return 差集数组
 */
- (NSArray *)arrayForMinusWithOtherArray:(NSArray *)otherArray;

#pragma mark - 排序
///=============================================================================
/// @name 取值
///=============================================================================

/**
 *  重组数组(打乱顺序)
 *
 *  @return 重组之后的数组
 */
- (NSArray *)shuffledArray;

/**
 *  数组倒序
 *
 *  @return 将数组倒序后得到的数组
 */
- (NSArray *)reversedArray;

/**
 *  数组去除相同的元素，并获得新的array
 *
 *  @return 去除相同元素后的array
 */
- (NSArray *)uniqueArray;

/**
 *  根据关键词 对array的内容进行排序，并返回排序后的array
 *
 *  @param parameters 关键词
 *  @param ascending  YES 升序 NO 降序
 *
 *  @return 经过排序后的数组
 */
- (NSArray *)arraySorting:(NSString *)parameters  ascending:(BOOL)ascending;


#pragma mark - 安全操作
///=============================================================================
/// @name 安全操作
///=============================================================================

/**
 *  获取下标为index的对象
 *
 *  @param index 下标
 *
 *  @return 获得的对象
 */
- (instancetype)objectWithIndex:(NSUInteger)index;

/**
 *  获取下标为index的字符串，不存在返回空，能转为string的转，不能的返回nil
 *
 *  @param index 下标
 *
 *  @return 获得的字符串
 */
- (NSString *)stringWithIndex:(NSUInteger)index;

/**
 *  获取下标为index的number，不存在返回空，能转为number的转，不能的返回nil
 *
 *  @param index 下标
 *
 *  @return 获得的number
 */
- (NSNumber *)numberWithIndex:(NSUInteger)index;

/**
 *  获取下标为index的array，不存返回nil
 *
 *  @param index 下标
 *
 *  @return 获得的array
 */
- (NSArray *)arrayWithIndex:(NSUInteger)index;

/**
 *  获取下标为index的Dictionary，不存返回nil
 *
 *  @param index 下标
 *
 *  @return 获得的Dictionary
 */
- (NSDictionary *)dictionaryWithIndex:(NSUInteger)index;

/**
 *  获取下标为index的integer，不存返回0
 *
 *  @param index 下标
 *
 *  @return 获得的integer
 */
- (NSInteger)integerWithIndex:(NSUInteger)index;

/**
 *  获取下标为index的unsignedInteger，不存返回0
 *
 *  @param index 下标
 *
 *  @return 获得的unsignedInteger
 */
- (NSUInteger)unsignedIntegerWithIndex:(NSUInteger)index;

/**
 *  获取下标为index的bool，不存返回NO
 *
 *  @param index 下标
 *
 *  @return 获得的bool
 */
- (BOOL)boolWithIndex:(NSUInteger)index;

/**
 *  获取下标为index的int16，不存返回0
 *
 *  @param index 下标
 *
 *  @return 获得的int16
 */
- (int16_t)int16WithIndex:(NSUInteger)index;

/**
 *  获取下标为index的int32，不存返回0
 *
 *  @param index 下标
 *
 *  @return 获得的int32
 */
- (int32_t)int32WithIndex:(NSUInteger)index;

/**
 *  获取下标为index的int64，不存返回0
 *
 *  @param index 下标
 *
 *  @return 获得的int64
 */
- (int64_t)int64WithIndex:(NSUInteger)index;

/**
 *  获取下标为index的charValue，不存返回0
 *
 *  @param index 下标
 *
 *  @return 获得的charValue
 */
- (char)charWithIndex:(NSUInteger)index;

/**
 *  获取下标为index的intValue，不存返回0
 *
 *  @param index 下标
 *
 *  @return 获得的intValue
 */
- (short)shortWithIndex:(NSUInteger)index;

/**
 *  获取下标为index的floatValue，不存返回0
 *
 *  @param index 下标
 *
 *  @return 获得的floatValue
 */
- (float)floatWithIndex:(NSUInteger)index;

/**
 *  获取下标为index的doubleValue，不存返回0
 *
 *  @param index 下标
 *
 *  @return 获得的doubleValue
 */
- (double)doubleWithIndex:(NSUInteger)index;

/**
 *  获取下标为index的CGFloat
 *
 *  @param index 下标
 *
 *  @return 获得的CGFloat
 */
- (CGFloat)CGFloatWithIndex:(NSUInteger)index;

/**
 *  获取下标为index的point
 *
 *  @param index 下标
 *
 *  @return 获得的point
 */
- (CGPoint)pointWithIndex:(NSUInteger)index;

/**
 *  获取下标为index的size
 *
 *  @param index 下标
 *
 *  @return 获得的size
 */
- (CGSize)sizeWithIndex:(NSUInteger)index;

/**
 *  获取下标为index的rect
 *
 *  @param index 下标
 *
 *  @return 获得的rect
 */
- (CGRect)rectWithIndex:(NSUInteger)index;


@end
