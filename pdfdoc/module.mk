d	:= pdfdoc

LOCAL_LIB	:= $(d)/libpdfdoc.a

SRCS_$(d)	:= $(d)/pdfdoc.c $(d)/pdfpage.c $(d)/pdfcatalog.c

OBJS_$(d)	:= $(SRCS_$(d):%.c=%.o)

DEPS_$(d)	:= $(SRCS_$(d):%.c=%.d)

#include 	$(DEPS_$(d))

CLEAN		:= $(CLEAN) $(OBJS_$(d)) $(DEPS_$(d))

TGT_LIB		:= $(TGT_LIB) $(LOCAL_LIB)

$(LOCAL_LIB) : $(OBJS_$(d)) $(COMMON_HEADERS)
	$(ARCHIVE)
