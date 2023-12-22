# http://sysbio.rnet.missouri.edu/bdm_download/DeepRank_db_tools/tools/DNCON2/CCMpred/cmake_lib/FindUUID.cmake
# Try to find GTest
# Once done this will define
#  GTEST_FOUND
#  GTEST_INCLUDE_DIR
#  GTEST_LIBRARY
#  GTEST_MAIN_LIBRARY

set(GTest_FOUND "YES")

find_path(
  GTEST_INCLUDE_DIRS
  NAMES gtest/gtest.h
        gtest.h
  HINTS /usr/local/include
  PATHS /usr/local/include/include
        /usr/include
)

IF(NOT GTEST_INCLUDE_DIRS)
  SET(GTest_FOUND "NO")
  MESSAGE(STATUS "Failed to find GTEST headers")
ENDIF()

find_library(
  GTEST_LIBRARIES
  NAMES libgtest
        gtest
        lgtest
  HINTS /usr/lib64
  PATHS /usr/local/lib
        /usr/lib
        /usr/lib64
        /usr/include
)

IF(NOT GTEST_LIBRARIES)
  SET(GTest_FOUND "NO")
  MESSAGE(STATUS "Failed to find GTEST library")
ENDIF()

find_library(
  GTEST_MAIN_LIBRARIES
  NAMES libgtest_main
        gtest_main
        lgtest_main
  HINTS /usr/lib64
  PATHS /usr/local/lib
        /usr/lib
        /usr/lib64
        /usr/include
)

IF(NOT GTEST_MAIN_LIBRARIES)
  SET(GTest_FOUND "NO")
  MESSAGE(STATUS "Failed to find GTEST library")
ENDIF()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(GTest DEFAULT_MSG GTEST_LIBRARIES GTEST_INCLUDE_DIRS GTEST_MAIN_LIBRARIES)

mark_as_advanced(GTEST_INCLUDE_DIRS GTEST_LIBRARIES GTEST_MAIN_LIBRARIES)

message(STATUS  ${GTEST_INCLUDE_DIRS} " " ${GTEST_LIBRARIES} " " ${GTEST_MAIN_LIBRARIES})

message(GTest_FOUND="${GTest_FOUND}")
message(GTEST_INCLUDE_DIRS="${GTEST_INCLUDE_DIRS}")
message(GTEST_LIBRARIES="${GTEST_LIBRARIES}")
message(GTEST_MAIN_LIBRARIES="${GTEST_MAIN_LIBRARIES}")
