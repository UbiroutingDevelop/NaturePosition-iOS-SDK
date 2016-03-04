//
//  SHTDataDef.h
//  naturelib.framework
//
//  Created by shitupublic on 15/8/20.
//  Copyright (c) 2015年 ubirouting. All rights reserved.
//

#ifndef naturelib_framework_SHTDataDef_h
#define naturelib_framework_SHTDataDef_h

/*
 百度地图经纬度坐标
 */
struct BaiduGPSCoordinate
{
    double latitude;
    double longitude;
};

/*
 角度
 */
typedef int angle;

/*
 弧度
 */
typedef float radian;

/*
 地图大小
 */
struct MapSize
{
    int width;
    int height;
    int floor;
};

/*
 室内地图位置
 */
struct IndoorPosition
{
    float x;
    float y;
    int floor;
};

typedef struct{
    int floor;
    int width;
    int height;
    float scale;
    int angleOffset;
} SHTFloor;

#endif
