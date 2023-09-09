
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

typedef struct CdlLOC CdlLOC;
typedef struct CdlFILE CdlFILE;

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



struct CdlLOC {
    byte minute;
    byte second;
    byte sector;
    byte track;
};

struct CdlFILE {
    CdlLOC pos;
    uint size;
    char name[16];
};




//--------------------------------

// made up
typedef struct HmdHead      HmdHead;
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

typedef struct ListElem     ListElem;
typedef struct DaList       DaList;
typedef struct AnimPlayer   AnimPlayer;



struct HmdHead {
    short f_00_unk;
    short f_02_unk2;
    int f_04_num_bones;
    int f_08_num_faces4;
    int f_0c_u1;
    int f_10_u2;
    byte * f_14_off_sht;
    int f_18_u3;
    char f_1c_name[8];
    int f_24_un4;
};



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

typedef void (*PFN_VOID)(void);


typedef void (*PFN_CHAN)(uint, HeadMID*, int);


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
    byte* f34_unk_pt;
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





// player related
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
    uint f_18_bits;
    undefined field25_0x1c;
    undefined field26_0x1d;
    undefined field27_0x1e;
    undefined field28_0x1f;
    undefined field29_0x20;
    undefined field30_0x21;
    undefined field31_0x22;
    undefined field32_0x23;
    undefined field33_0x24;
    undefined field34_0x25;
    undefined field35_0x26;
    undefined field36_0x27;
    undefined field37_0x28;
    undefined field38_0x29;
    undefined field39_0x2a;
    undefined field40_0x2b;
    undefined field41_0x2c;
    undefined field42_0x2d;
    undefined field43_0x2e;
    undefined field44_0x2f;
    undefined field45_0x30;
    undefined field46_0x31;
    undefined field47_0x32;
    undefined field48_0x33;
    undefined field49_0x34;
    undefined field50_0x35;
    undefined field51_0x36;
    undefined field52_0x37;
    undefined field53_0x38;
    undefined field54_0x39;
    undefined field55_0x3a;
    undefined field56_0x3b;
    undefined field57_0x3c;
    undefined field58_0x3d;
    undefined field59_0x3e;
    undefined field60_0x3f;
    undefined field61_0x40;
    undefined field62_0x41;
    undefined field63_0x42;
    undefined field64_0x43;
    undefined field65_0x44;
    undefined field66_0x45;
    undefined field67_0x46;
    undefined field68_0x47;
    undefined field69_0x48;
    undefined field70_0x49;
    undefined field71_0x4a;
    undefined field72_0x4b;
    undefined field73_0x4c;
    undefined field74_0x4d;
    undefined field75_0x4e;
    undefined field76_0x4f;
    undefined field77_0x50;
    undefined field78_0x51;
    undefined field79_0x52;
    undefined field80_0x53;
    undefined field81_0x54;
    undefined field82_0x55;
    undefined field83_0x56;
    undefined field84_0x57;
    undefined field85_0x58;
    undefined field86_0x59;
    undefined field87_0x5a;
    undefined field88_0x5b;
    undefined field89_0x5c;
    undefined field90_0x5d;
    undefined field91_0x5e;
    undefined field92_0x5f;
    undefined field93_0x60;
    undefined field94_0x61;
    undefined field95_0x62;
    undefined field96_0x63;
    VECTOR f_64_vc;
    undefined field98_0x74;
    undefined field99_0x75;
    undefined field100_0x76;
    undefined field101_0x77;
    undefined field102_0x78;
    undefined field103_0x79;
    undefined field104_0x7a;
    undefined field105_0x7b;
    undefined field106_0x7c;
    undefined field107_0x7d;
    undefined field108_0x7e;
    undefined field109_0x7f;
    undefined field110_0x80;
    undefined field111_0x81;
    undefined field112_0x82;
    undefined field113_0x83;
    undefined field114_0x84;
    undefined field115_0x85;
    undefined field116_0x86;
    undefined field117_0x87;
    undefined field118_0x88;
    undefined field119_0x89;
    undefined field120_0x8a;
    undefined field121_0x8b;
    undefined field122_0x8c;
    undefined field123_0x8d;
    undefined field124_0x8e;
    undefined field125_0x8f;
    undefined field126_0x90;
    undefined field127_0x91;
    undefined field128_0x92;
    undefined field129_0x93;
    undefined field130_0x94;
    undefined field131_0x95;
    undefined field132_0x96;
    undefined field133_0x97;
    undefined field134_0x98;
    undefined field135_0x99;
    undefined field136_0x9a;
    undefined field137_0x9b;
    undefined field138_0x9c;
    undefined field139_0x9d;
    undefined field140_0x9e;
    undefined field141_0x9f;
    VECTOR f_a0_vec1;
    VECTOR f_b0_vec2;
    int f_c0_v2;
    int f_c4_v;
    undefined field146_0xc8;
    undefined field147_0xc9;
    undefined field148_0xca;
    undefined field149_0xcb;
    undefined field150_0xcc;
    undefined field151_0xcd;
    undefined field152_0xce;
    undefined field153_0xcf;
    undefined field154_0xd0;
    undefined field155_0xd1;
    undefined field156_0xd2;
    undefined field157_0xd3;
    undefined field158_0xd4;
    undefined field159_0xd5;
    undefined field160_0xd6;
    undefined field161_0xd7;
    undefined field162_0xd8;
    undefined field163_0xd9;
    undefined field164_0xda;
    undefined field165_0xdb;
    int f_dc_qwe;
    int f_e0_qwe2;
    int f_e4_vr;
    undefined field169_0xe8;
    undefined field170_0xe9;
    undefined field171_0xea;
    undefined field172_0xeb;
    int f_ec_q5;
    int f_f0_q6;
    int f_f4_q7;
    undefined field176_0xf8;
    undefined field177_0xf9;
    undefined field178_0xfa;
    undefined field179_0xfb;
    int f_fc_fff;
    int f_100_q1;
    int f_100_q2;
    undefined field183_0x108;
    undefined field184_0x109;
    undefined field185_0x10a;
    undefined field186_0x10b;
    undefined field187_0x10c;
    undefined field188_0x10d;
    undefined field189_0x10e;
    undefined field190_0x10f;
    undefined field191_0x110;
    undefined field192_0x111;
    undefined field193_0x112;
    undefined field194_0x113;
    undefined field195_0x114;
    undefined field196_0x115;
    undefined field197_0x116;
    undefined field198_0x117;
    undefined field199_0x118;
    undefined field200_0x119;
    undefined field201_0x11a;
    undefined field202_0x11b;
    undefined field203_0x11c;
    undefined field204_0x11d;
    undefined field205_0x11e;
    undefined field206_0x11f;
    undefined field207_0x120;
    undefined field208_0x121;
    undefined field209_0x122;
    undefined field210_0x123;
    undefined field211_0x124;
    undefined field212_0x125;
    undefined field213_0x126;
    undefined field214_0x127;
    undefined field215_0x128;
    undefined field216_0x129;
    undefined field217_0x12a;
    undefined field218_0x12b;
    undefined field219_0x12c;
    undefined field220_0x12d;
    undefined field221_0x12e;
    undefined field222_0x12f;
    undefined field223_0x130;
    undefined field224_0x131;
    undefined field225_0x132;
    undefined field226_0x133;
    undefined field227_0x134;
    undefined field228_0x135;
    undefined field229_0x136;
    undefined field230_0x137;
    undefined field231_0x138;
    undefined field232_0x139;
    undefined field233_0x13a;
    undefined field234_0x13b;
    undefined field235_0x13c;
    undefined field236_0x13d;
    undefined field237_0x13e;
    undefined field238_0x13f;
    undefined field239_0x140;
    undefined field240_0x141;
    undefined field241_0x142;
    undefined field242_0x143;
    undefined field243_0x144;
    undefined field244_0x145;
    undefined field245_0x146;
    undefined field246_0x147;
    undefined field247_0x148;
    undefined field248_0x149;
    undefined field249_0x14a;
    undefined field250_0x14b;
    undefined field251_0x14c;
    undefined field252_0x14d;
    undefined field253_0x14e;
    undefined field254_0x14f;
    undefined field255_0x150;
    undefined field256_0x151;
    undefined field257_0x152;
    undefined field258_0x153;
    undefined field259_0x154;
    undefined field260_0x155;
    undefined field261_0x156;
    undefined field262_0x157;
    undefined field263_0x158;
    undefined field264_0x159;
    undefined field265_0x15a;
    undefined field266_0x15b;
    undefined field267_0x15c;
    undefined field268_0x15d;
    undefined field269_0x15e;
    undefined field270_0x15f;
    undefined field271_0x160;
    undefined field272_0x161;
    undefined field273_0x162;
    undefined field274_0x163;
    undefined field275_0x164;
    undefined field276_0x165;
    undefined field277_0x166;
    undefined field278_0x167;
    undefined field279_0x168;
    undefined field280_0x169;
    undefined field281_0x16a;
    undefined field282_0x16b;
    undefined field283_0x16c;
    undefined field284_0x16d;
    undefined field285_0x16e;
    undefined field286_0x16f;
    undefined field287_0x170;
    undefined field288_0x171;
    undefined field289_0x172;
    undefined field290_0x173;
    undefined field291_0x174;
    undefined field292_0x175;
    undefined field293_0x176;
    undefined field294_0x177;
    undefined field295_0x178;
    undefined field296_0x179;
    undefined field297_0x17a;
    undefined field298_0x17b;
    undefined field299_0x17c;
    undefined field300_0x17d;
    undefined field301_0x17e;
    undefined field302_0x17f;
    undefined field303_0x180;
    undefined field304_0x181;
    undefined field305_0x182;
    undefined field306_0x183;
    undefined field307_0x184;
    undefined field308_0x185;
    undefined field309_0x186;
    undefined field310_0x187;
    undefined field311_0x188;
    undefined field312_0x189;
    undefined field313_0x18a;
    undefined field314_0x18b;
    undefined field315_0x18c;
    undefined field316_0x18d;
    undefined field317_0x18e;
    undefined field318_0x18f;
    VECTOR f_190_v0;
    undefined field320_0x1a0;
    undefined field321_0x1a1;
    undefined field322_0x1a2;
    undefined field323_0x1a3;
    undefined field324_0x1a4;
    undefined field325_0x1a5;
    undefined field326_0x1a6;
    undefined field327_0x1a7;
    undefined field328_0x1a8;
    undefined field329_0x1a9;
    undefined field330_0x1aa;
    undefined field331_0x1ab;
    undefined field332_0x1ac;
    undefined field333_0x1ad;
    undefined field334_0x1ae;
    undefined field335_0x1af;
    undefined field336_0x1b0;
    undefined field337_0x1b1;
    undefined field338_0x1b2;
    undefined field339_0x1b3;
    int f_1b4_va;
    int f_1b8_vb;
    VECTOR f_1bc_v2;
    undefined field343_0x1cc;
    undefined field344_0x1cd;
    undefined field345_0x1ce;
    undefined field346_0x1cf;
    undefined field347_0x1d0;
    undefined field348_0x1d1;
    undefined field349_0x1d2;
    undefined field350_0x1d3;
    undefined field351_0x1d4;
    undefined field352_0x1d5;
    undefined field353_0x1d6;
    undefined field354_0x1d7;
    int f_1d8_iii;
    undefined field356_0x1dc;
    undefined field357_0x1dd;
    undefined field358_0x1de;
    undefined field359_0x1df;
    undefined field360_0x1e0;
    undefined field361_0x1e1;
    undefined field362_0x1e2;
    undefined field363_0x1e3;
    undefined field364_0x1e4;
    undefined field365_0x1e5;
    undefined field366_0x1e6;
    undefined field367_0x1e7;
    undefined field368_0x1e8;
    undefined field369_0x1e9;
    undefined field370_0x1ea;
    undefined field371_0x1eb;
    int f_1ec_valu;
    undefined field373_0x1f0;
    undefined field374_0x1f1;
    undefined field375_0x1f2;
    undefined field376_0x1f3;
    undefined field377_0x1f4;
    undefined field378_0x1f5;
    undefined field379_0x1f6;
    undefined field380_0x1f7;
    undefined field381_0x1f8;
    undefined field382_0x1f9;
    undefined field383_0x1fa;
    undefined field384_0x1fb;
    undefined field385_0x1fc;
    undefined field386_0x1fd;
    undefined field387_0x1fe;
    undefined field388_0x1ff;
    undefined field389_0x200;
    undefined field390_0x201;
    undefined field391_0x202;
    undefined field392_0x203;
    undefined field393_0x204;
    undefined field394_0x205;
    undefined field395_0x206;
    undefined field396_0x207;
    undefined field397_0x208;
    undefined field398_0x209;
    undefined field399_0x20a;
    undefined field400_0x20b;
    int f_20c_qqq;
    undefined field402_0x210;
    undefined field403_0x211;
    undefined field404_0x212;
    undefined field405_0x213;
    int f_214_i;
    int f_218_i3;
    int f_21c_i2;
    int f_220_i4;
    VECTOR f_224_vc;
    VECTOR f_234_vc2;
    undefined field412_0x244;
    undefined field413_0x245;
    undefined field414_0x246;
    undefined field415_0x247;
    undefined field416_0x248;
    undefined field417_0x249;
    undefined field418_0x24a;
    undefined field419_0x24b;
    undefined field420_0x24c;
    undefined field421_0x24d;
    undefined field422_0x24e;
    undefined field423_0x24f;
    undefined field424_0x250;
    undefined field425_0x251;
    undefined field426_0x252;
    undefined field427_0x253;
    undefined field428_0x254;
    undefined field429_0x255;
    undefined field430_0x256;
    undefined field431_0x257;
    undefined field432_0x258;
    undefined field433_0x259;
    undefined field434_0x25a;
    undefined field435_0x25b;
    undefined field436_0x25c;
    undefined field437_0x25d;
    undefined field438_0x25e;
    undefined field439_0x25f;
    undefined field440_0x260;
    undefined field441_0x261;
    undefined field442_0x262;
    undefined field443_0x263;
    undefined field444_0x264;
    undefined field445_0x265;
    undefined field446_0x266;
    undefined field447_0x267;
    undefined field448_0x268;
    undefined field449_0x269;
    undefined field450_0x26a;
    undefined field451_0x26b;
    undefined field452_0x26c;
    undefined field453_0x26d;
    undefined field454_0x26e;
    undefined field455_0x26f;
    undefined field456_0x270;
    undefined field457_0x271;
    undefined field458_0x272;
    undefined field459_0x273;
    undefined field460_0x274;
    undefined field461_0x275;
    undefined field462_0x276;
    undefined field463_0x277;
    undefined field464_0x278;
    undefined field465_0x279;
    undefined field466_0x27a;
    undefined field467_0x27b;
    undefined field468_0x27c;
    undefined field469_0x27d;
    undefined field470_0x27e;
    undefined field471_0x27f;
    undefined field472_0x280;
    undefined field473_0x281;
    undefined field474_0x282;
    undefined field475_0x283;
    undefined field476_0x284;
    undefined field477_0x285;
    undefined field478_0x286;
    undefined field479_0x287;
    undefined field480_0x288;
    undefined field481_0x289;
    undefined field482_0x28a;
    undefined field483_0x28b;
    undefined field484_0x28c;
    undefined field485_0x28d;
    undefined field486_0x28e;
    undefined field487_0x28f;
    undefined field488_0x290;
    undefined field489_0x291;
    undefined field490_0x292;
    undefined field491_0x293;
    undefined field492_0x294;
    undefined field493_0x295;
    undefined field494_0x296;
    undefined field495_0x297;
    undefined field496_0x298;
    undefined field497_0x299;
    undefined field498_0x29a;
    undefined field499_0x29b;
    undefined field500_0x29c;
    undefined field501_0x29d;
    undefined field502_0x29e;
    undefined field503_0x29f;
    undefined field504_0x2a0;
    undefined field505_0x2a1;
    undefined field506_0x2a2;
    undefined field507_0x2a3;
    undefined field508_0x2a4;
    undefined field509_0x2a5;
    undefined field510_0x2a6;
    undefined field511_0x2a7;
    undefined field512_0x2a8;
    undefined field513_0x2a9;
    undefined field514_0x2aa;
    undefined field515_0x2ab;
    undefined field516_0x2ac;
    undefined field517_0x2ad;
    undefined field518_0x2ae;
    undefined field519_0x2af;
    undefined field520_0x2b0;
    undefined field521_0x2b1;
    undefined field522_0x2b2;
    undefined field523_0x2b3;
    undefined field524_0x2b4;
    undefined field525_0x2b5;
    undefined field526_0x2b6;
    undefined field527_0x2b7;
    undefined field528_0x2b8;
    undefined field529_0x2b9;
    undefined field530_0x2ba;
    undefined field531_0x2bb;
    undefined field532_0x2bc;
    undefined field533_0x2bd;
    undefined field534_0x2be;
    undefined field535_0x2bf;
    undefined field536_0x2c0;
    undefined field537_0x2c1;
    undefined field538_0x2c2;
    undefined field539_0x2c3;
    short f_2c4_ii;
    short f_2c6_i2;
    short f_2c8_i3;
    undefined field543_0x2ca;
    undefined field544_0x2cb;
    short f_2cc_i5;
    short f_2ce_i8;
    short f_2d0_shhshh;
    undefined field548_0x2d2;
    undefined field549_0x2d3;
    short f_2d4;
    short f_2d6;
    short f_2d8;
    short f_2da_la;
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


