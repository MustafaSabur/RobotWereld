# If given on the commandline, the following options overrule any
# options given in the Autotools files. They either replace the
# value (cc and cxx) or ar added as last and additional/overruling
# argument (all others).
#
#	CC
#	CXX
#	LIBTOOLFLAGS
#	CPPFLAGS
#	CFLAGS
#	CXXFLAGS
#	LDFLAGS

AC_INIT([robotworld],[0.0.1],[J.Kraaijeveld@askesis.nl],[robotworld-0.0.1])
AC_CONFIG_AUX_DIR(.)
AM_INIT_AUTOMAKE

AC_CONFIG_MACRO_DIR(./m4)

# Check for programs

LT_INIT

AC_PROG_MAKE_SET

AC_PROG_CC
AC_PROG_CXX

AC_LANG([C])
AC_LANG([C++])

AC_CANONICAL_HOST

# Check for libraries

AX_BOOST_BASE([1.53])
AX_BOOST_SYSTEM
AX_BOOST_THREAD
AX_BOOST_DATE_TIME
AX_BOOST_REGEX
AX_BOOST_SERIALIZATION
AX_BOOST_FILESYSTEM
AX_BOOST_CHRONO

BOOST_LIBS="$BOOST_SYSTEM_LIB $BOOST_WSERIALIZATION_LIB $BOOST_THREAD_LIB $BOOST_DATE_TIME_LIB $BOOST_FILESYSTEM_LIB $BOOST_CHRONO_LIB"
AC_SUBST([BOOST_LIBS])

# AM_OPTIONS_WXCONFIG
# AM_PATH_WXCONFIG(2.9.4, wxWin=1, , ,[--debug=yes])

AM_OPTIONS_WXCONFIG
AM_PATH_WXCONFIG(2.9.4, wxWin=1, , ,[--debug=yes])
if test "$wxWin" != 1; then
	AC_MSG_ERROR([
				wxWidgets must be installed on your system
				but no wx-config script could be found.

				Please check that wx-config is in path, the directory
				where wxWidgets libraries are installed as returned by 
				'wx-config --libs' is in the linker path (LD_LIBRARY_PATH 
				or equivalent variable) and wxWidgets version is 2.9.4 or 
				above.
		])
	fi
if test "$wxWin" != 0; then
	AC_DEFINE(HAVE_WXWIDGETS,1,[define if the wxWidgets 2.9.4. or higher is available])
fi

case $host in

*mingw*)
	SOCKET_LIBS="-lwsock32 -lws2_32"
	;;
esac
AC_SUBST([SOCKET_LIBS])

#########################################################################################################
#                     Set the preprocessor, c-compiler, c++-compiler and linker option
#########################################################################################################

# set the CPP options
case $host in
*linux*)
	ROBOTWORLD_CPPFLAGS=""
	;;
*mingw*)
	ROBOTWORLD_CPPFLAGS="-D_WIN32_WINNT=0x0501"
	;;
esac
AC_SUBST([ROBOTWORLD_CPPFLAGS])

# set the C options
case $host in
*linux*)
	ROBOTWORLD_CFLAGS="-pipe -Wall -Wextra"
	;;
*mingw*)
	ROBOTWORLD_CFLAGS="-pipe -Wall -Wextra"
	;;
*darwin*)
	ROBOTWORLD_CFLAGS="-pipe -Wall -Wextra"
	;;
esac
AC_SUBST([ROBOTWORLD_CFLAGS])

# set the C++ options
case $host in
*linux*)
	ROBOTWORLD_CXXFLAGS="-pipe -Wall -Wextra -std=gnu++11"
	;;
*mingw*)
	ROBOTWORLD_CXXFLAGS="-pipe -Wall -Wextra -std=gnu++11"
	;;
*darwin*)
	ROBOTWORLD_CXXFLAGS="-pipe -Wall -Wextra -std=gnu++11"
	;;
esac
AC_SUBST([ROBOTWORLD_CXXFLAGS])

# set the Linker options
case $host in
*linux*)
	ROBOTWORLD_LDFLAGS=""
	;;
*mingw*)
	ROBOTWORLD_LDFLAGS="-Wl,--subsystem,windows -mwindows"
	;;
*darwin*)
	ROBOTWORLD_LDFLAGS=""
	;;
	
esac
AC_SUBST([ROBOTWORLD_LDFLAGS])

# Check for headers

AC_HEADER_STDC

# Check for typedefs, structures and compiler chracteristics

# Check for library functions

#########################################################################################################

AM_CPPFLAGS=
AM_CFLAGS=
AM_CXXFLAGS=
AM_LDFLAGS=

case $host in
*linux*)
	AM_CPPFLAGS="$AM_CPPFLAGS"
	AM_CFLAGS="$AM_CFLAGS"
	AM_CXXFLAGS="$AM_CXXFLAGS"
	AM_LDFLAGS="-no-undefined"
	;;
*darwin*)
	ROBOTWORLD_LDFLAGS=""
	AM_CPPFLAGS="$AM_CPPFLAGS"
	AM_CFLAGS="$AM_CFLAGS"
	AM_CXXFLAGS="$AM_CXXFLAGS"
	AM_LDFLAGS="-no-undefined"
	;;
*mingw*)
	AM_CPPFLAGS="$AM_CPPFLAGS"
	AM_CFLAGS="$AM_CFLAGS"
	AM_CXXFLAGS="$AM_CXXFLAGS"
	AM_LDFLAGS="-Wl,--enable-runtime-pseudo-reloc,--enable-auto-import -no-undefined"
	;;
esac

#########################################################################################################
#                               Set debug related compiler options
#########################################################################################################

development_default="yes"
AC_ARG_ENABLE(development,
AC_HELP_STRING([--enable-development= no/yes],[if enabled all development features will be on]),
enable_development=$enableval,
enable_development=$development_default)
if test "$enable_development" = "yes"; then
	AC_SUBST([AM_CPPFLAGS], -DDEVELOPMENT)
	AC_SUBST([AM_CFLAGS], "-O0 -pg -g3")
	AC_SUBST([AM_CXXFLAGS], "-O0 -pg -g3")
	AC_MSG_RESULT(Enabling development tracing)
else
	AC_SUBST([AM_CPPFLAGS], -DPRODUCTION)
	AC_SUBST([AM_CFLAGS], -O3)
	AC_SUBST([AM_CXXFLAGS], -O3)
	AC_MSG_RESULT(Enabling production tracing)
fi

AC_SUBST([AM_CPPFLAGS])
AC_SUBST([AM_CFLAGS])
AC_SUBST([AM_CXXFLAGS])
AC_SUBST([AM_LDFLAGS])
#AC_SUBST([AM_LDADD])

AM_LIBTOOLFLAGS="--silent"
AC_SUBST([AM_LIBTOOLFLAGS])

AC_PROG_INSTALL

# Output files
AC_CONFIG_HEADER([src/config.h])
AC_CONFIG_FILES(Makefile src/Makefile)
AC_OUTPUT


