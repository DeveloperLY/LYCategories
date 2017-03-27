//
//  NSObject+LYAdd.m
//  LYCategories
//
//  Created by Liu Y on 16/4/2.
//  Copyright © 2016年 DeveloperLY. All rights reserved.
//

#import "NSObject+LYAdd.h"
#import <objc/runtime.h>
#import "LYCategoriesMacro.h"

LYSYNTH_DUMMY_CLASS(NSObject_LYAdd)

#pragma mark - Runtime
BOOL ly_method_swizzle(Class klass, SEL origSel, SEL altSel) {
    if (!klass)
        return NO;
    
    Method __block origMethod, __block altMethod;
    
    void (^find_methods)() = ^ {
        unsigned methodCount = 0;
        Method *methodList = class_copyMethodList(klass, &methodCount);
        
        origMethod = altMethod = NULL;
        
        if (methodList)
            for (unsigned i = 0; i < methodCount; ++i) {
                if (method_getName(methodList[i]) == origSel)
                    origMethod = methodList[i];
                
                if (method_getName(methodList[i]) == altSel)
                    altMethod = methodList[i];
            }
        
        free(methodList);
    };
    
    find_methods();
    
    if (!origMethod) {
        origMethod = class_getInstanceMethod(klass, origSel);
        
        if (!origMethod)
            return NO;
        
        if (!class_addMethod(klass, method_getName(origMethod), method_getImplementation(origMethod), method_getTypeEncoding(origMethod)))
            return NO;
    }
    
    if (!altMethod) {
        altMethod = class_getInstanceMethod(klass, altSel);
        
        if (!altMethod)
            return NO;
        
        if (!class_addMethod(klass, method_getName(altMethod), method_getImplementation(altMethod), method_getTypeEncoding(altMethod)))
            return NO;
    }
    
    find_methods();
    
    if (!origMethod || !altMethod)
        return NO;
    
    method_exchangeImplementations(origMethod, altMethod);
    
    return YES;
}

void ly_method_append(Class toClass, Class fromClass, SEL selector) {
    if (!toClass || !fromClass || !selector)
        return;
    
    Method method = class_getInstanceMethod(fromClass, selector);
    
    if (!method)
        return;
    
    class_addMethod(toClass, method_getName(method), method_getImplementation(method), method_getTypeEncoding(method));
}

void ly_method_replace(Class toClass, Class fromClass, SEL selector) {
    if (!toClass || !fromClass || ! selector)
        return;
    
    Method method = class_getInstanceMethod(fromClass, selector);
    
    if (!method)
        return;
    
    class_replaceMethod(toClass, method_getName(method), method_getImplementation(method), method_getTypeEncoding(method));
}

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

#pragma mark - Runtime

+ (void)ly_swizzleMethod:(SEL)originalMethod withMethod:(SEL)newMethod {
    ly_method_swizzle(self.class, originalMethod, newMethod);
}

+ (void)ly_appendMethod:(SEL)newMethod fromClass:(Class)klass {
    ly_method_append(self.class, klass, newMethod);
}

+ (void)ly_replaceMethod:(SEL)method fromClass:(Class)klass {
    ly_method_replace(self.class, klass, method);
}

- (BOOL)ly_respondsToSelector:(SEL)selector untilClass:(Class)stopClass {
    return [self.class ly_instancesRespondToSelector:selector untilClass:stopClass];
}

- (BOOL)ly_superRespondsToSelector:(SEL)selector {
    return [self.superclass instancesRespondToSelector:selector];
}

- (BOOL)ly_superRespondsToSelector:(SEL)selector untilClass:(Class)stopClass {
    return [self.superclass ly_instancesRespondToSelector:selector untilClass:stopClass];
}

+ (BOOL)ly_instancesRespondToSelector:(SEL)selector untilClass:(Class)stopClass {
    BOOL __block (^ __weak block_self)(Class klass, SEL selector, Class stopClass);
    BOOL (^block)(Class klass, SEL selector, Class stopClass) = [^
                                                                 (Class klass, SEL selector, Class stopClass)
                                                                 {
                                                                     if (!klass || klass == stopClass)
                                                                         return NO;
                                                                     
                                                                     unsigned methodCount = 0;
                                                                     Method *methodList = class_copyMethodList(klass, &methodCount);
                                                                     
                                                                     if (methodList)
                                                                         for (unsigned i = 0; i < methodCount; ++i)
                                                                             if (method_getName(methodList[i]) == selector)
                                                                                 return YES;
                                                                     
                                                                     return block_self(klass.superclass, selector, stopClass);
                                                                 } copy];
    
    block_self = block;
    
    return block(self.class, selector, stopClass);
}

@end
