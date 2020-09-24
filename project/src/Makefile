
# Common sources and libraries (for both the client and the server)
COMMON_SOURCES=
COMMON_LIBS=-lm

# Client only sources and libraries
CLIENT_SOURCES=client.c
CLIENT_LIBS=

# Server only sources and libraries
SERVER_SOURCES=server.c
SERVER_LIBS=

# DO NOT CHANGE: Build aids, source and object lists
SOURCES=$(COMMON_SOURCES) $(SERVER_SOURCES) $(CLIENT_SOURCES)
COMMON_OBJECTS = $(patsubst %,$(SRC_BUILD_DIR)/%,$(COMMON_SOURCES:.c=.o))
CLIENT_OBJECTS = $(patsubst %,$(SRC_BUILD_DIR)/%,$(CLIENT_SOURCES:.c=.o))
SERVER_OBJECTS = $(patsubst %,$(SRC_BUILD_DIR)/%,$(SERVER_SOURCES:.c=.o))
OBJECTS=$(COMMON_OBJECTS) $(CLIENT_OBJECTS) $(SERVER_OBJECTS)

-include $(OBJECTS:.o=.d)

# targets for building our server and client binaries
all: $(BIN_DIR)/client $(BIN_DIR)/server

# DO NOT CHANGE: instructions on how to build object files and the two main executables
$(SRC_BUILD_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -MMD -MP $(DEFINES) $(INCLUDES) -c $< -o $@

$(BIN_DIR)/client: $(CLIENT_OBJECTS) $(COMMON_OBJECTS)
	$(CC) $(LDFLAGS) $(CLIENT_OBJECTS) $(COMMON_OBJECTS) $(COMMON_LIBS) $(SERVER_LIBS) -o $@

$(BIN_DIR)/server: $(SERVER_OBJECTS) $(COMMON_OBJECTS)
	$(CC) $(LDFLAGS) $(SERVER_OBJECTS) $(COMMON_OBJECTS) $(COMMON_LIBS) $(SERVER_LIBS) -o $@

# phony targets
.PHONY: all clean
