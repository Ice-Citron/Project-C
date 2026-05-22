#include "intvec.h"

#include <stdlib.h>

enum {
    INTVEC_INITIAL_CAP = 4
};

int intvec_init(IntVec *v)
{
    if (v == NULL) {
        return INTVEC_ERR_INVALID;
    }
    v->data = malloc(INTVEC_INITIAL_CAP * sizeof *v->data);
    if (v->data == NULL) {
        return INTVEC_ERR_ALLOC;
    }
    v->len = 0;
    v->cap = INTVEC_INITIAL_CAP;
    return INTVEC_OK;
}

void intvec_free(IntVec *v)
{
    free(v->data);
    v->data = NULL;
    v->len = 0;
    v->cap = 0;
}

int intvec_push(IntVec *v, int value)
{
    if (v == NULL) {
        return INTVEC_ERR_INVALID;
    }
    if (v->len == v->cap) {
        size_t new_cap = (v->cap == 0) ? 16 : v->cap * 2;
        int *temp = realloc(v->data, new_cap * sizeof *v->data);
        if (temp == NULL) {
            return INTVEC_ERR_ALLOC;
        }
        v->data = temp;
        v->cap = new_cap;
    }
    v->data[v->len] = value;
    v->len++;
    return INTVEC_OK;
}

int intvec_get(const IntVec *v, size_t index, int *out)
{
    if (v == NULL || out == NULL) {
        return INTVEC_ERR_INVALID;
    }
    if (index >= v->len) {
        return INTVEC_ERR_BOUNDS;
    }
    *out = v->data[index];
    return INTVEC_OK;
}

int intvec_set(IntVec *v, size_t index, int value)
{
    if (v == NULL) {
        return INTVEC_ERR_INVALID;
    }
    if (index >= v->len) {
        return INTVEC_ERR_BOUNDS;
    }
    v->data[index] = value;
    return INTVEC_OK;
}

size_t intvec_len(const IntVec *v)
{
    if (v == NULL) {
        return 0;
    }
    return v->len;
}
