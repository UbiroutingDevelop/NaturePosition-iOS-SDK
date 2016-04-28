//
//  SHTNatureParameters.h
//  naturelib.framework
//
//  Created by shitupublic on 15/8/21.
//  Copyright (c) 2015年 ubirouting. All rights reserved.
//

#import "SHTDataDef.h"
#import "SHTLocType.h"

#define WEICHAT_UUID @"FDA50693-A4E2-4FB1-AFCF-C6EB07647825"

@class SHTStore;

@interface SHTLocationParameters : NSObject
@property (nonatomic, readonly) NSString * UUID;
- (instancetype)initWithStore:(SHTStore *)store AndInitPosition:(struct IndoorPosition)initPosition AndKey:(NSString *)key WithLocType: (enum LocType)locType;

@end