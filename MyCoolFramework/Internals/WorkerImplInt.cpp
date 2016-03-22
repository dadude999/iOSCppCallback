//
//  WorkerImplInt.cpp
//  MyCoolFramework
//
//  Created by Daniel Dyre-Greensite on 3/9/16.
//  Copyright © 2016 Daniel Dyre-Greensite. All rights reserved.
//

#include "WorkerImplInt.h"

namespace DDG
{

void WorkerImplInt::doWork(void * cbPtr)
{
    int x = 0;
    while(isRunning())
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(m_PeriodMs));
        if(isRunning())
        {
            x++;
            m_CallbackFunc(cbPtr, x);
        }
    }
    std::cout << "Worker thread exiting...\n";
}

}