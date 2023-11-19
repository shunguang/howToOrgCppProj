message("\n BEG: src/libUtil/CMakeLists.txt")
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
# figure out pkg_root_dir, pkg_lib_dir, and pkg_bin_dir, 
#            src_root_dir, src_lib_dir, and appbin_dir
########################################################################
if(NOT DEFINED pkg_root_dir)
   #build from howToOrgCppProj/src/build
	set(pkg_root_dir "${CMAKE_CURRENT_SOURCE_DIR}/../../pkg" ) #howToOrgCppProj/pkg
	set(pkg_lib_dir "${pkg_root_dir}/build/lib")		          #howToOrgCppProj/pkg/build/lib
	set(pkg_bin_dir "${pkg_root_dir}/build/bin")		          #howToOrgCppProj/pkg/build/bin
	set(pkg_inc_dirs                                      #pkg_inc_dirs is a list
		${pkg_root_dir}/spdlog/include 
		${pkg_root_dir}/crossguid/include
	)

   message(pkg_root_dir="${pkg_root_dir}")
   message(pkg_lib_dir="${pkg_lib_dir}")
   message(pkg_bin_dir="${pkg_bin_dir}")  
   message("pkg_inc_dirs=${pkg_inc_dirs}")  #this is the only right way to print a list
endif()
if(NOT DEFINED src_root_dir)
   #build from howToOrgCppProj/src/build
	set(src_root_dir "${CMAKE_CURRENT_SOURCE_DIR}/.." )
   	set(src_lib_dir "${PROJECT_BINARY_DIR}/lib")
   	set(src_bin_dir "${PROJECT_BINARY_DIR}/bin")
	message(src_root_dir="${src_root_dir}")
	message(src_lib_dir="${src_lib_dir}")
	message(src_bin_dir="${src_bin_dir}")
endif()

# CMAKE_ARCHIVE_OUTPUT_DIRECTORY control the output dir of static libs
# CMAKE_LIBRARY_OUTPUT_DIRECTORY control the output dir of dynamic/dll libs
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${src_lib_dir}")   
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${src_lib_dir}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${src_bin_dir}")

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
message("pkg_inc_dirs=${pkg_inc_dirs}") 
message(src_root_dir="${src_root_dir}")
target_include_directories(${target} PUBLIC
	${pkg_inc_dirs}
	${src_root_dir}
)
message("\n END: src/libUtil/CMakeLists.txt")