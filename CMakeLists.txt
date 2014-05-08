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
	REQUIRED jansson
	REQUIRED libcrypto>=1.0.1
)
include_directories ( ${DEPS_INCLUDE_DIRS} )
link_directories ( ${DEPS_LIBRARY_DIRS} )
add_definitions ( ${DEPS_CFLAGS} )


if ( CMAKE_BUILD_TYPE MATCHES DEBUG )
	pkg_check_modules ( TESTDEPS
		REQUIRED cmocka
	)
	include_directories ( ${TESTDEPS_INCLUDE_DIRS} )
	link_directories ( ${TESTDEPS_LIBRARY_DIRS} )
	add_definitions ( ${TESTDEPS_CFLAGS} )
endif ( CMAKE_BUILD_TYPE MATCHES DEBUG )

### COMPILE ###
add_library ( agilekeychain SHARED src/agilekeychain.c )
target_link_libraries ( agilekeychain ${DEPS_LIBRARIES} )
add_library ( cloudkeychain SHARED src/cloudkeychain.c )
target_link_libraries ( cloudkeychain ${DEPS_LIBRARIES} )

### TESTING ###
if ( CMAKE_BUILD_TYPE MATCHES DEBUG )
	# TODO: dynamically link the library in
	enable_testing ()

	if ( CMAKE_CONFIGURATION_TYPES )
		add_custom_target ( check COMMAND ${CMAKE_CTEST_COMMAND} --force-new-ctest-process
		                                                         --output-on-failure
		                                                         --build-config "$<CONFIGURATION>"
		                          DEPENDS build_tests )
	else ( )
		add_custom_target ( check COMMAND ${CMAKE_CTEST_COMMAND} --force-new-ctest-process
		                                                         --output-on-failure
		                          DEPENDS build_tests )
	endif ( )


	### ACTUAL TESTS ###

	add_executable ( test_base64 EXCLUDE_FROM_ALL test/base64.c )
	target_link_libraries ( test_base64 ${DEPS_LIBRARIES} ${TESTDEPS_LIBRARIES} )
	add_test ( Base64 test_base64 )

	add_custom_target ( build_tests DEPENDS test_base64 )
endif ( CMAKE_BUILD_TYPE MATCHES DEBUG )
