#-------------------------------------------------
# helper_macros.cmake
# by shunguang.wu@gmail.com, 12/22/2023
#
#-------------------------------------------------
########################################################################
# set up required versions
########################################################################
macro(set_required_vers)
	set(required_cmake_ver 3.20)
	set(required_cxx_ver 17)
	set(set_required_vers_done "YES")
endmacro()

macro(print_required_vers)
	message(STATUS "set_versions: ${set_versions}")
	message(STATUS "required_cmake_ver: ${required_cmake_ver}")
	message(STATUS "required_cxx_ver: ${required_cxx_ver}")
endmacro()

########################################################################
# set up Build params
########################################################################
macro(set_build_params)
	# Select the release build type by default to get optimization flags
	if(NOT CMAKE_BUILD_TYPE)
   		set(CMAKE_BUILD_TYPE "Release")
   		message(STATUS "Build type not specified: defaulting to release.")
	endif(NOT CMAKE_BUILD_TYPE)

	set(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} CACHE STRING "")
	option(BUILD_SHARED_LIBS "Build using shared libraries" OFF) 
endmacro()

macro(print_build_params)
	message(STATUS ${CMAKE_BUILD_TYPE})
	message(STATUS ${BUILD_SHARED_LIBS})	
endmacro()

#-------------------------------------------------
# set_build_dirs()
#-------------------------------------------------
macro(set_build_dirs)
	set(set_build_dirs_done "YES")
	#we assume this project must have cmake/FindHowToOrgCppProj.cmake
	find_path(
    	how_to_org_cpp_proj_cmake_dir
		NAMES "HowToOrgCppProj.cmake"
		PATHS ${CMAKE_CURRENT_SOURCE_DIR}/cmake
	    	  ${CMAKE_CURRENT_SOURCE_DIR}/../cmake 
	      	${CMAKE_CURRENT_SOURCE_DIR}/../../cmake 
		  	${CMAKE_CURRENT_SOURCE_DIR}/../../../cmake
		  	${CMAKE_CURRENT_SOURCE_DIR}/../../../../cmake
	)

	if (NOT how_to_org_cpp_proj_cmake_dir)
    	SET(set_build_dirs_done "NO")
    	MESSAGE(FATAL_ERROR "Failed to find where is HowToOrgCppProj")
	else()
    	set(how_to_org_cpp_proj_root_dir "${how_to_org_cpp_proj_cmake_dir}/..")
    	set(pkg_dir "${how_to_org_cpp_proj_root_dir}/pkg")
    	# pkg_inc_dirs is a list
    	set(pkg_inc_dirs                            			
        	${how_to_org_cpp_proj_root_dir}/pkg/spdlog/include 
        	${how_to_org_cpp_proj_root_dir}/pkg/crossguid/include
    	)
    	set(src_dir "${how_to_org_cpp_proj_root_dir}/src")

		if (${ARGC} GREATER 0)
			#for bottom up building
			set(build_dir     "${ARGV0}")
			set(build_lib_dir "${ARGV0}")
			set(build_bin_dir "${ARGV0}")
		else()
			#for topdown building
			set(build_dir    	"${how_to_org_cpp_proj_root_dir}/build")
    		set(build_lib_dir  	"${how_to_org_cpp_proj_root_dir}/build/lib")
	    	set(build_bin_dir  	"${how_to_org_cpp_proj_root_dir}/build/bin")
		endif()
		#pkg_lib_dir: this addional  dir is defined for bottom-up building 
		#             for the topdown building, pkg_lib_dir == build_lib_dir
		set(pkg_lib_dir  	"${how_to_org_cpp_proj_root_dir}/build/lib")
	endif()
endmacro()

macro(print_build_dirs)
	message(set_build_dirs_done=${set_build_dirs_done})
	message(how_to_org_cpp_proj_root_dir=${how_to_org_cpp_proj_root_dir})
	message(pkg_dir=${pkg_dir})
	message(pkg_inc_dirs="${pkg_inc_dirs}")
	message(pkg_lib_dir="${pkg_lib_dir}")
	message(src_dir=${src_dir})
	message(build_dir=${build_dir})
	message(build_lib_dir=${build_lib_dir})
	message(build_bin_dir=${build_bin_dir})
endmacro()

macro(set_output_dirs)
	# CMAKE_ARCHIVE_OUTPUT_DIRECTORY control the output dir of static libs
	# CMAKE_LIBRARY_OUTPUT_DIRECTORY control the output dir of dynamic/dll libs
	set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${build_lib_dir}")   
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${build_lib_dir}")
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${build_bin_dir}")
endmacro()


macro(print_output_dirs)
	# CMAKE_ARCHIVE_OUTPUT_DIRECTORY control the output dir of static libs
	# CMAKE_LIBRARY_OUTPUT_DIRECTORY control the output dir of dynamic/dll libs
	message(STATUS ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})   
	message(STATUS ${MAKE_LIBRARY_OUTPUT_DIRECTORY})
	message(STATUS ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
endmacro()


