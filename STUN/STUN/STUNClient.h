//
//  STUNClient.h
//  STUN
//
//  Created by Igor Khomenko on 9/19/12.
//  Copyright (c) 2012 Quickblox. All rights reserved. Check our BAAS quickblox.com
//
//
// This a simple and ad-hoc STUN client (UDP), partially compliant with RFC5389
// it gets the public(reflective) IP and Port of a UDP socket
//
// Documentation http://tools.ietf.org/html/rfc5389#page-10
//
// From quickblox.com team with love!
//


#import <Foundation/Foundation.h>
#import "GCDAsyncUdpSocket.h"


// STUN default port
#define STUNPort 3478

// The following is a list of some public/free stun servers
// some of them send the trasport address as both MAPPED-ADDRESS and XOR-MAPPED-ADDRESS -
// and others send only MAPPED-ADDRESS
// All list - http://www.tek-tips.com/faqs.cfm?fid=7542
#define STUNServer @"stun.ekiga.net"

#define publicIPKey @"publicIPKey"
#define publicPortKey @"publicPortKey"
#define isNATTypeSymmetric @"isNATTypeSymmetric"

#define log 1
#define STUNLog(...) if (log) NSLog(__VA_ARGS__)


@protocol STUNClientDelegate;
@interface STUNClient : NSObject <GCDAsyncUdpSocketDelegate>{
    GCDAsyncUdpSocket *udpSocket;
    id<STUNClientDelegate>delegate;
    
    NSData *msgType;
    NSData *bodyLength;
    NSData *magicCookie;
    NSData *transactionId;
}

- (void)requestPublicIPandPortWithUDPSocket:(GCDAsyncUdpSocket *)socket delegate:(id<STUNClientDelegate>)delegate;

@end

@protocol STUNClientDelegate <NSObject>
-(void)didReceivePublicIPandPort:(NSDictionary *) data;
@end