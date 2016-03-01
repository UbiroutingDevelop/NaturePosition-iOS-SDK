SDK版本号0.8 (alpha)
#1 获取SDK
您可发送邮件至[sdk@ubirouting.com](mailto:sdk@ubirouting.com)获取最新的iOS SDK。详见概述。
目前SDK正处于测试过程中，若您再使用过程中遇到任何问题，欢迎您反馈至[sdk@ubirouting.com](mailto:sdk@ubirouting.com)。

注：因为模拟器不含有传感器，所以请您在调试过程中使用真机进行调试。

----

#2 开发
##2.1 导入.a 及相关的头文件
在获取.a文件后，将.a文件及相关头文件放置到所在项目中，并导入sqlite的相关库文件。
![alt library](http://www.ubirouting.com/imageUse/1.png)

在Build Settings下找到Linking，修改"Other Linker Flag"为"-ObjC"
![alt linking](http://www.ubirouting.com/imageUse/2.jpg)


##2.2 获取建筑列表
您可通过```SHTStoreDatas```类类获取您账户下的所有商户列表。

示例

```
#import "SHTStoreDatas.h"
#import "SHTStore.h"

...

- (void)getStores
{
	SHTStoreDatas * datas = [[SHTStoreDatas alloc]initWithKey:@"youkey"];
	data.delegate = self;
	
	// 识途的商户是通过代理，异步的方式返回
	[data fetchData];
}

//实现代理方法

- (void)onGetDatas: (NSArray *)datas
{
	//datas存取的是您账户下的所有建筑列表，在后面定位中会将作为参数传入
}

- (void)onFailed: (NSException *)exception
{
	//若有异常，通过此来返回。异常可能为网络异常，也可能是您的Key不正确导致的
}

```

## 2.3定位
再获取了商户列表以后，即可使用**识途定位SDK(iOS)**。

在您即将实现定位的Controller中，导入头文件：

```
#import "SHTLocationParameters.h"
#import "SHTPosition.h"
#import "SHTLocationManager.h"
```

然后构造一个```SHTLocationParameters.h```对象，构造方法需传入参数：

+ 并将您要定位的单个建筑（```SHTStore```对象，即上节所述）
+ 初始位置，为```struct IndoorPosition```结构体，可传入初始位置x，y,以及初始楼层。

其中初始位置x,y为可选，用以用其他方式定位获取的初始位置代替；识途定位会自动获取位置，**此时请将x和y均设为-1**。

若采用纯地磁定位，**初始楼层floor为必选**，目前识途定位SDK(iOS)纯地磁定位尚不支持跨层切换，我们会在后续的版本中逐渐完善该功能，并提供给您。其他定位方式均支持该跨层切换。

+ 每个楼层的地图像素长宽
+ 定位方式，目前**识途定位SDK(iOS)**可支持纯地磁定位，即```LOCTYPE_MAG_ONLY```，混合定位```LOCTYPE_MAG_IBEACON```以及纯iBeacon定位```LOCTYPE_IBEACON_ONLY```。

之后，构造locationManager对象，并将该SHTLocationParameters，以及APP Key等信息作为参数传入其中，并设置代理方法，详见如下示例：

```
#import "SHTLocationParameters.h"
#import "SHTPosition.h"
#import "SHTLocationManager.h"

//使用SHTLocationDelegate
@interface ViewController : UIViewController<SHTLocationDelegate>

...

//启动定位
- (void)startLocate
{
	//定义初始位置。若使用ibeacon混合定位，或纯iBeacon定位，不需要指定初始位置，即x,y均传入-1即可
	struct IndoorPosition initPosition;
    initPosition.x = -1;
    initPosition.y = -1;
    
    //需传入每个楼层的地图的像素宽度和高度，用以进行边界判断，该高宽需和采集时使用的地图高宽一致
    struct MapSize * mapSize = malloc(sizeof(struct MapSize) * 3);
    mapSize[0].floor = 1;
    mapSize[0].width = 1000;
    mapSize[0].height = 1000;
    
    mapSize[1].floor = 2;
    mapSize[1].width = 1000;
    mapSize[1].height = 1000;
    
    mapSize[2].floor = 3;
    mapSize[2].width = 1000;
    mapSize[2].height = 1000;
    
    //初始化定位参数， storeTest为2.2节中获取的任意store
    SHTLocationParameters * parameters = [SHTLocationParameters alloc]initWithStore:storeTest AndInitPosition:initPosition AndKey:@"youkey" AndMapSize:mapSize AndLocType:LOCTYPE_IBEACON_ONLY];
    
    //实例化一个locationManager对象
    _locationManager = [SHTLocationManager buildLocationManagerBy:para];
    
    //设置代理
    locationManager.delegate = self;
    
    //开启定位，定位结果将以代理的形式返回
    [self.locationManager start];
}

...
// 实现代理方法

// 在此更新坐标
- (void)getLocation:(SHTPosition *)position
{
    // 在这里更新坐标
    // position.x和position.y
    NSLog(@"position is %@", position);
}

- (void)getAngle:(int)angle
{
    //在这里更新角度（指南针）
}

- (void)getStatus:(int)status Message:(NSString *)message
{
	//再这里获取状态信息。
	
	//识途地磁定位的特点是需要用户行走一段距离，供服务器计算特征，只有当获取到的status==STATUS_FIRST_RELIABLE_POSITION时，该位置才具有较高的可靠性，之前的位置坐标均可丢弃。在获得上述状态时，需提示用户继续行走；
	
    NSLog(@"getStatus %d, %@", status, message);
}

@end
```
