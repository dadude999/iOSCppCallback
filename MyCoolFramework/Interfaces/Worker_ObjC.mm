//
//  Worker_ObjC.mm
//  MyCoolFramework
//
//  Created by Daniel Dyre-Greensite on 1/29/16.
//  Copyright © 2016 Daniel Dyre-Greensite. All rights reserved.
//

#import "Worker_ObjC.h"

#include "Internals/Worker.h"

// free function to be used as callback from C++
void cbPassThru(void * cbObject, int value)
{
    id<CallbackProtocol> objToCall = (__bridge id<CallbackProtocol>)cbObject;
    [objToCall callbackMethod:[[NSNumber numberWithInt:value] integerValue]];
}

@interface Worker_ObjC()

@property(strong, nonatomic) id<CallbackProtocol> callbackObject;
@property(nonatomic) NSUInteger tickTime;

@end

@implementation Worker_ObjC

// private C++ class instance
DDG::WorkerBase * myWorker;

-(id)init
{
    self = [super init];
    myWorker = NULL;
    return self;
}

-(id)initWithCallbackObject:(id<CallbackProtocol>)callbackObj
                  andTiming:(NSUInteger)interval
{
    self = [self init];
    self.callbackObject = callbackObj;
    self.tickTime = interval;
    return self;
}

-(void)start
{
    if(myWorker != NULL)
    {
        NSLog(@"Ooops - we're already running! Please call stop first!");
    }
    else
    {
        myWorker = new DDG::WorkerBase(&cbPassThru, (__bridge void *) self.callbackObject, [[NSNumber numberWithInteger:self.tickTime] intValue]);
    }
}

-(void)stop
{
    // cleanup unmanaged memory (will stop thread)
    if(myWorker != NULL)
    {
        delete myWorker;
        myWorker = NULL;
    }
}

-(void)dealloc
{
    [self stop];
}

@end
