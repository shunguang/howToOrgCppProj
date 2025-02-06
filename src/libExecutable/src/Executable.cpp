#include <csignal>
#include "libExecutable/include/Executable.h"
#ifdef _WIN32
    #include <conio.h>  // For Windows-only input handling
#else
    #include <unistd.h>  // For sleep() on Linux/macOS
#endif

static void Excutable::changeLogLevel();
{
        CfgExe::m_logLevel +=  1;
        if ( CfgExe::m_logLevel>5 ) {
            CfgExe::m_logLevel = 0;
        }
        //g_appLog.set_level(Excutable::m_logLevel);
}

// Protected constructor
Excutable::Excutable(CfgExePtrS &cfg)
: m_cfg( cfg )
{
}


void Excutable::run()
{   
    //update progId and progGuid
    m_cfg->generateProgId();
    m_cfg->generateGuid();

    //start log
    if( cfg.makeLog ){
    // ...
    }


    //change log level throug signal
    //liuux:    use pkill <signal> <processName>
    //windows:  use ctrl + C
#if _WIN32   
    std::signal(SIGINT, Excutable::changeLogLevel);
#else
    std::signal(SIGUSR1, Excutable::changeLogLevel);
#endif

    //call the virtual fucntion initTask()
    initTask();

    //log a star message
}
