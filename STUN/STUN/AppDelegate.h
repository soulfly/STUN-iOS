//
//  AppDelegate.h
//  STUN
//
//  Created by Igor Khomenko on 9/19/12.
//  Copyright (c) 2012 Quickblox. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "STUNClient.h"
#import "GCDAsyncUdpSocket.h"

@interface AppDelegate : UIResponder <UIApplicationDelegate, STUNClientDelegate>{
    STUNClient *stunClient;
    GCDAsyncUdpSocket *udpSocket;
}

@end
