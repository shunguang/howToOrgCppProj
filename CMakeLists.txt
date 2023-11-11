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
#defined global variables: top level defined variables can be see by all subfolders
########################################################################
set(pkg_dir "${CMAKE_CURRENT_SOURCE_DIR}/pkg")          #howToOrgCppProj/pkg
set(pkg_lib_dir "${PROJECT_BINARY_DIR}/pkg/lib")		#howToOrgCppProj/build/pkg/lib
set(pkg_bin_dir "${PROJECT_BINARY_DIR}/pkg/bin")		#howToOrgCppProj/build/pkg/bin

set(app_src_dir "${CMAKE_CURRENT_SOURCE_DIR}/src")      #howToOrgCppProj/src
set(app_lib_dir "${PROJECT_BINARY_DIR}/lib")			#howToOrgCppProj/build/lib
set(app_bin_dir "${PROJECT_BINARY_DIR}/bin")			#howToOrgCppProj/build/bin

message(CMAKE_CURRENT_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")
message(CMAKE_BINARY_DIR="${CMAKE_BINARY_DIR}")

message(pkg_dir=${pkg_dir})
message(pkg_lib_dir=${pkg_lib_dir})
message(pkg_bin_dir=${pkg_bin_dir})

message(app_src_dir=${app_src_dir})
message(app_lib_dir=${app_lib_dir})
message(app_bin_dir=${app_bin_dir})

########################################################################
# derived dirs and link-libs
########################################################################
file( GLOB pkg_inc_dirs
	${pkg_dir}/spdlog/include 
	${pkg_dir}/crossguid/include
 )
 
file( GLOB src_inc_dirs
	${app_src_dir}
	${app_src_dir}/libLog/include
	${app_src_dir}/libUtil/include
	${app_src_dir}/libCapture/include
	${app_src_dir}/libProcess/include
)

set(pkg2_libs crossguid gtest gtest_main uuid)
set(pkg1_libs boost_timer boost_filesystem boost_system boost_date_time boost_regex boost_chrono pthread boost_thread dl m pthread rt)
set(cuda_libs culibos cublasLt_static cublas_static cudart_static) 
set(app_libs Capture Process Util Log)

message(pkg_inc_dirs="${pkg_inc_dirs}")
message(src_inc_dirs="${src_inc_dirs}")

message(pkg1_libs=${pkg1_libs})
message(pkg2_libs=${pkg2_libs})
message(app_libs=${app_libs})

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

#top level includ and lib dirs applied to all subfolders
include_directories(
   ${pkg_inc_dirs}
   ${src_inc_dirs}
   ${Boost_INCLUDE_DIR}
   ${GTEST_INCLUDE_DIRS}
	)
link_directories(
	${pkg_lib_dir}
	${app_lib_dir}
	)

#cloud-geo-engin/build$ cmake -DENABLE_CUDA=OFF/ON ../
if (ENABLE_CUDA)
    include_directories(
		/usr/local/cuda/include
	)
	
	link_directories(
	/usr/local/cuda/targets/x86_64-linux
	)
endif(ENABLE_CUDA)


########################################################################
# add our pkg/ and src/ to build
########################################################################
add_subdirectory(pkg)
add_subdirectory(src)
############ eof ##############


