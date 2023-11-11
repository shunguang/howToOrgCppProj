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
set(target Process)
cmake_minimum_required(VERSION ${required_cmake_ver})
project(${target} LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD ${required_cxx_ver})

########################################################################
# figure out src_dir, app_lib_dir, and app_bin_dir
########################################################################
if(NOT DEFINED src_dir)
	set(src_dir "${CMAKE_CURRENT_SOURCE_DIR}/src" )
	message(src_dir="${src_dir}")
endif()
if(NOT DEFINED app_lib_dir)
    set(app_lib_dir "${PROJECT_BINARY_DIR}/lib")
	message(app_lib_dir="${app_lib_dir}")
endif()
if(NOT DEFINED app_bin_dir)
    set(app_bin_dir "${PROJECT_BINARY_DIR}/bin")
	message(app_bin_dir="${app_bin_dir}")
endif()

# CMAKE_ARCHIVE_OUTPUT_DIRECTORY control the output dir of static libs
# CMAKE_LIBRARY_OUTPUT_DIRECTORY control the output dir of dynamic/dll libs
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${app_lib_dir}")   
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${app_lib_dir}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${app_bin_dir}")

########################################################################
# Select the release build type by default to get optimization flags
########################################################################
if(NOT CMAKE_BUILD_TYPE)
   set(CMAKE_BUILD_TYPE "Release")
   message(STATUS "Build type not specified: defaulting to release.")
endif(NOT CMAKE_BUILD_TYPE)
set(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} CACHE STRING "")

########################################################################
#  check if pkg_inc and src_inc are defined by top level CMakeLists.txt
########################################################################
if(NOT DEFINED pkg_inc_dirs)
	message( FATAL_ERROR "pkg_inc_dirs not defined, cmake exit!" )
	#todo: find <pkg_inc_dirs> from ${CMAKE_CURRENT_SOURCE_DIR}
endif()

########################################################################
# Create the cloudGeoUtil Library
########################################################################
add_library(${target} STATIC
	src/Proc1.cpp
	src/Proc2.cpp
	)		

########################################################################
# Include directories
########################################################################
target_include_directories(${target} PUBLIC
	${pkg_inc_dirs}
	${src_dir}
)
