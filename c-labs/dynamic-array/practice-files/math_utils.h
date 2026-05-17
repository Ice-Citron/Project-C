#ifndef MATH_UTILS_H
#define MATH_UTILS_H

#include <stddef.h>

// `static`: Each .c file gets its own invisible copy; the linker never sees it.
// `inline`: The compiler will likely replace the call with a simple bitshift/division.
static inline size_t bytes_to_kb(size_t bytes) {
    return bytes / 1024;
}

#endif