#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

uint32_t read_u32_le(const unsigned char bytes[4]) {
    return ((uint32_t)bytes[0])
         | ((uint32_t)bytes[1] << 8)
         | ((uint32_t)bytes[2] << 16)
         | ((uint32_t)bytes[3] << 24);
         
}

int main() {
    unsigned char *bytes = malloc(sizeof(unsigned char) * 4);
    bytes[0] = 0x00;
    bytes[1] = 0x00;
    bytes[2] = 0x00;
    bytes[3] = 0x10;
    printf("Output value: %"PRIu32"", read_u32_le(bytes));
    free(bytes);
    return 0;
}