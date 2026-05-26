#include <stdio.h>
#include <stdlib.h>

long old_parse_gps_time(const char *s) {
    char *end;
    long gps_time = strtol(s, &end ,10);
    if (*end != 'Z') {
        return -1;
    }
    return gps_time;
}

long parse_gps_time(const char *s) {
    char *end;
    long gps_time = strtol(s, &end ,10);
    return (*end != 'Z') ? -1 : gps_time;
}

int main(void) {
    printf("%ld \n", parse_gps_time("1685490213"));
    printf("%ld \n", parse_gps_time("1685490213Z"));
    return 0;
}
