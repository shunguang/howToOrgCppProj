message("\n BEG: src/app2/CMakeLists.txt")
#######################################################################
#  set required versions
########################################################################
if(NOT DEFINED set_versions)
	list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_CURRENT_SOURCE_DIR}/../../cmake)
	find_package(SetVersions REQUIRED)
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
list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_CURRENT_SOURCE_DIR}/../../cmake)
find_package(SetCfg REQUIRED)

########################################################################
#  set output dirs
########################################################################
if(DEFINED build_dir)
   set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${build_lib_dir}")   
   set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${build_lib_dir}")
   set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${build_bin_dir}")
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
	${pkg_inc_dirs}     #a list of includer dirs
	${src_dir}          #howToOrgCppProj/src       
)

target_link_directories( ${target} PUBLIC
	${pkg_lib_dir}    #build/pkg/lib
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
