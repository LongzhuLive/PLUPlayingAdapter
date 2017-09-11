//
//  PLUPlayResolution.h
//  PLUVod
//
//  Created by plu-dev on 15/8/24.
//  Copyright (c) 2015年 DarrenYau. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PLUPlayResolution : NSObject

@property (nonatomic, assign, readonly) NSInteger resolutionLevel;
@property (nonatomic, strong) NSString *resolutionName;
@property (nonatomic, strong) NSString *resolutionNickName;
@property (nonatomic, strong) NSString *pluStreamUrl;

//原始PlayLine,//5-原画，4-蓝光，3-超清，2-高清，1-普清
@property (nonatomic, assign) NSInteger pluRateLevel;


- (void)fromPluRateLevel:(NSInteger)rateLevel;
- (void)fromPluMediaStreamResolution:(NSString *)resolution;

- (NSString *)resolutionNumDisplay;

@end
