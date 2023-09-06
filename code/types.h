#pragma once


#include <sys/types.h>


typedef struct SVECTOR
{
    short vx;
    short vy;
    short vz;
    short pad;
    
} SVECTOR;


typedef struct VECTOR
{
    int vx;
    int vy;
    int vz;
    int pad;
    
} VECTOR;



typedef struct MATRIX {
    short m[9];
    long t[3];
} MATRIX;



