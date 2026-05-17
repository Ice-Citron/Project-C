#ifndef THE_SAFE_MACRO_H
#define THE_SAFE_MACRO_H

#include <stdio.h>      // home for `printf()` and all other console/file printing functions
                        // `fprintf()`, `sprintf()`
#include <stdlib.h>     // home for `malloc()`, `calloc()` and `realloc()`. 

#define LOG_AND_FREE(ptr) \
    do { \
        printf("Freeing\n"); \
        free(ptr); \
    } while (0)

#endif