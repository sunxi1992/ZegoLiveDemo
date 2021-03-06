//
//  ZegoVideoCapture.h
//  zegoavkit
//
//  Copyright © 2016 Zego. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#elif TARGET_OS_MAC
#import <AppKit/AppKit.h>
#endif


@protocol ZegoVideoCaptureClientDelegate <NSObject>
- (void)destroy;
- (void)onIncomingCapturedData:(nullable CVImageBufferRef)image withPresentationTimeStamp:(CMTime)time;
- (void)onError:(nullable NSString*)reason;
- (void)onTakeSnapshot:(nonnull CGImageRef)image;
@end

@protocol ZegoVideoCaptureDevice <NSObject>

- (void)allocateAndStart:(nonnull id<ZegoVideoCaptureClientDelegate>) client;
- (void)stopAndDeAllocate;
- (int)startCapture;
- (int)stopCapture;
- (int)setFrameRate:(int)framerate;
- (int)setWidth:(int)width andHeight:(int)height;
- (int)setFrontCam:(int)bFront;
#if TARGET_OS_IPHONE
- (int)setView:(UIView* _Nullable )view;
#elif TARGET_OS_MAC
- (int)setView:(NSView* _Nullable )view;
#endif
- (int)setViewMode:(int)mode;
- (int)setViewRotation:(int)rotation;
- (int)setCaptureRotation:(int)rotaion;
- (int)startPreview;
- (int)stopPreview;
- (int)enableTorch:(bool)enable;
- (int)takeSnapshot;
- (int)setPowerlineFreq:(unsigned int)freq;

@end

@protocol ZegoVideoCaptureFactory <NSObject>

- (nonnull id<ZegoVideoCaptureDevice>)create:(nonnull NSString*)deviceId;
- (void)destroy:(nonnull id<ZegoVideoCaptureDevice>)device;

@end

