//
//  UIImage+LYAdd.m
//  LYCategories
//
//  Created by Liu Y on 16/4/3.
//  Copyright © 2016年 CoderYLiu. All rights reserved.
//

#import "UIImage+LYAdd.h"
#import "LYCategoriesMacro.h"
#import <objc/runtime.h>

LYSYNTH_DUMMY_CLASS(UIImage_LYAdd)

static const void *completeBlockKey = &completeBlockKey;
static const void *failBlockKey = &failBlockKey;

@interface UIImage ()

@property (nonatomic,copy) void(^completeBlock)();

@property (nonatomic,copy) void(^failBlock)();

@end

@implementation UIImage (LYAdd)

#pragma mark - 图片裁剪
+ (UIImage *)imageCircleTailorWithImage:(UIImage *)image {
    // 获取位图上下文
    UIGraphicsBeginImageContextWithOptions(image.size, NO, 0.0);
    
    // 设置裁剪路径
    UIBezierPath *path = [UIBezierPath bezierPathWithOvalInRect:CGRectMake(0, 0, image.size.width, image.size.height)];
    
    // 裁剪
    [path addClip];
    
    // 将图片绘制到位图上下文中
    [image drawAtPoint:CGPointZero];
    
    // 从位图上下文中输出新图片
    UIImage *newImage = UIGraphicsGetImageFromCurrentImageContext();
    
    // 关闭位图上下文
    UIGraphicsEndImageContext();
    
    // 返回裁剪成功
    return newImage;
}

+ (UIImage *)screenshotWithView:(UIView *)view {
    // 开启图形上下文
    UIGraphicsBeginImageContextWithOptions(view.frame.size, NO, 0.0f);
    
    // 获取上下文
    CGContextRef context = UIGraphicsGetCurrentContext();
    
    // 在新建的图形上下文中渲染view的layer
    [view.layer renderInContext:context];
    
    [[UIColor clearColor] setFill];
    
    // 获取图片
    UIImage *image = UIGraphicsGetImageFromCurrentImageContext();
    
    // 关闭图形上下文
    UIGraphicsEndImageContext();
    
    return image;
}

+ (UIImage *)screencapture {
    return [self screenshotWithView:[UIApplication sharedApplication].keyWindow];
}

- (UIImage *)screenshotWithFrame:(CGRect)frame {
    // 创建CGImage
    CGImageRef cgimage = CGImageCreateWithImageInRect(self.CGImage, frame);
    
    // 创建image
    UIImage *newImage=[UIImage imageWithCGImage:cgimage];
    
    // 释放CGImage
    CGImageRelease(cgimage);
    
    return newImage;
}

#pragma mark - 拉伸图片

+ (UIImage *)resizeWithImageName:(NSString *)imageName {
    return [self resizeWithImageName:imageName leftCap:0.5f topCap:0.5f];
}

+ (UIImage *)resizeWithImageName:(NSString *)imageName leftCap:(CGFloat)leftCap topCap:(CGFloat)topCap {
    return [[UIImage imageNamed:imageName] stretchableImageWithLeftCapWidth:leftCap topCapHeight:topCap];
}

#pragma mark - 抗锯齿图片

- (UIImage *)imageAntialias {
    CGFloat border = 1.0f;
    CGRect rect = CGRectMake(border, border, self.size.width - 2 * border, self.size.height - 2 * border);
    
    UIImage *img = nil;
    
    UIGraphicsBeginImageContext(CGSizeMake(rect.size.width,rect.size.height));
    [self drawInRect:CGRectMake(-1, -1, self.size.width, self.size.height)];
    img = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    
    UIGraphicsBeginImageContext(self.size);
    [img drawInRect:rect];
    UIImage* antiImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    
    return antiImage;
}

#pragma mark - 图片颜色相关

/**
 *  获得某个像素的颜色
 *
 *  @param point 像素点的位置
 */
