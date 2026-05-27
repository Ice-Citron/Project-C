#include <stdio.h>
#include <stdint.h>

int validate_packet(FILE *file, uint8_t *buffer, size_t max_buffer_size) {
    uint8_t header[2];
    if (fread(header, sizeof(header[0]), 2, file) < 2) {
        return -1;
    }
    
    uint16_t payload_size = (uint16_t)(header[1] << 8) | header[0];
    if (payload_size > max_buffer_size) { 
        return -1; 
    }
    
    size_t bytes_read = fread(buffer, sizeof(*buffer), payload_size, file);
    if (bytes_read != payload_size) { 
        return -1; 
    }

    return (int)bytes_read;
}

int main(void) {
    return 0;
}
