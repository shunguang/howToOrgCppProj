########################################################################
#  Project Setup
########################################################################
if(NOT DEFINED cmake_req_ver)
	set(cmake_req_ver 3.20)
endif()

set(target testCap)
cmake_minimum_required(VERSION ${cmake_req_ver})
project( ${target} LANGUAGES CXX C)

########################################################################
#  check if pkg_inc and src_inc are defined by top level CMakeLists.txt
########################################################################
if(NOT DEFINED pkg_inc)
	message( FATAL_ERROR "pkg_inc not defined, cmake exit!" )
else()
	#todo: figureout var: pkg_inc
endif()

if(NOT DEFINED src_inc)
	message( FATAL_ERROR " src_inc not defined, cmake exit!")
else()
	#todo: figureout var: pkg_src
endif()

set(proj_inc "${CMAKE_CURRENT_SOURCE_DIR}" )

########################################################################
# Check if already compiled (NEEDED?)
########################################################################
target_include_directories(${target} PUBLIC
	${proj_inc}
)

########################################################################
# Create the tests Executable
########################################################################
add_executable(${target}
	src/main.cpp
	src/test1.cpp
	src/test2.cpp
)		


########################################################################
# Include directories
########################################################################
target_include_directories(${target} PUBLIC
	${proj_inc}
	)

target_link_directories(${target} PUBLIC
	${src_lib_dir}
	${pkg_lib_dir}
)

########################################################################
# Link Libraries
########################################################################
target_link_libraries( ${target} PUBLIC
	#wus1: note order matters
	${app_cpu_libs}
	${app_gpu_libs}
	${pkg2_libs}
	${pkg1_libs}
)

