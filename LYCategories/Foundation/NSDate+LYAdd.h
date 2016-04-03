//
//  NSDate+LYAdd.h
//  LYCategories
//
//  Created by Liu Y on 16/4/3.
//  Copyright © 2016年 CoderYLiu. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDate (LYAdd)

#pragma mark - 当前时间
///=============================================================================
/// @name 当前时间
///=============================================================================

/**
 *  获获取当前客户端的逻辑日历
 *
 *  @return 当前客户端的逻辑日历
 */
+ (NSCalendar *)currentCalendar;

/**
 *  将日期转换为当前时区的日期
 *
 *  @param forDate 要转换的日期
 *
 *  @return 转换过的日期
 */
+ (NSDate *)convertDateToLocalTime:(NSDate *)forDate;

#pragma mark - 相对日期
///=============================================================================
/// @name 相对日期
///=============================================================================

/**
 *  现在的日期
 *
 *  @return 现在的日期
 */
+ (NSDate *)dateNow;

/**
 *  明天的日期
 *
 *  @return 明天的日期
 */
+ (NSDate *)dateTomorrow;

/**
 *  昨天的日期
 *
 *  @return 昨天日期
 */
+ (NSDate *)dateYesterday;

/**
 *  从现在起向后推几天的日期
 *
 *  @param days 向后推的天数
 *
 *  @return 后推得到的日期
 */
+ (NSDate *)dateWithDaysFromNow:(NSInteger)days;

/**
 *  从现在起向前推几天的日期
 *
 *  @param days 向前推的天数
 *
 *  @return 前推得到的日期
 */
+ (NSDate *)dateWithDaysBeforeNow:(NSInteger)days;

/**
 *  从现在起向后推几小时的日期
 *
 *  @param days 向后推的小时数
 *
 *  @return 后推得到的日期
 */
+ (NSDate *)dateWithHoursFromNow:(NSInteger)dHours;

/**
 *  从现在起向前推几小时的日期
 *
 *  @param days 向前推的小时数
 *
 *  @return 前推得到的日期
 */
+ (NSDate *)dateWithHoursBeforeNow:(NSInteger)dHours;

/**
 *  从现在起向后推几分钟的日期
 *
 *  @param days 向后推的分钟数
 *
 *  @return 后推得到的日期
 */
+ (NSDate *)dateWithMinutesFromNow:(NSInteger)dMinutes;

/**
 *  从现在起向前推几分钟的日期
 *
 *  @param days 向前推的分钟数
 *
 *  @return 前推得到的日期
 */
+ (NSDate *)dateWithMinutesBeforeNow:(NSInteger)dMinutes;

#pragma mark - 日期转字符串
///=============================================================================
/// @name 日期转字符串
///=============================================================================

// 使用NSDateFormatter转换时间字符串时，默认的时区是系统时区，如我们使用一般都是北京时间(＋8)

/**
 *  通过format格式将当前日期转换为String格式
 *
 *  @param format 格式样式
 *
 *  @return 转换后得到的String
 */
- (NSString *)stringWithFormat:(NSString *)format;

/**
 *  通过系统自带的时间风格 来得到字符串
 *
 *  @param dateStyle 日期格式 年月日
 *  @param timeStyle 时间格式 时分秒
 *
 *  @return 得到最终的字符串
 */
- (NSString *)stringWithDateStyle:(NSDateFormatterStyle)dateStyle timeStyle:(NSDateFormatterStyle)timeStyle;

/**
 *  5/5/15, 10:48 AM
 *
 *  @return 相应格式的日期+时间
 */
- (NSString *)shortString;

/**
 *  10:48 AM
 *
 *  @return 相应格式的时间
 */
- (NSString *)shortTimeString;

/**
 *  5/5/15
 *
 *  @return 相应格式的日期
 */
- (NSString *)shortDateString;

/**
 *  May 5, 2015, 10:35:23 AM
 *
 *  @return 相应格式的日期+时间
 */
- (NSString *)mediumString;

/**
 *  10:35:23 AM
 *
 *  @return 相应格式的时间
 */
- (NSString *)mediumTimeString;

/**
 *  May 5, 2015
 *
 *  @return 相应格式的日期
 */
- (NSString *)mediumDateString;

/**
 *  May 5, 2015 at 10:35:23 AM GMT+8
 *
 *  @return 相应格式的日期+时间
 */
- (NSString *)longString;

/**
 *  May 5, 2015
 *
 *  @return 相应格式的时间
 */
- (NSString *)longTimeString;

/**
 *  10:35:23 AM GMT+8
 *
 *  @return 相应格式的日期
 */
- (NSString *)longDateString;

#pragma mark - 日期比较
///=============================================================================
/// @name 日期比较
///=============================================================================

/**
 *  抛弃时间外 日期是否相等 精确到天的范围内
 *
 *  @param aDate 比较的date
 *
 *  @return YES 相等 NO 不相等
 */
