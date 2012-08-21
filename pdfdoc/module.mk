d	:= pdfdoc

LOCAL_LIB	:= $(d)/libpdfdoc.a

SRCS__$(d)	:= pdfdoc.c pdfpage.c pdfcatalog.c pdffilter.c pdfcontentstream.c pdfcmds.c pdfcrypto.c \
		pdfcolorspace.c pdfwrite.c

SRCS_$(d)       := $(addprefix $(d)/, $(SRCS__$(d)))

OBJS_$(d)	:= $(SRCS_$(d):%.c=%.o)

DEPS_$(d)	:= $(SRCS_$(d):%.c=%.d)

include 	$(DEPS_$(d))

HDRS_$(d)	:= $(wildcard $(d)/*.h)

CLEAN		:= $(CLEAN) $(OBJS_$(d)) $(DEPS_$(d))

TGT_LIB		:= $(TGT_LIB) $(LOCAL_LIB)

$(LOCAL_LIB) : $(OBJS_$(d))
	@echo $^ 
	$(ARCHIVE)
