/**
 * @file IProcess.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-04
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __PARALLEL_THREAD_IPROCESS_H__
#define __PARALLEL_THREAD_IPROCESS_H__

namespace Parallel
{
    class IProcess
    {
    public:
        IProcess() = default;

    protected:
        virtual void OnProcess()=0;
    };
} /* namespace parallel */
#endif /* __PARALLEL_THREAD_IPROCESS_H__ */