// 0x24 / 0x30 ?
struct Node {
    MATRIX f_00_mtx;
    Node * f_20_n1;
    Node * f_24_n2;
    Node * f_24_n3; // oops
    byte f_2c_b0;
    byte f_2d_b1;
    byte f_2e_b2;
    byte f_2f_b3;
};


// not sure
struct ListElem {
    void * f00_my_data;
    ListElem * f04_next;
    ListElem * f08_prev;
};

// not sure
struct DaList {
  
  ListElem* first;  
};



// anim playback state    sizeof 0xAC
struct AnimPlayer
{
    ListElem * f_00_my_link;
    uint f_04;
    uint f_08;
    byte * f_0c_an_data_start;
    byte * f_10_an_data_cur;
    int f_14_frame;
    int f_18_neg;
    void* f_1c_func;
    uint f_20_unk;
    byte * f_24_ptr_data_for_cb;
    int f_28_flg;
    int f_2c_u3;
    int f_30_dunno;
    int f_34_u1;
    int f_38_u2;
    int f_3c_derp1[18];
    int f_84_derp2[8];
    int f_a4_derp3[2];
};



typedef struct MaybeMd78    MaybeMd78;
typedef struct XfSht        XfSht;
typedef struct EntData1C    EntData1C;


// model instance ?

