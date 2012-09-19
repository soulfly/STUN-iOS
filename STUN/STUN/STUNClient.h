//
//  STUNClient.h
//  STUN
//
//  Created by IgorKh on 9/19/12.
//  Copyright (c) 2012 quickblox. All rights reserved.
//
//
// This a simple and ad-hoc STUN client (UDP), partially compliant with RFC5389
// it gets the public(reflective) IP and Port of a UDP socket
//
// Documentation http://tools.ietf.org/html/rfc5389#page-10
//

#import <Foundation/Foundation.h>
#import "GCDAsyncUdpSocket.h"

// STUN default port
#define SNUTPort 3478

// The following is a list of some public/free stun servers
// some of them send the trasport address as both MAPPED-ADDRESS and XOR-MAPPED-ADDRESS -
// and others send only MAPPED-ADDRESS
// All list - http://www.tek-tips.com/faqs.cfm?fid=7542
#define SNUTServer @"stun.ekiga.net" 

// For explanations about the following variables see the section 7.2.1 of RFC5389
#define rc 7    // maximum number of the requests to send
#define rm 16   // used for calculating the last receive timeout
#define rto 0.5 // Retransmission TimeOut


#define publicIPKey @"publicIPKey"
#define publicPortKey @"publicPortKey"


@protocol STUNClientDelegate;
@interface STUNClient : NSObject <GCDAsyncUdpSocketDelegate>{
    GCDAsyncUdpSocket *udpSocket;
    id<STUNClientDelegate>delegate;
}

- (void)requestPublicIPandPortWithDelegate:(id<STUNClientDelegate>)delegate;

@end

@protocol STUNClientDelegate <NSObject>
-(void)didReceivePublicIPandPort:(NSDictionary *) ipAndPort;
@end