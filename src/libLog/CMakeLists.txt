message("\n BEG: src/libLog/CMakeLists.txt:")
########################################################################
#  set required versions
########################################################################
if(NOT DEFINED set_versions)
	list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_CURRENT_SOURCE_DIR}/../../cmake)
	find_package(SetVersions REQUIRED)
endif()

########################################################################
#  Project Setup
########################################################################
set(target Log)
cmake_minimum_required(VERSION ${required_cmake_ver})
project(${target} LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD ${required_cxx_ver})

########################################################################
#  set building parameters
########################################################################
list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_CURRENT_SOURCE_DIR}/../../cmake)
find_package(SetCfg REQUIRED)

# CMAKE_ARCHIVE_OUTPUT_DIRECTORY control the output dir of static libs
# CMAKE_LIBRARY_OUTPUT_DIRECTORY control the output dir of dynamic/dll libs
if(DEFINED build_dir)
   set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${build_lib_dir}")   
   set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${build_lib_dir}")
   set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${build_bin_dir}")
endif()

########################################################################
# Create the LoggingUtils Library
########################################################################
add_library(${target} STATIC
	src/AppLog.cpp
	)

########################################################################
# Include directories
########################################################################
target_include_directories(${target} PUBLIC
   ${pkg_inc_dirs}    #all dependent folders in howToOrgCppProj/pkg
   ${src_dir}     #howToOrgCppProj/src
)

if (APPLOG_TESTS)
   add_subdirectory(test)
endif()
message("\n END: src/libLog/CMakeLists.txt")
