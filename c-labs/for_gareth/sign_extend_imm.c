#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

int64_t sign_extend(uint64_t value, unsigned bits) {
    uint64_t sign = (value >> (bits - 1)) & 1ULL;
    uint64_t mask = (bits == 64) ? UINT64_MAX : ((1ULL << bits) - 1ULL);
    value &= mask;
    uint64_t upper_mask = (sign == 1) ? ~mask : 0ULL;
    return (int64_t)(value | upper_mask);
}           // printf("x=%"PRId64"\n", (int64_t)(value | upper_mask));

int main() {
    printf("-1 == %"PRId64"\n", sign_extend(0b111111, 6)); // -1
    printf("-32 == %"PRId64"\n", sign_extend(0b100000, 6)); // -32
    printf("31 == %"PRId64"\n", sign_extend(0b011111, 6)); // 31
    return 0;
}