AC_INIT([ffttest], [0.1], [])
AM_INIT_AUTOMAKE
AC_PROG_CXX
AC_PROG_CXX_C_O
CXXFLAGS+=" -std=gnu++11"
LDFLAGS="  -lfftw3"
AC_CHECK_LIB([fftw3],[fftw_execute],[],[AC_MSG_WARN([fftw3 lib NOT found.])])
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
