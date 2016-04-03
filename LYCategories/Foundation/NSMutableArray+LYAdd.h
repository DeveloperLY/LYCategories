//
//  NSMutableArray+LYAdd.h
//  LYCategories
//
//  Created by Liu Y on 16/4/3.
//  Copyright © 2016年 CoderYLiu. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface NSMutableArray (LYAdd)

#pragma 增加或删除对象
///=============================================================================
/// @name 增加或删除对象
///=============================================================================

/**
 *  插入一个元素到指定位置
 *
 *  @param object 需要插入的元素
 *  @param index  位置
 */
- (void)insertObject:(id)object atIndexIfNotNil:(NSUInteger)index;

/**
 *  移动对象 从一个位置到另一个位置
 *
 *  @param index   原位置
 *  @param toIndex 目标位置
 */
- (void)moveObjectAtIndex:(NSUInteger)index toIndex:(NSUInteger)toIndex;


#pragma mark - 排序
///=============================================================================
/// @name 排序
///=============================================================================

/**
 *  重组数组(打乱顺序)
 *
 */
- (void)shuffle;

/**
 *  数组倒序
 *
 */
- (void)reverse;

/**
 *  数组去除相同的元素
 */
- (void)unique;

/**
 *  根据关键词 对本数组的内容进行排序
 *
 *  @param parameters 关键词
 *  @param ascending  YES 升序 NO 降序
 *
 */
- (void)sorting:(NSString *)parameters ascending:(BOOL)ascending;

#pragma - mark 安全操作
///=============================================================================
/// @name 安全操作
///=============================================================================

/**
 *  添加新对象
 *
 *  @param i 添加的对象
 */
- (void)addObj:(id)i;

/**
 *  添加字符串
 *
 *  @param i 添加的字符串
 */
- (void)addString:(NSString*)i;

/**
 *  添加Bool
 *
 *  @param i 添加的Bool
 */
- (void)addBool:(BOOL)i;

/**
 *  添加Int
 *
 *  @param i 添加的Int
 */
- (void)addInt:(int)i;

/**
 *  添加Integer
 *
 *  @param i 添加的Integer
 */
- (void)addInteger:(NSInteger)i;

/**
 *  添加UnsignedInteger
 *
 *  @param i 添加的UnsignedInteger
 */
- (void)addUnsignedInteger:(NSUInteger)i;

/**
 *  添加CGFloat
 *
 *  @param i 添加的CGFloat
 */
- (void)addCGFloat:(CGFloat)f;

/**
 *  添加Char
 *
 *  @param i 添加的Char
 */
- (void)addChar:(char)c;

/**
 *  添加Float
 *
 *  @param i 添加的Float
 */
- (void)addFloat:(float)i;

/**
 *  添加Point
 *
 *  @param i 添加的Point
 */
- (void)addPoint:(CGPoint)o;

/**
 *  添加Size
 *
 *  @param i 添加的Size
 */
- (void)addSize:(CGSize)o;

/**
 *  添加Rect
 *
 *  @param i 添加的Rect
 */
- (void)addRect:(CGRect)o;

@end
