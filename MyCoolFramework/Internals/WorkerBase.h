//
//  Worker.h
//  MyCoolFramework
//
//  Created by Daniel Dyre-Greensite on 1/29/16.
//  Copyright © 2016 Daniel Dyre-Greensite. All rights reserved.
//

#ifndef Worker_h
#define Worker_h

#include <thread>
#include <functional>

namespace DDG
{

class WorkerBase
{
public:
    WorkerBase() { }
    WorkerBase(const std::function<void(void *, int)>& func, void * cbArg, uint32_t period);
    virtual ~WorkerBase();
    
protected:
    virtual void doWork(void * cbPtr);
private:
    bool isRunning();
    std::thread * m_workerThread;
    std::function<void(void *, int)> m_PeriodicFunc;
    uint32_t m_PeriodMs;
    std::mutex m_Mutex;
    bool m_Running;
};

}
#endif /* Worker_h */