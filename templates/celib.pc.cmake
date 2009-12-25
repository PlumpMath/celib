prefix=@CMAKE_INSTALL_PREFIX@
exec_prefix=${prefix}
libdir=${exec_prefix}/@INSTALL_LIB_DIR@
includedir=${prefix}/@INSTALL_INC_DIR@

Name: CeLib
Description: coldnew's C libraries
Version: @VERSION@
Libs: -L${libdir} -lcelib
Cflags: -I${includedir}/celib
