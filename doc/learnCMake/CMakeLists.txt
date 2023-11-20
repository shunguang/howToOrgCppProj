function(SET_TOP_DIRS)
	find_path(
		HOW_TO_ORG_CPP_PROJ_ROOT_DIR
		NAMES "HowToOrgCppProjRootTag.txt"
		PATHS ${CMAKE_CURRENT_SOURCE_DIR}/../ 
		      ${CMAKE_CURRENT_SOURCE_DIR}/../../ 
			  ${CMAKE_CURRENT_SOURCE_DIR}/../../../
	)
	if (NOT HOW_TO_ORG_CPP_PROJ_ROOT_DIR)
		message(FATAL_ERROR "HOW_TO_ORG_CPP_PROJ_ROOT_DIR cannot be found")
	else()
		message(HOW_TO_ORG_CPP_PROJ_ROOT_DIR="${HOW_TO_ORG_CPP_PROJ_ROOT_DIR}")
	endif()

	set(pkg_root_dir "${HOW_TO_ORG_CPP_PROJ_ROOT_DIR}/pkg" PARENT_SCOPE)				#howToOrgCppProj/pkg
	set(src_root_dir "${HOW_TO_ORG_CPP_PROJ_ROOT_DIR}/src" PARENT_SCOPE)				#howToOrgCppProj/src
	
	set(pkg_inc_dirs                            			#pkg_inc_dirs is a list
	 ${HOW_TO_ORG_CPP_PROJ_ROOT_DIR}/pkg/spdlog/include 
	 ${HOW_TO_ORG_CPP_PROJ_ROOT_DIR}/pkg/crossguid/include
	 PARENT_SCOPE
	)

	#build output dirs
    set(build_dir  "${HOW_TO_ORG_CPP_PROJ_ROOT_DIR}/build" PARENT_SCOPE)	#howToOrgCppProj/build
    set(pkg_lib_dir  "${HOW_TO_ORG_CPP_PROJ_ROOT_DIR}/build/pkg/lib" PARENT_SCOPE)
    set(pkg_bin_dir  "${HOW_TO_ORG_CPP_PROJ_ROOT_DIR}/build/pkg/bin" PARENT_SCOPE)
    set(src_lib_dir  "${HOW_TO_ORG_CPP_PROJ_ROOT_DIR}/build/src/lib" PARENT_SCOPE)
    set(src_bin_dir  "${HOW_TO_ORG_CPP_PROJ_ROOT_DIR}/build/src/bin" PARENT_SCOPE)
endfunction()


cmake_minimum_required(VERSION 3.22)

set_top_dirs()

message(pkg_root_dir="${pkg_root_dir}")
message(src_root_dir="${src_root_dir}")
message(pkg_lib_dir="${pkg_lib_dir}")
message(pkg_bin_dir="${pkg_bin_dir}")
message(src_lib_dir="${src_lib_dir}")
message(src_bin_dir="${src_bin_dir}")
message(pkg_inc_dirs="${pkg_inc_dirs}")

