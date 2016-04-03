//
//  LYCategoriesMacro.h
//  LYCategories <https://github.com/CoderYLiu/LYCategories>
//
//  Created by Liu Y on 16/4/2.
//  Copyright © 2016年 CoderYLiu. All rights reserved.
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//

#import <UIKit/UIKit.h>

#ifndef LYCategoriesMacro_h
#define LYCategoriesMacro_h

// 动态Get方法
#define ly_categoryPropertyGet(property) return objc_getAssociatedObject(self, @#property);
// 动态Set方法
#define ly_categoryPropertySet(property) objc_setAssociatedObject(self,@#property, property, OBJC_ASSOCIATION_RETAIN_NONATOMIC);

/**
 Add this macro before each category implementation, so we don't have to use
 -all_load or -force_load to load object files from static libraries that only
 contain categories and no classes.
 More info: http://developer.apple.com/library/mac/#qa/qa2006/qa1490.html .
 *******************************************************************************
 Example:
 LYSYNTH_DUMMY_CLASS(NSString_LYAdd)
 */
#ifndef LYSYNTH_DUMMY_CLASS
#define LYSYNTH_DUMMY_CLASS(_name_) \
@interface LYSYNTH_DUMMY_CLASS_ ## _name_ : NSObject @end \
@implementation LYSYNTH_DUMMY_CLASS_ ## _name_ @end
#endif


//ios系统版本
#define ios9x [[[UIDevice currentDevice] systemVersion] floatValue] >= 9.0f
#define ios8x [[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0f
#define ios7x ([[[UIDevice currentDevice] systemVersion] floatValue] >= 7.0f) && ([[[UIDevice currentDevice] systemVersion] floatValue] < 8.0f)
#define ios6x [[[UIDevice currentDevice] systemVersion] floatValue] < 7.0f
#define iosNot6x [[[UIDevice currentDevice] systemVersion] floatValue] >= 7.0f


#define iphone4x_3_5 ([UIScreen mainScreen].bounds.size.height==480.0f)

#define iphone5x_4_0 ([UIScreen mainScreen].bounds.size.height==568.0f)

#define iphone6_4_7 ([UIScreen mainScreen].bounds.size.height==667.0f)

#define iphone6Plus_5_5 ([UIScreen mainScreen].bounds.size.height==736.0f || [UIScreen mainScreen].bounds.size.height==414.0f)



#endif /* LYCategoriesMacro_h */
