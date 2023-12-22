message("\n BEG: src/libProcess/CMakeLists.txt")

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
set(target Process)
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
add_library(${target} STATIC
	src/Proc1.cpp
	src/Proc2.cpp
	)		

########################################################################
# Include directories
########################################################################
target_include_directories(${target} PUBLIC
	${pkg_inc_dirs}
	${src_dir}
)
message("\n END: src/libProcess/CMakeLists.txt")
