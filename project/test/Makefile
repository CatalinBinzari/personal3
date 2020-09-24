
# Common libraries (shared by all tests)
LIBS=-lcmocka

# # Client only sources and libraries
# CLIENT_SOURCES=client.c
# CLIENT_LIBS=

# # Server only sources and libraries
# SERVER_SOURCES=server.c
# SERVER_LIBS=

# # DO NOT CHANGE: Build aids, source and object lists
# SOURCES=$(COMMON_SOURCES) $(SERVER_SOURCES) $(CLIENT_SOURCES)
# COMMON_OBJECTS = $(patsubst %,$(SRC_BUILD_DIR)/%,$(COMMON_SOURCES:.c=.o))
# CLIENT_OBJECTS = $(patsubst %,$(SRC_BUILD_DIR)/%,$(CLIENT_SOURCES:.c=.o))
# SERVER_OBJECTS = $(patsubst %,$(SRC_BUILD_DIR)/%,$(SERVER_SOURCES:.c=.o))
# OBJECTS=$(COMMON_OBJECTS) $(CLIENT_OBJECTS) $(SERVER_OBJECTS)

-include $(OBJECTS:.o=.d)

# targets for building our server and client binaries
all: $(BIN_DIR)/test_main

# do not change: instructions on how to build object files
$(TEST_BUILD_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -MMD -MP $(DEFINES) $(INCLUDES) -c $< -o $@

# test executables, add as many as you need; test_main is added as and example
$(BIN_DIR)/test_main: $(TEST_BUILD_DIR)/test_main.o
	$(CC) $(LDFLAGS) $< $(LIBS) -o $@

# phony targets
.PHONY: all clean
