# Tooling Notes

Default local toolchain:

```sh
clang -std=c17 -Wall -Wextra -Wpedantic -Wconversion -Wshadow -g
```

Useful sanitizer flags:

```sh
-fsanitize=address,undefined -fno-omit-frame-pointer
```

Working rule:

- Compile cleanly before optimising.
- Run with sanitizers before trusting memory code.
- Keep generated build files out of Git.
- Prefer reproducible commands over IDE-only builds.
