#-------------------------------------------------
# FindSetCfg.cmake
# by shunguang.wu@gmail.com, 12/21/2023
#
#-------------------------------------------------
message("\n BEG: FindSetCfg.cmake")

########################################################################
# set up Build Type
########################################################################
# Select the release build type by default to get optimization flags
if(NOT CMAKE_BUILD_TYPE)
   set(CMAKE_BUILD_TYPE "Release")
   message(STATUS "Build type not specified: defaulting to release.")
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} CACHE STRING "")
message(STATUS ${CMAKE_BUILD_TYPE})
