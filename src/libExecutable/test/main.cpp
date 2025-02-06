// main.cpp
#include "libExe/test/Task.h"
#include "libExe/test/CfgToRunTask.h"

int main() 
{   
    //prepare the cfg to run this task
    const std::string logDir=".";
    const int logLevel = 2;
    CfgExePtrS taskCfg = std::make_shared<CfgToRunTask>( logDir, logLevel);
    taskCfg->disp();

    //create an instatnce and run task
    ExecutablePtrS task = Task::getInstance( taskCfg );
    task->run();

    return 0;
}



