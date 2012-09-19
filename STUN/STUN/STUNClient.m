//
//  STUNClient.m
//  STUN
//
//  Created by IgorKh on 9/19/12.
//  Copyright (c) 2012 quickblox. All rights reserved.
//

#import "STUNClient.h"
#include <stdlib.h>

@implementation STUNClient

- (void)requestPublicIPandPortWithDelegate:(id<STUNClientDelegate>)_delegate{
    // create socket
    udpSocket = [[GCDAsyncUdpSocket alloc] initWithDelegate:self delegateQueue:dispatch_get_main_queue()];
    
    delegate = _delegate;
    
    
    NSData *maddr = nil;   // mapped ip
    NSData *mport = nil;   // mapped port
    
    NSData *xmaddr = nil;  // xor mapped ip
    NSData *xmport = nil;  // xor mapped port
    
    
    NSData *msg_type = [NSData dataWithBytes:"\x00\x01" length:2]; // STUN binding request. A Binding request has class=0b00 (request) and
                                                                   // method=0b000000000001 (Binding)
    NSData *body_length = [NSData dataWithBytes:"\x00\x00" length:2]; // we have/need no attributes, so message body length is zero
    NSData *magic_cookie = [NSData dataWithBytes:"\x21\x12\xA4\x42" length:4]; // The magic cookie field MUST contain the fixed value 0x2112A442 in
                                                                               // network byte order.
    NSData *transaction_id = [self createNRundomBytes:12]; //  The transaction ID used to uniquely identify STUN transactions.

    // create final request
    NSMutableData *stun_request = [NSMutableData data];
    [stun_request appendData:msg_type];
    [stun_request appendData:body_length];
    [stun_request appendData:magic_cookie];
    [stun_request appendData:transaction_id];
    
    NSLog(@"stun_request=%@", stun_request);
}


#pragma mark -
#pragma mark Utils

/**
 * Generate random n bytes
 **/
-(NSData *)createNRundomBytes:(int)n{
    NSMutableData* theData = [NSMutableData dataWithCapacity:n];
    for( unsigned int i = 0 ; i < n ; ++i ){
        u_int32_t randomBits = arc4random();
        [theData appendBytes:(void*)&randomBits length:4];
    }
    return theData;
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
