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

class Worker
{
public:
    Worker() { }
    Worker(const std::function<void(void *, int)>& func, void * argToPass, uint32_t period);
    virtual ~Worker();
    
private:
    void doWork(void * a);
    bool isRunning();
    std::thread * m_workerThread;
    std::function<void(void *, int)> m_PeriodicFunc;
    uint32_t m_PeriodMs;
    std::mutex m_Mutex;
    bool m_Running;
};

}
#endif /* Worker_h */