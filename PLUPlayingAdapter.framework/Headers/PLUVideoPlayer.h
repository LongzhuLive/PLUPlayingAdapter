//
//  PLUVideoPlayer.h
//  TGA
//
//  Created by plu-dev on 16/2/22.
//  Copyright © 2016年 developer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLUFullScreenVideoViewController.h"
#import "PLUVideoPlayerSource.h"
#import "PLUVideoPlayerPlayLineDirectory.h"
#import <MediaPlayer/MediaPlayer.h>


@protocol SNPlayerProtocol;

@class PLUVideoPlayer;

@protocol PLUVideoPlayerDelegate <NSObject>

- (nonnull id<SNPlayerProtocol>)videoPlayerCreateInternalSNPlayer:(nullable PLUVideoPlayer*)videoPlayer;

- (void)videoPlayer:(nullable PLUVideoPlayer*)videoPlayer screenChanged:(BOOL)fullScreen;
//PLUVideoPlayerStateStopped时可以不用处理，到stoppedWithError中处理
- (void)videoPlayer:(nullable PLUVideoPlayer*)videoPlayer playerStateChanged:(PLUVideoPlayerState)playerState;
//error: 可为nil
- (void)videoPlayer:(nullable PLUVideoPlayer*)videoPlayer stoppedWithError:(nullable NSError *)error;
//position
- (void)videoPlayer:(nullable PLUVideoPlayer*)videoPlayer positionChange:(NSTimeInterval)position duration: (NSTimeInterval)duration;
@optional
- (void)videoPlayer:(nullable PLUVideoPlayer*)videoPlayer playLineDirectoryPrepared:(nullable PLUVideoPlayerPlayLineDirectory *)videoPlayerPlayLineDirectory;
//DNS预先解析
- (nonnull NSString *)videoPlayer:(nullable PLUVideoPlayer*)videoPlayer resolvePlayAddress:(nullable NSString *)urlPath;
//友盟上报
- (void)videoPlayer:(nullable PLUVideoPlayer*)videoPlayer event:(nonnull NSString *)event attributes: (nullable NSDictionary *)attributes;
//萌层Image的设置
- (void)videoPlayer:(nullable PLUVideoPlayer*)videoPlayer shouldSetImageView: (nonnull UIImageView *)imageView imageUrl: (nonnull NSString *)imageUrl;
//分辨率模式,1-a,2-b,3-c,4-d,其他-origin
//只有wangsuRoom时有用
- (void)videoPlayer:(nullable PLUVideoPlayer*)videoPlayer usingResolutionMode: (NSInteger)resolutionMode;

@end


@interface PLUVideoPlayer : NSObject

+ (nonnull PLUVideoPlayer *)sharedInstance;


@property (nonatomic, weak, nullable) id<PLUVideoPlayerDelegate> delegate;
//半屏UI，attach前设置
@property (nonatomic, weak, nullable) UIView *smallPlayerUI;
//全屏UI，attach前设置
@property (nonatomic, weak, nullable) UIView *mainPlayerUI;
@property (nonatomic, weak, nullable, readonly) UIViewController *presentViewController;
@property (nonatomic, nullable, readonly) UIView *smallPlayerLandingView;
@property (nonatomic, assign) BOOL hwDecoderEnabled;
@property (nonatomic, assign) BOOL screenAutoRotate;
@property (nonatomic, readonly) BOOL isStarted;
@property (nonatomic, readonly) BOOL isPortraitVideo;
@property (nonatomic, readonly, nullable) PLUVideoPlayerSource *playSource;
///统计相关
@property (nonnull, strong) NSString *userId;
@property (nonnull, strong) NSString *userName;
//视频显示模式
@property(nonatomic, assign) MPMovieScalingMode videoScalingMode;
//是否镜像
@property(nonatomic, assign) BOOL mirrorShow;
//是否为审核环境
@property (nonatomic, assign) BOOL notNormalVersion;


/**
 *  播放器样式,play前设置，设置后不可以更改
 */
