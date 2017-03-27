//
//  UITextField+LYAdd.m
//  LYCategories
//
//  Created by Liu Y on 16/4/3.
//  Copyright © 2016年 DeveloperLY. All rights reserved.
//

#import "UITextField+LYAdd.h"
#import "LYCategoriesMacro.h"

LYSYNTH_DUMMY_CLASS(UITextField_LYAdd)

@implementation UITextField (LYAdd)

#pragma mark - Select
- (void)selectAllText {
    UITextRange *range = [self textRangeFromPosition:self.beginningOfDocument toPosition:self.endOfDocument];
    [self setSelectedTextRange:range];
}

- (void)setSelectedRange:(NSRange)range {
    UITextPosition *beginning = self.beginningOfDocument;
    UITextPosition *startPosition = [self positionFromPosition:beginning offset:range.location];
    UITextPosition *endPosition = [self positionFromPosition:beginning offset:NSMaxRange(range)];
    UITextRange *selectionRange = [self textRangeFromPosition:startPosition toPosition:endPosition];
    [self setSelectedTextRange:selectionRange];
}

- (NSRange)ly_selectedRange {
    UITextPosition* beginning = self.beginningOfDocument;
    
    UITextRange* selectedRange = self.selectedTextRange;
    UITextPosition* selectionStart = selectedRange.start;
    UITextPosition* selectionEnd = selectedRange.end;
    
    NSInteger location = [self offsetFromPosition:beginning toPosition:selectionStart];
    NSInteger length = [self offsetFromPosition:selectionStart toPosition:selectionEnd];
    
    return NSMakeRange(location, length);
}

@end
