.PHONY: make_libjpeg_turbo make_libopenjpeg

#include/pdf.h : make_libjpeg_turbo
#include/pdf.h : make_libopenjpeg

_pwd := $(PWD)

LIBJPEG := $(_pwd)/obj/libturbojpeg.so.0.0.0
make_libjpeg_turbo: $(LIBJPEG)

$(LIBJPEG) :
	cd pkgs/libjpeg-turbo;\
	./configure; make;\
	make install prefix=$(_pwd) libdir=$(_pwd)/obj/;\
	cd ../..

LIBOPENJPEG := $(_pwd)/obj/libopenjp2.so.2.0.0

make_libopenjpeg : $(LIBOPENJPEG)

$(LIBOPENJPEG) :
	cd pkgs/openjpeg;\
	cmake -DCMAKE_INSTALL_PREFIX=$(_pwd)/obj/ -DBUILD_THIRDPARTY:BOOL=YES .; \
	make; make install; \
	cp $(_pwd)/obj/lib/lib* $(_pwd)/obj/;\
	cd ../..

PKG_CLEAN := $(PKGCLEAN) $(LIBJPEG) $(LIBOPENJPEG)

include         pkgs/zlib/module.mk
