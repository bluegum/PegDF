d	:= zlib

LOCAL_LIB	:= $(d)/libzlib.a

SRCS__$(d)	:=         adler32.c \
        compress.c \
        crc32.c \
        deflate.c \
        inffast.c \
        inflate.c \
        inftrees.c \
        trees.c \
        uncompr.c \
        zutil.c

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
