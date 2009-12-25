CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(celib)
include(FindPkgConfig)
INCLUDE_DIRECTORIES(${celib_BINARY_DIR})
SET(celib_SRCS cestring.c ceswap.c)
ADD_LIBRARY(celib SHARED ${celib_SRCS})

# Generate pkgconfig file
configure_file (templates/celib.pc.cmake@ONLY)

INSTALL_FILES(/include/celib/ .h)
INSTALL_FILES(/usr/lib/pkgconfig/ .pc)
INSTALL(TARGETS celib 
		RUNTIME DESTINATION bin 
		LIBRARY DESTINATION lib 
		ARCHIVE DESTINATION libstatic
)
