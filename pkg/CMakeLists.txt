########################################################################
#  Project Setup
########################################################################
if(NOT DEFINED required_cmake_ver)
    set(required_cmake_ver 3.20)
    message(STATUS "required_cmake_ver set to ${required_cmake_ver}")
endif()
if(NOT DEFINED required_cxx_ver)
    set(required_cxx_ver 17)
    message(STATUS "required_cxx_ver set to ${required_cxx_ver}")
endif()
cmake_minimum_required(VERSION ${required_cmake_ver}) 
project(pkg LANGUAGES CXX C)


########################################################################
# CXX version and Build Type
########################################################################
set(CMAKE_CXX_STANDARD ${required_cxx_ver})
if(NOT CMAKE_BUILD_TYPE)
   set(CMAKE_BUILD_TYPE "Release")
   message(STATUS "Build type not specified: defaulting to release.")
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} CACHE STRING "")
message(STATUS ${CMAKE_BUILD_TYPE})

########################################################################
#global variables: top level defined variables can be see by all subfolders
########################################################################
message("\nin pkg/CMakeLists: ")
if(NOT DEFINED pkg_dir)
    set(pkg_dir "${CMAKE_CURRENT_SOURCE_DIR}")
    message(pkg_dir="${pkg_dir}")
endif()

if(NOT DEFINED pkg_lib_dir)
    set(pkg_lib_dir "${PROJECT_BINARY_DIR}/lib")
    message(pkg_lib_dir="${pkg_lib_dir}")
endif()

if(NOT DEFINED pkg_bin_dir)
    set(pkg_bin_dir "${PROJECT_BINARY_DIR}/bin")
    message(pkg_bin_dir="${pkg_bin_dir}")
endif()

message("\ngoing to pkg/crossguid/CMakeLists: ")
add_subdirectory(crossguid)

#message("going to pkg/xyz/CMakeLists: ")
#add_other_subdirectory(xyz)