- (BOOL)isEqualToDateIgnoringTime:(NSDate *)aDate;


/**
 *  日期是不是今天
 *
 *  @return YES 是 NO 不是
 */
- (BOOL)isToday;

/**
 *  日期是不是明天
 *
 *  @return YES  是 NO 不是
 */
- (BOOL)isTomorrow;

/**
 *  是不是昨天
 *
 *  @return YES 是 NO 不是
 */
- (BOOL)isYesterday;


/**
 *  判断和指定日期是否是同一个星期内的
 *
 *  @param aDate 相比较的日期
 *
 *  @return YES 是 NO 不是
 */
- (BOOL)isSameWeekAsDate:(NSDate *)aDate;

/**
 *  判断是不是本周
 *
 *  @return YES 是 NO 不是
 */
- (BOOL)isThisWeek;

/**
 *  判断是不是下周
 *
 *  @return YES 是 NO  不是
 */
- (BOOL)isNextWeek;

/**
 *  判断是不是上周
 *
 *  @return YES 是 NO 不是
 */
- (BOOL)isLastWeek;



/**
 *  判断是不是同一个月
 *
 *  @param aDate 比较的日期
 *
 *  @return YES 是 NO 不是
 */
- (BOOL)isSameMonthAsDate:(NSDate *)aDate;

/**
 *  判断是不是本月
 *
 *  @return YES 是 NO 不是
 */
- (BOOL)isThisMonth;

/**
 *  判断是不是上个月
 *
 *  @return YES 是 NO 不是
 */
- (BOOL)isLastMonth;

/**
 *  判断是不是下个月
 *
 *  @return YES 是 NO 不是
 */
- (BOOL)isNextMonth;



/**
 *  判断是不是同一年
 *
 *  @param aDate 比较的日期
 *
 *  @return YES 是 NO 不是
 */
- (BOOL)isSameYearAsDate:(NSDate *)aDate;

/**
 *  判断是不是本年
 *
 *  @return YES 是 NO 不是
 */
- (BOOL)isThisYear;

/**
 *  判断是不是下一年
 *
 *  @return YES 是 NO 不是
 */
- (BOOL)isNextYear;

/**
 *  判断是不是上一年
 *
 *  @return YES 是 NO 不是
 */
- (BOOL)isLastYear;


/**
 *  判断是不是比指定日期早
 *
 *  @param aDate 指定的日期
 *
 *  @return YES 早 NO 不早
 */
- (BOOL)isEarlierThanDate:(NSDate *)aDate;

/**
 *  判断是不是比指定日期晚
 *
 *  @param aDate 指定的日期
 *
 *  @return YES 晚 NO 不晚
 */
- (BOOL)isLaterThanDate:(NSDate *)aDate;


/**
 *  判断一个日期是不是在将来
 *
 *  @return YES 是 NO 不是
 */
- (BOOL)isInFuture;

/**
 *  判断一个日期是不是在过去
 *
 *  @return YES 是 NO 不是
 */
- (BOOL)isInPast;

#pragma mark - 日期规则
///=============================================================================
/// @name 星期内工作日
///=============================================================================

/**
 *  是不是周六日
 *
 *  @return YES 是 NO 不是
 */
- (BOOL)isTypicallyWeekend;

/**
 *  是不是工作日
 *
 *  @return YES 是 NO 不是
 */
- (BOOL)isTypicallyWorkday;

#pragma mark - 调整日期
///=============================================================================
/// @name 调整日期
///=============================================================================

/**
 *  指定日期后推几年得到的日期
 *
 *  @param dYears 后推的年数
 *
 *  @return 后推后得到的日期
 */
- (NSDate *)dateByAddingYears:(NSInteger)dYears;

/**
 *  指定日期前推几年得到的日期
 *
 *  @param dYears 前推的年数
 *
 *  @return 前推得到的日期
 */
- (NSDate *)dateBySubtractingYears:(NSInteger)dYears;

/**
 *  指定日期后推几个月得到的日期
 *
 *  @param dMonths 后推的月数
 *
 *  @return 后推后得到的日期
 */
- (NSDate *)dateByAddingMonths:(NSInteger)dMonths;

/**
 *  指定日期前推几个月得到的日期
 *
 *  @param dMonths 前推的月数
 *
 *  @return 前推后得到的日期
 */
- (NSDate *)dateBySubtractingMonths:(NSInteger)dMonths;

/**
 *  指定日期后推几天得到的日期
 *
 *  @param dDays 后推的天数
 *
 *  @return 后推得到的日期
 */
- (NSDate *)dateByAddingDays:(NSInteger)dDays;

/**
 *  指定日期前推几天的到的日期
 *
 *  @param dDays 前推的天数
 *
 *  @return 前推得到的日期
 */
- (NSDate *)dateBySubtractingDays:(NSInteger)dDays;