- (UIColor *)pixelColorAtLocation:(CGPoint)point {
    UIColor *color = nil;
    CGImageRef inImage = self.CGImage;
    CGContextRef contexRef = [self ARGBBitmapContextFromImage:inImage];
    if (contexRef == NULL) return nil;
    
    size_t w = CGImageGetWidth(inImage);
    size_t h = CGImageGetHeight(inImage);
    CGRect rect = {{0,0},{w,h}};
    
    // Draw the image to the bitmap context. Once we draw, the memory
    // allocated for the context for rendering will then contain the
    // raw image data in the specified color space.
    CGContextDrawImage(contexRef, rect, inImage);
    
    // Now we can get a pointer to the image data associated with the bitmap
    // context.
    unsigned char* data = CGBitmapContextGetData (contexRef);
    if (data != NULL) {
        //offset locates the pixel in the data from x,y.
        //4 for 4 bytes of data per pixel, w is width of one row of data.
        int offset = 4*((w*round(point.y))+round(point.x));
        int alpha =  data[offset];
        int red = data[offset+1];
        int green = data[offset+2];
        int blue = data[offset+3];
        //		NSLog(@"offset: %i colors: RGB A %i %i %i  %i",offset,red,green,blue,alpha);
        color = [UIColor colorWithRed:(red/255.0f) green:(green/255.0f) blue:(blue/255.0f) alpha:(alpha/255.0f)];
    }
    
    // When finished, release the context
    CGContextRelease(contexRef);
    // Free image data memory for the context
    if (data) { free(data); }
    
    return color;
}

/**
 *  根据CGImageRef来创建一个ARGBBitmapContext
 */
- (CGContextRef)ARGBBitmapContextFromImage:(CGImageRef) inImage {
    CGContextRef    context = NULL;
    CGColorSpaceRef colorSpace;
    void *          bitmapData;
    NSInteger             bitmapByteCount;
    NSInteger             bitmapBytesPerRow;
    
    // Get image width, height. We'll use the entire image.
    size_t pixelsWide = CGImageGetWidth(inImage);
    size_t pixelsHigh = CGImageGetHeight(inImage);
    
    // Declare the number of bytes per row. Each pixel in the bitmap in this
    // example is represented by 4 bytes; 8 bits each of red, green, blue, and
    // alpha.
    bitmapBytesPerRow   = (pixelsWide * 4);
    bitmapByteCount     = (bitmapBytesPerRow * pixelsHigh);
    
    // Use the generic RGB color space.
    //colorSpace = CGColorSpaceCreateWithName(kCGColorSpaceGenericRGB);  //deprecated
    colorSpace = CGColorSpaceCreateDeviceRGB();
    if (colorSpace == NULL) {
        fprintf(stderr, "Error allocating color space\n");
        return NULL;
    }
    
    // Allocate memory for image data. This is the destination in memory
    // where any drawing to the bitmap context will be rendered.
    bitmapData = malloc( bitmapByteCount );
    if (bitmapData == NULL) {
        fprintf (stderr, "Memory not allocated!");
        CGColorSpaceRelease( colorSpace );
        return NULL;
    }
    
    // Create the bitmap context. We want pre-multiplied ARGB, 8-bits
    // per component. Regardless of what the source image format is
    // (CMYK, Grayscale, and so on) it will be converted over to the format
    // specified here by CGBitmapContextCreate.
    context = CGBitmapContextCreate (bitmapData,
                                     pixelsWide,
                                     pixelsHigh,
                                     8,      // bits per component
                                     bitmapBytesPerRow,
                                     colorSpace,
                                     (CGBitmapInfo)kCGImageAlphaPremultipliedFirst);
    if (context == NULL) {
        free (bitmapData);
        fprintf (stderr, "Context not created!");
    }
    
    // Make sure and release colorspace before returning
    CGColorSpaceRelease( colorSpace );
    
    return context;
}

+ (UIImage *)imageWithColor:(UIColor *)color {
    CGRect rect = CGRectMake(0.0f, 0.0f, 1.0f, 1.0f);
    UIGraphicsBeginImageContext(rect.size);
    CGContextRef context = UIGraphicsGetCurrentContext();
    CGContextSetFillColorWithColor(context, [color CGColor]);
    CGContextFillRect(context, rect);
    UIImage *theImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    
    return theImage;
}

