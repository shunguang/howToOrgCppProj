message("\n BEG: src/CMakeLists.txt")
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
# figure out pkg_root_dir, pkg_lib_dir, and pkg_bin_dir, 
#            src_root_dir, src_lib_dir, and appbin_dir
########################################################################
if(NOT DEFINED src_root_dir)
	set(src_root_dir "${CMAKE_CURRENT_SOURCE_DIR}")
    set(src_lib_dir "${PROJECT_BINARY_DIR}/lib")
    set(src_bin_dir "${PROJECT_BINARY_DIR}/bin")

	message(src_root_dir=${src_root_dir})
    message(src_lib_dir=${src_lib_dir})
    message(src_bin_dir=${src_bin_dir})
endif()

if(NOT DEFINED pkg_root_dir)
	#if reached here, it means you want to seperately build pkg/ and howToOrgCppProj/src.
	#we require you build pkg/ first, and hence 
	#  howToOrgCppProj/pkg/build/ 
	#was already created and its subfolders and files are valid
	message("pkg_root_dir is not defined, we redfines them:")
	
	set(pkg_root_dir "${src_root_dir}/../pkg")		#howToOrgCppProj/pkg
	set(pkg_lib_dir "${pkg_root_dir}/build/lib")		#howToOrgCppProj/pkg/build/lib
	set(pkg_bin_dir "${pkg_root_dir}/build/bin")		#howToOrgCppProj/pkg/build/bin
	set(pkg_inc_dirs                            #pkg_inc_dirs is a list
		${pkg_root_dir}/spdlog/include 
		${pkg_root_dir}/crossguid/include
	)

	message(pkg_root_dir=${pkg_root_dir})
	message(pkg_lib_dir=${pkg_lib_dir})
	message(pkg_bin_dir=${pkg_bin_dir})
	#message(pkg_inc_dirs="${pkg_inc_dirs}")  #does not work
	message("pkg_inc_dirs=${pkg_inc_dirs}")  #this is the only right way to print a list
endif()

add_subdirectory(libLog)
add_subdirectory(libUtil)
add_subdirectory(libCapture)
add_subdirectory(libProcess)
add_subdirectory(app1)
add_subdirectory(app2)
message("\n END: src/CMakeLists.txt")


