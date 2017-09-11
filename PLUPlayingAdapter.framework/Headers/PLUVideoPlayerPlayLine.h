//
//  PLUVideoPlayerPlayLine.h
//  TGA
//
//  Created by plu-dev on 16/4/15.
//  Copyright © 2016年 developer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLUPlayResolution.h"

@interface PLUVideoPlayerPlayLine : NSObject

@property (nonatomic, assign) NSInteger lineType;//0-主线
@property(nonatomic,assign) NSInteger playLiveStreamType;
@property (nonatomic, strong) NSArray<PLUPlayResolution *> *playResolutions;
//分辨率命名Mode
@property (nonatomic, assign) NSInteger resolutionMode;

@end

@interface PLUVideoPlayerPlayLine (Utils)

//获取分辨率个数
- (NSInteger)getResolutionsCount;
//根据分辨率Index选择分辨率，如果越界则会取临近的index
- (PLUPlayResolution*)getPlayResolutionByResolutionIndex: (NSInteger)resolutionIndex pActualResolutionIndex: (NSInteger *)pActualResolutionIndex;
//根据分辨率Level选择分辨率，如果越界则会取临近的index
- (PLUPlayResolution*)getPlayResolutionByResolutionRateLevel: (NSInteger)resolutionRateLevel pActualResolutionIndex: (NSInteger *)pActualResolutionIndex;

- (void)filterByMaxLevel: (NSInteger)maxLevel;

@end

