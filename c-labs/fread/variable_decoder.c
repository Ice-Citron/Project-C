#include <stdint.h>

uint32_t fetch_variable_instruction(FILE *file, int *error) {
    // first byte of instruction is opcode
    if (error != NULL) *error = 0;
    
    uint8_t opcode;
    if (fread(&opcode, 1, 1, file) != 1) {
        if (error != NULL) *error = 1;
        return 0;
    }

    uint8_t instruction[3] = {0};
    size_t bytes_to_read = (opcode < 0x80) ? 1 : 3;
    size_t instruction_read = fread(&bytes_to_read, 1, 1, file);

    if (instruction_read != 1) {
        if (error != NULL) *error = 1;
        return 0;
    }

    return (instruction[2] << 24) 
         | (instruction[1] << 16)
         | (instruction[0] << 8)
         | opcode;
}

int main(void) {
    return 0;
}