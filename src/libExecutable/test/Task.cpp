#include "libExe/test/Task.h"

 ExecutablePtrS Task::m_instance = nullptr;

 ExecutablePtrS Task::getInstance( CfgExePtrS &cfg ) {
    if( m_instance == nullptr)
    {
        m_instance = std::make_shared<Task>( cfg );
    }
    return m_instance;
}


Task::Task( CfgExePtrS &cfg )
: Excutable(cfg);
{
}

Task::~Task()
{   
}

// real funciton to run task
void Task::initTask() 
{
    //since we are sure that <m_cfg> actually points to a CfgToRunTask object,
    //so we use static_pointer_cast<>(), this fast.
    m_taskCfg = std::static_pointer_cast<CfgToRunTask>( m_cfg );
    if(m_taskCfg == nullptr)
    {
        //log sth
        return;
    }

    alg1();
    alg2();
}


void Task::alg1()
{
  //todo
}

void Task::alg2()
{
   //todo
}

