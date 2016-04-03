//
//  UIImage+LYAdd.h
//  LYCategories
//
//  Created by Liu Y on 16/4/3.
//  Copyright © 2016年 CoderYLiu. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 *  水印方向
 */
typedef NS_ENUM(NSUInteger, LYWatermarkDirection) {
    LYWatermarkDirectionTopLeft,        // 左上
    LYWatermarkDirectionTopRight,       // 右上
    LYWatermarkDirectionBottomLeft,     // 左下
    LYWatermarkDirectionBottomRight,    // 右下
    LYWatermarkDirectionCenter,         // 正中
};

@interface UIImage (LYAdd)

#pragma mark - 图片裁剪
///=============================================================================
/// @name 图片裁剪
///=============================================================================

/**
 *  将图片裁剪成圆形
 *
 *  @param image 需要裁剪的图片
 *
 *  @return 裁剪完成的圆形图片
 */
+ (UIImage *)imageCircleTailorWithImage:(UIImage *)image;

/**
 *  从给定的UIView中截图：UIView转UIImage
 *
 *  @param view 需要转UIImage的UIView
 *
 *  @return UIView
 */
+ (UIImage *)screenshotWithView:(UIView *)view;

/**
 *  直接截屏
 *
 *  @return 截取的屏幕
 */
+ (UIImage *)screencapture;

/**
 *  指定区域位置截取图片
 *
 *  @param frame 区域位置
 *
 *  @return 截取的图片
 */
- (UIImage *)screenshotWithFrame:(CGRect)frame;

#pragma mark - 拉伸图片
///=============================================================================
/// @name 拉伸图片
///=============================================================================

/**
 *  传入图片名称,返回拉伸好的图片
 *
 *  @param imageName 图片名称
 *
 *  @return 拉伸好的图片
 */
+ (UIImage *)resizeWithImageName:(NSString *)imageName;

/**
 *  拉伸图片:自定义比例
 *
 *  @param name    图片名称
 *  @param leftCap 左边比例
 *  @param topCap  上面比例
 *
 *  @return 拉伸完成的图片
 */
+ (UIImage *)resizeWithImageName:(NSString *)imageName leftCap:(CGFloat)leftCap topCap:(CGFloat)topCap;

#pragma mark - 抗锯齿图片
///=============================================================================
/// @name 抗锯齿图片
///=============================================================================

/**
 *  返回一张抗锯齿图片
 *    本质：在图片生成一个透明为1的像素边框
 *
 *  @return 抗锯齿图片
 */
- (UIImage *)imageAntialias;

#pragma mark - 图片颜色相关
///=============================================================================
/// @name 图片颜色相关
///=============================================================================

/**
 *  获得某个像素的颜色
 *
 *  @param point 像素点的位置
 *
 *  @return 该像素点的颜色
 */
- (UIColor *)pixelColorAtLocation:(CGPoint)point;

/**
 *  根据颜色生成图片
 *
 *  @param color 颜色
 *
 *  @return 图片
 */
+ (UIImage *)imageWithColor:(UIColor *)color;

/**
 *  根据颜色获得一张指定大小的不透明图片
 *
 *  @param color 颜色
 *  @param size  指定尺寸
 *
 *  @return 指定尺寸的图片
 */
+ (UIImage *)imageWithColor:(UIColor *)color size:(CGSize)size;

#pragma mark - 图片渲染相关
///=============================================================================
/// @name 图片渲染相关
///=============================================================================

/**
 *  加载最原始的图片
 *
 *  @param imageName 图片名称
 *
 *  @return 返回最原始图片
 */
+ (UIImage *)imageWithOriginalImageName:(NSString *)imageName;

#pragma mark - 相册操作相关
///=============================================================================
/// @name 相册操作相关
///=============================================================================

/**
 *  将图片保存到相册
 *
 *  @param completeBlock 保存成功回调
 *  @param failBlock     保存失败回调
 */
- (void)savedPhotoAlbum:(void(^)())completeBlock failBlock:(void(^)())failBlock;

#pragma mark - 解决应用图片旋转或颠倒的bug
///=============================================================================
/// @name 解决应用图片旋转或颠倒的bug
///=============================================================================

/**
 *  解决应用图片旋转或颠倒的bug
 *      用相机拍摄出来的照片含有EXIF信息，UIImage的imageOrientation属性指的就是EXIF中的orientation信息。
 *      如果我们忽略orientation信息，而直接对照片进行像素处理或者drawInRect等操作，得到的结果是翻转或者旋转90之后的样子。
 *      这是因为我们执行像素处理或者drawInRect等操作之后，    imageOrientaion信息被删除了，imageOrientaion被重设为0，造成照片内容和imageOrientaion不匹配。
 *      所以，在对照片进行处理之前，先将照片旋转到正确的方向，并且返回的imageOrientaion为0。
 *
 *  @return 正常图片
 */
- (UIImage *)fixOrientation;

#pragma mark - 图片水印
///=============================================================================
/// 图片水印
///=============================================================================

/**
 *  给图片添加文字水印
 *
 *  @param text      文字水印
 *  @param direction 水印在图片中的位置
 *  @param fontColor 文字颜色
 *  @param fontPoint 位置中心点
 *  @param marginXY  间距
 *
 *  @return 有水印的图片
 */
- (UIImage *)watermarkWithText:(NSString *)text direction:(LYWatermarkDirection)direction fontColor:(UIColor *)fontColor fontPoint:(CGFloat)fontPoint marginXY:(CGPoint)marginXY;

/**
 *  给图片添加图片水印
 *
 *  @param watermarkImage 图片水印
 *  @param direction      水印在图中的位置
 *  @param waterSize      水印大小
 *  @param marginXY       间距
 *
 *  @return 有水印的图片
 */
- (UIImage *)watermarkWithWatermarkImage:(UIImage *)watermarkImage direction:(LYWatermarkDirection)direction watermarkSize:(CGSize)watermarkSize  marginXY:(CGPoint)marginXY;

@end
