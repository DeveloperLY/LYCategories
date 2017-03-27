//
//  NSHTTPCookieStorage+LYAdd.h
//  LYCategories
//
//  Created by LiuY on 2017/3/27.
//  Copyright © 2017年 DeveloperLY. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSHTTPCookieStorage (LYAdd)

/**
 *  @brief 存储 UIWebView cookies到磁盘目录
 */
- (void)ly_saveCookie;

/**
 *  @brief 读取UIWebView cookies从磁盘目录
 */
- (void)ly_loadCookie;

@end
