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

INC_DIR   += $(BIN_DIR)/include
INC_DIR   += $(BIN_DIR)/include/openjpeg-2.1
LIBS      += $(LIBOPENJPEG) $(LIBJPEG)

#
# openssl/libcrypto
#

$(LIB_CRYPTO) :  $(PKGS_DIR)/openssl/include/openssl/evp.h
	@cd $(PKGS_DIR)/openssl; $(MAKE) clean; ./config shared no-dso $(OPENSSL_DEBUG);  $(MAKE) depend; $(MAKE) build_crypto; cd ..;

$(PKGS_DIR)/openssl/include/openssl/evp.h :
	@cd openssl; ./config shared $(OPENSSL_DEBUG); $(MAKE) build_crypto; cd ..;

INC_DIR   += $(PKGS_DIR)/openssl/include
INC_DIR   += $(PKGS_DIR)/openssl/include/openssl
INC_DIR   += $(PKGS_DIR)/openssl