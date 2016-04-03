//
//  UIView+LYAdd.m
//  LYCategories
//
//  Created by Liu Y on 16/4/3.
//  Copyright © 2016年 CoderYLiu. All rights reserved.
//

#import "UIView+LYAdd.h"
#import "LYCategoriesMacro.h"
#import <objc/runtime.h>

LYSYNTH_DUMMY_CLASS(UIView_LYAdd)

static char nametag_key;

@implementation UIView (LYAdd)

#pragma mark - Frame相关

#pragma mark - setter
- (void)setCenterX:(CGFloat)centerX {
    CGPoint center = self.center;
    center.x = centerX;
    self.center = center;
}

- (void)setCenterY:(CGFloat)centerY {
    CGPoint center = self.center;
    center.y = centerY;
    self.center = center;
}

- (void)setX:(CGFloat)x {
    CGRect tempFrame = self.frame;
    tempFrame.origin.x = x;
    self.frame = tempFrame;
}

- (void)setY:(CGFloat)y {
    CGRect tempFrame = self.frame;
    tempFrame.origin.y  = y;
    self.frame = tempFrame;
}

- (void)setWidth:(CGFloat)width {
    CGRect tempFrame = self.frame;
    tempFrame.size.width = width;
    self.frame = tempFrame;
}

- (void)setHeight:(CGFloat)height {
    CGRect tempFrame = self.frame;
    tempFrame.size.height = height;
    self.frame = tempFrame;
}

- (void)setOrigin:(CGPoint)origin {
    CGRect frame = self.frame;
    frame.origin = origin;
    self.frame = frame;
}

- (void)setSize:(CGSize)size {
    CGRect frame = self.frame;
    frame.size = size;
    self.frame = frame;
}


#pragma mark - getter
- (CGFloat)centerX {
    return self.center.x;
}

- (CGFloat)centerY {
    return self.center.y;
}

- (CGFloat)x {
    return self.frame.origin.x;
}

- (CGFloat)y {
    return self.frame.origin.y;
}

- (CGFloat)width {
    return self.frame.size.width;
}

- (CGFloat)height {
    return self.frame.size.height;
}

- (CGPoint)origin {
    return self.frame.origin;
}

- (CGSize)size {
    return self.frame.size;
}

#pragma mark - 标记

- (void)setNametag:(NSString *)theNametag {
    objc_setAssociatedObject(self, &nametag_key, theNametag, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (NSString *)getNametag {
    return objc_getAssociatedObject(self, &nametag_key);
}

- (UIView *)viewWithNameTag:(NSString *)aName {
    if (!aName) return nil;
    
    // Is this the right view?
    if ([[self getNametag] isEqualToString:aName])
        return self;
    // Recurse depth first on subviews;
    for (UIView *subview in self.subviews) {
        UIView *resultView = [subview viewNamed:aName];
        if (resultView) return  resultView;
    }
    // Not found
    return nil;
}

- (UIView *)viewNamed:(NSString *)aName {
    if (!aName) return nil;
    return [self viewWithNameTag:aName];
}

#pragma mark - 圆角处理
- (void)setRadius:(CGFloat)r {
    if (r <= 0)
        r = self.bounds.size.width * .5f;
    
    //圆角半径
    self.layer.cornerRadius = r;
    
    //强制
    self.layer.masksToBounds = YES;
}

#pragma mark - XIB相关

+ (instancetype)viewFromXIB {
    NSString* name = NSStringFromClass(self);
    
    UIView* xibView = [[[NSBundle mainBundle] loadNibNamed:name owner:nil options:nil] firstObject];
    
    if (!xibView) {
        NSString *errorInfo = [NSString stringWithFormat:@"CoreXibView：从xib创建视图失败，当前类是：%@", name];
        [NSException exceptionWithName:@"viewFromXIB异常" reason:errorInfo userInfo:nil];
    }
    
    return xibView;
}

@end
