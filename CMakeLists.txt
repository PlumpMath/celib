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

#############################################################
# user-changeable settings which can be used to customize
# layout of celib installation
# (default values are platform-specific)

SET (IDGEN_BIN_SUBDIR     ${DEFAULT_BIN_SUBDIR}     CACHE STRING "Subdirectory where executables will be installed")

# mark *_SUBDIR variables as advanced as this is not something
# that an average user would use
MARK_AS_ADVANCED (celib_BIN_SUBDIR)

# full paths for the installation
SET (CELIB_BIN_DIR     ${celib_BIN_SUBDIR})

###########################################################
# process subdirs

SUBDIRS(src)

#############################################################
# install stuff



## Configured files##########################################################
# Generate pkgconfig file
if(NOT WIN32)
    configure_file(
        TEMPLATES/celib.pc.cmake
        ${celib_BINARY_DIR}/TEMPLATES/celib.pc
        @ONLY)

    install(
        FILES "${celib_BINARY_DIR}/TEMPLATES/celib.pc"
        DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/pkgconfig)
endif()



