<h2>STUN protocol implementation for iOS</h2>

This is a Session Traversal Utilities for NAT (STUN)  protocol implementation for iOS.
Original specification: [http://tools.ietf.org/html/rfc5389](http://tools.ietf.org/html/rfc5389)

<h2>How it works</h2>

1.  Import **STUNClient** and **GCDAsyncUdpSocket** classes:

        #import "GCDAsyncUdpSocket.h"
        #import "STUNClient.h"  

2. Add **STUNClientDelegate** protocol to your class:

        @interface MyClass : NSObject <STUNClientDelegate>{

3. Create instances of **GCDAsyncUdpSocket** and **STUNClient** classes. Perform method **requestPublicIPandPortWithUDPSocket:delegate:** and pass to it udp socket & delegate:

        GCDAsyncUdpSocket *udpSocket = [[GCDAsyncUdpSocket alloc] initWithDelegate:self delegateQueue:dispatch_get_main_queue()];

        STUNClient *stunClient = [[STUNClient alloc] init];
        [stunClient requestPublicIPandPortWithUDPSocket:udpSocket delegate:self];

4. Catch result in delegate's method **-(void)didReceivePublicIPandPort:(NSDictionary *) data**:

        -(void)didReceivePublicIPandPort:(NSDictionary *) data{
            NSLog(@"Public IP=%@, public Port=%@, NAT is Symmetric: %@", [data objectForKey:publicIPKey],
            [data objectForKey:publicPortKey], [data objectForKey:isNATTypeSymmetric]);
        }

5. See in log:

        2012-09-20 15:55:31.160 STUN[19255:f803] Public IP=52.177.223.158, public Port=42483

6. Start send Indication messages:

        [stunClient startSendIndicationMessage];

7. Injoit!