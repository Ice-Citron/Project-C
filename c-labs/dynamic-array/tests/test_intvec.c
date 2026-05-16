#include "intvec.h"

#include <stdio.h>
#include <stdlib.h>

#define CHECK(condition)                                                        \
    do {                                                                       \
        if (!(condition)) {                                                     \
            fprintf(stderr, "CHECK failed at %s:%d: %s\n", __FILE__, __LINE__, \
                    #condition);                                               \
            exit(EXIT_FAILURE);                                                 \
        }                                                                      \
    } while (0)

static void test_init_and_free(void)
{
    IntVec v;

    CHECK(intvec_init(&v) == INTVEC_OK);
    CHECK(v.data != NULL);
    CHECK(v.len == 0);
    CHECK(v.cap >= 1);
    CHECK(intvec_len(&v) == 0);

    intvec_free(&v);
    CHECK(v.data == NULL);
    CHECK(v.len == 0);
    CHECK(v.cap == 0);
}

static void test_push_and_get(void)
{
    IntVec v;
    int out = 0;

    CHECK(intvec_init(&v) == INTVEC_OK);

    CHECK(intvec_push(&v, 10) == INTVEC_OK);
    CHECK(intvec_push(&v, 20) == INTVEC_OK);
    CHECK(intvec_push(&v, 30) == INTVEC_OK);

    CHECK(intvec_len(&v) == 3);
    CHECK(intvec_get(&v, 0, &out) == INTVEC_OK);
    CHECK(out == 10);
    CHECK(intvec_get(&v, 1, &out) == INTVEC_OK);
    CHECK(out == 20);
    CHECK(intvec_get(&v, 2, &out) == INTVEC_OK);
    CHECK(out == 30);

    intvec_free(&v);
}

static void test_growth(void)
{
    IntVec v;

    CHECK(intvec_init(&v) == INTVEC_OK);

    for (int i = 0; i < 100; i++) {
        CHECK(intvec_push(&v, i * 2) == INTVEC_OK);
    }

    CHECK(intvec_len(&v) == 100);

    for (int i = 0; i < 100; i++) {
        int out = 0;
        CHECK(intvec_get(&v, (size_t)i, &out) == INTVEC_OK);
        CHECK(out == i * 2);
    }

    intvec_free(&v);
}

static void test_set_and_bounds(void)
{
    IntVec v;
    int out = 0;

    CHECK(intvec_init(&v) == INTVEC_OK);
    CHECK(intvec_push(&v, 1) == INTVEC_OK);
    CHECK(intvec_push(&v, 2) == INTVEC_OK);

    CHECK(intvec_set(&v, 1, 99) == INTVEC_OK);
    CHECK(intvec_get(&v, 1, &out) == INTVEC_OK);
    CHECK(out == 99);

    CHECK(intvec_get(&v, 2, &out) == INTVEC_ERR_BOUNDS);
    CHECK(intvec_set(&v, 2, 100) == INTVEC_ERR_BOUNDS);

    intvec_free(&v);
}

static void test_invalid_arguments(void)
{
    IntVec v;
    int out = 0;

    CHECK(intvec_init(NULL) == INTVEC_ERR_INVALID);
    CHECK(intvec_push(NULL, 1) == INTVEC_ERR_INVALID);
    CHECK(intvec_get(NULL, 0, &out) == INTVEC_ERR_INVALID);
    CHECK(intvec_set(NULL, 0, 1) == INTVEC_ERR_INVALID);

    CHECK(intvec_init(&v) == INTVEC_OK);
    CHECK(intvec_get(&v, 0, NULL) == INTVEC_ERR_INVALID);
    intvec_free(&v);
}

int main(void)
{
    test_init_and_free();
    test_push_and_get();
    test_growth();
    test_set_and_bounds();
    test_invalid_arguments();

    puts("all intvec tests passed");
    return EXIT_SUCCESS;
}
