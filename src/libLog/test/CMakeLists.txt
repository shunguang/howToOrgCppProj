message("\n BEG: src/libLog/test/CMakeLists.txt")

#######################################################################
#  include macro and functions if have any
########################################################################
list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_CURRENT_SOURCE_DIR}/../../../cmake)
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
set(target logTest)
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
# Create the LoggingUtils Library
########################################################################
add_executable(${target}
	main.cpp
	YourClass.cpp
	)

target_include_directories(${target} PUBLIC
   ${pkg_inc_dirs}
   ${src_dir}
)

target_link_directories(${target} PUBLIC
   ${build_lib_dir}
   )

target_link_libraries(${target} PUBLIC
   Log
)
message("\n END: src/libLog/test/CMakeLists.txt")

