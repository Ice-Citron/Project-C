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