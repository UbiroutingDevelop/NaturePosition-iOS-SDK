//
//  SHTStore.h
//  naturelib.framework
//
//  Created by YangTao on on 15/8/20.
//  Copyright (c) 2015年 ubirouting. All rights reserved.
//


#import "SHTDataDef.h"

@interface SHTStore : NSObject

/**
 * 商店名称
 */
@property (nonatomic) NSString * name;

@property (nonatomic) struct BaiduGPSCoordinate coordinate;

@property (nonatomic) long idd;

@property (nonatomic) int floorNum;

@property (nonatomic) SHTFloor * floorParameters;

@end
