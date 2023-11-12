message("\n BEG: src/app2/CMakeLists.txt")

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
set(target app2)
cmake_minimum_required(VERSION ${required_cmake_ver})
project(${target} LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD ${required_cxx_ver})

########################################################################
# figure out pkg_root_dir, pkg_lib_dir, and pkg_bin_dir, 
#            src_root_dir, src_lib_dir, and appbin_dir
########################################################################
if(NOT DEFINED pkg_root_dir)
   #build from howToOrgCppProj/src/libCapture/build
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
    #build from howToOrgCppProj/src/libCapture/build
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
#  check if pkg_inc and src_inc are defined by top level CMakeLists.txt
########################################################################
if(NOT DEFINED pkg_inc_dirs)
	message( FATAL_ERROR "pkg_inc_dirs not defined, cmake exit!" )
	#todo: find <pkg_inc_dirs> from ${CMAKE_CURRENT_SOURCE_DIR}
endif()

########################################################################
# Create the cloudGeoUtil Library
########################################################################
add_executable(${target} 
	src/main.cpp
	)		

########################################################################
# Include directories
########################################################################
target_include_directories(${target} PUBLIC
	${pkg_inc_dirs}  #a list of includer dirs
	${src_root_dir}   #howToOrgCppProj/src       
)

target_link_directories( ${target} PUBLIC
	${pkg_lib_dir}  #build/pkg/lib
	${src_lib_dir}  #build/lib
)

#for a real proj we may need this:
#set(pkg2_libs crossguid gtest gtest_main)
#set(pkg1_libs boost_timer boost_filesystem boost_system boost_date_time boost_regex boost_chrono pthread boost_thread dl m pthread rt)
#set(cuda_libs culibos cublasLt_static cublas_static cudart_static) 
#set(app_libs Capture Process Util Log)
target_link_libraries(${target} PUBLIC
	Process
	Capture
	Util
	Log
	crossguid
)

message("\n END: src/app2/CMakeLists.txt")
