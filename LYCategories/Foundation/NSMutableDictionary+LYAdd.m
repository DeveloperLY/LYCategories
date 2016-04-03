//
//  NSMutableDictionary+LYAdd.m
//  LYCategories
//
//  Created by Liu Y on 16/4/3.
//  Copyright © 2016年 CoderYLiu. All rights reserved.
//

#import "NSMutableDictionary+LYAdd.h"
#import "LYCategoriesMacro.h"

LYSYNTH_DUMMY_CLASS(NSMutableDictionary_LYAdd)

@implementation NSMutableDictionary (LYAdd)

#pragma mark - 安全操作

- (void)setObj:(id)i forKey:(NSString*)key {
    if (i!=nil) {
        self[key] = i;
    }
}

- (void)setString:(NSString*)i forKey:(NSString*)key {
    [self setValue:i forKey:key];
}

- (void)setBool:(BOOL)i forKey:(NSString *)key {
    self[key] = @(i);
}

- (void)setInt:(int)i forKey:(NSString *)key {
    self[key] = @(i);
}

- (void)setInteger:(NSInteger)i forKey:(NSString *)key {
    self[key] = @(i);
}

- (void)setUnsignedInteger:(NSUInteger)i forKey:(NSString *)key {
    self[key] = @(i);
}

- (void)setCGFloat:(CGFloat)f forKey:(NSString *)key {
    self[key] = @(f);
}

- (void)setChar:(char)c forKey:(NSString *)key {
    self[key] = @(c);
}

- (void)setFloat:(float)i forKey:(NSString *)key {
    self[key] = @(i);
}

- (void)setDouble:(double)i forKey:(NSString*)key {
    self[key] = @(i);
}

- (void)setLongLong:(long long)i forKey:(NSString*)key {
    self[key] = @(i);
}

- (void)setPoint:(CGPoint)o forKey:(NSString *)key {
    self[key] = NSStringFromCGPoint(o);
}

- (void)setSize:(CGSize)o forKey:(NSString *)key {
    self[key] = NSStringFromCGSize(o);
}

- (void)setRect:(CGRect)o forKey:(NSString *)key {
    self[key] = NSStringFromCGRect(o);
}

@end
