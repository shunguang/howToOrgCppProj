message("\n BEG: src/libUtil/CMakeLists.txt")

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
set(target Util)
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
# Create the cloudGeoUtil Library
########################################################################
add_library(${target} STATIC
	src/AppBagRead.cpp
	src/AppBagWrite.cpp
	src/CapImg.cpp
	src/CRC.cpp
	src/CvUtilFuncs.cpp
	src/FileUtil.cpp
	src/Roi.cpp
	src/Uint8Stream.cpp
	src/UtilFuncs.cpp 
	)		

########################################################################
# Include directories
########################################################################
target_include_directories(${target} PUBLIC
	${pkg_inc_dirs}
	${src_dir}
)
message("\n END: src/libUtil/CMakeLists.txt")
