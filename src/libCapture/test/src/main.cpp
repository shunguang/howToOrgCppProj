// main.cpp
#include <iostream>
#include <string>
#include "libLog/include/AppLog.hpp"
#include "gtest/gtest.h"

#include "libUtil/include/Util.h"

void print_usage();

int main(int argc, char** argv)
{
  if (argc == 1) {
    print_usage();
    return 0;
  }

  //--- set up logger ----------
  std::string  logFilePath = "./log.txt";
#ifdef _WIN32
  logFilePath = "c:/temp/log.txt";
#endif

  setupCgeLogger(logFilePath, CloudGeoSettings::default_m_logger_name, 0);
  //logUsageExamples();

  testing::InitGoogleTest(&argc, argv);
    
  return RUN_ALL_TESTS();
}

void print_usage() {
  printf("test.exe --gtest_filter=APP_CapTest.test1*   --> will run test1\n");
  printf("test.exe --gtest_filter=APP_CapTest.test2*   --> will run test2\n");
  printf("test.exe --gtest_filter=APP*       --> will run  ALL test cases\n");
}

