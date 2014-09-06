.PHONY: make_libjpeg_turbo make_libopenjpeg

#include/pdf.h : make_libjpeg_turbo
#include/pdf.h : make_libopenjpeg

_pwd := $(PWD)

LIBJPEG := $(BIN_DIR)/libturbojpeg.so
make_libjpeg_turbo: $(LIBJPEG)

$(LIBJPEG) :
	cd pkgs/libjpeg-turbo;\
	./configure --prefix $(BIN_DIR);
	make install; \
	cd ../..

#	make install prefix=$(INC_DIR) libdir=$(BIN_DIR);

LIBOPENJPEG := $(BIN_DIR)/libopenjp2.so

make_libopenjpeg : $(LIBOPENJPEG)

$(LIBOPENJPEG) :
	cd pkgs/openjpeg/build;\
	cmake -DCMAKE_INSTALL_PREFIX=$(BIN_DIR) -DBUILD_THIRDPARTY:BOOL=YES ..; \
	DESTDIR=$(BIN_DIR);\
    make install; \
	cd ../../..

#	cp $(_pwd)/obj/lib/lib* $(_pwd)/obj/;\

PKG_CLEAN := $(PKGCLEAN) $(LIBJPEG) $(LIBOPENJPEG)

include         pkgs/zlib/module.mk


#LIBS      += $(LIBOPENJPEG) $(LIBJPEG)