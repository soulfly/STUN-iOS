<h2>STUN protocol implementation for iOS</h2>

This is a Session Traversal Utilities for NAT (STUN)  protocol implementation for iOS.
Original specification: [http://tools.ietf.org/html/rfc5389](http://tools.ietf.org/html/rfc5389)

<h2>How it works</h2>

1.  Import **STUNClient** class:

        #import "STUNClient.h"  

2. Add **STUNClientDelegate** protocol to your class:

        @interface MyClass : NSObject <STUNClientDelegate>{

3. Create an instance of **STUNClient** class & perform method **requestPublicIPandPortWithDelegate**:

        STUNClient *stunClient = [[STUNClient alloc] init];
        [stunClient requestPublicIPandPortWithDelegate:self];

4. Catch result in delegate's method **-(void)didReceivePublicIPandPort:(NSDictionary *) ipAndPort**:

        -(void)didReceivePublicIPandPort:(NSDictionary *) ipAndPort{
            NSLog(@"Public IP=%@, public Port=%@", [ipAndPort objectForKey:publicIPKey], 
                    [ipAndPort objectForKey:publicPortKey]);
        }

5. See in log:

        2012-09-20 15:55:31.160 STUN[19255:f803] Public IP=52:177:223:158, public Port=42483

6. Injoit!