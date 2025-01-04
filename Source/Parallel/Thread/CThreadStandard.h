/**
 * @file CThreadStandard.h@
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-04
 * 
 * @copyright Copyright (c) 2025
 * 
 */ 

#ifndef __PARALLEL_THREAD_CTHREADSTANDARD_H__
#define __PARALLEL_THREAD_CTHREADSTANDARD_H__

#include <Common.h>
#include <Parallel/Thread/IProcess.h>

namespace Parallel 
{
    class CThread : public IProcess
    {
    public:
        explicit CThread();
        virtual ~CThread() noexcept;

    public:
        void Join();
        bool Joinable();
        void Detach();

    private:
        void Process();

    protected:
        virtual void OnProcess() override;

    private:
        std::thread m_thread;
    };
} /* namespace Parallel */

#endif /* __PARALLEL_THREAD_CTHREADSTANDARD_H__ */