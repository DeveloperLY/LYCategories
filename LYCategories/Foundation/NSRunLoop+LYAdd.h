//
//  NSRunLoop+LYAdd.h
//  LYCategories
//
//  Created by LiuY on 2017/3/27.
//  Copyright © 2017年 DeveloperLY. All rights reserved.
//

/* Demo
 - (void)testPerformBlockAndWait {
     // 1
     __block BOOL flag = NO;
     
     [[NSRunLoop currentRunLoop] performBlockAndWait:^(BOOL *finish) {
         double delayInSeconds = 2.0;
         dispatch_time_t popTime = dispatch_time(DISPATCH_TIME_NOW, (int64_t)(delayInSeconds * NSEC_PER_SEC));
         dispatch_queue_t queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
         dispatch_after(popTime, queue, ^(void){
             // 2
             flag = YES;
             *finish = YES;
         });
     }];
     
     // 3
     XCTAssertTrue(flag);
 }
 */

#import <Foundation/Foundation.h>

extern NSString * const NSRunloopTimeoutException;

@interface NSRunLoop (LYAdd)

/**
 *  @author ishkawa
 *
 *  @brief   extension of NSRunLoop for waiting.
 *
 *  @param block <#block description#>
 */
- (void)ly_performBlockAndWait:(void (^)(BOOL *finish))block;

/**
 *  @author ishkawa
 *
 *  @brief   extension of NSRunLoop for waiting.
 *
 *  @param block <#block description#>
 */
- (void)ly_performBlockAndWait:(void (^)(BOOL *finish))block timeoutInterval:(NSTimeInterval)timeoutInterval;

@end
