function(FOO_SET_VARS)
	find_path(
		HOW_TO_ORG_CPP_PROJ_ROOT_DIR
		NAMES "FindMatab.cmake"
		PATHS ${CMAKE_CURRENT_SOURCE_DIR}/cmake 
		      ${CMAKE_CURRENT_SOURCE_DIR}/../cmake 
	)
	if (NOT HOW_TO_ORG_CPP_PROJ_ROOT_DIR)
		message(FATAL_ERROR "HOW_TO_ORG_CPP_PROJ_ROOT_DIR cannot be found")
	else()
		message(HOW_TO_ORG_CPP_PROJ_ROOT_DIR="${HOW_TO_ORG_CPP_PROJ_ROOT_DIR}")
	endif()

	set(pkg_dir2 "${HOW_TO_ORG_CPP_PROJ_ROOT_DIR}/pkg" PARENT_SCOPE)
	set(pkg_inc_dirs2                            			#pkg_inc_dirs is a list
	 ${HOW_TO_ORG_CPP_PROJ_ROOT_DIR}/pkg/spdlog/include 
	 ${HOW_TO_ORG_CPP_PROJ_ROOT_DIR}/pkg/crossguid/include
	 PARENT_SCOPE
	)

	set(src_dir2 "${HOW_TO_ORG_CPP_PROJ_ROOT_DIR}/src" PARENT_SCOPE)
    set(build_dir2  "${HOW_TO_ORG_CPP_PROJ_ROOT_DIR}/build" PARENT_SCOPE)
endfunction()

# add_interface(<name> PACKAGE <package>
#   [INCLUDES include...]
# )
#
function(add_interface NAME)
  cmake_parse_arguments(IFACE "" "PACKAGE" "INCLUDES" ${ARGN})
  # ...
endfunction(add_interface)

# add_component(<name> PACKAGE <package>
#   SOURCES source...
#   [INCLUDES include...]
#   [USING dependency...]
#   [SHARING dependency...]
#   [TESTS test...]
# )
#
function(add_component NAME)
  # cmake_parse_arguments(COMP ...)
  # ...
endfunction(add_component)

# add_application(<name> PACKAGE <package>
#   SOURCES source...
#   [COMPONENTS component...]
# )
#
function(add_application NAME)
message( add_application called )
endfunction(add_application)
