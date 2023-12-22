########################################################################
#  once done, it will define
#  Boost_FOUND
#  Boost_LIBRARIES
#  Boost_INCLUDE_DIR
#  Boost_INCLUDE_DIRS
########################################################################

set(Boost_FOUND "YES")

if(UNIX AND EXISTS "/usr/lib64")
    list(APPEND BOOST_LIBRARYDIR "/usr/lib64")
endif()

set(Boost_ADDITIONAL_VERSIONS
   "1.69" "1.71"
)
find_package(Boost COMPONENTS filesystem date_time thread chrono)
if(NOT Boost_FOUND)
    message(FATAL_ERROR "Boost required to compile Uniform")
endif()
message(Boost_LIBRARIES="${Boost_LIBRARIES}")
message(Boost_INCLUDE_DIR="${Boost_INCLUDE_DIR}")
message(Boost_INCLUDE_DIRS="${Boost_INCLUDE_DIRS}")

