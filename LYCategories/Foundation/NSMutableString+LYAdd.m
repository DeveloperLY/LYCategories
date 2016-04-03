//
//  NSMutableString+LYAdd.m
//  LYCategories
//
//  Created by Liu Y on 16/4/3.
//  Copyright © 2016年 CoderYLiu. All rights reserved.
//

#import "NSMutableString+LYAdd.h"
#import "LYCategoriesMacro.h"

LYSYNTH_DUMMY_CLASS(NSMutableString_LYAdd)

@implementation NSMutableString (LYAdd)

- (void)replaceString:(NSString *)searchString withString:(NSString *)newString {
    NSRange range = [self rangeOfString:searchString];
    [self replaceCharactersInRange:range withString:newString];
}

- (void)removeSpace {
    [self replaceString:@" " withString:@""];
}


- (void)removeNilAndNull {
    
    if ([self isEqual:[NSNull null]]| (self == nil)) {
        
        [self setString:@""];
    }
}

@end
