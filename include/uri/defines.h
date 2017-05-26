#ifndef URI_DEFINES_H
#define URI_DEFINES_H

#include <stdio.h>

#ifndef DEBUG
#define dbg(M, ...) fprintf(stderr, M, ##__VA_ARGS__)
#else
#define dbg(M, ...)
#endif

#endif
