dir	:= pdfdraw

d	:= $(dir)

LOCAL_LIB	:= $(dir)/libpdfdraw.a

OBJS_$(d)	:= $(d)/pdfdraw.o

DEPS_$(d)	:= $(OBJS_$(d):%=%.d)

CLEAN		:= $(CLEAN) $(OBJS_$(d)) $(DEPS_$(d))

TGT_LIB		:= $(TGT_LIB) $(LOCAL_LIB)

$(LOCAL_LIB) : $(OBJS_$(d))
		$(ARCHIVE)
