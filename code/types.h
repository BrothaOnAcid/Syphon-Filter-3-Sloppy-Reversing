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

typedef long long  longlong;
typedef unsigned long long  ulonglong;

#define FNC

#define false (0)
#define true (1)



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


typedef struct HeadMID      HeadMID;
typedef struct HeadMMID     HeadMMID;
typedef struct HeadSBNK     HeadSBNK;
typedef struct BankProps    BankProps;
typedef struct BankTab      BankTab;
typedef struct BankEnt      BankEnt;
typedef struct SndChan      SndChan;

struct BankProps {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct BankTab {
    byte smp_ind;
    byte vo;
    ushort pad;
    BankProps * p_juice;
};


struct BankEnt {
    int f_00_i;
    HeadSBNK * f_04_my;
    uint f_08_nam1;
    uint f_0c_nam2;
    short f_10_i;
    short f_12_i2;
    int field6_0x14;
    int field7_0x18;
    HeadMMID * f_1c_ptr_mmid;
    int f_20_dunno;
};




struct HeadSBNK {
    uint f_00_SBNK;
    uint f_04_u;
    uint f_08_va;
    uint f_0c_nam;
    byte f_10_some_ind;
    byte f_11_b2;
    short f_12_sho;
    HeadSBNK * f_14_ptr_sb;
    short f_18_s;
    short f_1a_s2;
    int f_1c_uuu;
    BankEnt * f_20_ents;
    BankTab * f_24_tabs;
    BankProps * f_28_props;
    int field12_0x2c;
    int field13_0x30;
    int field14_0x34;
    int field15_0x38;
    int field16_0x3c;
    int field17_0x40;
    int field18_0x44;
    int field19_0x48;
    int field20_0x4c;
    int field21_0x50;
    undefined field22_0x54;
    undefined field23_0x55;
    undefined field24_0x56;
    undefined field25_0x57;
    undefined field26_0x58;
    undefined field27_0x59;
    undefined field28_0x5a;
    undefined field29_0x5b;
    undefined field30_0x5c;
    undefined field31_0x5d;
    undefined field32_0x5e;
    undefined field33_0x5f;
    undefined field34_0x60;
    undefined field35_0x61;
    undefined field36_0x62;
    undefined field37_0x63;
    undefined field38_0x64;
    undefined field39_0x65;
    undefined field40_0x66;
    undefined field41_0x67;
    undefined field42_0x68;
    undefined field43_0x69;
    undefined field44_0x6a;
    undefined field45_0x6b;
    undefined field46_0x6c;
    undefined field47_0x6d;
    undefined field48_0x6e;
    undefined field49_0x6f;
    undefined field50_0x70;
    undefined field51_0x71;
    undefined field52_0x72;
    undefined field53_0x73;
    undefined field54_0x74;
    undefined field55_0x75;
    undefined field56_0x76;
    undefined field57_0x77;
    undefined field58_0x78;
    undefined field59_0x79;
    undefined field60_0x7a;
    undefined field61_0x7b;
    undefined field62_0x7c;
    undefined field63_0x7d;
    undefined field64_0x7e;
    undefined field65_0x7f;
};



struct HeadMMID {
    uint f_00_sign;
    byte f_04_aa;
    byte f_05_bb;
    byte f_06_cc;
    byte f_07_num_midi;
    uint f_08_name;
    HeadMID * f_0c_ar_mid[16];
};


struct HeadMID {
    uint f_00_sign;
    ushort f_04_s1;
    byte f_06_s2;
    byte f_07_s3;
    int f_08_u;
    HeadMID * f_0c_next;
    uint f_10_name;
    HeadSBNK* f_14_ptr_sbnk;
    byte * f_18_juice_start;
    byte * f_1c_rt_juice_cur;
    HeadMMID * f_20_ptr_MMID;
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
    HeadMID * f_a8_ptr_ano_mid2;
};



struct SndChan {
    int f00_first;
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    int f_08_i2;
    short f_c_unk1;
    short f_e_unk2;
    short f_10_mini;
    short f_12_va;
    int f_14_i;
    ushort f18_note;
    undefined field15_0x1a;
    undefined field16_0x1b;
    undefined field17_0x1c;
    undefined field18_0x1d;
    undefined field19_0x1e;
    undefined field20_0x1f;
    int f_20_fla;
    undefined field22_0x24;
    undefined field23_0x25;
    undefined field24_0x26;
    undefined field25_0x27;
    undefined field26_0x28;
    undefined field27_0x29;
    undefined field28_0x2a;
    undefined field29_0x2b;
    undefined field30_0x2c;
    undefined field31_0x2d;
    undefined field32_0x2e;
    undefined field33_0x2f;
    int f30_inte;
    undefined field35_0x34;
    undefined field36_0x35;
    undefined field37_0x36;
    undefined field38_0x37;
    undefined field39_0x38;
    undefined field40_0x39;
    undefined field41_0x3a;
    undefined field42_0x3b;
    undefined field43_0x3c;
    undefined field44_0x3d;
    undefined field45_0x3e;
    undefined field46_0x3f;
    HeadMID * f_40_my_mid;
    void (* f44_ptr_code)(int, HeadMID *, int);
};


