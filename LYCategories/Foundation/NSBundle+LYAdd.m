//
//  NSBundle+LYAdd.m
//  LYCategories
//
//  Created by Liu Y on 16/4/3.
//  Copyright © 2016年 CoderYLiu. All rights reserved.
//

#import "NSBundle+LYAdd.h"
#import "LYCategoriesMacro.h"

LYSYNTH_DUMMY_CLASS(NSBundle_LYAdd)

@implementation NSBundle (LYAdd)

- (NSString *)appIconPath {
    NSString *iconFilename = [[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleIconFile"];
    NSString *iconBasename = [iconFilename stringByDeletingPathExtension];
    NSString *iconExtension = [iconFilename pathExtension];
    return [[NSBundle mainBundle] pathForResource:iconBasename
                                           ofType:iconExtension];
}

- (UIImage *)appIcon {
    UIImage *appIcon = [[UIImage alloc] initWithContentsOfFile:[self appIconPath]];
    return appIcon;
}

@end
