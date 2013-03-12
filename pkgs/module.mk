.PHONY: make_libjpeg_turbo make_libopenjpeg

pdfdoc/pdf.h : make_libjpeg_turbo make_libopenjpeg


make_libjpeg_turbo:
	cd pkgs/libjpeg-turbo;\
	./configure; make;\
	cd ../..

make_libopenjpeg:
	cd pkgs/openjpeg;\
	./configure; make;\
	cd ../..