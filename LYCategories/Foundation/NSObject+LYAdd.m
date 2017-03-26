//
//  NSObject+LYAdd.m
//  LYCategories
//
//  Created by Liu Y on 16/4/2.
//  Copyright © 2016年 DeveloperLY. All rights reserved.
//

#import "NSObject+LYAdd.h"
#import "LYCategoriesMacro.h"

LYSYNTH_DUMMY_CLASS(NSObject_LYAdd)

/** 
 *  objc_getAssociatedObject和objc_setAssociatedObject都需要指定一个固定的地址，
 *  这个固定的地址值用来表示属性的key，起到一个常量的作用。
 */
static const void *LYStringProperty = &LYStringProperty;
static const void *LYIntegerProperty = &LYIntegerProperty;

@implementation NSObject (LYAdd)

#pragma mark - NSInvocation封装

- (id)performSelector:(SEL)aSelector withObjects:(NSArray *)objects {
    NSMethodSignature  *signature = [[self class] instanceMethodSignatureForSelector:aSelector];
    
    if (!signature) {
        NSString *errorInfo = [NSString stringWithFormat:@"%@方法找不到", NSStringFromSelector(aSelector)];
        [NSException exceptionWithName:@"NSInvocation扩展异常" reason:errorInfo userInfo:nil];
    }
    
    NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:signature];
    invocation.target = self;
    invocation.selector = aSelector;
    
    NSUInteger argsCount = signature.numberOfArguments - 2;
    NSUInteger arrCount = objects.count;
    NSUInteger count = MIN(argsCount, arrCount);
    
    for (NSUInteger i = 0; i < count; i++) {
        id obj = objects[i];
        if ([obj isKindOfClass:[NSNull class]]) {
            obj = nil;
        }
        [invocation setArgument:&obj atIndex:i + 2];
    }
    
    [invocation invoke];
    
    id res = nil;
    if (signature.methodReturnLength != 0) {
        [invocation getReturnValue:&res];
    }
    return res;
}

#pragma mark - AssociatedObject 附加属性

- (void)ly_associateValue:(id)value withKey:(void *)key {
    objc_setAssociatedObject(self, key, value, OBJC_ASSOCIATION_RETAIN);
}

- (void)ly_weaklyAssociateValue:(id)value withKey:(void *)key {
    objc_setAssociatedObject(self, key, value, OBJC_ASSOCIATION_ASSIGN);
}

- (id)ly_associatedValueForKey:(void *)key {
    return objc_getAssociatedObject(self, key);
}

#pragma mark - AddProperty 添加属性
@dynamic ly_stringProperty;
@dynamic ly_integerProperty;

//set
/**
 *  @brief  catgory runtime实现get set方法增加一个字符串属性
 */
- (void)setLy_stringProperty:(NSString *)ly_stringProperty {
    //use that a static const as the key
    objc_setAssociatedObject(self, LYStringProperty, ly_stringProperty, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    //use that property's selector as the key:
    //objc_setAssociatedObject(self, @selector(stringProperty), stringProperty, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

//get
- (NSString *)ly_stringProperty {
    return objc_getAssociatedObject(self, LYStringProperty);
}

//set
/**
 *  @brief  catgory runtime实现get set方法增加一个NSInteger属性
 */
- (void)setLy_integerProperty:(NSInteger)ly_integerProperty {
    NSNumber *number = [[NSNumber alloc]initWithInteger:ly_integerProperty];
    objc_setAssociatedObject(self,LYIntegerProperty, number, OBJC_ASSOCIATION_ASSIGN);
}

//get
- (NSInteger)ly_integerProperty {
    return [objc_getAssociatedObject(self, LYIntegerProperty) integerValue];
}

@end