struct MaybeMd78 {
    int f_00;
    int f_04;
    int f_08;
    int f_0c;
    int f_10;
    int f_14;
    int f_18;
    int f_1c;
    HmdHead * f_20_ptr_hmd;
    byte* f_24_ptpt;
    uint f_28_fla;
    int * f_2c_p_un;
    undefined field12_0x30;
    undefined field13_0x31;
    undefined field14_0x32;
    undefined field15_0x33;
    undefined field16_0x34;
    undefined field17_0x35;
    undefined field18_0x36;
    undefined field19_0x37;
    undefined field20_0x38;
    undefined field21_0x39;
    undefined field22_0x3a;
    undefined field23_0x3b;
    undefined field24_0x3c;
    undefined field25_0x3d;
    undefined field26_0x3e;
    undefined field27_0x3f;
    undefined field28_0x40;
    undefined field29_0x41;
    undefined field30_0x42;
    undefined field31_0x43;
    undefined field32_0x44;
    undefined field33_0x45;
    undefined field34_0x46;
    undefined field35_0x47;
    undefined field36_0x48;
    undefined field37_0x49;
    undefined field38_0x4a;
    undefined field39_0x4b;
    undefined field40_0x4c;
    undefined field41_0x4d;
    undefined field42_0x4e;
    undefined field43_0x4f;
    undefined field44_0x50;
    undefined field45_0x51;
    undefined field46_0x52;
    undefined field47_0x53;
    undefined field48_0x54;
    undefined field49_0x55;
    undefined field50_0x56;
    undefined field51_0x57;
    undefined field52_0x58;
    undefined field53_0x59;
    undefined field54_0x5a;
    undefined field55_0x5b;
    undefined field56_0x5c;
    undefined field57_0x5d;
    undefined field58_0x5e;
    undefined field59_0x5f;
    undefined field60_0x60;
    undefined field61_0x61;
    undefined field62_0x62;
    undefined field63_0x63;
    undefined field64_0x64;
    undefined field65_0x65;
    undefined field66_0x66;
    undefined field67_0x67;
    undefined field68_0x68;
    undefined field69_0x69;
    undefined field70_0x6a;
    undefined field71_0x6b;
    undefined field72_0x6c;
    undefined field73_0x6d;
    undefined field74_0x6e;
    undefined field75_0x6f;
    undefined field76_0x70;
    undefined field77_0x71;
    undefined field78_0x72;
    undefined field79_0x73;
    int f_74_int;
};



