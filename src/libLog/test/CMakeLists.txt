########################################################################
# version requirements
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
set(target appLogTest)
cmake_minimum_required(VERSION ${required_cmake_ver})
project(${target} LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD ${required_cxx_ver})

########################################################################
# figure out pkg_dir which will be used as a reference of install folder:
#  pkg/install/lib/
########################################################################
if(NOT DEFINED pkg_inc_dirs)
   message( FATAL_ERROR "pkg_inc_dirs is not defined, you need to run libLog/CMakeList.txt with -DAPPLOG_TESTS=1")
endif()
if(NOT DEFINED app_lib_dir)
   message( FATAL_ERROR "app_lib_dir is not defined, you need to run libLog/CMakeList.txt with -DAPPLOG_TESTS=1")
endif()
if(NOT DEFINED app_bin_dir)
   message( FATAL_ERROR "app_bin_dir is not defined, you need to run libLog/CMakeList.txt with -DAPPLOG_TESTS=1")
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
message(STATUS ${CMAKE_BUILD_TYPE})


########################################################################
# set precompile flags if need
########################################################################
#add_definitions(-DXYZ)

########################################################################
# Create the LoggingUtils Library
########################################################################
add_executable(${target}
	main.cpp
	YourClass.cpp
	)

target_include_directories(${target} PUBLIC
   ${pkg_inc_dirs}
   ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_directories(${target} PUBLIC
   ${app_lib_dir}
   )

target_link_libraries(${target} PUBLIC
   appLog
)
