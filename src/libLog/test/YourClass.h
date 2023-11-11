#pragma once

#include "libLog/include/AppLog.h"
class YourClass{
	public:
		YourClass();
		void foo();

    protected:
        int xyz{0}; 

	protected:
        ADD_SPD_LOG(YuorClass)
};

