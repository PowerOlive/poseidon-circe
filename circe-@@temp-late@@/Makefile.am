AM_CPPFLAGS = -Wall -Wextra -Werror -Wconversion -Wsign-conversion	\
	-Winvalid-pch -Wno-missing-field-initializers -Wwrite-strings -Wsuggest-attribute=noreturn	\
	-Wundef -Wshadow -Wstrict-aliasing=2 -Wstrict-overflow=2 -Wno-error=pragmas	\
	-Wno-long-long -Wno-variadic-macros -Wno-error=unused-{function,variable,parameter}	\
	-pipe -fPIC -DPIC -pthread
AM_CXXFLAGS = -Wnon-virtual-dtor

pkgsysconfdir = ${sysconfdir}/@PACKAGE@
pkgsysconf_DATA =	\
	etc/circe/circe-@@temp-late@@-template.conf

pkginclude_HEADERS =

pkginclude_@@temp_late@@dir = ${pkgincludedir}/@@temp-late@@
pkginclude_@@temp_late@@_HEADERS =	\
	circe-@@temp-late@@/src/mmain.hpp

lib_LTLIBRARIES =	\
	lib/libcirce-@@temp-late@@.la

lib_libcirce_@@temp_late@@_la_SOURCES =	\
	circe-@@temp-late@@/src/mmain.cpp

lib_libcirce_@@temp_late@@_la_LDFLAGS =	\
	-Wl,--no-undefined -module -no-undefined -version-info 0:0:0

lib_libcirce_@@temp_late@@_la_LIBADD =	\
	../circe-common/lib/libcirce-common.la	\
	-lposeidon-main
