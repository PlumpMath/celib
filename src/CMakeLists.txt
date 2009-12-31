CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(celib)
INCLUDE(FindPkgConfig)
INCLUDE_DIRECTORIES(${celib_BINARY_DIR})
SET(celib_SRCS cestring.c ceswap.c)
ADD_LIBRARY(celib SHARED ${celib_SRCS})
## Configured files##########################################################
# Generate pkgconfig file
if(NOT WIN32)
    configure_file(
        templates/celib.pc.cmake
        celib.pc
        @ONLY)

    install(
        FILES ${celib_BINARY_DIR}/celib.pc
        DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/pkgconfig)
endif()

## Install
INSTALL_FILES(/include/celib/ .h)
INSTALL(TARGETS celib 
		RUNTIME DESTINATION bin 
		LIBRARY DESTINATION lib 
		ARCHIVE DESTINATION libstatic
)
