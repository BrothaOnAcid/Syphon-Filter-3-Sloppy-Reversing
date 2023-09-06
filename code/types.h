#pragma once


#include <sys/types.h>

typedef unsigned char u8;

typedef unsigned char   undefined;
typedef unsigned short  undefined2;
typedef unsigned int    undefined4;

typedef int s32;
typedef unsigned int u32;

typedef unsigned char byte;
typedef unsigned char uchar;
typedef unsigned long ulong;
typedef unsigned int uint; 

//----------------------------------------


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



