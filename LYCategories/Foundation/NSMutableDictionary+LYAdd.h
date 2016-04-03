//
//  NSMutableDictionary+LYAdd.h
//  LYCategories
//
//  Created by Liu Y on 16/4/3.
//  Copyright © 2016年 CoderYLiu. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface NSMutableDictionary (LYAdd)

#pragma mark - 安全操作

/**
 *  设置key——value object
 *
 *  @param i   object
 *  @param key key
 */
- (void)setObj:(id)i forKey:(NSString*)key;

/**
 *  设置key——value String
 *
 *  @param i   String
 *  @param key key
 */
- (void)setString:(NSString*)i forKey:(NSString*)key;

/**
 *  设置key——value Bool
 *
 *  @param i   Bool
 *  @param key key
 */
- (void)setBool:(BOOL)i forKey:(NSString *)key;

/**
 *  设置key——value Int
 *
 *  @param i   Int
 *  @param key key
 */
- (void)setInt:(int)i forKey:(NSString *)key;

/**
 *  设置key——value Integer
 *
 *  @param i  Integer
 *  @param key key
 */
- (void)setInteger:(NSInteger)i forKey:(NSString *)key;

/**
 *  设置key——value UnsignedInteger
 *
 *  @param i   UnsignedInteger
 *  @param key key
 */
- (void)setUnsignedInteger:(NSUInteger)i forKey:(NSString *)key;

/**
 *  设置key——value CGFloat
 *
 *  @param i   CGFloat
 *  @param key key
 */
- (void)setCGFloat:(CGFloat)f forKey:(NSString *)key;

/**
 *  设置key——value Char
 *
 *  @param i   Char
 *  @param key key
 */
- (void)setChar:(char)c forKey:(NSString *)key;

/**
 *  设置key——value Float
 *
 *  @param i   Float
 *  @param key key
 */
- (void)setFloat:(float)i forKey:(NSString *)key;

/**
 *  设置key——value Double
 *
 *  @param i   Double
 *  @param key key
 */
- (void)setDouble:(double)i forKey:(NSString*)key;

/**
 *  设置key——value LongLong
 *
 *  @param i   LongLong
 *  @param key key
 */
- (void)setLongLong:(long long)i forKey:(NSString*)key;

/**
 *  设置key——value Point
 *
 *  @param i   Point
 *  @param key key
 */
- (void)setPoint:(CGPoint)o forKey:(NSString *)key;

/**
 *  设置key——value Size
 *
 *  @param i   Size
 *  @param key key
 */
- (void)setSize:(CGSize)o forKey:(NSString *)key;

/**
 *  设置key——value Rect
 *
 *  @param i   Rect
 *  @param key key
 */
- (void)setRect:(CGRect)o forKey:(NSString *)key;

@end
