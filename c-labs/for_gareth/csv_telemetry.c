#include <stdio.h>
#include <stdlib.h>

void parse_encoders(const char *s, long long out[3]) {
    char *end = (char *)s;
    int i = 0;
    do {
        long long val = strtoll(end, &end, 10);
        if (val == 0 && end[0] == ',') {
            end += 1;
        } else {
            out[i] = val;
            i++;
        }
    } while(*end != '\0');
}

void super_encoders(const char *s, long long out[3]) {
    char *end = (char *)s;
    for (int i = 0; i < 3; i++) {
        if (*end == ',') { end++; }
        if (*end == '\0') { break; }
        out[i] = strtoll(end, &end, 10);
    }
}

int main(void) {
    const char* str = "1005,2040,993";
    long long* output = malloc(3 * sizeof(long long));
    super_encoders(str, output);
    for (int i = 0; i < 3; i++) {
        printf("Value %d: %lld \n", i, output[i]);
    }
    return 0;
}
