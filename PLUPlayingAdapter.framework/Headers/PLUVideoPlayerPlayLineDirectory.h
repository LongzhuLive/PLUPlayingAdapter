//
//  PLUVideoPlayerPlayLineDirectory.h
//  TGA
//
//  Created by plu-dev on 16/4/15.
//  Copyright © 2016年 developer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLUVideoPlayerPlayLine.h"

@interface PLUVideoPlayerPlayLineDirectory : NSObject

@property (nonatomic, assign) NSInteger liveSourceType;
@property (nonatomic, assign) NSInteger liveStreamType;

@property (nonatomic, strong) NSArray<PLUVideoPlayerPlayLine*> *videoPlayerPlayLines;


@end


@interface PLUVideoPlayerPlayLineDirectory (Utils)

//获取线路个数
- (NSInteger)getPlayLineCount;
//根据线路Index选择线路，如果越界则会取临近的index
- (PLUVideoPlayerPlayLine*)getPlayLineByLineIndex: (NSInteger)lineIndex pActualLineIndex: (NSInteger *)pActualLineIndex;

@end










