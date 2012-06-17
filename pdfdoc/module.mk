d	:= pdfdoc

LOCAL_LIB	:= $(d)/libpdfdoc.a

SRCS_$(d)	:= $(d)/pdfdoc.c $(d)/pdfpage.c $(d)/pdfcatalog.c $(d)/pdffilter.c $(d)/pdfcontentstream.c $(d)/pdfcmds.c \
		$(d)/md5.c $(d)/sha256.c $(d)/rc4_enc.c $(d)/aes_cbc.c $(d)/aes_ecb.c $(d)/aes_core.c \
		$(d)/pdfcolorspace.c

OBJS_$(d)	:= $(SRCS_$(d):%.c=%.o)

DEPS_$(d)	:= $(SRCS_$(d):%.c=%.d)

#include 	$(DEPS_$(d))

HDRS_$(d)	:= $(d)/*.h

CLEAN		:= $(CLEAN) $(OBJS_$(d)) $(DEPS_$(d))

TGT_LIB		:= $(TGT_LIB) $(LOCAL_LIB)

$(LOCAL_LIB) : $(OBJS_$(d)) $(COMMON_HEADERS) $(HDRS_$(d))
	$(ARCHIVE)
