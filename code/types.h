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


typedef struct RECT {
    short x;
    short y;
    short w;
    short h;
} RECT;




typedef struct GsIMAGE {
    ulong pmode;
    short px;
    short py;
    ushort pw;
    ushort ph;
    ulong * pixel;
    short cx;
    short cy;
    ushort cw;
    ushort ch;
    ulong * clut;
} GsIMAGE;



//--------------------------------


typedef struct HeadMID      HeadMID;
typedef struct HeadMMID     HeadMMID;
typedef struct HeadSBNK     HeadSBNK;
typedef struct BankProps    BankProps;
typedef struct BankTab      BankTab;
typedef struct BankEnt      BankEnt;
typedef struct SndChan      SndChan;

typedef struct DonkSub1     DonkSub1;
typedef struct DonkSub2C    DonkSub2C;

typedef struct WpnTabS10    WpnTabS10;

typedef struct PlaStAtF4    PlaStAtF4;

typedef struct ImgDerp      ImgDerp;


typedef struct StrTabHead   StrTabHead;
typedef struct Node         Node;


struct BankProps {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    byte f_06_rng1;
    byte f_07_rng2;
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




typedef void (*PFN_CHAN)(int, HeadMID*, int);


struct SndChan {
    int f00_first;
    int f_04_val1;
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
    int f_28_mb_prio;
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
    PFN_CHAN f44_ptr_code;
};





// wpn related
struct DonkSub1 {
    short f_00_sho1;
    short f_02_sho2;
    int f_04_i;
    int f_08_i2;
};



// wpn related
struct DonkSub2C {
    int f_00_i;
    short f_04_s1;
    short f_06_s2;
    short f_08_s3_mb_arr;
    short f_0a_aaa;
    short f_0c_bbb;
    byte f_e_by1;
    byte f_f_by2;
    short f_10_s1;
    short f_12_s2;
    undefined field10_0x14;
    undefined field11_0x15;
    undefined field12_0x16;
    undefined field13_0x17;
    ushort f_18_x1;
    ushort f_1a_x2;
    undefined field16_0x1c;
    undefined field17_0x1d;
    undefined field18_0x1e;
    undefined field19_0x1f;
    undefined field20_0x20;
    undefined field21_0x21;
    undefined field22_0x22;
    undefined field23_0x23;
    undefined field24_0x24;
    undefined field25_0x25;
    undefined field26_0x26;
    undefined field27_0x27;
    undefined field28_0x28;
    undefined field29_0x29;
    undefined field30_0x2a;
    undefined field31_0x2b;
};



// icons ?
struct WpnTabS10 {
    int f_0_u;
    short f_2_shsh;
    byte f_6_qq;
    byte f_7_ub;
    short f_8_x1;
    ushort f_a_x2;
    ushort f_c_sh2;
    short f_e_sh3;
};







struct PlaStAtF4 {
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
    undefined field24_0x18;
    undefined field25_0x19;
    undefined field26_0x1a;
    undefined field27_0x1b;
    undefined field28_0x1c;
    undefined field29_0x1d;
    undefined field30_0x1e;
    undefined field31_0x1f;
    undefined field32_0x20;
    undefined field33_0x21;
    undefined field34_0x22;
    undefined field35_0x23;
    undefined field36_0x24;
    undefined field37_0x25;
    undefined field38_0x26;
    undefined field39_0x27;
    undefined field40_0x28;
    undefined field41_0x29;
    undefined field42_0x2a;
    undefined field43_0x2b;
    undefined field44_0x2c;
    undefined field45_0x2d;
    undefined field46_0x2e;
    undefined field47_0x2f;
    undefined field48_0x30;
    undefined field49_0x31;
    undefined field50_0x32;
    undefined field51_0x33;
    undefined field52_0x34;
    undefined field53_0x35;
    undefined field54_0x36;
    undefined field55_0x37;
    undefined field56_0x38;
    undefined field57_0x39;
    undefined field58_0x3a;
    undefined field59_0x3b;
    undefined field60_0x3c;
    undefined field61_0x3d;
    undefined field62_0x3e;
    undefined field63_0x3f;
    undefined field64_0x40;
    undefined field65_0x41;
    undefined field66_0x42;
    undefined field67_0x43;
    undefined field68_0x44;
    undefined field69_0x45;
    undefined field70_0x46;
    undefined field71_0x47;
    undefined field72_0x48;
    undefined field73_0x49;
    undefined field74_0x4a;
    undefined field75_0x4b;
    undefined field76_0x4c;
    undefined field77_0x4d;
    undefined field78_0x4e;
    undefined field79_0x4f;
    undefined field80_0x50;
    undefined field81_0x51;
    undefined field82_0x52;
    undefined field83_0x53;
    undefined field84_0x54;
    undefined field85_0x55;
    undefined field86_0x56;
    undefined field87_0x57;
    undefined field88_0x58;
    undefined field89_0x59;
    undefined field90_0x5a;
    undefined field91_0x5b;
    undefined field92_0x5c;
    undefined field93_0x5d;
    undefined field94_0x5e;
    undefined field95_0x5f;
    undefined field96_0x60;
    undefined field97_0x61;
    undefined field98_0x62;
    undefined field99_0x63;
    VECTOR f_64_vc;
    undefined field101_0x74;
    undefined field102_0x75;
    undefined field103_0x76;
    undefined field104_0x77;
    undefined field105_0x78;
    undefined field106_0x79;
    undefined field107_0x7a;
    undefined field108_0x7b;
    undefined field109_0x7c;
    undefined field110_0x7d;
    undefined field111_0x7e;
    undefined field112_0x7f;
    undefined field113_0x80;
    undefined field114_0x81;
    undefined field115_0x82;
    undefined field116_0x83;
    undefined field117_0x84;
    undefined field118_0x85;
    undefined field119_0x86;
    undefined field120_0x87;
    undefined field121_0x88;
    undefined field122_0x89;
    undefined field123_0x8a;
    undefined field124_0x8b;
    undefined field125_0x8c;
    undefined field126_0x8d;
    undefined field127_0x8e;
    undefined field128_0x8f;
    undefined field129_0x90;
    undefined field130_0x91;
    undefined field131_0x92;
    undefined field132_0x93;
    undefined field133_0x94;
    undefined field134_0x95;
    undefined field135_0x96;
    undefined field136_0x97;
    undefined field137_0x98;
    undefined field138_0x99;
    undefined field139_0x9a;
    undefined field140_0x9b;
    undefined field141_0x9c;
    undefined field142_0x9d;
    undefined field143_0x9e;
    undefined field144_0x9f;
    undefined field145_0xa0;
    undefined field146_0xa1;
    undefined field147_0xa2;
    undefined field148_0xa3;
    undefined field149_0xa4;
    undefined field150_0xa5;
    undefined field151_0xa6;
    undefined field152_0xa7;
    undefined field153_0xa8;
    undefined field154_0xa9;
    undefined field155_0xaa;
    undefined field156_0xab;
    undefined field157_0xac;
    undefined field158_0xad;
    undefined field159_0xae;
    undefined field160_0xaf;
    undefined field161_0xb0;
    undefined field162_0xb1;
    undefined field163_0xb2;
    undefined field164_0xb3;
    undefined field165_0xb4;
    undefined field166_0xb5;
    undefined field167_0xb6;
    undefined field168_0xb7;
    undefined field169_0xb8;
    undefined field170_0xb9;
    undefined field171_0xba;
    undefined field172_0xbb;
    undefined field173_0xbc;
    undefined field174_0xbd;
    undefined field175_0xbe;
    undefined field176_0xbf;
    undefined field177_0xc0;
    undefined field178_0xc1;
    undefined field179_0xc2;
    undefined field180_0xc3;
    undefined field181_0xc4;
    undefined field182_0xc5;
    undefined field183_0xc6;
    undefined field184_0xc7;
    undefined field185_0xc8;
    undefined field186_0xc9;
    undefined field187_0xca;
    undefined field188_0xcb;
    undefined field189_0xcc;
    undefined field190_0xcd;
    undefined field191_0xce;
    undefined field192_0xcf;
    undefined field193_0xd0;
    undefined field194_0xd1;
    undefined field195_0xd2;
    undefined field196_0xd3;
    undefined field197_0xd4;
    undefined field198_0xd5;
    undefined field199_0xd6;
    undefined field200_0xd7;
    undefined field201_0xd8;
    undefined field202_0xd9;
    undefined field203_0xda;
    undefined field204_0xdb;
    undefined field205_0xdc;
    undefined field206_0xdd;
    undefined field207_0xde;
    undefined field208_0xdf;
    undefined field209_0xe0;
    undefined field210_0xe1;
    undefined field211_0xe2;
    undefined field212_0xe3;
    undefined field213_0xe4;
    undefined field214_0xe5;
    undefined field215_0xe6;
    undefined field216_0xe7;
    undefined field217_0xe8;
    undefined field218_0xe9;
    undefined field219_0xea;
    undefined field220_0xeb;
    undefined field221_0xec;
    undefined field222_0xed;
    undefined field223_0xee;
    undefined field224_0xef;
    undefined field225_0xf0;
    undefined field226_0xf1;
    undefined field227_0xf2;
    undefined field228_0xf3;
    undefined field229_0xf4;
    undefined field230_0xf5;
    undefined field231_0xf6;
    undefined field232_0xf7;
    undefined field233_0xf8;
    undefined field234_0xf9;
    undefined field235_0xfa;
    undefined field236_0xfb;
    undefined field237_0xfc;
    undefined field238_0xfd;
    undefined field239_0xfe;
    undefined field240_0xff;
    undefined field241_0x100;
    undefined field242_0x101;
    undefined field243_0x102;
    undefined field244_0x103;
    undefined field245_0x104;
    undefined field246_0x105;
    undefined field247_0x106;
    undefined field248_0x107;
    undefined field249_0x108;
    undefined field250_0x109;
    undefined field251_0x10a;
    undefined field252_0x10b;
    undefined field253_0x10c;
    undefined field254_0x10d;
    undefined field255_0x10e;
    undefined field256_0x10f;
    undefined field257_0x110;
    undefined field258_0x111;
    undefined field259_0x112;
    undefined field260_0x113;
    undefined field261_0x114;
    undefined field262_0x115;
    undefined field263_0x116;
    undefined field264_0x117;
    undefined field265_0x118;
    undefined field266_0x119;
    undefined field267_0x11a;
    undefined field268_0x11b;
    undefined field269_0x11c;
    undefined field270_0x11d;
    undefined field271_0x11e;
    undefined field272_0x11f;
    undefined field273_0x120;
    undefined field274_0x121;
    undefined field275_0x122;
    undefined field276_0x123;
    undefined field277_0x124;
    undefined field278_0x125;
    undefined field279_0x126;
    undefined field280_0x127;
    undefined field281_0x128;
    undefined field282_0x129;
    undefined field283_0x12a;
    undefined field284_0x12b;
    undefined field285_0x12c;
    undefined field286_0x12d;
    undefined field287_0x12e;
    undefined field288_0x12f;
    undefined field289_0x130;
    undefined field290_0x131;
    undefined field291_0x132;
    undefined field292_0x133;
    undefined field293_0x134;
    undefined field294_0x135;
    undefined field295_0x136;
    undefined field296_0x137;
    undefined field297_0x138;
    undefined field298_0x139;
    undefined field299_0x13a;
    undefined field300_0x13b;
    undefined field301_0x13c;
    undefined field302_0x13d;
    undefined field303_0x13e;
    undefined field304_0x13f;
    undefined field305_0x140;
    undefined field306_0x141;
    undefined field307_0x142;
    undefined field308_0x143;
    undefined field309_0x144;
    undefined field310_0x145;
    undefined field311_0x146;
    undefined field312_0x147;
    undefined field313_0x148;
    undefined field314_0x149;
    undefined field315_0x14a;
    undefined field316_0x14b;
    undefined field317_0x14c;
    undefined field318_0x14d;
    undefined field319_0x14e;
    undefined field320_0x14f;
    undefined field321_0x150;
    undefined field322_0x151;
    undefined field323_0x152;
    undefined field324_0x153;
    undefined field325_0x154;
    undefined field326_0x155;
    undefined field327_0x156;
    undefined field328_0x157;
    undefined field329_0x158;
    undefined field330_0x159;
    undefined field331_0x15a;
    undefined field332_0x15b;
    undefined field333_0x15c;
    undefined field334_0x15d;
    undefined field335_0x15e;
    undefined field336_0x15f;
    undefined field337_0x160;
    undefined field338_0x161;
    undefined field339_0x162;
    undefined field340_0x163;
    undefined field341_0x164;
    undefined field342_0x165;
    undefined field343_0x166;
    undefined field344_0x167;
    undefined field345_0x168;
    undefined field346_0x169;
    undefined field347_0x16a;
    undefined field348_0x16b;
    undefined field349_0x16c;
    undefined field350_0x16d;
    undefined field351_0x16e;
    undefined field352_0x16f;
    undefined field353_0x170;
    undefined field354_0x171;
    undefined field355_0x172;
    undefined field356_0x173;
    undefined field357_0x174;
    undefined field358_0x175;
    undefined field359_0x176;
    undefined field360_0x177;
    undefined field361_0x178;
    undefined field362_0x179;
    undefined field363_0x17a;
    undefined field364_0x17b;
    undefined field365_0x17c;
    undefined field366_0x17d;
    undefined field367_0x17e;
    undefined field368_0x17f;
    undefined field369_0x180;
    undefined field370_0x181;
    undefined field371_0x182;
    undefined field372_0x183;
    undefined field373_0x184;
    undefined field374_0x185;
    undefined field375_0x186;
    undefined field376_0x187;
    undefined field377_0x188;
    undefined field378_0x189;
    undefined field379_0x18a;
    undefined field380_0x18b;
    undefined field381_0x18c;
    undefined field382_0x18d;
    undefined field383_0x18e;
    undefined field384_0x18f;
    undefined field385_0x190;
    undefined field386_0x191;
    undefined field387_0x192;
    undefined field388_0x193;
    undefined field389_0x194;
    undefined field390_0x195;
    undefined field391_0x196;
    undefined field392_0x197;
    undefined field393_0x198;
    undefined field394_0x199;
    undefined field395_0x19a;
    undefined field396_0x19b;
    undefined field397_0x19c;
    undefined field398_0x19d;
    undefined field399_0x19e;
    undefined field400_0x19f;
    undefined field401_0x1a0;
    undefined field402_0x1a1;
    undefined field403_0x1a2;
    undefined field404_0x1a3;
    undefined field405_0x1a4;
    undefined field406_0x1a5;
    undefined field407_0x1a6;
    undefined field408_0x1a7;
    undefined field409_0x1a8;
    undefined field410_0x1a9;
    undefined field411_0x1aa;
    undefined field412_0x1ab;
    undefined field413_0x1ac;
    undefined field414_0x1ad;
    undefined field415_0x1ae;
    undefined field416_0x1af;
    undefined field417_0x1b0;
    undefined field418_0x1b1;
    undefined field419_0x1b2;
    undefined field420_0x1b3;
    undefined field421_0x1b4;
    undefined field422_0x1b5;
    undefined field423_0x1b6;
    undefined field424_0x1b7;
    undefined field425_0x1b8;
    undefined field426_0x1b9;
    undefined field427_0x1ba;
    undefined field428_0x1bb;
    undefined field429_0x1bc;
    undefined field430_0x1bd;
    undefined field431_0x1be;
    undefined field432_0x1bf;
    undefined field433_0x1c0;
    undefined field434_0x1c1;
    undefined field435_0x1c2;
    undefined field436_0x1c3;
    undefined field437_0x1c4;
    undefined field438_0x1c5;
    undefined field439_0x1c6;
    undefined field440_0x1c7;
    undefined field441_0x1c8;
    undefined field442_0x1c9;
    undefined field443_0x1ca;
    undefined field444_0x1cb;
    undefined field445_0x1cc;
    undefined field446_0x1cd;
    undefined field447_0x1ce;
    undefined field448_0x1cf;
    undefined field449_0x1d0;
    undefined field450_0x1d1;
    undefined field451_0x1d2;
    undefined field452_0x1d3;
    undefined field453_0x1d4;
    undefined field454_0x1d5;
    undefined field455_0x1d6;
    undefined field456_0x1d7;
    undefined field457_0x1d8;
    undefined field458_0x1d9;
    undefined field459_0x1da;
    undefined field460_0x1db;
    undefined field461_0x1dc;
    undefined field462_0x1dd;
    undefined field463_0x1de;
    undefined field464_0x1df;
    undefined field465_0x1e0;
    undefined field466_0x1e1;
    undefined field467_0x1e2;
    undefined field468_0x1e3;
    undefined field469_0x1e4;
    undefined field470_0x1e5;
    undefined field471_0x1e6;
    undefined field472_0x1e7;
    undefined field473_0x1e8;
    undefined field474_0x1e9;
    undefined field475_0x1ea;
    undefined field476_0x1eb;
    undefined field477_0x1ec;
    undefined field478_0x1ed;
    undefined field479_0x1ee;
    undefined field480_0x1ef;
    undefined field481_0x1f0;
    undefined field482_0x1f1;
    undefined field483_0x1f2;
    undefined field484_0x1f3;
    undefined field485_0x1f4;
    undefined field486_0x1f5;
    undefined field487_0x1f6;
    undefined field488_0x1f7;
    undefined field489_0x1f8;
    undefined field490_0x1f9;
    undefined field491_0x1fa;
    undefined field492_0x1fb;
    undefined field493_0x1fc;
    undefined field494_0x1fd;
    undefined field495_0x1fe;
    undefined field496_0x1ff;
    undefined field497_0x200;
    undefined field498_0x201;
    undefined field499_0x202;
    undefined field500_0x203;
    undefined field501_0x204;
    undefined field502_0x205;
    undefined field503_0x206;
    undefined field504_0x207;
    undefined field505_0x208;
    undefined field506_0x209;
    undefined field507_0x20a;
    undefined field508_0x20b;
    undefined field509_0x20c;
    undefined field510_0x20d;
    undefined field511_0x20e;
    undefined field512_0x20f;
    undefined field513_0x210;
    undefined field514_0x211;
    undefined field515_0x212;
    undefined field516_0x213;
    int f_214_i;
    int f_218_i3;
    int f_21c_i2;
    int f_220_i4;
    VECTOR f_224_vc;
    VECTOR f_234_vc2;
};




struct ImgDerp {
    byte * f_00_ptr;
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    byte f_08_dunno;
    byte f_09_mb_uploaded;
    undefined field7_0xa;
    undefined field8_0xb;
    GsIMAGE f_0c_gs_img;
    int f_28_dunno;
};



struct StrTabHead {
    byte * ptr_dun;
    int bb;
    int cc;
    int dd;
};


struct Node {
    MATRIX f_00_mtx;
    Node * f_20_n1;
    Node * f_24_n2;
    Node * f_24_n3;
    byte f_2c_b0;
    byte f_2d_b1;
    byte f_2e_b2;
    byte f_2f_b3;
};



//--------------------------- mad skillz

inline ushort __EvilGet2_2(void* src)
{
	ushort* s = (ushort*)src;
	return s[1];
}


