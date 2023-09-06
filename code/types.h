#pragma once


#include <sys/types.h>

typedef int bool;

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

#define FNC

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


//--------------------------------


typedef struct HeadMID HeadMID;



struct HeadMID {
    uint f_00_sign;
    ushort f_04_s1;
    byte f_06_s2;
    byte f_07_s3;
    int f_08_u;
    HeadMID * f_0c_next;
    uint f_10_name;
    byte * f_14_ptr_sbnk;
    byte * f_18_juice_start;
    byte * f_1c_rt_juice_cur;
    byte * f_20_ptr_MMID;
    int f_24_dunno1;
    int f_28_unk1;
    uint f_2c_spd_rel;
    uint f_30_iii2;
    int f_34_unk2;
    short f_38_s;
    short f_3a_ww;
    short f_3c_unk3;
    short f_3e_yyy;
    short f_40_unkunk;
    ushort f_42_msk1;
    int field22_0x44;
    int field23_0x48;
    int field24_0x4c;
    int field25_0x50;
    int field26_0x54;
    int field27_0x58;
    int field28_0x5c;
    int field29_0x60;
    short f_64_arr_a[16];
    short f_84_arr_b[16];
    HeadMID * f_a4_ptr_ano_mid;
    byte * f_a8_ptr;
};



