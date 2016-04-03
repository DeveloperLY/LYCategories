//
//  CALayer+LYAdd.m
//  LYCategories
//
//  Created by Liu Y on 16/4/3.
//  Copyright © 2016年 CoderYLiu. All rights reserved.
//

#import "CALayer+LYAdd.h"
#import "LYCategoriesMacro.h"

LYSYNTH_DUMMY_CLASS(CALayer_LYAdd)

@implementation CALayer (LYAdd)

#pragma mark - 动画相关

- (void)pauseAnimate {
    CFTimeInterval pausedTime = [self convertTime:CACurrentMediaTime() fromLayer:nil];
    self.speed = 0.0;
    self.timeOffset = pausedTime;
}

- (void)resumeAnimate {
    CFTimeInterval pausedTime = [self timeOffset];
    self.speed = 1.0;
    self.timeOffset = 0.0;
    self.beginTime = 0.0;
    CFTimeInterval timeSincePause = [self convertTime:CACurrentMediaTime() fromLayer:nil] - pausedTime;
    self.beginTime = timeSincePause;
}

- (CATransition *)transitionWithAnimType:(LYTransitionAnimType)animType subType:(LYTransitionSubType)subType curve:(LYTransitionCurve)curve duration:(CGFloat)duration {
    
    NSString *key = @"transition";
    
    if ([self animationForKey:key] != nil) {
        [self removeAnimationForKey:key];
    }
    
    CATransition *transition=[CATransition animation];
    
    // 动画时长
    transition.duration=duration;
    
    // 动画类型
    transition.type=[self animaTypeWithTransitionType:animType];
    
    // 动画方向
    transition.subtype=[self animaSubtype:subType];
    
    // 缓动函数
    transition.timingFunction=[CAMediaTimingFunction functionWithName:[self curve:curve]];
    
    // 完成动画删除
    transition.removedOnCompletion = YES;
    
    [self addAnimation:transition forKey:key];
    
    return transition;
}

/**
 *  返回动画曲线
 */
- (NSString *)curve:(LYTransitionCurve)curve {
    // 曲线数组
    NSArray *funcNames = @[kCAMediaTimingFunctionDefault,
                           kCAMediaTimingFunctionEaseIn,
                           kCAMediaTimingFunctionEaseInEaseOut,
                           kCAMediaTimingFunctionEaseOut,
                           kCAMediaTimingFunctionLinear];
    
    return [self objFromArray:funcNames index:curve isRamdom:(LYTransitionCurveRamdom == curve)];
}

/**
 *  返回动画方向
 */
- (NSString *)animaSubtype:(LYTransitionSubType)subType {
    // 设置转场动画的方向
    NSArray *subtypes = @[kCATransitionFromTop,
                          kCATransitionFromLeft,
                          kCATransitionFromBottom,
                          kCATransitionFromRight];
    
    return [self objFromArray:subtypes index:subType isRamdom:(LYTransitionSubtypesFromRamdom == subType)];
}

/**
 *  返回动画类型
 */
- (NSString *)animaTypeWithTransitionType:(LYTransitionAnimType)type {
    //设置转场动画的类型
    NSArray *animArray = @[@"rippleEffect",
                           @"suckEffect",
                           @"pageCurl",
                           @"oglFlip",
                           @"cube",
                           @"reveal",
                           @"pageUnCurl",
                           @"push"];
    
    return [self objFromArray:animArray index:type isRamdom:(LYTransitionAnimTypeRamdom == type)];
}

/**
 *  统一从数据返回对象
 */
- (id)objFromArray:(NSArray *)array index:(NSUInteger)index isRamdom:(BOOL)isRamdom {
    
    NSUInteger count = array.count;
    
    NSUInteger i = isRamdom ? arc4random_uniform((u_int32_t)count) : index;
    
    return array[i];
}

@end