+ (UIImage *)imageWithColor:(UIColor *)color size:(CGSize)size {
    CGRect rect=(CGRect){{0.0f,0.0f},size};
    
    //开启一个图形上下文
    UIGraphicsBeginImageContextWithOptions(rect.size, NO, 0.0f);
    
    //获取图形上下文
    CGContextRef context=UIGraphicsGetCurrentContext();
    
    CGContextSetFillColorWithColor(context, color.CGColor);
    
    CGContextFillRect(context, rect);
    
    //获取图像
    UIImage *image=UIGraphicsGetImageFromCurrentImageContext();
    
    //关闭上下文
    UIGraphicsEndImageContext();
    
    return image;
}

#pragma mark - 图片渲染相关

+ (UIImage *)imageWithOriginalImageName:(NSString *)imageName {
    return [[UIImage imageNamed:imageName] imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal];
}

#pragma mark - 相册操作相关

- (void)savedPhotoAlbum:(void (^)())completeBlock failBlock:(void (^)())failBlock {
    UIImageWriteToSavedPhotosAlbum(self, self, @selector(image:didFinishSavingWithError:contextInfo:), NULL);
    self.completeBlock = completeBlock;
    self.failBlock = failBlock;
}

- (void)image:(UIImage *)image didFinishSavingWithError:(NSError *)error contextInfo:(void *)contextInfo{
    
    if (!error) {
        if (self.completeBlock != nil) self.completeBlock();
    } else {
        if (self.failBlock != nil) self.failBlock();
    }
    
}

// ********** 模拟成员变量 ********** //
-(void (^)())failBlock {
    return objc_getAssociatedObject(self, failBlockKey);
}

