//
//  STUNClient.m
//  STUN
//
//  Created by IgorKh on 9/19/12.
//  Copyright (c) 2012 quickblox. All rights reserved.
//

#import "STUNClient.h"

@implementation STUNClient

- (void)requestPublicIPandPortWithDelegate:(id<STUNClientDelegate>)_delegate{
    // create socket
    udpSocket = [[GCDAsyncUdpSocket alloc] initWithDelegate:self delegateQueue:dispatch_get_main_queue()];
    
    delegate = _delegate;
}


#pragma mark -
#pragma mark GCDAsyncUdpSocketDelegate

/**
 * Called when the socket has received the requested datagram.
 **/
- (void)udpSocket:(GCDAsyncUdpSocket *)sock didReceiveData:(NSData *)data
      fromAddress:(NSData *)address
withFilterContext:(id)filterContext{
    
    
    // notify delegate
    if([delegate respondsToSelector:@selector(didReceivePublicIPandPort:)]){
        [delegate didReceivePublicIPandPort:nil];
    }
}

@end
