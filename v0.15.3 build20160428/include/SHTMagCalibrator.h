//
//  SHTMagCalibrator.h
//  naturelib.framework
//
//  Created by YangTao on on 15/7/20.
//  Copyright (c) 2015年 ubirouting. All rights reserved.
//

#import "SHTSensors.h"

/**
 * 地磁八字矫正法的回调方法
 */
@protocol SHTMagCalibratorDeletegate <NSObject>
@required
/**
 * 矫正过程中，返回矫正百分比
 */
- (void)onCalibrating: (float)percent;
/**
 * 结束矫正
 */
- (void)onFinish;
@end

/**
 * 地磁八字矫正法
 */
@interface SHTMagCalibrator : NSObject<SHTSensorDelegate>
@property (nonatomic, weak) id<SHTMagCalibratorDeletegate> delegate;
/**
 * 设置矫正参数，一般不用
 */
- (void)setCalibrationTimeLimit: (NSTimeInterval) calibrationTimeLimit PeakValue: (float) peakValue ValleyValue: (float)valleyValue;
- (void)startCalibration;
- (void)finishCalibration;

@end
