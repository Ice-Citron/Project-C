#ifndef PRACTICE_CONFIG_H
#define PRACTICE_CONFIG_H

#include <stddef.h>

extern int sys_verbosity;   // Declaration only... no memory allocated here. 

#endif
    // Note: must then define `int sys_verbosity = 0;` in EXACTLY ONE `.c`
    // file (e.g., `config.c`).