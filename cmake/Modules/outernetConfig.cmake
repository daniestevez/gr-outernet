INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_OUTERNET outernet)

FIND_PATH(
    OUTERNET_INCLUDE_DIRS
    NAMES outernet/api.h
    HINTS $ENV{OUTERNET_DIR}/include
        ${PC_OUTERNET_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    OUTERNET_LIBRARIES
    NAMES gnuradio-outernet
    HINTS $ENV{OUTERNET_DIR}/lib
        ${PC_OUTERNET_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(OUTERNET DEFAULT_MSG OUTERNET_LIBRARIES OUTERNET_INCLUDE_DIRS)
MARK_AS_ADVANCED(OUTERNET_LIBRARIES OUTERNET_INCLUDE_DIRS)

