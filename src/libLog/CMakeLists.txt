message("\n BEG: src/libLog/CMakeLists.txt:")
#######################################################################
#  include macro and functions if have any
########################################################################
list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_CURRENT_SOURCE_DIR}/../../cmake)
include(helper_macros)

########################################################################
#  set required versions if need
########################################################################
if(NOT DEFINED set_required_vers_done)
	set_required_vers()
	print_required_vers()
endif()

########################################################################
#  Project Setup
########################################################################
set(target Log)
cmake_minimum_required(VERSION ${required_cmake_ver})
project(${target} LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD ${required_cxx_ver})

########################################################################
#  set building parameters
########################################################################
set_build_params()
if( NOT DEFINED  set_build_dirs_done)
   set_build_dirs(${CMAKE_CURRENT_BINARY_DIR})
   print_build_dirs()
endif()

set_output_dirs()
print_output_dirs()

########################################################################
# Create the LoggingUtils Library
########################################################################
add_library(${target} STATIC
	src/AppLog.cpp
	)

########################################################################
# Include directories
########################################################################
target_include_directories(${target} PUBLIC
   ${pkg_inc_dirs}    #all dependent folders in howToOrgCppProj/pkg
   ${src_dir}     #howToOrgCppProj/src
)

if (BUILD_LOG_TESTS)
   add_subdirectory(test)
endif()
message("\n END: src/libLog/CMakeLists.txt")
