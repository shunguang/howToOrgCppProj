// YourClass.cpp
#include "YourClass.h"

YourClass::YourClass()
{
    //add log
    GET_SPD_LOG

    //othe stuff
}

void YourClass :: foo()
{
    int v1=10;
    float v2=50.5;
    m_logger->info("blabla v1={}, v2={}", v1, v2);
    m_logger->error("Error: v1={}, v2={}", v1, v2);
    m_logger->debug("Debug msg: v1={}, v2={}", v1, v2);
    m_logger->warn("warnning msg: v1={}, v2={}", v1, v2);
    m_logger->trace("trace msg: v1={}, v2={}", v1, v2);
    m_logger->critical("critical: v1={}, v2={}", v1, v2);
}