@property (nonatomic, assign) PLUVideoPlayerUIStyle videoPlayerUIStyle;
//视频填充方式，随拍里比较有用，撑满
@property (nonatomic, assign) PLUVideoPlayerVideoFitMode videoFitMode;
//最大重试次数，默认8次
@property (nonatomic, assign) NSInteger maxRetryCount;
//没有流状态下超时后是否重试，默认不重试
@property (nonatomic, assign) BOOL shouldRetryWhenTimeout;
//出现播放错误是否重试
@property (nonatomic, assign) BOOL shouldRetryWhenError;
//播放器获取URL重试设置，默认不重试，可以设置隔多久重试一次
@property (nonatomic, assign) NSInteger maxUrlFetchErrRetryCount;
@property (nonatomic, strong, nullable) NSArray<NSNumber *> *urlFetchErrRetryIntervals;
/**
 *  设置播放器显示逻辑
 *
 *  @param presentViewController  需要切换全屏时需要设置
 *  @param smallPlayerLandingView 半屏时播放器View的父View，必须设置
 */
- (void)attachViewController: (nullable UIViewController *)presentViewController smallPlayerLandingView: (nonnull UIView *)smallPlayerLandingView;
/**
 *  必须与attach成对调用
 */
- (void)deattachViewController;
//设置播放区域，一般不会用到
- (void)setPlayerRenderFrame: (CGRect)frame;
//播放控制相关
@property(nonatomic,readonly) PLUVideoPlayerState playerState;
- (void)playPlayerSource: (nonnull PLUVideoPlayerSource *)playerSource;
//刷新，必须调用过playPlayerSource
- (void)reload;
- (void)stop;
- (void)pause;
- (void)resume;
- (void)seekTo:(NSTimeInterval)playbackTime;
- (void)changeResolutionIndexOnPlayLine:(NSInteger)playLineIndex resolutionIndex: (NSInteger)resolutionIndex;
//前提是必须设置过presentViewController
- (void)switchFullScreen:(BOOL)fullScreen;//强制全屏和小窗切换
//视频信息
@property(nonatomic,readonly) NSTimeInterval duration;
@property(nonatomic,readonly) NSTimeInterval playableDuration;
@property(nonatomic,readonly) NSTimeInterval currentPlaybackTime;
//当前播放地址，如果没有则是videoId
@property(nonatomic,readonly, nullable) NSString *currentPlayAddress;
@property(nonatomic, readonly, nullable) PLUVideoPlayerPlayLineDirectory *videoPlayerPlayLineDirectory;
//清晰度相关
@property(nonatomic, readonly) NSInteger playLineIndex;
@property(nonatomic, readonly) NSInteger resolutionIndex;
@property(nonatomic, readonly, nullable) PLUPlayResolution *playResolution;
//playerRenderView
@property(nonatomic,readonly, nonnull) UIView* playerRenderView;
//播放器全屏时的UIViewController
@property(nonatomic,readonly, nullable) PLUFullScreenVideoViewController* fullscreenViewController;
//是否处于全屏状态
@property(nonatomic,readonly) BOOL isFullScreen;

//helper
- (void)showIndicatior;
-(void)showIndicatorByDelay: (NSTimeInterval)delay;
- (void)hideIndicator;
@property (nonatomic, readonly, nullable) UIImageView *imageView;
@property (nonatomic, readonly, nullable) UIView *indicatorView;

//
//failCode: PlayerURLFetchErrorTypeNoUrl,==>>0
//PlayerURLFetchErrorTypeParseError,==>>1
//PlayerURLFetchErrorTypeNetworkError,==>>2

//formatExt: @"flv,rtmp,m3u8"
+(void)getVideoPlayerPlayLineDirectoryByRoomId: (NSInteger)roomId
                                     formatExt: (nonnull NSString *)formatExt
                                  successBlock: (nullable void(^)( PLUVideoPlayerPlayLineDirectory * _Nullable videoPlayerPlayLineDirectory))successBlock
                                       failure: (nullable void(^)(NSInteger failCode, NSError  * _Nullable error))failureBlock;

@end
