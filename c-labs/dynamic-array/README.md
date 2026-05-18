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
   Because v is a pointer, which means we can't directly access attribute `len`
   using `.`, as it's not the actual struct object itself, but rather a pointer.
   Hence we use `v->len`, which is equivalent to `(*v).len`, which first
   dereferences the pointer v, before accessing struct-attribute `len`.

2. What does `sizeof *v->data` mean, and why can it be safer than `sizeof(int)`?
   Because if we decide to later decided to change the type of `data` from
   `int` to other data-types such as `long long`, for example, using 
   `sizeof *v->data` will ensure that `sizeof` compiler automatically feeds
   the `sizeof` function the real type of the new `data`; which decreases the 
   risk where after refactoring, the new programmer forget to modify the type of
   `sizeof`.
            // `sizeof` is a compile-time operator, not a function.
            // The compiler evaluates it and replaces it with hardcoded numbers
            // ...

3. After `intvec_free(&v)`, what should `v.data`, `v.len`, and `v.cap` become?
   They should be `NULL`?
            // ... `v->data` is a pointer, so setting it to `NULL` is correct
            // and prevents "use-after-fee" bugs. However, `len` and `cap`
            // are `size_t` (unsigned integers). You cannot set integers to 
            // `NULL`; they should simply be set to `0`.

4. In `intvec_get`, why is `out` an `int *` rather than returning the integer directly?
   I am unsure, but this reduces data duplication? As why create another copu of
   the same data if you don't need to . Furthermore, by passing the original
   object from the list; this allows the users to directly edit the returned
   object itself.
            // FEEDBACK: Incorrect, but a very logical guess. In C, passing an
            // `int` by value is extremely fast (it just goes into a CPU 
            // register), so avoiding copies isn't the issues here. 
            -
            // THE REAL REASON: ERROR HANDLING. If the function signature was
            // `int intvec_get(..., size_t index)`, what happens if the user
            // asks for index `999` in an array of len=5? If you return `-1` to
            // signal an error, what happens if `-1` was actually a valid piece
            // of data stored at that index?
            -
            // By passing an `int *out` pointer, the function can write the
            // requested data to that memory address, and use the actual return 
            // value of the function to return a status code (e.g., `INTVEC_OK`
            // or `INTVEC_ERR_BOUNDS`).

5. What should happen if `realloc` fails during `intvec_push`?
   I'm not sure, but don't we normally only do `realloc` when we have reached
   the threshold for allocating more space? Hence, `realloc` is used for
   extensions?. Idk
            // ... `realloc` is for extending space, but weren't sure about
            // failure.
            -
            // FEEDBACK: This is one of the most common ways C programs leak
            // memory or crash. If the operating system is completely out of 
            // memory, `realloc` will fail and return `NULL`.

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
