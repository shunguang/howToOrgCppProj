message("\n BEG: howToOrgCppProj/CMakeLists.txt")
########################################################################
#  The Topest Setup
########################################################################
list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(helper_macros)

set_required_vers()
print_required_vers()

cmake_minimum_required(VERSION ${required_cmake_ver}) 
project(howToOrgCppProj LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD ${required_cxx_ver})


########################################################################
# print flags set by cmake command: 
# >cmake ../
########################################################################
message(ENABLE_CUDA="${ENABLE_CUDA}")
message(ENABLE_TEST="${ENABLE_TEST}")
if (ENABLE_CUDA)
	message("cuda enabled")
else()	
	message("cuda is disabled")
endif()

########################################################################
# call macros and print params
########################################################################
set_build_params()
print_build_params()

set_build_dirs()
print_build_dirs()

########################################################################
# Find packages
########################################################################
find_package(OurBoost REQUIRED)
if (NOT Boost_FOUND)
    message(FATAL_ERROR "Cannot find boost, uou might need to run 'sudo apt-get install boost' or similar")
endif()

find_package(GTest REQUIRED)
if(NOT GTest_FOUND)
    message(FATAL_ERROR "canor find google test")
endif(NOT GTest_FOUND)


########################################################################
# Compiler specific setup
########################################################################
if (ENABLE_CUDA)
	add_definitions(-DHAVE_OPENMP)
	add_definitions(-DGUID_LIBUUID)
	add_definitions(-DENABLE_CUDA)
else ()
	add_definitions(-Wall)
	add_definitions(-Wextra)
endif()
#add_definitions(-std=c++17)
#add_definitions(-DCMAKE_CXX_COMPILER=clang)

########################################################################
# add our pkg/ and src/ to build
########################################################################
add_subdirectory(pkg)
add_subdirectory(src)
message("\n END: howToOrgCppProj/CMakeLists.txt")
