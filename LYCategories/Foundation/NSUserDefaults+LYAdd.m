//
//  NSUserDefaults+LYAdd.m
//  LYCategories
//
//  Created by LiuY on 2017/3/27.
//  Copyright © 2017年 DeveloperLY. All rights reserved.
//

#import "NSUserDefaults+LYAdd.h"
#import "LYCategoriesMacro.h"

LYSYNTH_DUMMY_CLASS(NSUserDefaults_LYAdd)

@implementation NSUserDefaults (LYAdd)

- (void)ly_setValue:(id)value forKey:(NSString *)key iCloudSync:(BOOL)sync {
    if (sync)
        [[NSUbiquitousKeyValueStore defaultStore] setValue:value forKey:key];
    
    [self setValue:value forKey:key];
}

- (instancetype)ly_valueForKey:(NSString *)key iCloudSync:(BOOL)sync {
    if (sync) {
        //Get value from iCloud
        id value = [[NSUbiquitousKeyValueStore defaultStore] valueForKey:key];
        
        //Store locally and synchronize
        [self setValue:value forKey:key];
        [self synchronize];
        
        return value;
    }
    
    return [self valueForKey:key];
}

- (void)ly_removeValueForKey:(NSString *)key iCloudSync:(BOOL)sync {
    [self ly_removeObjectForKey:key iCloudSync:sync];
}



- (void)ly_setObject:(id)value forKey:(NSString *)defaultName iCloudSync:(BOOL)sync {
    if (sync)
        [[NSUbiquitousKeyValueStore defaultStore] setObject:value forKey:defaultName];
    
    [self setObject:value forKey:defaultName];
}

- (instancetype)ly_objectForKey:(NSString *)key iCloudSync:(BOOL)sync {
    if (sync) {
        //Get value from iCloud
        id value = [[NSUbiquitousKeyValueStore defaultStore] objectForKey:key];
        
        //Store to NSUserDefault and synchronize
        [self setObject:value forKey:key];
        [self synchronize];
        
        return value;
    }
    
    return [self objectForKey:key];
}

- (void)ly_removeObjectForKey:(NSString *)key iCloudSync:(BOOL)sync {
    if (sync)
        [[NSUbiquitousKeyValueStore defaultStore] removeObjectForKey:key];
    
    //Remove from NSUserDefault
    return [self removeObjectForKey:key];
}



- (BOOL)ly_synchronizeAlsoiCloudSync:(BOOL)sync {
    BOOL res = true;
    
    if (sync)
        res &= [self synchronize];
    
    res &= [[NSUbiquitousKeyValueStore defaultStore] synchronize];
    
    return res;
}

#pragma mark - 安全操作
+ (NSString *)ly_stringForKey:(NSString *)defaultName {
    return [[NSUserDefaults standardUserDefaults] stringForKey:defaultName];
}

+ (NSArray *)ly_arrayForKey:(NSString *)defaultName {
    return [[NSUserDefaults standardUserDefaults] arrayForKey:defaultName];
}

+ (NSDictionary *)ly_dictionaryForKey:(NSString *)defaultName {
    return [[NSUserDefaults standardUserDefaults] dictionaryForKey:defaultName];
}

+ (NSData *)ly_dataForKey:(NSString *)defaultName {
    return [[NSUserDefaults standardUserDefaults] dataForKey:defaultName];
}

+ (NSArray *)ly_stringArrayForKey:(NSString *)defaultName {
    return [[NSUserDefaults standardUserDefaults] stringArrayForKey:defaultName];
}

+ (NSInteger)ly_integerForKey:(NSString *)defaultName {
    return [[NSUserDefaults standardUserDefaults] integerForKey:defaultName];
}

+ (float)ly_floatForKey:(NSString *)defaultName {
    return [[NSUserDefaults standardUserDefaults] floatForKey:defaultName];
}

+ (double)ly_doubleForKey:(NSString *)defaultName {
    return [[NSUserDefaults standardUserDefaults] doubleForKey:defaultName];
}

+ (BOOL)ly_boolForKey:(NSString *)defaultName {
    return [[NSUserDefaults standardUserDefaults] boolForKey:defaultName];
}

+ (NSURL *)ly_URLForKey:(NSString *)defaultName {
    return [[NSUserDefaults standardUserDefaults] URLForKey:defaultName];
}

#pragma mark - WRITE FOR STANDARD

+ (void)ly_setObject:(id)value forKey:(NSString *)defaultName {
    [[NSUserDefaults standardUserDefaults] setObject:value forKey:defaultName];
    [[NSUserDefaults standardUserDefaults] synchronize];
}

#pragma mark - READ ARCHIVE FOR STANDARD

+ (instancetype)ly_arcObjectForKey:(NSString *)defaultName {
    return [NSKeyedUnarchiver unarchiveObjectWithData:[[NSUserDefaults standardUserDefaults] objectForKey:defaultName]];
}

#pragma mark - WRITE ARCHIVE FOR STANDARD

+ (void)ly_setArcObject:(id)value forKey:(NSString *)defaultName {
    [[NSUserDefaults standardUserDefaults] setObject:[NSKeyedArchiver archivedDataWithRootObject:value] forKey:defaultName];
    [[NSUserDefaults standardUserDefaults] synchronize];
}

@end
