########################################################################
#  Project Setup
########################################################################
if(NOT DEFINED required_cmake_ver)
    set(required_cmake_ver 3.20)
    message(STATUS "required_cmake_ver set to ${required_cmake_ver}")
endif()
if(NOT DEFINED required_cxx_ver)
    set(required_cxx_ver 17)
    message(STATUS "required_cxx_ver set to ${required_cxx_ver}")
endif()
cmake_minimum_required(VERSION ${required_cmake_ver}) 
project(src LANGUAGES CXX C)

message("\nin src/CMakeLists.txt:")

########################################################################
# CXX version and Build Type
########################################################################
set(CMAKE_CXX_STANDARD ${required_cxx_ver})
if(NOT CMAKE_BUILD_TYPE)
   set(CMAKE_BUILD_TYPE "Release")
   message(STATUS "Build type not specified: defaulting to release.")
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} CACHE STRING "")
message(STATUS ${CMAKE_BUILD_TYPE})


########################################################################
#global variables: top level defined variables can be see by all subfolders
########################################################################
if(NOT DEFINED app_src_dir)
	set(app_src_dir "${CMAKE_CURRENT_SOURCE_DIR}")
	message(app_src_dir="${app_src_dir}")
endif()

if(NOT DEFINED app_lib_dir)
    set(app_lib_dir "${PROJECT_BINARY_DIR}/lib")
    message(app_lib_dir="${app_lib_dir}")
endif()

if(NOT DEFINED app_bin_dir)
    set(app_bin_dir "${PROJECT_BINARY_DIR}/bin")
    message(app_bin_dir="${app_bin_dir}")
endif()


if(NOT DEFINED pkg_dir)
	#if reached here, it means you want to seperately build pkg/ and howToOrgCppProj/src.
	#we require you build pkg/ first, and hence 
	#  howToOrgCppProj/pkg/build/ 
	#was already created and its subfolders and files are valid
	message("pkg_dir is not defined, we redfines them:")
	
	set(pkg_dir "${app_src_dir}/../pkg")		#howToOrgCppProj/pkg
	set(pkg_lib_dir "${pkg_dir}/build/lib")		#howToOrgCppProj/pkg/build/lib
	set(pkg_bin_dir "${pkg_dir}/build/bin")		#howToOrgCppProj/pkg/build/bin
	file( GLOB pkg_inc_dirs
		${pkg_dir}/spdlog/include 
		${pkg_dir}/crossguid/include
	 )

	message(pkg_dir="${pkg_dir}")
	message(pkg_lib_dir="${pkg_lib_dir}")
	message(pkg_bin_dir="${pkg_bin_dir}")
	message(pkg_inc_dirs="${pkg_inc_dirs}")
endif()

add_subdirectory(libLog)
#add_subdirectory(libUtil)
#add_subdirectory(libCapture)
#add_subdirectory(libProcess)
#add_subdirectory(app1)
#add_subdirectory(app2)
############ eof ##############


