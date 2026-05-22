CC ?= clang
CFLAGS ?= -std=c17 -Wall -Wextra -Wpedantic -Wconversion -Wshadow -g -fsanitize=address,undefined -fno-omit-frame-pointer
CPPFLAGS ?= -Iinclude
SANFLAGS ?= -fsanitize=address,undefined -fno-omit-frame-pointer

BUILD_DIR := build
BUILD_STAMP := $(BUILD_DIR)/.dir
TEST_BIN := $(BUILD_DIR)/test_intvec
SRC := src/intvec.c
TEST_SRC := tests/test_intvec.c

.PHONY: all build test asan clean

all: build

$(BUILD_STAMP):
	mkdir -p $(BUILD_DIR)
	touch $(BUILD_STAMP)

$(TEST_BIN): $(SRC) $(TEST_SRC) | $(BUILD_STAMP)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(SRC) $(TEST_SRC) -o $(TEST_BIN)

build: $(TEST_BIN)

test: $(TEST_BIN)
	./$(TEST_BIN)

asan: CFLAGS += $(SANFLAGS)
asan: clean test

clean:
	rm -rf $(BUILD_DIR)
