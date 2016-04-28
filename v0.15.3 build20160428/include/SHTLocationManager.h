//
//  SHTLocationManager.h
//  naturelib.framework
//
//  Created by shitupublic on 15/10/14.
//  Copyright © 2015年 ubirouting. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SHTLocationParameters.h"
#import "SHTPosition.h"
#import "SHTLocType.h"

#define ERROR_FAILED_TO_GET_LOCATION_MANYTIMES 14
#define ERROR_NO_DATA 15
#define ERROR_SERVER_BUSY 18
#define ERROR_NETWORK_CONNECTED_FAILED 13;
#define ERROR_NETWORK_RECONNECT_FAILED 0x02;

// 初次获取一个比较可信的坐标，只有拿到这个状态后，才比较可信
#define STATUS_FIRST_RELIABLE_POSITION 200

// 开始定位
#define STATUS_START_LOCATE 400


// 获取坐标的代理
@protocol SHTLocationDelegate <NSObject>
@required
//更新坐标
- (void) getLocation: (SHTPosition *) position;

//变换楼层
- (void) onSwitchFloor: (int)area;

//更新状态
- (void) getStatus: (int)status Message: (NSString *)message;

// 更新角度，指磁南极，顺时针为正
- (void) getAngle: (int) angle;

//更新状态
- (void) onError: (NSError *) error;

//当网络错误时，会触发
- (void)onNetProblem:(NSException *) exception;

//当网络重新链接成功触发
- (void)onReconnectOK;
@end

// 识途LocationManager
@interface SHTLocationManager : NSObject
@property (nonatomic, weak) id<SHTLocationDelegate> delegate;
@property (nonatomic, readonly) SHTLocationParameters * parameters;

+ (SHTLocationManager *)buildLocationManagerBy: (SHTLocationParameters *) para;

+ (NSString *)sdkVersion;

- (void)start;
- (void)stop;
@end
