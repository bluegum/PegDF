.PHONY: make_libjpeg_turbo make_libopenjpeg

include/pdf.h : make_libjpeg_turbo make_libopenjpeg

_pwd := $(PWD)

make_libjpeg_turbo: $(_pwd)/obj/libturbojpeg.so.0.0.0

$(_pwd)/obj/libturbojpeg.so.0.0.0 :
	cd pkgs/libjpeg-turbo;\
	./configure; make;\
	make install prefix=$(_pwd) libdir=$(_pwd)/obj/;\
	cd ../..

make_libopenjpeg: $(_pwd)/obj/libopenjp2.so.2.0.0

$(_pwd)/obj/libopenjp2.so.2.0.0:
	cd pkgs/openjpeg;\
	cmake -DCMAKE_INSTALL_PREFIX=$(_pwd)/obj/ -DBUILD_THIRDPARTY:BOOL=YES .; \
	make; make install; \
	cp $(_pwd)/obj/lib/lib* $(_pwd)/obj/;\
	cd ../..

LIBJPEG_CLEAN := $(_pwd)/obj/libturbojpeg.so.0.0.0
