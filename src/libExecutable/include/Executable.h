#pragma once

#include <iostream>
#include <random>
#include <sstream>
#include <iomanip>
#include <string>
#include <mutex>
#include <memory>
#include <atomic>

#include "libExecutable/include/CfgExe.h"

class Excutable {
public:
    // Virtual Destructor
    virtual ~Excutable() = default;

    // Pure virtual functions to be implemented by derived classes
    void run();
    
    static void changeLogLevel();

protected:
    // Protected constructor to prevent direct instantiation
    Excutable( CfgExePtrS &cfg );
    virtual void initTask() =  0;

protected:
    CfgExePtrS    m_cfg;
};
typedef std::shared_ptr<Excutable> ExecutablePtrS;

