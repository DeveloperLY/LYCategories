//
//  UIView+LYAdd.h
//  LYCategories
//
//  Created by Liu Y on 16/4/3.
//  Copyright © 2016年 CoderYLiu. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (LYAdd)

#pragma mark - Frame相关
///=============================================================================
/// @name Frame相关
///=============================================================================
@property (nonatomic, assign) CGFloat centerX;
@property (nonatomic, assign) CGFloat centerY;
@property (nonatomic, assign) CGFloat x;
@property (nonatomic, assign) CGFloat y;
@property (nonatomic, assign) CGFloat width;
@property (nonatomic, assign) CGFloat height;
@property (nonatomic, assign) CGSize size;
@property (nonatomic, assign) CGPoint origin;

#pragma mark - 标记
///=============================================================================
/// @name 标记
///=============================================================================

- (NSString *)getNametag;

- (void)setNametag:(NSString *)theNametag;

- (UIView *)viewNamed:(NSString *)aName;

#pragma mark - 圆角处理
///=============================================================================
/// @name 圆角处理
///=============================================================================

/**
 *  设置圆角
 *
 *  @param radius 圆角半径
 */
- (void)setRadius:(CGFloat)r;

#pragma mark - XIB相关
///=============================================================================
/// @name XIB相关
///=============================================================================

/**
 *  自动从xib创建视图
 *
 *  @return 视图对象
 */
+ (instancetype)viewFromXIB;


@end
