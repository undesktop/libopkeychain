### BOILERPLATE ###
cmake_minimum_required ( VERSION 2.8 )
list ( APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake )
set ( CMAKE_INCLUDE_CURRENT_DIR ON )
set ( CMAKE_COLOR_MAKEFILE ON )

string ( COMPARE EQUAL "${CMAKE_SOURCE_DIR}" "${CMAKE_BINARY_DIR}" insource )
if ( insource )
	message ( FATAL_ERROR "All undesktop projects require an out-of-source build." )
endif ( insource )


### PROJECT INFO ###
project ( libopkeychain C )
set ( VERSION "0.1.0" )
set ( COPYRIGHT "Copyright 2014 Undesktop Project and contributors" )
set ( DESCRIPTION "Unofficial 1Password Keychain library" )
set ( WEBSITE "http://undesktop.github.io/libopkeychain/" )


### LOAD PACKAGES ###
find_package ( PkgConfig REQUIRED )
pkg_check_modules ( DEPS
	REQUIRED json-c
	REQUIRED libcrypto>=1.0.1
)
include_directories ( ${DEPS_INCLUDE_DIRS} )
link_libraries ( ${DEPS_LIBRARIES} )
link_directories ( ${DEPS_LIBRARY_DIRS} )
add_definitions ( ${DEPS_CFLAGS} )


### COMPILE ###
add_library ( agilekeychain SHARED src/agilekeychain.c )
add_library ( cloudkeychain SHARED src/cloudkeychain.c )
