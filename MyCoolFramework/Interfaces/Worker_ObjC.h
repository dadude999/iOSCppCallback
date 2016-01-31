//
//  Worker_ObjC.h
//  MyCoolFramework
//
//  Created by Daniel Dyre-Greensite on 1/29/16.
//  Copyright © 2016 Daniel Dyre-Greensite. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "CallbackProtocol.h"

// THIS CLASS IS NOT THREAD SAFE
@interface Worker_ObjC : NSObject

-(id)initWithCallbackObject:(id<CallbackProtocol>)callback
                  andTiming:(NSUInteger)interval;
-(void)start;
-(void)stop;

@end