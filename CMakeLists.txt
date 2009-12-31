# set version
SET(CPACK_PACKAGE_VERSION_MAJOR "0")
SET(CPACK_PACKAGE_VERSION_MINOR "0")
SET(CPACK_PACKAGE_VERSION_PATCH "1")
SET(COMPLETE_VERSION ${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH})
SET(PROJECT_VERSION ${COMPLETE_VERSION})
PROJECT(celib${PROJECT_VERSION})

###########################################################
# CMake setting

CMAKE_MINIMUM_REQUIRED (VERSION 2.6)

SET(CMAKE_COLOR_MAKEFILE ON)


###########################################################
# process subdirs

SUBDIRS(src)

#############################################################
# install stuff

## Configured files##########################################################
# Generate pkgconfig file
if(NOT WIN32)
    set(PC_FILE ${CMAKE_BINARY_DIR}/celib.pc)
    configure_file(
        "TEMPLATES/celib.pc.cmake"
        ${PC_FILE}
        @ONLY)

#    install(
#        FILES "${celib_BINARY_DIR}/celib.pc"
#        DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/pkgconfig)
        install(FILES ${PC_FILE} DESTINATION ${LIB_INSTALL_DIR}/pkgconfig)

#LIB_INSTALL_DIR
endif()



