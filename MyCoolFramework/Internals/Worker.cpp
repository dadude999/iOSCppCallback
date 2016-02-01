//
//  Worker.cpp
//  MyCoolFramework
//
//  Created by Daniel Dyre-Greensite on 1/29/16.
//  Copyright © 2016 Daniel Dyre-Greensite. All rights reserved.
//

#include "WorkerBase.h"

#include <iostream>

namespace DDG
{
    WorkerBase::WorkerBase(const std::function<void(void *, int)>& func, void * cbArg, uint32_t period) :
    m_Running(true), m_PeriodicFunc(func), m_PeriodMs(period)
    {
        // RAII
        m_workerThread = new std::thread(&WorkerBase::doWork, this, cbArg);
    };
    
    void WorkerBase::doWork(void * cbPtr)
    {
        int x = 0;
        while(isRunning())
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(m_PeriodMs));
            if(isRunning())
            {
                x++;
                m_PeriodicFunc(cbPtr, x);
            }
        }
        std::cout << "Worker thread exiting...\n";
    }
    
    bool WorkerBase::isRunning()
    {
        bool result = false;
        m_Mutex.lock();
        result = m_Running;
        m_Mutex.unlock();
        
        return result;
    }
    
    WorkerBase::~WorkerBase()
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
}