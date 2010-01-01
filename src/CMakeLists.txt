CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(celib)
INCLUDE(FindPkgConfig)
INCLUDE_DIRECTORIES(${celib_BINARY_DIR})
SET(celib_SRCS cestring.c ceswap.c cebigint.c)
ADD_LIBRARY(celib SHARED ${celib_SRCS})




## Install
INSTALL_FILES(/include/celib/ .h)
INSTALL(TARGETS celib 
		RUNTIME DESTINATION bin 
		LIBRARY DESTINATION lib 
		ARCHIVE DESTINATION libstatic
)


