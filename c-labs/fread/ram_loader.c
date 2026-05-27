#include <stdio.h>

size_t load_rom(const char *path, uint8_t *ram, size_t ram_size, 
                size_t start_offset) {
    if (start_offset >= ram_size) {
        return 0;
    }
    
    size_t max_to_read = ram_size - start_offset;
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        return 0;
    }

    ram += start_offset;
    size_t bytes_read = fread(ram, sizeof(*ram), max_to_read, file);
    fclose(file);
    return bytes_read;
}

int main(void) {
    return 0;
}
