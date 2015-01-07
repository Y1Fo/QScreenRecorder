//
//  QRecordable.h
//  CaptureRecord
//
//  Created by Jolin He on 14-1-2.
//  Copyright (c) 2014年 Jolin He. All rights reserved.
//

#import <CoreMedia/CoreMedia.h>

/*!
 The QRecordable protocol defines a renderable view with a fixed size.
 
 If the QRecordable needs to start and stop, they can define those methods and will be notified of start and stop events.
 
 @see QScreenRecorder
 @see QCameraRecorder
 @see QUIViewRecorder
 */
@protocol QRecordable <NSObject>

/*!
 Render the recordable in the specified context.
 @param context Context to render in
 @param videoSize Video size
 */
- (void)renderInContext:(CGContextRef)context videoSize:(CGSize)videoSize;

/*!
 @result The size of the recordable. This size must be fixed and is required before any rendering begins.
 */
- (CGSize)size;

@optional

/*!
 When the recording is started, we will notify the recordable.
 @param error Out error
 @result YES if started successfully, NO otherwise
 */
- (BOOL)start:(NSError **)error;

/*!
 When the recording is stopped, we will notify the recordable.
 @param error Out error
 @result YES if stopped successfully, NO otherwise
 */
- (BOOL)stop:(NSError **)error;

@end

/*!
 The QAudioWriter protocol defines that a class can record audio. 
 
 @see QVideoWriter
 */
@protocol QAudioWriter <NSObject>
/*!
 Append audio sample buffer.
 @param sampleBuffer Audio sample buffer
 */
- (BOOL)appendSampleBuffer:(CMSampleBufferRef)sampleBuffer;
@end
