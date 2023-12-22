macro(set_dirs)
	message(ARGC=${ARGC})
	message(ARGV0="${ARGV0}")
	message(ARGV1="${ARGV1}")
	message(ARGV2="${ARGV2}")

	if ( ${ARGC} GREATER 0 )
		set(pkg_dir "${ARGV0}/abc")
		set(src_dir "${ARGV0}/efg")
	else()
		set(pkg_dir "/home/pkg")
		set(src_dir "/home/src")
	endif()
endmacro()

macro(print_dirs)
	message(pkg_dir="${pkg_dir}")
	message(src_dir="${src_dir}")
endmacro()


macro(set_vers)
	set(set_versions "YES")
	set(required_cmake_ver 3.20)
	set(required_cxx_ver 17)
endmacro()

macro(print_vers)
	message(STATUS "set_versions: ${set_versions}")
	message(STATUS "required_cmake_ver: ${required_cmake_ver}")
	message(STATUS "required_cxx_ver: ${required_cxx_ver}")
endmacro()

