//
//  PLUVideoPlayerDefine.h
//  TGA
//
//  Created by plu-dev on 16/2/22.
//  Copyright © 2016年 developer. All rights reserved.
//

#ifndef PLUVideoPlayerDefine_h
#define PLUVideoPlayerDefine_h

/**
 * PLUVideoSourceType
 */
typedef NS_ENUM(NSUInteger, PLUVideoSourceType) {
    PLUVideoSourceTypeUnknow = 0,
    PLUVideoSourceTypeTencentLive,
    PLUVideoSourceTypeTencentVod,
    PLUVideoSourceTypeWangsuLive,
    PLUVideoSourceTypeWangsuVod,
    PLUVideoSourceTypePlayUrlLive,
    PLUVideoSourceTypePlayUrlVod,
};

/**
 * PLUVideoPlayerEngineType
 */
typedef NS_ENUM(NSUInteger, PLUVideoPlayerEngineType) {
    PLUVideoPlayerEngineTypeUnknow = 0,
    PLUVideoPlayerEngineTypeTencent,
    PLUVideoPlayerEngineTypeAVPlayer,
    PLUVideoPlayerEngineTypeKsy
};

/**
 
 * PLUVideoPlayerState
 
 */

typedef NS_ENUM(NSUInteger, PLUVideoPlayerState) {
    //初始状态
    PLUVideoPlayerStateUnknow = 0,
    PLUVideoPlayerStateVideoDirectoryPreparing,
    PLUVideoPlayerStateVideoDirectoryPrepared,
    PLUVideoPlayerStateVideoPlayPraparing,
    PLUVideoPlayerStateVideoPlayReady,
    PLUVideoPlayerStateVideoPlayPlaying,
    PLUVideoPlayerStateVideoPlayPaused,
    PLUVideoPlayerStateVideoPlayStopped
};


FOUNDATION_EXPORT NSString * const PLUVideoPlayerErrorDomain;
FOUNDATION_EXPORT NSString * const PLUVideoPlayerErrorDescKey;
/**
 * PLUVideoPlayerError
 */
typedef NS_ENUM(NSUInteger, PLUVideoPlayerError) {
    PLUVideoPlayerErrorUnkow = 0,
    //PLUVideoPlayerErrorDescKey{@"key": String}
    PLUVideoPlayerErrorUnsupportedSource = 100000,
    //PLUVideoPlayerErrorDescKey{@"key": String}
    PLUVideoPlayerErrorCannotFetchUrl = 100001,
    //PLUVideoPlayerErrorDescKey{@"key": String}
    PLUVideoPlayerErrorNoPlayUrl = 100002,
    //PLUVideoPlayerErrorDescKey{@"key": String}
    PLUVideoPlayerErrorPlayInternalError = 100003,
    //PLUVideoPlayerErrorDescKey{@"key": String},只有点播会有
    PLUVideoPlayerErrorPlayReachEnd = 100004,
};

/**
 * PLUVideoPlayerUIStyle
 */
typedef NS_ENUM(NSUInteger, PLUVideoPlayerUIStyle) {
    PLUVideoPlayerUIStyleGame = 0,
    PLUVideoPlayerUIStyleSuipai = 1
};

/**
 * PLUVideoPlayerVideoFitMode   视频填充方式，随拍里比较有用，撑满，
 */
typedef NS_ENUM(NSUInteger, PLUVideoPlayerVideoFitMode) {
    PLUVideoPlayerVideoFitModeNormal = 0,
    PLUVideoPlayerVideoFitModeRotateLeft = 1,//横屏下如果width<height则左转
    PLUVideoPlayerVideoFitModeRotateRight = 2//横屏下如果width<height则右转
};


//PLAYENGINE OPtion Keys
//@"pluijk-first-high-water-mark-ms"--INT
FOUNDATION_EXPORT NSString * const PLUPlayEngineOptionPLUIJKFirstHWMS;
//@"pluijk-next-high-water-mark-ms"--INT
FOUNDATION_EXPORT NSString * const PLUPlayEngineOptionPLUIJKNextHWMS;
//@"pluijk-last-high-water-mark-ms"--INT
FOUNDATION_EXPORT NSString * const PLUPlayEngineOptionPLUIJKLastHWMS;
//@"pluijk-max-latency-in-ms"--INT
FOUNDATION_EXPORT NSString * const PLUPlayEngineOptionPLUIJKMaxLatencyMS;
//@"pluijk-min-latency-in-ms"--INT
FOUNDATION_EXPORT NSString * const PLUPlayEngineOptionPLUIJKMinLatencyMS;

#endif /* PLUVideoPlayerDefine_h */
