//
//  WorkerBase.h
//  MyCoolFramework
//
//  Created by Daniel Dyre-Greensite on 1/29/16.
//  Copyright © 2016 Daniel Dyre-Greensite. All rights reserved.
//

#ifndef WorkerBase_h
#define WorkerBase_h

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
    WorkerBase(const std::function<void(void *, T)>& func, void * cbArg) :
    m_Running(true), m_CallbackFunc(func)
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
    std::function<void(void *, T)> m_CallbackFunc;
private:
    std::thread * m_workerThread;
    std::mutex m_Mutex;
    bool m_Running;
};

}
#endif /* WorkerBase_h */