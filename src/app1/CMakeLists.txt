message("\n BEG: src/app1/CMakeLists.txt")

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
set(target app1)
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
	${pkg_inc_dirs}
	${src_dir}
)

########################################################################
# link directories
########################################################################
target_link_directories( ${target} PUBLIC
	${pkg_lib_dir}    #howToOrgCppProj/build/lib
	${build_lib_dir}  #build/lib
)

target_link_libraries(${target} PUBLIC
	Process
	Capture
	Util
	Log
	crossguid
)
message("\n END: src/app1/CMakeLists.txt")
