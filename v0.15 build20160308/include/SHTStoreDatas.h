//
//  SHTStoreDatas.h
//  naturelib.framework
//
//  Created by shitupublic on 15/8/20.
//  Copyright (c) 2015年 ubirouting. All rights reserved.
//
@protocol SHTStoreDatasDelegate <NSObject>

@required
- (void)onGetDatas: (NSArray *)datas;
- (void)onFailed: (NSException *)exception;

@end


@interface SHTStoreDatas : NSObject

@property (nonatomic, weak) id<SHTStoreDatasDelegate> delegate;

- (instancetype) initWithKey: (NSString *)key;

- (void)fetchData;

@end
