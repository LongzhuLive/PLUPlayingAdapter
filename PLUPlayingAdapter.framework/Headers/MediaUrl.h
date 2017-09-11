//
//  MediaUrl.h
//  PLUVod
//
//  Created by plu-dev on 15/7/16.
//  Copyright (c) 2015年 DarrenYau. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SNPlayerSDK/SNPlayerSDK.h>

/**
 * Player Media SourceType
 */
typedef NS_ENUM(NSUInteger, PLUMediaSourceType) {
    //ffmpeg兼容模式
    PLUMediaSourceTypeFFSource,
    PLUMediaSourceTypeFLV,
    PLUMediaSourceTypeRTMP,
    PLUMediaSourceTypeHLS,
    PLUMediaSourceTypeMP4,
    PLUMediaSourceTypeTencentStream
};


@interface MediaUrl : SNPlayerMediaSource
@property (nonatomic, assign) PLUMediaSourceType sourceType;
@property (nonatomic, strong) NSString* urlPath;
//可能urlPath是采用域名预解析的，这时referUrlPath表示原地址
@property (nonatomic, strong) NSString* referUrlPath;
//是否为缓存的播放地址(应用相关的，FIXME)
@property (nonatomic, assign) BOOL isCachedUrl;
@property (nonatomic, assign) BOOL isBufferring;

@property (nonatomic, assign) NSTimeInterval playTimeout;

+ (PLUMediaSourceType)guessMediaSourceTypeFromUrlPath: (NSString *)urlPath;

@end
