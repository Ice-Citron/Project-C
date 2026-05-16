#ifndef PROJECT_C_INTVEC_H
#define PROJECT_C_INTVEC_H

#include <stddef.h>

typedef struct {
    int *data;
    size_t len;
    size_t cap;
} IntVec;

typedef enum {
    INTVEC_OK = 0,
    INTVEC_ERR_ALLOC = -1,
    INTVEC_ERR_BOUNDS = -2,
    INTVEC_ERR_INVALID = -3
} IntVecStatus;

int intvec_init(IntVec *v);
void intvec_free(IntVec *v);
int intvec_push(IntVec *v, int value);
int intvec_get(const IntVec *v, size_t index, int *out);
int intvec_set(IntVec *v, size_t index, int value);
size_t intvec_len(const IntVec *v);

#endif
