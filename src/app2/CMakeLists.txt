message("\n BEG: src/app2/CMakeLists.txt")
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
set(target app2)
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
add_executable(${target} 
	src/main.cpp
	)		

########################################################################
# Include directories
########################################################################
target_include_directories(${target} PUBLIC
	${pkg_inc_dirs}     #a list of includer dirs
	${src_dir}          #howToOrgCppProj/src       
)

target_link_directories( ${target} PUBLIC
	${pkg_lib_dir}    #howToOrgCppProj/build/lib
	${build_lib_dir}  #build/lib
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
