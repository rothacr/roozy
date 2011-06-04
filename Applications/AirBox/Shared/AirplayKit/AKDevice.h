//
//  AKDevice.h
//  AirplayKit
//
//  Created by Andy Roth on 1/18/11.
//  Copyright 2011 Resource Interactive. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AsyncSocket.h"

@class AKDevice;

@protocol AKDeviceDelegate <NSObject>

@optional

- (void) device:(AKDevice *)device didSendBackMessage:(NSString *)message;

@end


@interface AKDevice : NSObject <AsyncSocketDelegate>
{
@private
	NSString *hostname;
	UInt16 port;
	id <AKDeviceDelegate> delegate;
	BOOL connected;
	AsyncSocket *socket;
	NSData *savedData;
	BOOL okToSend;
}

@property (nonatomic, readonly) NSString *displayName;
@property (nonatomic, retain) NSString *hostname;
@property (nonatomic) UInt16 port;
@property (nonatomic, assign) id <AKDeviceDelegate> delegate;
@property (nonatomic) BOOL connected; // Set to YES when the device is connected.
@property (nonatomic, retain) AsyncSocket *socket; // The socket used to transmit data. Only use for completely custom actions.

- (void) sendRawMessage:(NSString *)message; // Sends a raw HTTP string over Airplay.
- (void) sendContentURL:(NSString *)url;
- (void) sendImage:(UIImage *)image;
- (void) sendStop;
- (void) sendReverse;

- (UIImage *) highResImageFromImage:(UIImage *)lowImage;

@end
