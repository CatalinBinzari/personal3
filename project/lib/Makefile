
all: $(LIB_BUILD_DIR)/libcmocka.a

#libcmocka
#libcmocka we have already built, we just need to copy it to the build directory
$(LIB_BUILD_DIR)/libcmocka.a: libcmocka.a
	$(CP) -v $< $@

.PHONY: all clean
