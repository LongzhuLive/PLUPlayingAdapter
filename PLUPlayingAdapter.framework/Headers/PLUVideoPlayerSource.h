//
//  PLUVideoPlayerSource.h
//  TGA
//
//  Created by plu-dev on 16/2/22.
//  Copyright © 2016年 developer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLUVideoPlayerDefine.h"

@interface PLUVideoPlayerSource : NSObject

@property (nonatomic, assign) PLUVideoSourceType sourceType;
//腾讯流的channnelId或videoId，直播流(金山／七牛／网宿)的roomId或videoId, PlayUrl
@property (nonatomic, strong) NSString *playId;
@property (nonatomic, assign) BOOL forceRefreshUrlCache;
//预设的播放地址(PLUVideoSourceTypeWangsuLive时生效)，如果有则播放器会先播放这个地址，3秒拉不到流会改用原逻辑
@property (nonatomic, strong) NSString *presetPlayUrl;
//只会在腾讯视频／和设置缓存过时有用，做数据上报使用
@property (nonatomic, assign) NSInteger playStreamType;
//playRoomIdForStat，做数据上报使用
@property (nonatomic, strong) NSString *playRoomIdForStat;
//最大分辨率
@property (nonatomic, assign) NSInteger maxRateLevel;
//网速流的格式
@property (nonatomic, strong) NSString *wangsuExt;
@property (nonatomic, assign) PLUVideoPlayerEngineType wangsuPlayEngineType;
//线路选项－0是主路线
@property (nonatomic, assign) NSInteger defaultPlayLineIndex;
//分辨率选项
@property (nonatomic, assign) NSInteger defaultResolutionIndex;
//default Resolution Level（defaultResolutionIndex=-1时生效）
////5-原画，4-蓝光，3-超清，2-高清，1-普清
@property (nonatomic, assign) NSInteger defaultRateLevel;

@property (nonatomic, copy) NSString *coverImgUrl;

@end

@interface PLUVideoPlayerSource (helper)

- (BOOL)hasPresetPlayUrl;

@end

