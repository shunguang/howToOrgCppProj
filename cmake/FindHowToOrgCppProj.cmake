#-------------------------------------------------
# FindHowToOrgCppProj.cmake
# by shunguang.wu@gmail.com, 12/21/2023
#
# Try to find where is howToOrgCppProj, once done this will define:
#  HowToOrgCppProj_FOUND
#  how_to_org_cpp_proj_root_dir
#  pkg_dir
#  pkg_inc_dirs
#  src_dir
#  build_dir
#  build_lib_dir
#  build_bin_dir
#-------------------------------------------------
message("\n BEG: FindHowToOrgCppProj.cmake")

set(HowToOrgCppProj_FOUND "YES")

#we assume this project must have cmake/FindHowToOrgCppProj.cmake
find_path(
    how_to_org_cpp_proj_cmake_dir
	NAMES "FindHowToOrgCppProj.cmake"
	PATHS ${CMAKE_CURRENT_SOURCE_DIR}/cmake
	      ${CMAKE_CURRENT_SOURCE_DIR}/../cmake 
	      ${CMAKE_CURRENT_SOURCE_DIR}/../../cmake 
		  ${CMAKE_CURRENT_SOURCE_DIR}/../../../cmake
		  ${CMAKE_CURRENT_SOURCE_DIR}/../../../../cmake
)

if (NOT how_to_org_cpp_proj_cmake_dir)
    SET(HowToOrgCppProj_FOUND "NO")
    MESSAGE(STATUS "Failed to find where is HowToOrgCppProj")
else()
    set(how_to_org_cpp_proj_root_dir "${how_to_org_cpp_proj_cmake_dir}/..")
    set(pkg_dir "${how_to_org_cpp_proj_root_dir}/pkg")
    # pkg_inc_dirs is a list
    set(pkg_inc_dirs                            			
        ${how_to_org_cpp_proj_root_dir}/pkg/spdlog/include 
        ${how_to_org_cpp_proj_root_dir}/pkg/crossguid/include
    )
    set(src_dir "${how_to_org_cpp_proj_root_dir}/src")
    set(build_dir    "${how_to_org_cpp_proj_root_dir}/build")
    set(build_lib_dir  "${how_to_org_cpp_proj_root_dir}/build/lib")
    set(build_bin_dir  "${how_to_org_cpp_proj_root_dir}/build/bin")
endif()

# --- debug info ---
message(how_to_org_cpp_proj_root_dir=${how_to_org_cpp_proj_root_dir})
message(pkg_dir=${pkg_dir})
message(pkg_inc_dirs="${pkg_inc_dirs}")
message(src_dir=${src_dir})
message(build_dir=${build_dir})
message(build_lib_dir=${build_lib_dir})
message(build_bin_dir=${build_bin_dir})
message(" END: FindHowToOrgCppProj.cmake")


