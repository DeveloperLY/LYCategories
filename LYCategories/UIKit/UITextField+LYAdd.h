//
//  UITextField+LYAdd.h
//  LYCategories
//
//  Created by Liu Y on 16/4/3.
//  Copyright © 2016年 DeveloperLY. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UITextField (LYAdd)

#pragma mark - Select

/**
 *  设置选定的所有文本。
 */
- (void)selectAllText;

/**
 *  设置选定范围内的文本
 *
 *  @param @range 文档中选定文本的范围
 */
- (void)setSelectedRange:(NSRange)range;

/**
 *  @brief  当前选中的字符串范围
 *
 *  @return NSRange
 */
- (NSRange)ly_selectedRange;

@end
