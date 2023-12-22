message("\n BEG: src/libUtil/CMakeLists.txt")

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
set(target Util)
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
# Create the cloudGeoUtil Library
########################################################################
add_library(${target} STATIC
	src/AppBagRead.cpp
	src/AppBagWrite.cpp
	src/CapImg.cpp
	src/CRC.cpp
	src/CvUtilFuncs.cpp
	src/FileUtil.cpp
	src/Roi.cpp
	src/Uint8Stream.cpp
	src/UtilFuncs.cpp 
	)		

########################################################################
# Include directories
########################################################################
# message("pkg_inc_dirs=${pkg_inc_dirs}") 
# message(src_dir="${src_dir}")
target_include_directories(${target} PUBLIC
	${pkg_inc_dirs}
	${src_dir}
)
message("\n END: src/libUtil/CMakeLists.txt")
