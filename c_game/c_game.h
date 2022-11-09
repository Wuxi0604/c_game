#ifndef C_GAME_H
#define C_GAME_H

#include <stdio.h>
#include <stdlib.h>


#define FALSE 0
#define TRUE  1
typedef int gbool;

typedef signed char         sint8;
typedef unsigned char       uint8;
typedef signed int          sint16;
typedef unsigned int        uint16;
typedef signed long         sint32;
typedef unsigned int        uint32;
typedef signed long long    sint64;
typedef unsigned long long  uint64;

#ifdef GAME_DEBUG
#define GAME_ASSERT(exp)\
    if(exp != TRUE)\
    {\
        uint16 i = 1; \
        uint16 nosense = 0; \
        uint16 result;      \
        fprintf(stderr, "Project crashed in file: %s, line: %d\n", __FILE__, __LINE__); \
        result = i / nosense; \
    }
#endif


#endif
