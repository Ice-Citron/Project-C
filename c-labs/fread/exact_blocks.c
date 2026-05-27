#include <stdio.h>
#include <stdint.h>

int read_exact_blocks(FILE *file, uint16_t *dest, size_t count) {
    size_t blocks_read = fread(dest, sizeof(*dest), count, file);       // BSCF
    if (blocks_read < count) { return -1; }
    return 0;
}

int main(void) {
    return(0);
}
