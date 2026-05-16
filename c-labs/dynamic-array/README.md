# Dynamic Array Lab

Build a small `IntVec` dynamic array in C. This is a syntax-reactivation lab: pointers, structs, heap allocation, ownership, return codes, and tests.

## Goal

Implement this API:

```c
int intvec_init(IntVec *v);
void intvec_free(IntVec *v);
int intvec_push(IntVec *v, int value);
int intvec_get(const IntVec *v, size_t index, int *out);
int intvec_set(IntVec *v, size_t index, int value);
size_t intvec_len(const IntVec *v);
```

## Build

```sh
make build
make test
make asan
```

`make build` should compile. `make test` will fail until you implement the TODOs.

## Warm-Up Questions

Answer these before coding.

1. In `IntVec *v`, why do we use `v->len` instead of `v.len`?
2. What does `sizeof *v->data` mean, and why can it be safer than `sizeof(int)`?
3. After `intvec_free(&v)`, what should `v.data`, `v.len`, and `v.cap` become?
4. In `intvec_get`, why is `out` an `int *` rather than returning the integer directly?
5. What should happen if `realloc` fails during `intvec_push`?

## Syntax Hints

- `v->field` means `(*v).field`.
- `malloc(n * sizeof *ptr)` allocates space for `n` elements of the pointed-to type.
- `realloc(old_ptr, new_size)` may move the allocation; assign it to a temporary first.
- `free(NULL)` is allowed.
- `size_t` is the standard unsigned type for sizes and indexes.
- Return `INTVEC_OK` on success and an error code on failure.
- Check pointer arguments before dereferencing them.

## Implementation Order

1. Implement `intvec_init`.
2. Implement `intvec_free`.
3. Implement `intvec_len`.
4. Implement `intvec_get`.
5. Implement `intvec_set`.
6. Implement growth inside `intvec_push`.

## Expected Behaviour

- A fresh vector has length `0`.
- Pushing values appends them in order.
- Capacity grows when length reaches capacity.
- Getting an out-of-bounds index returns `INTVEC_ERR_BOUNDS`.
- Setting an out-of-bounds index returns `INTVEC_ERR_BOUNDS`.
- Freeing a vector resets it to an empty safe state.

## Stretch Variant

After the tests pass, add:

```c
int intvec_reserve(IntVec *v, size_t min_cap);
int intvec_pop(IntVec *v, int *out);
```

Then write tests for both.