-(void)setFailBlock:(void (^)())failBlock {
    objc_setAssociatedObject(self, failBlockKey, failBlock, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

-(void (^)())completeBlock{
    return objc_getAssociatedObject(self, completeBlockKey);
}

-(void)setCompleteBlock:(void (^)())completeBlock {
    objc_setAssociatedObject(self, completeBlockKey, completeBlock, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

#pragma mark - 解决应用图片旋转或颠倒的bug
- (UIImage *)fixOrientation {
    
    // No-op if the orientation is already correct
    if (self.imageOrientation == UIImageOrientationUp) return self;
    
    // We need to calculate the proper transformation to make the image upright.
    // We do it in 2 steps: Rotate if Left/Right/Down, and then flip if Mirrored.
    CGAffineTransform transform = CGAffineTransformIdentity;
    
    switch (self.imageOrientation) {
        case UIImageOrientationDown:
        case UIImageOrientationDownMirrored:
            transform = CGAffineTransformTranslate(transform, self.size.width, self.size.height);
            transform = CGAffineTransformRotate(transform, M_PI);
            break;
            
        case UIImageOrientationLeft:
        case UIImageOrientationLeftMirrored:
            transform = CGAffineTransformTranslate(transform, self.size.width, 0);
            transform = CGAffineTransformRotate(transform, M_PI_2);
            break;
            
        case UIImageOrientationRight:
        case UIImageOrientationRightMirrored:
            transform = CGAffineTransformTranslate(transform, 0, self.size.height);
            transform = CGAffineTransformRotate(transform, -M_PI_2);
            break;
        default:
            break;
    }
    
    switch (self.imageOrientation) {
        case UIImageOrientationUpMirrored:
        case UIImageOrientationDownMirrored:
            transform = CGAffineTransformTranslate(transform, self.size.width, 0);
            transform = CGAffineTransformScale(transform, -1, 1);
            break;
            
        case UIImageOrientationLeftMirrored:
        case UIImageOrientationRightMirrored:
            transform = CGAffineTransformTranslate(transform, self.size.height, 0);
            transform = CGAffineTransformScale(transform, -1, 1);
            break;
        default:
            break;
    }
    
    // Now we draw the underlying CGImage into a new context, applying the transform
    // calculated above.
    CGContextRef ctx = CGBitmapContextCreate(NULL, self.size.width, self.size.height,
                                             CGImageGetBitsPerComponent(self.CGImage), 0,
                                             CGImageGetColorSpace(self.CGImage),
                                             CGImageGetBitmapInfo(self.CGImage));
    CGContextConcatCTM(ctx, transform);
    switch (self.imageOrientation) {
        case UIImageOrientationLeft:
        case UIImageOrientationLeftMirrored:
        case UIImageOrientationRight:
        case UIImageOrientationRightMirrored:
            // Grr...
            CGContextDrawImage(ctx, CGRectMake(0,0,self.size.height,self.size.width), self.CGImage);
            break;
            
        default:
            CGContextDrawImage(ctx, CGRectMake(0,0,self.size.width,self.size.height), self.CGImage);
            break;
    }
    
    // And now we just create a new UIImage from the drawing context
    CGImageRef cgimg = CGBitmapContextCreateImage(ctx);
    UIImage *img = [UIImage imageWithCGImage:cgimg];
    CGContextRelease(ctx);
    CGImageRelease(cgimg);
    return img;
}

#pragma mark - 图片水印

- (UIImage *)watermarkWithText:(NSString *)text direction:(LYWatermarkDirection)direction fontColor:(UIColor *)fontColor fontPoint:(CGFloat)fontPoint marginXY:(CGPoint)marginXY {
    
    CGSize size = self.size;
    
    CGRect rect = (CGRect){CGPointZero,size};
    
    //新建图片图形上下文
    UIGraphicsBeginImageContextWithOptions(size, NO, 0.0f);
    
    //绘制图片
    [self drawInRect:rect];
    
    //绘制文本
    NSDictionary *attr =@{NSFontAttributeName : [UIFont systemFontOfSize:fontPoint],NSForegroundColorAttributeName:fontColor};
    
    CGRect strRect = [self calWidth:text attr:attr direction:direction rect:rect marginXY:marginXY];
    
    [text drawInRect:strRect withAttributes:attr];
    
    //获取图片
    UIImage *newImage = UIGraphicsGetImageFromCurrentImageContext();
    
    //结束图片图形上下文
    UIGraphicsEndImageContext();
    
    return newImage;
}

- (UIImage *)watermarkWithWatermarkImage:(UIImage *)watermarkImage direction:(LYWatermarkDirection)direction watermarkSize:(CGSize)watermarkSize marginXY:(CGPoint)marginXY {
    CGSize size = self.size;
    
    CGRect rect = (CGRect){CGPointZero, size};
    
    //新建图片图形上下文
    UIGraphicsBeginImageContextWithOptions(size, NO, 0.0f);
    
    //绘制图片
    [self drawInRect:rect];
    
    //计算水印的rect
    CGSize watermarkImageSize = CGSizeEqualToSize(watermarkSize, CGSizeZero) ? watermarkImage.size : watermarkSize;
    CGRect calRect = [self rectWithRect:rect size:watermarkImageSize direction:direction marginXY:marginXY];
    
    //绘制水印图片
    [watermarkImage drawInRect:calRect];
    
    //获取图片
    UIImage *newImage = UIGraphicsGetImageFromCurrentImageContext();
    
    //结束图片图形上下文
    UIGraphicsEndImageContext();
    
    return newImage;
}

- (CGRect)calWidth:(NSString *)str attr:(NSDictionary *)attr direction:(LYWatermarkDirection)direction rect:(CGRect)rect marginXY:(CGPoint)marginXY {
    
    CGSize size =  [str sizeWithAttributes:attr];
    
    CGRect calRect = [self rectWithRect:rect size:size direction:direction marginXY:marginXY];
    
    return calRect;
}

- (CGRect)rectWithRect:(CGRect)rect size:(CGSize)size direction:(LYWatermarkDirection)direction marginXY:(CGPoint)marginXY {
    
    CGPoint point = CGPointZero;
    
    // 右上
    if (LYWatermarkDirectionTopRight == direction) point = CGPointMake(rect.size.width - size.width, 0);
    
    // 左下
    if(LYWatermarkDirectionBottomLeft == direction) point = CGPointMake(0, rect.size.height - size.height);
    
    // 右下
    if(LYWatermarkDirectionBottomRight == direction) point = CGPointMake(rect.size.width - size.width, rect.size.height - size.height);
    
    // 正中
    if(LYWatermarkDirectionCenter == direction) point = CGPointMake((rect.size.width - size.width)*.5f, (rect.size.height - size.height)*.5f);
    
    point.x += marginXY.x;
    point.y += marginXY.y;
    
    CGRect calRect = (CGRect){point,size};
    
    return calRect;
}


@end
