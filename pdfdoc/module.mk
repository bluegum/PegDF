dir	:= pdfdoc

d	:= $(dir)

LOCAL_LIB	:= $(dir)/libpdfdoc.a

OBJS_$(d)	:= $(d)/pdfdoc.o $(d)/pdfpage.o $(d)/pdfcatalog.o

DEPS_$(d)	:= $(OBJS_$(d):%=%.d)

CLEAN		:= $(CLEAN) $(OBJS_$(d)) $(DEPS_$(d))

TGT_LIB		:= $(TGT_LIB) $(LOCAL_LIB)

$(LOCAL_LIB) : $(OBJS_$(d))
		$(ARCHIVE)
