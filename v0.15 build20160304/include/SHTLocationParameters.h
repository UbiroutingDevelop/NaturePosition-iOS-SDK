//
//  SHTNatureParameters.h
//  naturelib.framework
//
//  Created by shitupublic on 15/8/21.
//  Copyright (c) 2015年 ubirouting. All rights reserved.
//

#import "SHTDataDef.h"
#import "SHTLocType.h"

@class SHTStore;

@interface SHTLocationParameters : NSObject

- (instancetype)initWithStore:(SHTStore *)store AndInitPosition:(struct IndoorPosition)initPosition AndKey:(NSString *)key AndMapSize:(struct MapSize *)size AndLocType: (enum LocType)locType;

@end