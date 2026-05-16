#include "intvec.h"

#include <stdlib.h>

enum {
    INTVEC_INITIAL_CAP = 4
};

int intvec_init(IntVec *v)
{
    (void)v;
    return INTVEC_ERR_INVALID;
}

void intvec_free(IntVec *v)
{
    (void)v;
}

int intvec_push(IntVec *v, int value)
{
    (void)v;
    (void)value;
    return INTVEC_ERR_INVALID;
}

int intvec_get(const IntVec *v, size_t index, int *out)
{
    (void)v;
    (void)index;
    (void)out;
    return INTVEC_ERR_INVALID;
}

int intvec_set(IntVec *v, size_t index, int value)
{
    (void)v;
    (void)index;
    (void)value;
    return INTVEC_ERR_INVALID;
}

size_t intvec_len(const IntVec *v)
{
    (void)v;
    return 0;
}
