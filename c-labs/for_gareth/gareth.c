#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

int get_bits(uint32_t value, int start, int end) {
    value = value >> end;
    size_t width = (start - end) + 1;
    uint32_t mask = (width == 32) ? UINT32_MAX : ((1u << width) - 1u);
    value = value & mask;
    printf("x=%"PRIu32"\n", value);
    return value;
}

int main() {
    uint32_t value = 0b11010100;
    uint32_t masked = get_bits(value, 31, 0);
}

