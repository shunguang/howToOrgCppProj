// CfgExe.h
#pragma once

#include "libExecutable/include/CfgExe.h"

class CfgToRunTask : public CfgExe {
public:
    // Constructor
    CfgToRunTask() 
    : CfgExe(false, true)
    {       
    }

    // Destructor
    ~CfgToRunTask()=default;


    virtual std::string disp() final
    {
    }

    virtual std::string toString() const
    {       
    }

private:
    int taskParam1=0;
    float taskParam2=1.0;
};
typedef std::shared_ptr<CfgToRunTask> CfgToRunTaskPtrS;
