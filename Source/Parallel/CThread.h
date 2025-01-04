/**
 * @file CThread.h
 * @author jinhee.lee (tjrgl@naver.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-04
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __PARALLEL_THREAD_CTHREAD_H__
#define __PARALLEL_THREAD_CTHREAD_H__

#include "Thread/CThreadStandard.h"

#ifdef PTHREAD
    #include "CThreadLinux.h"
#elif STANDARD
    #include "CThreadPStandard.h"
#endif

namespace Thread
{
    typedef Parallel::CThread jh_thread_t;

    template<typename T>
    T * JH_Thread_Create()
    {
        std::unique_ptr<T> ins = std::make_unique<T>();
        return ins.release();
    }

    void JH_Thread_Join(jh_thread_t * thread)
    {
        thread->Join();
    }

    void JH_Thread_Detach(jh_thread_t * thread)
    {
        thread->Detach();
    }

    bool JH_Thread_Joinable(jh_thread_t * thread)
    {
        return thread->Joinable();
    }

} /* namespace Parallel */

#endif /* __PARALLEL_THREAD_CTHREAD_H__ */