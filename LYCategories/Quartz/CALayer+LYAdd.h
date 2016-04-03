//
//  CALayer+LYAdd.h
//  LYCategories
//
//  Created by Liu Y on 16/4/3.
//  Copyright © 2016年 CoderYLiu. All rights reserved.
//

#import <QuartzCore/QuartzCore.h>

/**
 *  动画类型
 */
typedef NS_ENUM(NSUInteger, LYTransitionAnimType) {
    LYTransitionAnimTypeRippleEffect,     // 水波
    LYTransitionAnimTypeSuckEffect,       // 吸走
    LYTransitionAnimTypePageCurl,         // 翻开书本
    LYTransitionAnimTypeOglFlip,          // 正反翻转
    LYTransitionAnimTypeCube,             // 正方体
    LYTransitionAnimTypeReveal,           // push推开
    LYTransitionAnimTypePageUnCurl,       // 合上书本
    LYTransitionAnimTypeRamdom,           // 随机
};

/**
 *  动画方向
 */
typedef NS_ENUM(NSUInteger, LYTransitionSubType) {
    LYTransitionSubtypesFromTop,        // 从上
    LYTransitionSubtypesFromLeft,       // 从左
    LYTransitionSubtypesFromBotoom,     // 从下
    LYTransitionSubtypesFromRight,      // 从右
    LYTransitionSubtypesFromRamdom,     // 随机
};

/**
 *  动画曲线
 */
typedef NS_ENUM(NSUInteger, LYTransitionCurve) {
    LYTransitionCurveDefault,           // 默认
    LYTransitionCurveEaseIn,            // 缓进
    LYTransitionCurveEaseOut,           // 缓出
    LYTransitionCurveEaseInEaseOut,     // 缓进缓出
    LYTransitionCurveLinear,            // 线性
    LYTransitionCurveRamdom,            // 随机
};


@interface CALayer (LYAdd)

#pragma mark - 动画相关
///=============================================================================
/// @name 动画相关
///=============================================================================

/**
 *  暂停动画
 */
- (void)pauseAnimate;

/**
 *  恢复暂停动画
 */
- (void)resumeAnimate;

/**
 *  转场动画
 *
 *  @param animType 转场动画类型
 *  @param subtype  转动动画方向
 *  @param curve    转动动画曲线
 *  @param duration 转动动画时长
 *
 *  @return 转场动画实例
 */
- (CATransition *)transitionWithAnimType:(LYTransitionAnimType)animType subType:(LYTransitionSubType)subType curve:(LYTransitionCurve)curve duration:(CGFloat)duration;


@end
