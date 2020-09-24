# define compilers and other utilities
export CC=gcc
export CPP=g++
export CP=cp

# base directory - root project directory
export BASE_DIR ?= $(PWD)

# build directory - directory where the project is build
export BUILD_DIR ?= $(PWD)/build

export LIB_BUILD_DIR = $(BUILD_DIR)/lib
export SRC_BUILD_DIR = $(BUILD_DIR)/src
export TEST_BUILD_DIR = $(BUILD_DIR)/test
export BUILD_TYPE ?= debug

# directory where to build the executables
export BIN_DIR = $(BUILD_DIR)

ifeq ($(BUILD_TYPE),)
	BUILD_TYPE=debug
	OPTIM=-g
else ifeq ($(BUILD_TYPE),debug)
	BUILD_TYPE=debug
	OPTIM=-g
else ifeq ($(BUILD_TYPE),optim)
	BUILD_TYPE=optim
	OPTIM=-O3 -flto
endif

# build flags - change only if you know what you are doing
export CFLAGS = -Wall -Werror -std=c11 $(OPTIM) -fPIC
export INCLUDES = -I$(BASE_DIR)/include -I$(BASE_DIR)/src
export DEFINES = -DPIC
export ASFLAGS =
export LDFLAGS = -fPIC -L$(LIB_BUILD_DIR)

# high level build targets
# these will call specific build targets into the existing build directories
# no need to modify or add new targets unless adding a new directory to the project

all: $(BUILD_DIR)

$(BUILD_DIR): $(LIB_BUILD_DIR) $(SRC_BUILD_DIR) $(TEST_BUILD_DIR)

$(LIB_BUILD_DIR):
	mkdir -p $(LIB_BUILD_DIR)
	$(MAKE) --directory lib all

$(SRC_BUILD_DIR):
	mkdir -p $(SRC_BUILD_DIR)
	$(MAKE) --directory src all

$(TEST_BUILD_DIR):
	mkdir -p $(TEST_BUILD_DIR)
	$(MAKE) --directory test all

# cleanup built artifacts
clean:
	rm -rf $(BUILD_DIR)

# "Fake" targets (don't have a specific artifact that they save on disk, but
# are used to trigger some actions or build other targets)
.PHONY: all $(BUILD_DIR) $(LIB_BUILD_DIR) $(SRC_BUILD_DIR) $(TEST_BUILD_DIR) test clean