// not sure
struct XfSht {
    Node * nodes;
};





// entity related
struct EntData1C
{
    ListElem * f_00_my_link;
    byte f_04_dun_se;
    byte f_05_bb;
    byte f_06_cc;
    byte f_07_d;
    ushort f_08_fla;
    byte f_0a_u1;
    byte f_0b_u2;
    XfSht f_0c_nodes;
    MaybeMd78 * f_10_ptr_md;
    uint f_14_flfl;
    Node * * f_18_ptr_arr_nodes;
};



typedef struct GsCOORD2PARAM GsCOORD2PARAM;
typedef struct GsCOORDINATE2 GsCOORDINATE2;
typedef struct GsVIEW2 GsVIEW2;

struct GsCOORD2PARAM {
    VECTOR scale;
    SVECTOR rotate;
    VECTOR trans;
};

struct GsCOORDINATE2 {
    ulong flg;
    MATRIX coord;
    MATRIX workm;
    GsCOORD2PARAM * param;
    GsCOORDINATE2 * super;
    GsCOORDINATE2 * sub;
};


struct GsVIEW2 {
    MATRIX view;
    GsCOORDINATE2 * super;
};



typedef struct Ano0x78 Ano0x78;

struct Ano0x78 {
    Node * f_00_node;
    byte * f_04_allocated_1c20;
    undefined field2_0x8;
    undefined field3_0x9;
    undefined field4_0xa;
    undefined field5_0xb;
    undefined field6_0xc;
    undefined field7_0xd;
    undefined field8_0xe;
    undefined field9_0xf;
    GsCOORDINATE2 * f_10_p_cord;
    int f14_i;
    GsCOORDINATE2 f18_coord;
    GsVIEW2 f_68_view;
    DaList f_8c_some_list_of_1Cs;
    undefined field15_0x90;
    undefined field16_0x91;
    undefined field17_0x92;
    undefined field18_0x93;
    undefined field19_0x94;
    undefined field20_0x95;
    undefined field21_0x96;
    undefined field22_0x97;
};


//--------------------------- mad skillz

inline ushort __EvilGet2_2(void* src)
{
	ushort* s = (ushort*)src;
	return s[1];
}


inline uint __EvilGet0_4(void* src)
{
	uint* p = (uint*)src;
	return p[0];
}

inline uint __EvilGet4_4(void* src)
{
	uint* p = (uint*)src;
	return p[1];
}

inline uint __EvilGet8_4(void* src)
{
	uint* p = (uint*)src;
	return p[2];
}

inline uint __EvilGet12_4(void* src)
{
	uint* p = (uint*)src;
	return p[3];
}

inline uint __EvilGet16_4(void* src)
{
	uint* p = (uint*)src;
	return p[4];
}


