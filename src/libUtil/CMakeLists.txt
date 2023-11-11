########################################################################
#  CMake for LibUtil
########################################################################

if(NOT DEFINED required_cmake_ver)
   set(required_cmake_ver 3.20)
   message(STATUS "required_cmake_ver not specified: set defaulting to ${required_cmake_ver}")
endif()
if(NOT DEFINED required_cxx_ver)
    set(required_cxx_ver 17)
    message(STATUS "required_cxx_ver set to ${required_cxx_ver}")
endif()

########################################################################
#  Project Setup
########################################################################
set(target Util)
cmake_minimum_required(VERSION ${required_cmake_ver})
project(${target} LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD ${required_cxx_ver})

########################################################################
# figure out pkg_dir, pkg_lib_dir, and pkg_bin_dir, 
#            app_src_dir, app_lib_dir, and appbin_dir
########################################################################
if(NOT DEFINED pkg_dir)
   #build from howToOrgCppProj/src/build
	set(pkg_dir "${CMAKE_CURRENT_SOURCE_DIR}/../../pkg" ) #howToOrgCppProj/pkg
	set(pkg_lib_dir "${pkg_dir}/build/lib")		         #howToOrgCppProj/pkg/build/lib
	set(pkg_bin_dir "${pkg_dir}/build/bin")		         #howToOrgCppProj/pkg/build/bin
	file( GLOB pkg_inc_dirs
		${pkg_dir}/spdlog/include 
	 )

   message(pkg_dir="${pkg_dir}")
   message(pkg_lib_dir="${pkg_lib_dir}")
   message(pkg_bin_dir="${pkg_bin_dir}")  
endif()
if(NOT DEFINED app_src_dir)
   #build from howToOrgCppProj/src/build
	set(app_src_dir "${CMAKE_CURRENT_SOURCE_DIR}/.." )
   	set(app_lib_dir "${PROJECT_BINARY_DIR}/lib")
   	set(app_bin_dir "${PROJECT_BINARY_DIR}/bin")
	message(app_src_dir="${app_src_dir}")
	message(app_lib_dir="${app_lib_dir}")
	message(app_bin_dir="${app_bin_dir}")
endif()

########################################################################
# Select the release build type by default to get optimization flags
########################################################################
if(NOT CMAKE_BUILD_TYPE)
   set(CMAKE_BUILD_TYPE "Release")
   message(STATUS "Build type not specified: defaulting to release.")
endif(NOT CMAKE_BUILD_TYPE)
set(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} CACHE STRING "")

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
