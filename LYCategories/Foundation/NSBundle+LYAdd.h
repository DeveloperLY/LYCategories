//
//  NSBundle+LYAdd.h
//  LYCategories
//
//  Created by Liu Y on 16/4/3.
//  Copyright © 2016年 CoderYLiu. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface NSBundle (LYAdd)

/**
 *  获取icon的路径
 *
 *  @return 获得的路径
 */
- (NSString *)appIconPath;

/**
 *  获取appIcon
 *
 *  @return 得到的iconImage
 */
- (UIImage *)appIcon;

@end
