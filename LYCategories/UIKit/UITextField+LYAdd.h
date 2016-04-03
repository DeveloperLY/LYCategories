//
//  UITextField+LYAdd.h
//  LYCategories
//
//  Created by Liu Y on 16/4/3.
//  Copyright © 2016年 CoderYLiu. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UITextField (LYAdd)

/**
 *  设置选定的所有文本。
 */
- (void)selectAllText;

/**
 Set text in range selected.
 
 @param range  The range of selected text in a document.
 */
/**
 *  设置选定范围内的文本
 *
 *  @param range 文档中选定文本的范围
 */
- (void)setSelectedRange:(NSRange)range;

@end
