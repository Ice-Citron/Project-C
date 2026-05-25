# Variables
CC = clang
CFLAGS = -std=c17 -Wall -Wextra -Wpedantic -Wconversion -Wshadow -g
ASAN_FLAGS = -fsanitize=address,undefined -fno-omit-frame-pointer
INCLUDES = - Iinclude
SRC = src/bit_utils.c tests/test_bit_utils.c	# Update these as needed
OUT = build/test_runner

# Default target: builds without sanitizers
build: build
	mkdir -p build
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC) -o $(OUT)

# ASan target: builds with sanitizers
asan: clean
	mkdir -p build
	$(CC) $(CFLAGS) $(ASAN_FLAGS) $(INCLUDES) $(SRC) -o $(OUT)

# Test target: builds ASan and runs it immediately
test: asan
	./$(OUT)

# Clean target: removes build artifacts
clean: rm -rf build