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
#include <iostream>

namespace DDG
{

template<typename T>
class WorkerBase
{
public:
    WorkerBase() { }
    WorkerBase(const std::function<void(void *, T)>& func, void * cbArg, uint32_t period) :
    m_Running(true), m_PeriodicFunc(func), m_PeriodMs(period)
    {
        // RAII
        m_workerThread = new std::thread(&WorkerBase::doWork, this, cbArg);
    }
    virtual ~WorkerBase()
    {
        std::cout << "Destructor!\n";
        // cleanup
        m_Mutex.lock();
        m_Running = false;
        m_Mutex.unlock();
        if(m_workerThread->joinable())
        {
            m_workerThread->join();
        }
        delete m_workerThread;
    }
    
protected:
    virtual void doWork(void * cbPtr) = 0;
    bool isRunning()
    {
        bool result = false;
        m_Mutex.lock();
        result = m_Running;
        m_Mutex.unlock();
        
        return result;
    }
    std::function<void(void *, T)> m_PeriodicFunc;
    uint32_t GetPeriod() { return m_PeriodMs; }
private:
    std::thread * m_workerThread;
    uint32_t m_PeriodMs;
    std::mutex m_Mutex;
    bool m_Running;
};

}
#endif /* Worker_h */