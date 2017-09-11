//
//  PLUFullScreenVideoViewController.h
//  TGA
//
//  Created by plu-dev on 16/2/22.
//  Copyright © 2016年 developer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class PLUVideoPlayer;

@interface PLUFullScreenVideoViewController : UIViewController

@property (nonatomic, assign) UIInterfaceOrientationMask orientationMask;
@property (nonatomic, assign) UIInterfaceOrientation preferredInterfaceOrientation;

@property (nonatomic, readonly) PLUVideoPlayer *videoPlayer;

-(instancetype)initWithVideoPlayer: (PLUVideoPlayer *)videoPlayer;

@end
