cmake_minimum_required(VERSION 3.22)
project(xyz)

message(CMAKE_CURRENT_SOURCE_DIR=${CMAKE_CURRENT_SOURCE_DIR})
set (CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
message(CMAKE_MODULE_PATH=${CMAKE_MODULE_PATH})

message("\nrun find_packages:")
find_package(MyMatlab)
message(MyMatlab_FOUND="${MyMatlab_FOUND}")
message(matlab_dir="${matlab_dir}")

# include macros
message("\nrun macros:")
include(helper_macros)
set_dirs()
print_dirs()

set_dirs("${CMAKE_CURRENT_SOURCE_DIR}")
print_dirs()

set_vers()
print_vers()

message("\nrun funcs:")
# run functions
include(helper_funcs)
FOO_SET_VARS()
message(pkg_dir2="${pkg_dir2}")
message(pkg_inc_dirs2="${pkg_inc_dirs2}")
message(src_dir2="${src_dir2}")
message(build_dir2="${build_lib_dir2}")

add_application( "ABC" )
add_application( "EFG" )
