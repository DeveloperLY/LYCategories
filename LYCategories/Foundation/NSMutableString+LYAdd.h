//
//  NSMutableString+LYAdd.h
//  LYCategories
//
//  Created by Liu Y on 16/4/3.
//  Copyright © 2016年 CoderYLiu. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSMutableString (LYAdd)

/**
 *  替换字符串
 *
 *  @param searchString 将要被替换的字符串
 *  @param newString    替换后的字符串
 */
- (void)replaceString:(NSString *)searchString withString:(NSString *)newString;

/**
 *  去除空格
 */
- (void)removeSpace;

/**
 *  将字符串中“Nil”和“Null”去除
 */
- (void)removeNilAndNull;

@end
