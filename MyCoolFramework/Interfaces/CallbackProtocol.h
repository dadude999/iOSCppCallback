//
//  CallbackProtocol.h
//  MyCoolFramework
//
//  Created by Daniel Dyre-Greensite on 1/30/16.
//  Copyright © 2016 Daniel Dyre-Greensite. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol CallbackProtocol <NSObject>

@required

-(void)callbackMethod:(NSInteger)receivedInt;

@end