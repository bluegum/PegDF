d	:= pdfdraw

LOCAL_LIB	:= $(d)/libpdfdraw.a

SRCS_$(d)	:= $(d)/pdfdraw.c

OBJS_$(d)	:= $(SRCS_$(d):%.c=%.o)

DEPS_$(d)	:= $(OBJS_$(d):%=%.d)

CLEAN		:= $(CLEAN) $(OBJS_$(d)) $(DEPS_$(d))

TGT_LIB		:= $(TGT_LIB) $(LOCAL_LIB)

$(LOCAL_LIB) : $(OBJS_$(d)) $(COMMON_HEADERS)
		$(ARCHIVE)
