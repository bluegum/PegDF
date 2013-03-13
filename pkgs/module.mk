.PHONY: make_libjpeg_turbo make_libopenjpeg

include/pdf.h : make_libjpeg_turbo make_libopenjpeg

_pwd := $(PWD)

make_libjpeg_turbo: $(_pwd)/obj/libturbojpeg.so.0.0.0

$(_pwd)/obj/libturbojpeg.so.0.0.0 :
	cd pkgs/libjpeg-turbo;\
	./configure; make;\
	make install prefix=$(_pwd) libdir=$(_pwd)/obj/;\
	cd ../..

make_libopenjpeg:
	cd pkgs/openjpeg;\
	cmake -DBUILD_THIRDPARTY:BOOL=YES .; make;\
	cd ../..

LIBJPEG_CLEAN := $(_pwd)/obj/libturbojpeg.so.0.0.0
