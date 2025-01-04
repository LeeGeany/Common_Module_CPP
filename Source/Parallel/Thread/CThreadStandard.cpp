/**
 * @file CThreadStandard.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-04
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <Parallel/Thread/CThreadStandard.h>

namespace Parallel 
{
    CThread::CThread()
    : m_thread(&CThread::Process, this)
    {

    }

    CThread::~CThread() noexcept
    {
        m_thread.join();
    }

    void CThread::Join()
    {
        m_thread.join();
    }
    
    bool CThread::Joinable()
    {
        return m_thread.joinable();
    }

    void CThread::Detach()
    {
        m_thread.detach();
    }

    void CThread::Process()
    {
        try
        {
            OnProcess();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }   
    }

    void CThread::OnProcess()
    {
        std::cout << "Default Thread!! Make Your Own Thread!\n";
    }
} /* namespace Parallel */