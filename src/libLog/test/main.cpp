#include "libLog/include/AppLog.h"
#include "YourClass.h"
void logUsageExamples();
int main()
{  
    setupAppLogger( "./log.txt",  "myApp", spdlog::level::debug);

    logUsageExamples(); 

    YourClass x;
    x.foo();
    //do somethting
}


void logUsageExamples()
{
	//init: in your main()  call setupappLogger() 
	//setupappLogger( "./mylog.txt", "MyDefaultKeyWord", 0);

	//option 1: printf() style  --  in any part of your code you can call any of the following fucntions
	int x = 10;
	float y = 3.5;
	//log messages with "MyDefaultKeyWord" 
	appLog("msg1");
	appLog("abc=%d, efg=%f", x++, y);
	appErr("abc=%d, efg=%f", x++, y);
	appDebug("abc=%d, efg=%f", x++, y);
	appAssert(true, "abc=%d, efg=%f", x++, y);
	appAssert(false, "abc=%d, efg=%f", x++, y);

	//log messages with  "AnotherKeyWord"
	std::string keyword = "AnotherKeyWord";
	appLog2(keyword, "msg1");
	appInfo2(keyword, "abc=%d, efg=%f", x++, y);
	appErr2(keyword, "abc=%d, efg=%f", x++, y);
	appDebug2(keyword, "abc=%d, efg=%f", x++, y);
	appAssert2(true, keyword, "abc=%d, efg=%f", x++, y);
	appAssert2(false, keyword, "abc=%d, efg=%f", x++, y);
}

