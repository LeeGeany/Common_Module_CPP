#ifndef __linux__
#define __linux__
int CommonProjectVersion[4] 	__attribute__((section("BuildVersion"))) = {0,0,0,1};
int CommonProjectBuildDate[4]	__attribute__((section("BUildDate"))) = {2024,5,15,1};
#endif

#include "Common.h"
#include "Source/Parallel/CThread.h"

class newThread : public CLONE_THREAD
{

};


int main(void)
{
    /* Example of Thread */
    Thread::jh_thread_t * thd1 = Thread::JH_Thread_Create();
    
    Thread::JH_Thread_Join(thd1);

    if(Thread::JH_Thread_Joinable(thd1))
    {
        Thread::JH_Thread_Join(thd1);
    }
    
    return 0;
}
