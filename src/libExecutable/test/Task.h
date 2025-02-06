#pragma once

#include "libExecutable/include/Excutable.h"
#include "libExecutable/test/CfgToRunTask.h"

#include <thread>

class Task : public Excutable {
public:
    // Deleted copy constructor and assignment operator to enforce Singleton
    Task(const Task& ) = delete;
    Task& operator=(const Task&) = delete;

    //Static method to get the Singleton instance
    static ExecutablePtrS getInstance( CfgExePtrS &cfg );

protected:
    //method to start this task
    virtual void initTask() override;

    // Private constructor to enforce Singleton
    Task( CfgExePtrS &cfg );
    ~Task();

private:
    void alg1();
    void alg2();

private:
    CfgToRunTaskPtrS m_taskCfg = nullptr;
    static ExecutablePtrS m_instance;
};
