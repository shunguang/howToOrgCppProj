message("\n BEG: howToOrgCppProj/CMakeLists.txt")
########################################################################
#  The Topest Setup
########################################################################
set(required_cmake_ver 3.20)
set(required_cxx_ver 17)
cmake_minimum_required(VERSION ${required_cmake_ver}) 
project(howToOrgCppProj LANGUAGES CXX C)

########################################################################
# Build options
########################################################################
option(BUILD_SHARED_LIBS "Build using shared libraries" OFF) 

########################################################################
# figure out pkg_root_dir, pkg_lib_dir, pkg_bin_dir, pkg_inc_dirs,
#            src_root_dir, src_lib_dir, and appbin_dir
########################################################################
set(pkg_root_dir "${CMAKE_CURRENT_SOURCE_DIR}/pkg")          #howToOrgCppProj/pkg
set(pkg_lib_dir "${PROJECT_BINARY_DIR}/pkg/lib")		#howToOrgCppProj/build/pkg/lib
set(pkg_bin_dir "${PROJECT_BINARY_DIR}/pkg/bin")		#howToOrgCppProj/build/pkg/bin
set(pkg_inc_dirs                            			#pkg_inc_dirs is a list
	 ${pkg_root_dir}/spdlog/include 
	 ${pkg_root_dir}/crossguid/include
)

set(src_root_dir "${CMAKE_CURRENT_SOURCE_DIR}/src")      #howToOrgCppProj/src
set(src_lib_dir "${PROJECT_BINARY_DIR}/lib")			#howToOrgCppProj/build/lib
set(src_bin_dir "${PROJECT_BINARY_DIR}/bin")			#howToOrgCppProj/build/bin

message(CMAKE_CURRENT_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")
message(CMAKE_BINARY_DIR="${CMAKE_BINARY_DIR}")

message(pkg_root_dir=${pkg_root_dir})
message(pkg_lib_dir=${pkg_lib_dir})
message(pkg_bin_dir=${pkg_bin_dir})
message(pkg_inc_dirs="${pkg_inc_dirs}")

message(src_root_dir=${src_root_dir})
message(src_lib_dir=${src_lib_dir})
message(src_bin_dir=${src_bin_dir})

########################################################################
# print out our flags
########################################################################
message(ENABLE_CUDA="${ENABLE_CUDA}")
message(ENABLE_TEST="${ENABLE_TEST}")

########################################################################
# Find boost
########################################################################
if(UNIX AND EXISTS "/usr/lib64")
    list(APPEND BOOST_LIBRARYDIR "/usr/lib64")
endif(UNIX AND EXISTS "/usr/lib64")

set(Boost_ADDITIONAL_VERSIONS
   "1.69" "1.71"
)
find_package(Boost COMPONENTS filesystem date_time thread chrono)
if(NOT Boost_FOUND)
    message(FATAL_ERROR "Boost required to compile Uniform")
endif()
message(Boost_LIBRARIES="${Boost_LIBRARIES}")
message(Boost_INCLUDE_DIR="${Boost_INCLUDE_DIR}")
message(Boost_INCLUDE_DIRS="${Boost_INCLUDE_DIRS}")

########################################################################
# Find GTest
########################################################################
find_package(GTest REQUIRED)
if(NOT GTest_FOUND)
    message(FATAL_ERROR "GoogleTest required to compile Uniform")
endif(NOT GTest_FOUND)

if (ENABLE_CUDA)
	message("cuda enabled")
else()	
	message("cuda is disabled")
endif()

########################################################################
# Build Type
########################################################################
# Select the release build type by default to get optimization flags
if(NOT CMAKE_BUILD_TYPE)
   set(CMAKE_BUILD_TYPE "Release")
   message(STATUS "Build type not specified: defaulting to release.")
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} CACHE STRING "")
message(STATUS ${CMAKE_BUILD_TYPE})


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
