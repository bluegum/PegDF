.PHONY: make_libjpeg_turbo make_libopenjpeg

_pwd := $(PWD)

LIBJPEG := $(BIN_DIR)/lib/libturbojpeg.a
make_libjpeg_turbo: $(LIBJPEG)
$(LIBJPEG) :
	cd pkgs/libjpeg-turbo;\
	./configure --prefix $(BIN_DIR);
	make install; \
	cd ../..

#	make install prefix=$(INC_DIR) libdir=$(BIN_DIR);

LIBOPENJPEG := $(BIN_DIR)/lib/libopenjp2.a

make_libopenjpeg : $(LIBOPENJPEG)

$(LIBOPENJPEG) :
	cd pkgs/openjpeg/build;\
	cmake -DCMAKE_INSTALL_PREFIX=$(_pwd)/$(BIN_DIR) -DBUILD_THIRDPARTY:BOOL=YES -DBUILD_SHARED_LIBS:bool=OFF ..; \
    make install; \
	cd ../../..

PKG_CLEAN := $(PKGCLEAN) $(LIBJPEG) $(LIBOPENJPEG)

include         pkgs/zlib/module.mk


LIBS      += $(LIBOPENJPEG) $(LIBJPEG)
