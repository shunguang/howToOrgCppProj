message("\n BEG: src/CMakeLists.txt")

#######################################################################
#  include macro and functions if have any
########################################################################
list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_CURRENT_SOURCE_DIR}/../cmake)
include(helper_macros)

########################################################################
#  set required versions
########################################################################
if(NOT DEFINED set_required_vers_done)
	set_required_vers()
	print_required_vers()
endif()

########################################################################
#  setup project
########################################################################
set(target src)
cmake_minimum_required(VERSION ${required_cmake_ver}) 
project(${target} LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD ${required_cxx_ver})

########################################################################
#  add sub dirs
########################################################################
add_subdirectory(libLog)
add_subdirectory(libUtil)
add_subdirectory(libCapture)
add_subdirectory(libProcess)
add_subdirectory(app1)
add_subdirectory(app2)
message("\n END: src/CMakeLists.txt")

