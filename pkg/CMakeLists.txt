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

message("\ngoing to pkg/crossguid/CMakeLists: ")
add_subdirectory(crossguid)

#message("\ngoing to pkg/xyz/CMakeLists: ")
#add_other_subdirectory(xyz)

message("\nout pkg/CMakeLists: ")


