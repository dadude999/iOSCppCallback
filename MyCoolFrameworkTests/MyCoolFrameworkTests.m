//
//  MyCoolFrameworkTests.m
//  MyCoolFrameworkTests
//
//  Created by Daniel Dyre-Greensite on 1/29/16.
//  Copyright © 2016 Daniel Dyre-Greensite. All rights reserved.
//

#import <XCTest/XCTest.h>

#import <MyCoolFramework.h>

@interface MyCoolFrameworkTests : XCTestCase<CallbackProtocol>

@end

@implementation MyCoolFrameworkTests

- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

-(void)callbackMethod:(NSInteger)receivedInt
{
    NSLog(@"The int value received from C++ is %li.", (long)receivedInt);
}

- (void)testRunPeriodicWork
{
    Worker_ObjC * testWorker = [[Worker_ObjC alloc] initWithCallbackObject:self
                                                                 andTiming:1000];
    [testWorker start];
//    [testWorker start]; // no effect, just prints warning
    sleep(5);
    [testWorker stop];
}

@end
