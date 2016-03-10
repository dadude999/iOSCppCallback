//
//  WorkerImplInt.h
//  MyCoolFramework
//
//  Created by Daniel Dyre-Greensite on 3/9/16.
//  Copyright © 2016 Daniel Dyre-Greensite. All rights reserved.
//

#ifndef WorkerImplInt_h
#define WorkerImplInt_h

#include "WorkerBase.h"

namespace DDG
{
    
class WorkerImplInt : public WorkerBase<int>
{
public:
    WorkerImplInt() { }
    WorkerImplInt(const std::function<void(void *, int)>& func, void * cbArg, uint32_t period) : WorkerBase(func, cbArg, period) { }
private:
    void doWork(void * cbPtr);
};
    
}
#endif /* WorkerImplInt_h */
