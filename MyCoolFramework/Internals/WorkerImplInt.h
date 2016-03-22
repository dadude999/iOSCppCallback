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
    WorkerImplInt(const std::function<void(void *, int)>& func, void * cbArg, uint32_t period) : WorkerBase(func, cbArg), m_PeriodMs(period) { }
private:
    WorkerImplInt() { }
    void doWork(void * cbPtr);
    uint32_t m_PeriodMs;
};
    
}
#endif /* WorkerImplInt_h */