/**
 *  指定日期后推几小时得到的日期
 *
 *  @param dHours 后推的几个小时
 *
 *  @return 后推后的日期
 */
- (NSDate *)dateByAddingHours:(NSInteger)dHours;

/**
 *  指定日期前推几小时得到的日期
 *
 *  @param dHours 前推的小时数
 *
 *  @return 前推后得到的日期
 */
- (NSDate *)dateBySubtractingHours:(NSInteger)dHours;

/**
 *  指定日期后推几分钟得到的日期
 *
 *  @param dMinutes 后推的分钟数
 *
 *  @return 后推得到的日期
 */
- (NSDate *)dateByAddingMinutes:(NSInteger)dMinutes;

/**
 *  指定日期前推几分钟得到的日期
 *
 *  @param dMinutes 前推的分钟数
 *
 *  @return 前推得到的日期
 */
- (NSDate *)dateBySubtractingMinutes:(NSInteger)dMinutes;

/**
 *  指定日期和给的日期之间相差的时间
 *
 *  @param aDate 比较的日期
 *
 *  @return 相差的时间
 */
- (NSDateComponents *)componentsWithOffsetFromDate:(NSDate *)aDate;

#pragma mark - 极端例子
///=============================================================================
/// @name 极端例子
///=============================================================================

/**
 *  得到指定日期这一天的开始日期
 *
 *  @return 得到的日期
 */
- (NSDate *)dateAtStartOfDay;

/**
 *  得到指定日期这一天的结束日期
 *
 *  @return 得到的日期
 */
- (NSDate *)dateAtEndOfDay;


#pragma mark - 检索间隔
///=============================================================================
/// @name 检索间隔
///=============================================================================

/**
 *  得到当前日期在给定日期之后的分钟数
 *
 *  @param aDate 给定的日期
 *
 *  @return 得到的分钟数
 */
- (NSInteger)minutesAfterDate:(NSDate *)aDate;

/**
 *  得到当前日期在给定日期之前的分钟数
 *
 *  @param aDate 给定的日期
 *
 *  @return 得到的分钟数
 */
- (NSInteger)minutesBeforeDate:(NSDate *)aDate;

/**
 *  得到当前日期在给定日期之后的小时数
 *
 *  @param aDate 给定的日期
 *
 *  @return 得到的小时数
 */
- (NSInteger)hoursAfterDate:(NSDate *)aDate;

/**
 *  得到当前日期在给定日期之前的小时数
 *
 *  @param aDate 给定的日期
 *
 *  @return 得到的小时数
 */
- (NSInteger)hoursBeforeDate:(NSDate *)aDate;

/**
 *  得到当前日期在给定日期之后的天数
 *
 *  @param aDate 给定的日期
 *
 *  @return 得到的天数
 */
- (NSInteger)daysAfterDate:(NSDate *)aDate;

/**
 *  得到当前日期在给定日期之后的天数
 *
 *  @param aDate 给定的日期
 *
 *  @return 得到的天数
 */
- (NSInteger)daysBeforeDate:(NSDate *)aDate;

/**
 *  当前的日期和给定的日期之间相差的天数
 *
 *  @param anotherDate 给定的日期
 *
 *  @return 相差的天数
 */
- (NSInteger)distanceInDaysToDate:(NSDate *)anotherDate;

#pragma mark - 日期分解
///=============================================================================
/// @name 日期分解
///=============================================================================

/**
 *  距离当前时间最近的小时 比如9：55 就是10：00 9：25就是9：00
 *
 *  @return 最近的小时
 */
- (NSInteger)nearestHour;

/**
 *  当前日期的小时
 *
 *  @return 当前日期的小时
 */
- (NSInteger)hour;

/**
 *  当前日期的分钟
 *
 *  @return 当前日期的分钟
 */
- (NSInteger)minute;

/**
 *  当前日期的秒
 *
 *  @return 当前日期的秒
 */
- (NSInteger)seconds;

/**
 *  当前日期的几号
 *
 *  @return 当前日期的几号
 */
- (NSInteger)day;

/**
 *  当前日期的几月
 *
 *  @return 当前日期的几月
 */
- (NSInteger)month;

/**
 *  当前月的第几周
 *
 *  @return 当前月的第几周
 */
- (NSInteger)weekOfMonth;

/**
 *  当前年的第几周
 *
 *  @return 当前年的第几周
 */
- (NSInteger)weekOfYear;

/**
 *  当前日期所在周的第几天
 *
 *  @return 第几天
 */
- (NSInteger)weekday;

/**
 *  当前日期所在年的第几季度
 *
 *  @return 获得的季度
 */
- (NSInteger)nthWeekday; // e.g. 2nd Tuesday of the month is 2

/**
 *  当前日期的年
 *
 *  @return 当前日期的年
 */
- (NSInteger)year;



@end
