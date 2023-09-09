#include "types.h"

#define EXTEXT(adr,ty) (*(ty*)(adr))  

//------ funcs




#define f_800fc774_sbank_dunno   ( (void(FNC*)(HeadSBNK*,int)) 0x800fc774 )
#define f_801078a4_spu_voice_env ( (int(FNC*)(void)) 0x801078a4 )

#define ratan2   	             ( (int(FNC*)(int,int)) 0x800f2fc0 )
#define ApplyMatrixLV            ( (VECTOR*(FNC*)(MATRIX*,VECTOR*,VECTOR*)) 0x800f3c60 )
#define DrawSync   	             ( (void(FNC*)(int)) 0x800f4098 )
#define ClearImage   	         ( (void(FNC*)(RECT*,uint,uint,uint)) 0x800f421c )
#define LoadImage   	         ( (void(FNC*)(RECT*,void*)) 0x800f42ac )
#define memset   	             ( (void*(FNC*)(void*,byte,int)) 0x800f6f00 )
#define printf   	             ( (int(FNC*)(char*,...)) 0x800f6f10 )
#define TransposeMatrix          ( (MATRIX*(FNC*)(MATRIX*,MATRIX*)) 0x800f9134 )
#define SquareRoot0   	         ( (long(FNC*)(long)) 0x800f9174 )
#define SquareRoot12   	         ( (long(FNC*)(long)) 0x800f9204 )
#define rcos   	                 ( (int(FNC*)(int)) 0x800f92a4 )
#define rsin   	                 ( (int(FNC*)(int)) 0x800f9344 )
#define ApplyTransposeMatrixLV   ( (VECTOR*(FNC*)(MATRIX*,VECTOR*,VECTOR*)) 0x800f9414 )
#define CompMatrixLV   	         ( (MATRIX*(FNC*)(MATRIX*,MATRIX*,MATRIX*)) 0x800f96e8 )
#define RotMatrixYXZ             ( (MATRIX*(FNC*)(SVECTOR*,MATRIX*)) 0x800f9938 )
#define MulMatrix0               ( (MATRIX*(FNC*)(MATRIX*,MATRIX*,MATRIX*)) 0x800f9bc8 )
#define GsGetTimInfo   	         ( (void(FNC*)(ulong*,GsIMAGE*)) 0x800f9cd8 )
#define strcmp   	             ( (int(FNC*)(char*,char*)) 0x800fb018 )
#define ApplyMatrixSV            ( (SVECTOR*(FNC*)(MATRIX*,SVECTOR*,SVECTOR*)) 0x800fb1c8 )
#define ScaleMatrix              ( (MATRIX*(FNC*)(MATRIX*,VECTOR*)) 0x800fb228 )
#define SpuSetKey   	         ( (void(FNC*)(int,uint)) 0x801087d0 )


//-------- data






#define g_8010b634_glo_vc3               EXTEXT(0x8010b634,VECTOR)

#define g_8010f0d0_mtx_ident            EXTEXT(0x8010f0d0,MATRIX)

typedef uint ARR_ANGANG[4096];
#define g_8011aa6c_ang_table            EXTEXT(0x8011aa6c,ARR_ANGANG)

typedef int ARR_TMP1[4];
#define g_8011fcb0_ar_vol_sht           EXTEXT(0x8011fcb0,ARR_TMP1)




#define g_80121b24_list_elem_free       EXTEXT(0x80121b24,ListElem*)
#define g_80121b28_list_elem_tot_cnt    EXTEXT(0x80121b28,short)







// 0: gameplay
// 1: briefing loading ?
// 3: fmv ?
// 4: menu, mem-card
// 6: menu transition ?
// 7: pause menu ?
// 8: briefing ready ?
// 9: transition to pause-menu ?
#define g_80121b88_main_mode            EXTEXT(0x80121b88,uint)







#define g_80122130_midi_speed           EXTEXT(0x80122130,uint)

#define g_80122138_music_danger_timer   EXTEXT(0x80122138,int)

#define g_8012214c_snd_val1             EXTEXT(0x8012214c,int)
#define g_80122150_snd_val2             EXTEXT(0x80122150,int)
#define g_80122154_snd_banks            EXTEXT(0x80122154,HeadSBNK*)
#define g_80122158_ptr_MMID             EXTEXT(0x80122158,HeadMMID*)
#define g_8012215c_iv5                  EXTEXT(0x8012215c,int)

#define g_80122168_voice_env_req        EXTEXT(0x80122168,int)




#define g_80122170_snd_x1               EXTEXT(0x80122170,int)
#define g_80122174_snd_cb_x2            EXTEXT(0x80122174,PFN_VOID)
#define g_80122178_snd_some_mask        EXTEXT(0x80122178,uint)
#define g_8012217c_snd_mask2            EXTEXT(0x8012217c,uint)
#define g_80122180_snd_msk4             EXTEXT(0x80122180,uint)
#define g_80122184_snd_msk3             EXTEXT(0x80122184,uint)



#define g_8012218c_current_MID_ptr      EXTEXT(0x8012218c,HeadMID*)
#define g_80122190_midi_u9              EXTEXT(0x80122190,int)
#define g_801221b0_snd_rela99           EXTEXT(0x801221b0,int)







#define g_80122234_hmd_re1              EXTEXT(0x80122234,short)

#define g_8012225a_scr_w                EXTEXT(0x8012225a,short)
#define g_8012225c_scr_h                EXTEXT(0x8012225c,short)


typedef AnimPlayer ARR_ANIM_PLAYERZ[14];
#define g_80122908_ar_anim_players      EXTEXT(0x80122908,ARR_ANIM_PLAYERZ)


typedef ListElem ARR_LISTELEMPOOL[911];
#define g_80126708_list_elem_pool       EXTEXT(0x80126708,ARR_LISTELEMPOOL)





typedef WpnTabS10 ARR_WPNTAB1[83];
#define g_80132084_wpn_icons_tab        EXTEXT(0x80132084,ARR_WPNTAB1)


typedef SndChan ARR_SND_CHANS[24];
#define g_80145ac0_chans                EXTEXT(0x80145ac0,ARR_SND_CHANS)






//----------------------------------

void trap(ushort v)
{
    printf("TRAP ! %04X\n", v);
}

//-------------------------------

void f_800feeb8_snd_reset2(void)
{
    printf("snd reset2 !\n");
    
  g_8012214c_snd_val1 = 0;
  g_80122150_snd_val2 = 0;
  g_80122154_snd_banks = (HeadSBNK *)0x0;
  g_80122158_ptr_MMID = (HeadMMID *)0x0;
  return;
}




void f_800fffec_snd_spu_key(void)
{
  uint uVar1;
  
  if (g_8012217c_snd_mask2 != 0) {
    SpuSetKey(0,g_8012217c_snd_mask2);
    
    uVar1 = g_8012217c_snd_mask2;
    g_8012217c_snd_mask2 = 0;
    g_80122180_snd_msk4 = g_80122180_snd_msk4 & ~uVar1;
    g_80122184_snd_msk3 = g_80122184_snd_msk3 | uVar1;
  }
  return;
}




void f_800ff758_snd_mmid2(HeadMMID *m)
{
  BankEnt *ba;
  int ii;
  HeadSBNK *sb;
  int i2;
  
  sb = g_80122154_snd_banks;
  if (g_80122154_snd_banks != (HeadSBNK *)0x0) {
    do {
      ii = 0;
      if (0 < sb->f_18_s) {
        i2 = 0;
        do {
          ba = sb->f_20_ents;
          if (*(HeadMMID **)((int)&ba->f_1c_ptr_mmid + i2) == m) {
            f_800fc774_sbank_dunno(sb,ii);
            *(undefined4 *)((int)&ba->f_1c_ptr_mmid + i2) = 0;
          }
          ii = ii + 1;
          i2 = i2 + 0x24;
        } while (ii < sb->f_18_s);
      }
      sb = sb->f_14_ptr_sb;
    } while (sb != (HeadSBNK *)0x0);
  }
  return;
}





void f_800ff5a8_snd_mmid_recs(byte *data)
{
  HeadMID *m1;
  HeadMID *m2;
  byte *b;
  int ii;
  
  if (g_8012215c_iv5 == 0) {
    f_800ff758_snd_mmid2((HeadMMID *)data);
  }
                    /* MMID */
  if (*(int *)data == 0x44494d4d) {
    ii = 0;
    g_8012215c_iv5 = 1;
    b = data;
    if (data[7] != 0) {
      do {
        f_800ff5a8_snd_mmid_recs(*(byte **)(b + 0x10));
        ii = ii + 1;
        b = b + 4;
      } while (ii < (int)(uint)data[7]);
    }
    g_8012215c_iv5 = 0;
  }
  if (g_80122158_ptr_MMID != (HeadMMID *)0x0) {
    if (g_80122158_ptr_MMID == (HeadMMID *)data) {
      g_80122158_ptr_MMID = *(HeadMMID **)(data + 0xc);
    }
    else {
      m1 = g_80122158_ptr_MMID->f_0c_ar_mid[0];
      m2 = (HeadMID *)g_80122158_ptr_MMID;
      while (m1 != (HeadMID *)data) {
        m2 = m2->f_0c_next;
        m1 = m2->f_0c_next;
      }
      m2->f_0c_next = *(HeadMID **)(data + 0xc);
    }
  }
  return;
}




void f_800fcb1c_snd_chan_cb_sht(uint m,HeadMID *mid,int arg3)
{

  if ((arg3 < 5) && (0 < arg3)) {
    mid->f_1c_rt_juice_cur = (byte *)((uint)mid->f_1c_rt_juice_cur & ~(1 << (m & 0x1f)));
  }
  return;
}




int f_800fc9f0_sbank_check(HeadSBNK *sb,int i)
{
  BankEnt *ee;
  int q;
  
  if ((((sb != (HeadSBNK *)0x0) && (i < sb->f_18_s)) && (-1 < i)) &&
     (ee = sb->f_20_ents + i, ee->f_04_my != (HeadSBNK *)0x0)) {
    q = ee->f_00_i;
    if (q == 4) {
      return (uint)(ee->f_10_i == 0);
    }
    if (q < 5) {
      if (q == 3) {
        return 1;
      }
    }
    else if (q == 5) {
      return 1;
    }
    return 0;
  }
  return 0;
}





uint f_80101244_midi_juice_stuff(byte *midiJuice,int *out)

{
  uint u1;
  int i1;
  
  u1 = (uint)*midiJuice;
  i1 = 1;
  if ((*midiJuice & 0x80) != 0) {
    u1 = u1 & 0x7f;
    do {
      midiJuice = midiJuice + 1;
      i1 = i1 + 1;
      u1 = u1 * 0x80 + (*midiJuice & 0x7f);
    } while ((*midiJuice & 0x80) != 0);
  }
  *out = i1;
  return u1;
}




// on midi change ?
void f_80101838_midi_help1(HeadMID *mid)
{
  HeadMID *pp;
  int i1;
  
  mid->f_40_unkunk = 0;
  i1 = 0;
  pp = mid;
  do {
    *(undefined *)((int)mid->f_64_arr_a + i1 + -0x20) = 0;
    *(undefined *)((int)mid->f_64_arr_a + i1 + -0x10) = 0x7f;
    pp->f_64_arr_a[0] = 0;
    pp->f_84_arr_b[0] = 0x2000;
    i1 = i1 + 1;
    pp = (HeadMID *)((int)&pp->f_00_sign + 2);
  } while (i1 < 0x10);
  mid->f_42_msk1 = 0;
  return;
}


// midi swaps ?
void f_80100998_midi_sets_ptrs(HeadMID *m)
{
  HeadMID *p1;
  HeadMID *p2;
  bool bb;
  
  p2 = g_8012218c_current_MID_ptr;
  bb = g_8012218c_current_MID_ptr != (HeadMID *)0x0;
  m->f_a4_ptr_ano_mid = (HeadMID *)0x0;
  if (bb) {
    p1 = p2->f_a4_ptr_ano_mid;
    while (p1 != (HeadMID *)0x0) {
      p2 = p2->f_a4_ptr_ano_mid;
      p1 = p2->f_a4_ptr_ano_mid;
    }
    p2->f_a4_ptr_ano_mid = m;
    return;
  }
  g_8012218c_current_MID_ptr = m;
  return;
}




byte * f_801008dc_midi_checks_sign(HeadMID *mid)
{
  uint u1;
  byte *b1;
  
  b1 = mid->f_1c_rt_juice_cur;
  if (b1 == (byte *)0x0) {
    return (byte *)0x0;
  }
  if (*(int *)b1 != 0x2044494d) {
    u1 = (uint)*(byte *)((int)&mid->f_18_juice_start + 1);
    if ((int)(b1[7] - 1) < (int)u1) {
      return (byte *)0x0;
    }
    b1 = *(byte **)(b1 + u1 * 4 + 0x10);
  }
  return b1;
}





void f_800ff6dc_snd_mmid_setups(HeadMMID *mmid)
{
  HeadMID *mid;
  HeadMID *qqq;
  
  if (g_80122158_ptr_MMID != (HeadMMID *)0x0) {
    mid = g_80122158_ptr_MMID->f_0c_ar_mid[0];
    qqq = (HeadMID *)g_80122158_ptr_MMID;
    while (mid != (HeadMID *)0x0) {
      qqq = qqq->f_0c_next;
      mid = qqq->f_0c_next;
    }
    qqq->f_0c_next = (HeadMID *)mmid;
    return;
  }
  g_80122158_ptr_MMID = mmid;
  return;
}




HeadSBNK * f_800ff43c_snd_bank_by_name(byte *data)
{
  HeadSBNK *sb;
  
  sb = g_80122154_snd_banks;
  if (g_80122154_snd_banks != (HeadSBNK *)0x0) {
    do {
      if ((byte *)sb->f_0c_nam == data) {
        return sb;
      }
      sb = sb->f_14_ptr_sb;
    } while (sb != (HeadSBNK *)0x0);
  }
  return sb;
}




int f_800ff4bc_midi_inits_rec(byte *da)
{
  HeadSBNK *b1;
  byte *b2;
  byte *pbVar1;
  int i1;

                    /* MID */
  if (*(int *)da == 0x2044494d) {
    b1 = f_800ff43c_snd_bank_by_name(*(byte **)(da + 0x10));
    i1 = *(int *)(da + 0x18);
    *(HeadSBNK **)(da + 0x14) = b1;
    *(undefined4 *)(da + 0xc) = 0;
    *(undefined4 *)(da + 0x20) = 0;
    *(byte **)(da + 0x18) = da + i1;
    *(byte **)(da + 0x1c) = da + i1;
    f_800ff6dc_snd_mmid_setups((HeadMMID *)da);
  }
  else {
                    /* MMID */
    if (*(int *)da == 0x44494d4d) {
      *(undefined4 *)(da + 0xc) = 0;
      f_800ff6dc_snd_mmid_setups((HeadMMID *)da);
      i1 = 0;
      pbVar1 = da;
      if (da[7] != 0) {
        do {
          i1 = i1 + 1;
          b2 = da + *(int *)(pbVar1 + 0x10);
          *(byte **)(pbVar1 + 0x10) = b2;
          f_800ff4bc_midi_inits_rec(b2);
          *(byte **)(b2 + 0x20) = da;
          pbVar1 = pbVar1 + 4;
        } while (i1 < (int)(uint)da[7]);
      }
    }
  }
  return 0;
}



HeadSBNK * f_800ff47c_snd_bank_find_unk(byte by)
{
  HeadSBNK *r;
  
  r = g_80122154_snd_banks;
  if (g_80122154_snd_banks != (HeadSBNK *)0x0) {
    do {
      if (r->f_10_some_ind == by) {
        return r;
      }
      r = r->f_14_ptr_sb;
    } while (r != (HeadSBNK *)0x0);
  }
  return r;
}



HeadMMID * f_800ff6a4_snd_mmid_find(uint nam)
{
  HeadMMID *mid;
  
  mid = g_80122158_ptr_MMID;
  if (g_80122158_ptr_MMID != (HeadMMID *)0x0) {
    do {
      if (mid->f_08_name == nam) {
        return mid;
      }
      mid = (HeadMMID *)mid->f_0c_ar_mid[0];
    } while (mid != (HeadMMID *)0x0);
  }
  return mid;
}


void f_800ff184_snd_sb_big_sht(void)
{
  char cVar1;
  bool bVar2;
  int iVar3;
  HeadMMID *mmid;
  uint *puVar4;
  int *q1;
  HeadSBNK *sb1;
  BankEnt *qq;
  HeadSBNK *sb2;
  int i1;
  int i2;
  
  sb2 = g_80122154_snd_banks;
  if (g_80122154_snd_banks != (HeadSBNK *)0x0) {
    do {
      i2 = 0;
      if (0 < sb2->f_18_s) {
        i1 = 0;
        do {
          puVar4 = (uint *)((int)&sb2->f_20_ents->f_00_i + i1);
          if ((puVar4[8] & 1) != 0) {
            *puVar4 = (uint)*(byte *)(puVar4 + 3);
            *(undefined4 *)((int)&sb2->f_20_ents->f_04_my + i1) =
                 *(undefined4 *)((int)&sb2->f_20_ents->f_08_nam1 + i1);
          }
          sb1 = (HeadSBNK *)0x0;
          q1 = (int *)((int)&sb2->f_20_ents->f_00_i + i1);
          bVar2 = false;
          if (*q1 - 7U < 2) {
            sb1 = f_800ff43c_snd_bank_by_name((byte *)q1[1]);
            bVar2 = true;
          }
          q1 = (int *)((int)&sb2->f_20_ents->f_00_i + i1);
          if (*q1 - 9U < 5) {
            sb1 = f_800ff47c_snd_bank_find_unk(*(byte *)(q1 + 1));
            bVar2 = true;
          }
          if (sb1 == (HeadSBNK *)0x0) {
            if (bVar2) {
              *(undefined4 *)((int)&sb2->f_20_ents->f_04_my + i1) = 0;
            }
            else {
              *(HeadSBNK **)((int)&sb2->f_20_ents->f_04_my + i1) = sb2;
            }
            qq = sb2->f_20_ents;
            mmid = f_800ff6a4_snd_mmid_find(*(uint *)((int)&qq->f_0c_nam2 + i1));
            *(HeadMMID **)((int)&qq->f_1c_ptr_mmid + i1) = mmid;
          }
          else {
            q1 = (int *)((int)&sb2->f_20_ents->f_00_i + i1);
            if (*q1 - 7U < 4) {
              if ((int)(uint)*(byte *)((int)q1 + 0x19) < (int)sb1->f_18_s) {
                qq = sb1->f_20_ents + *(byte *)((int)q1 + 0x19);
                iVar3 = qq->f_00_i;
                q1[1] = (int)sb1;
                *q1 = iVar3;
                *(undefined *)((int)q1 + 0xd) = *(undefined *)((int)&qq->f_0c_nam2 + 1);
                cVar1 = *(char *)((int)&sb2->f_20_ents->f_0c_nam2 + i1);
                if ((cVar1 == '\a') || (cVar1 == '\t')) {
                  *(undefined *)((int)q1 + 0xe) = *(undefined *)((int)&qq->f_0c_nam2 + 2);
                  *(undefined *)((int)q1 + 0xf) = *(undefined *)((int)&qq->f_0c_nam2 + 3);
                  *(undefined *)(q1 + 4) = *(undefined *)&qq->f_10_i;
                  *(undefined *)((int)q1 + 0x11) = *(undefined *)((int)&qq->f_10_i + 1);
                  *(undefined *)((int)q1 + 0x12) = *(undefined *)&qq->f_12_i2;
                  *(undefined *)((int)q1 + 0x13) = *(undefined *)((int)&qq->f_12_i2 + 1);
                  *(undefined2 *)(q1 + 5) = *(undefined2 *)&qq->field6_0x14;
                  *(undefined2 *)((int)q1 + 0x16) = *(undefined2 *)((int)&qq->field6_0x14 + 2);
                  *(undefined *)(q1 + 6) = *(undefined *)&qq->field7_0x18;
                }
              }
              else {
                q1[1] = 0;
              }
            }
            else {
              *q1 = *q1 + -10;
              *(HeadSBNK **)((int)&sb2->f_20_ents->f_04_my + i1) = sb1;
            }
            *(uint *)((int)&sb2->f_20_ents->f_20_dunno + i1) =
                 *(uint *)((int)&sb2->f_20_ents->f_20_dunno + i1) | 1;
          }
          i2 = i2 + 1;
          i1 = i1 + 0x24;
        } while (i2 < sb2->f_18_s);
      }
      sb2->f_08_va = sb2->f_08_va | 2;
      sb2 = sb2->f_14_ptr_sb;
    } while (sb2 != (HeadSBNK *)0x0);
  }
  return;
}





void f_800fe844_music_danger_set(int val)
{
  if (0x7f < val) {
    val = 0x7f;
  }
  if (val < 0) {
    val = 0;
  }
  g_80122138_music_danger_timer = val;
  return;
}



int f_800fe86c_music_danger_get(void)
{
  return g_80122138_music_danger_timer;
}




int f_801007e0_snd_mid4(HeadMID *mid,int aa,int bb)
{
  HeadMID *mm;
  int iVar1;
  byte *b2;
  short s1;
  

  mm = (HeadMID *)f_801008dc_midi_checks_sign(mid);
  iVar1 = -1;
  if ((mm != (HeadMID *)0x0) && (iVar1 = -1, mm->f_14_ptr_sbnk != (HeadSBNK *)0x0)) {
    if (aa == -1) {
      *(undefined *)((int)&mid->f_10_name + 2) = *(undefined *)((int)&mid->f_10_name + 3);
    }
    else if (aa != -2) {
      *(char *)((int)&mid->f_10_name + 2) = (char)aa;
    }
    if (bb == -1) {
      *(undefined2 *)&mid->f_14_ptr_sbnk = *(undefined2 *)((int)&mid->f_14_ptr_sbnk + 2);
    }
    else if (bb != -2) {
      *(short *)&mid->f_14_ptr_sbnk = (short)bb;
    }
    b2 = mm->f_18_juice_start;
    *(undefined *)&mm->f_3c_unk3 = *(undefined *)((int)&mid->f_10_name + 2);
    mm->f_3e_yyy = *(short *)&mid->f_14_ptr_sbnk;
    *(undefined *)((int)&mm->f_3c_unk3 + 1) = *(undefined *)&mid->f_18_juice_start;
    s1 = *(short *)&mid->f_10_name;
    mm->f_28_unk1 = 0;
    mm->f_24_dunno1 = 0;
    mm->f_1c_rt_juice_cur = b2;
    mm->f_06_s2 = mm->f_06_s2 | 5;
    mm->f_3a_ww = s1;
    f_80101838_midi_help1(mm);
    f_80100998_midi_sets_ptrs(mm);
    iVar1 = 1;
  }
  return iVar1;
}




void f_80100964_mid_set_u2(HeadMID *m,uint vvv)
{
  m->f_40_unkunk = m->f_40_unkunk | (ushort)(1 << (vvv & 0x1f));
  return;
}





int f_800fdb08_bank_unk3(HeadSBNK *sb,int ind,int val)

{
  BankEnt *e;
  
  //printf("bank unk %08X %d %d\n", sb, ind, val);
  
  if (((sb != (HeadSBNK *)0x0) && (ind < sb->f_18_s)) && (-1 < ind)) {
    e = sb->f_20_ents + ind;
    if (1 < e->f_00_i - 4U) {
      if (e->f_00_i == 0xe) {
        e = sb->f_20_ents + ind + 1;
        val = -1;
      }
      if (val != -1) {
        return (uint)*(byte *)((int)&e->f_0c_nam2 + 2);
      }
      return (uint)*(byte *)((int)&e->f_0c_nam2 + 3);
    }
  }
  return -1;
}




void f_80100b10_midi_unk_set_one(void)
{
  g_80122190_midi_u9 = 1;
  return;
}



void f_80100b20_midi_zero1(void)
{
  g_80122190_midi_u9 = 0;
  return;
}








int f_8009e8d0_vecs2_sht(VECTOR *v0,VECTOR *v1)
{
  int q1;
  int q2;
  int q3;
  int q4;
  
  //printf("ves shi %p %p\n", v0, v1);
  
  q1 = v0->vx - v1->vx;
  if (q1 < 0) {
    q1 = v1->vx - v0->vx;
  }
  q4 = v0->vy - v1->vy;
  if (q4 < 0) {
    q4 = v1->vy - v0->vy;
  }
  q3 = v0->vz - v1->vz;
  if (q3 < 0) {
    q3 = v1->vz - v0->vz;
  }
  q2 = q1;
  if (q1 < q4) {
    q2 = q4;
    q4 = q1;
  }
  q1 = q2;
  if (q2 < q3) {
    q1 = q3;
    q3 = q2;
  }
  return q1 + (q4 + q3 >> 2);
}






uint f_80010698_bits(uint aa,uint bb)
{
  uint u1;
  uint u2;
  
  u2 = aa ^ bb;
  if ((bb != 0) || (u1 = 0x7fffffff, false)) {
    if ((int)aa < 0) {
      aa = -aa;
    }
    if ((int)bb < 0) {
      bb = -bb;
    }
    u1 = (aa << 0xc) / bb;
    if (bb == 0) {
      trap(0x1c00);
    }
    if (aa >> 0x14 != 0) {
      if (bb == 0) {
        trap(0x1c00);
      }
      u1 = u1 + (aa >> 0x14) * 2 * (0x80000000 / bb);
    }
  }
  if ((int)u2 < 0) {
    u1 = -u1;
  }
  return u1;
}





int f_800a45e0_vecs_mi(VECTOR *v0,VECTOR *v1)
{
  int i1;
  int i2;
  int i3;
  int i4;
  

  i1 = v0->vx - v1->vx;
  if (i1 < 0) {
    i1 = v1->vx - v0->vx;
  }
  i4 = v0->vy - v1->vy;
  if (i4 < 0) {
    i4 = v1->vy - v0->vy;
  }
  i3 = v0->vz - v1->vz;
  if (i3 < 0) {
    i3 = v1->vz - v0->vz;
  }
  i2 = i1;
  if (i1 < i4) {
    i2 = i4;
    i4 = i1;
  }
  i1 = i2;
  if (i2 < i3) {
    i1 = i3;
    i3 = i2;
  }
  return i1 + (i4 + i3 >> 2);
}




int f_80027d88_vec_xyz_sht(VECTOR *aa,VECTOR *bb,int *out)
{
  int i1;
  int i2;
  int i3;
  int i4;
  
  i1 = aa->vx - bb->vx;
  if (i1 < 0) {
    i1 = bb->vx - aa->vx;
  }
  i4 = aa->vy - bb->vy;
  if (i4 < 0) {
    i4 = bb->vy - aa->vy;
  }
  i3 = aa->vz - bb->vz;
  if (i3 < 0) {
    i3 = bb->vz - aa->vz;
  }
  i2 = i1;
  if (i1 < i4) {
    i2 = i4;
    i4 = i1;
  }
  i1 = i2;
  if (i2 < i3) {
    i1 = i3;
    i3 = i2;
  }
  *out = i1 + (i4 + i3 >> 2);
  return 0;
}




int f_80028750_vec_big_mults(VECTOR *v0,VECTOR *v1,VECTOR *dst)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = f_80010654_longlong_mult(v0->vx,v1->vx);
  iVar2 = f_80010654_longlong_mult(v0->vy,v1->vy);
  iVar3 = f_80010654_longlong_mult(v0->vz,v1->vz);
  iVar3 = iVar1 + iVar2 + iVar3;
  iVar1 = f_80010654_longlong_mult(v1->vx,iVar3);
  iVar2 = f_80010654_longlong_mult(v1->vy,iVar3);
  iVar3 = f_80010654_longlong_mult(v1->vz,iVar3);
  dst->vx = v0->vx - iVar1;
  dst->vy = v0->vy - iVar2;
  dst->vz = v0->vz - iVar3;
  return 0;
}




int f_80027d00_vec_stuff_xz(VECTOR *v0,VECTOR *v1,int *out)

{
  int i1;
  int i2;
  int i3;
  int i4;
  
  //printf("stuff xz %p %p\n", v0, v1);
  
  i4 = v0->vx - v1->vx;
  if (i4 < 0) {
    i4 = v1->vx - v0->vx;
  }
  i1 = v0->vz - v1->vz;
  if (i1 < 0) {
    i1 = v1->vz - v0->vz;
  }
  i2 = i4 + i1;
  i3 = i4 - i1;
  if (i3 < 0) {
    i3 = i1 - i4;
  }
  if (i3 < i2 >> 1) {
    i2 = i2 - (i2 >> 2);
  }
  else if (i3 <= (i2 >> 1) + (i2 >> 2)) {
    i2 = i2 - (i2 >> 3);
  }
  *out = i2;
  return 0;
}





int f_800230e4_vc_shift(VECTOR *aa,VECTOR *bb)
{
  bb->vx = aa->vx << 0xc;
  bb->vy = aa->vy << 0xc;
  bb->vz = aa->vz << 0xc;
  return 0;
}




int f_80010654_longlong_mult(int aa,int bb)
{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  
  lVar1 = (longlong)aa * (longlong)bb;
  uVar3 = (uint)((ulonglong)lVar1 >> 0x20);
  if (-1 < lVar1) {
    return uVar3 * 0x100000 + ((uint)lVar1 >> 0xc);
  }
  uVar2 = -(uint)lVar1;
  uVar3 = ~uVar3;
  if (uVar2 == 0) {
    uVar3 = uVar3 + 1;
  }
  return -(uVar3 * 0x100000 + (uVar2 >> 0xc));
}





int f_80023a4c_vec_mag_xz(VECTOR *v0,int *v1)

{
  int i1;
  int i2;
  int i3;
  
  i1 = f_80010654_longlong_mult(v0->vx,v0->vx);
  i2 = f_80010654_longlong_mult(v0->vz,v0->vz);
  i3 = SquareRoot12(i1 + i2);
  *v1 = i3;
  return 0;
}





int f_80028150_vec_mag_and_ratan(VECTOR *vec,int *out)
{
  int i1;
  int hm [2];
  
  f_80023a4c_vec_mag_xz(vec,hm);
  i1 = ratan2(vec->vy,hm[0]);
  *out = -i1;
  return 0;
}



int f_800280dc_ratan_stuff(VECTOR *vv,int *out)
{
  int q;
  
  q = SquareRoot0(vv->vx * vv->vx + vv->vz * vv->vz);
  q = ratan2(vv->vy,q);
  *out = -q;
  return 0;
}


int f_800281a4_ratan_wrp(VECTOR *vv,int *ou)
{
  int i1;
  
  i1 = ratan2(vv->vx,vv->vz);
  *ou = i1;
  return 0;
}


int f_800282ec_xz_ratan(VECTOR *vv,VECTOR *out)
{
  int i1;
  
  i1 = ratan2(vv->vx,vv->vz);
  out->vy = i1;
  f_800280dc_ratan_stuff(vv,&out->vx);
  out->vz = 0;
  return 0;
}





void f_800a86b4_fill_mem(uint *pp,int sz)
{
  int i;
  undefined *p;
  
  i = sz + -1;
  if (sz != 0) {
    p = (undefined *)((int)pp + 6);
    do {
      p[9] = 8;
      p[-2] = 0;
      p[-1] = 0;
      *p = 0;
      p = p + 0x10;
      *pp = 0;
      i = i + -1;
      pp = pp + 4;
    } while (i != -1);
  }
  return;
}




void f_800266a8_mem_set(void *adr,int val,int sz)
{
  uint wrd;
  
  wrd = val & 0xff;
  if (3 < (uint)sz) {
    do {
      *(uint *)adr = wrd | wrd << 8 | wrd << 0x10 | wrd << 0x18;
      sz = sz - 4;
      adr = (void *)((int)adr + 4);
    } while (3 < (uint)sz);
  }
  return;
}



void f_8009f890_mtx_shuff(MATRIX *m)
{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  
  sVar1 = m->m[0];
  sVar2 = m->m[3];
  sVar3 = m->m[6];
  sVar4 = m->m[4];
  sVar5 = m->m[7];
  sVar6 = m->m[2];
  sVar7 = m->m[5];
  sVar8 = m->m[8];
  m->m[0] = m->m[1];
  m->m[3] = sVar4;
  m->m[6] = sVar5;
  m->m[1] = -sVar6;
  m->m[4] = -sVar7;
  m->m[7] = -sVar8;
  m->m[2] = -sVar1;
  m->m[5] = -sVar2;
  m->m[8] = -sVar3;
  return;
}



void f_8009f798_mtx_shuff2(MATRIX *m)
{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  
  sVar1 = m->m[0];
  sVar2 = m->m[3];
  sVar3 = m->m[6];
  sVar4 = m->m[1];
  sVar5 = m->m[4];
  sVar6 = m->m[7];
  sVar7 = m->m[5];
  sVar8 = m->m[8];
  m->m[0] = -m->m[2];
  m->m[3] = -sVar7;
  m->m[6] = -sVar8;
  m->m[1] = sVar1;
  m->m[4] = sVar2;
  m->m[7] = sVar3;
  m->m[2] = -sVar4;
  m->m[5] = -sVar5;
  m->m[8] = -sVar6;
  return;
}



void f_8009f6a0_mtx_shuff3(MATRIX *m)
{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  
  sVar1 = m->m[0];
  sVar2 = m->m[3];
  sVar3 = m->m[6];
  sVar4 = m->m[4];
  sVar5 = m->m[7];
  sVar6 = m->m[2];
  sVar7 = m->m[5];
  sVar8 = m->m[8];
  m->m[0] = -m->m[1];
  m->m[3] = -sVar4;
  m->m[6] = -sVar5;
  m->m[1] = -sVar6;
  m->m[4] = -sVar7;
  m->m[7] = -sVar8;
  m->m[2] = sVar1;
  m->m[5] = sVar2;
  m->m[8] = sVar3;
  return;
}




void f_8009f5ac_mtx_shuff4(MATRIX *m)
{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  
  sVar1 = m->m[0];
  sVar2 = m->m[3];
  sVar3 = m->m[6];
  sVar4 = m->m[1];
  sVar5 = m->m[4];
  sVar6 = m->m[7];
  sVar7 = m->m[5];
  sVar8 = m->m[8];
  m->m[0] = m->m[2];
  m->m[3] = sVar7;
  m->m[6] = sVar8;
  m->m[1] = -sVar1;
  m->m[4] = -sVar2;
  m->m[7] = -sVar3;
  m->m[2] = -sVar4;
  m->m[5] = -sVar5;
  m->m[8] = -sVar6;
  return;
}




void f_80100038_sndchan_destr(uint i)
{
  PFN_CHAN ff;
  
  SpuSetKey(0,1 << (i & 0x1f));
  ff = g_80145ac0_chans[i].f44_ptr_code;
  g_80145ac0_chans[i].f00_first = 0;
  if (ff != 0x0) {
    (*ff)(i,g_80145ac0_chans[i].f_40_my_mid,4);
  }
  return;
}






void f_80100254_snd_chan_un1(int chInd)
{
  uint u1;
  SndChan *sc;
  uint q;
  
  q = 0;
  sc = g_80145ac0_chans;
  do {
    u1 = 1 << (q & 0x1f);
    if (((chInd & u1) != 0) && (sc->f00_first == 1)) {
      if (sc->f44_ptr_code != 0x0) {
        (*sc->f44_ptr_code)(q,sc->f_40_my_mid,3);
      }
      if ((g_80122178_snd_some_mask & u1) != 0) {
        g_80122178_snd_some_mask = g_80122178_snd_some_mask & ~u1;
      }
    }
    q = q + 1;
    sc = sc + 1;
  } while ((int)q < 0x18);
  g_8012217c_snd_mask2 = g_8012217c_snd_mask2 | chInd;
  return;
}



SndChan * f_80100318_snd_chan_by_index(int ind)
{
  return g_80145ac0_chans + ind;
}



// every frame
void f_80100120_snd_chans_iter_un(void)
{
  int i;
  SndChan *cha;
  uint u1;
  uint u2;
  

  u2 = 0;
  u1 = 0;
  cha = g_80145ac0_chans;
  do {
    if (((cha->f00_first == 1) && (i = cha->f_08_i2 + -1, cha->f_08_i2 != 0)) &&
       (cha->f_08_i2 = i, i == 0)) {
      u2 = u2 | 1 << (u1 & 0x1f);
      if (cha->f44_ptr_code != 0x0) {
          printf(" at iter... exec cb !\n");
        (*cha->f44_ptr_code)(u1,cha->f_40_my_mid,3);
      }
    }
    u1 = u1 + 1;
    cha = cha + 1;
  } while ((int)u1 < 0x18);
  g_8012217c_snd_mask2 = g_8012217c_snd_mask2 | u2;
  return;
}


// snd kill ?
void f_801001c4_snd_chan_he2(int chan_i)
{
  uint uu;
  
  if ((g_80145ac0_chans[chan_i].f00_first == 1) &&
     (g_80145ac0_chans[chan_i].f44_ptr_code != 0x0)) {
    (*g_80145ac0_chans[chan_i].f44_ptr_code)(chan_i,g_80145ac0_chans[chan_i].f_40_my_mid,3);
  }
  uu = 1 << (chan_i & 0x1fU);
  if ((g_80122178_snd_some_mask & uu) != 0) {
    g_80122178_snd_some_mask = g_80122178_snd_some_mask & ~uu;
  }
  g_8012217c_snd_mask2 = g_8012217c_snd_mask2 | uu;
  return;
}




int f_80107a94_snd_get_unk99(void)
{
  return g_801221b0_snd_rela99;
}





void f_800fcb4c_snd_cha_sb_unks(HeadSBNK *sb)
{
  SndChan *ch;
  int ii;
  uint i;
  
  printf("unkzzz %p\n", sb);
  
  if (sb != 0x0) {
    ii = 0;
    if (0 < sb->f_18_s) {
      do {
        f_800fc774_sbank_dunno(sb,ii);
        ii = ii + 1;
      } while (ii < sb->f_18_s);
    }
    i = 0;
    do {
      ch = f_80100318_snd_chan_by_index(i);
      if (ch->f44_ptr_code == f_800fcb1c_snd_chan_cb_sht) {
        if (((HeadMID *)sb->f_20_ents <= ch->f_40_my_mid) &&
           (ch->f_40_my_mid <=
            (HeadMID *)((int)(HeadMID *)sb->f_20_ents + sb->f_18_s * 0x24 + -0x24))) {
          f_80100038_sndchan_destr(i);
        }
      }
      i = i + 1;
    } while ((int)i < 0x18);
  }
  return;
}






int f_800ffc3c_snd_chans_maybe_alloc(int maybePriority,HeadMID *mid,PFN_CHAN func1)
{
  SndChan *cha;
  int q1;
  int i1;
  
  q1 = 0;
  cha = g_80145ac0_chans;
  do {
    if (cha->f00_first == 0) {
      cha->f00_first = 2;
      i1 = f_80107a94_snd_get_unk99();
      cha->f_04_val1 = i1;
      goto LAB_800ffd84;
    }
    q1 = q1 + 1;
    cha = cha + 1;
  } while (q1 < 0x18);
  q1 = 0;
  i1 = 1;
  cha = g_80145ac0_chans;
  do {
    if ((cha[1].f_28_mb_prio < g_80145ac0_chans[q1].f_28_mb_prio) ||
       ((cha[1].f_28_mb_prio == g_80145ac0_chans[q1].f_28_mb_prio &&
        ((uint)cha[1].f_04_val1 < (uint)g_80145ac0_chans[q1].f_04_val1)))) {
      q1 = i1;
    }
    i1 = i1 + 1;
    cha = cha + 1;
  } while (i1 < 0x18);
  cha = g_80145ac0_chans + q1;
  i1 = -1;
  if ((g_80145ac0_chans[q1].f_28_mb_prio <= maybePriority) &&
     (i1 = -1, g_80145ac0_chans[q1].f_28_mb_prio != 0x7f)) {
    if (g_80145ac0_chans[q1].f44_ptr_code != 0x0) {
      (*g_80145ac0_chans[q1].f44_ptr_code)(q1,g_80145ac0_chans[q1].f_40_my_mid,1);
    }
    cha->f00_first = 2;
    i1 = f_80107a94_snd_get_unk99();
    g_80145ac0_chans[q1].f_04_val1 = i1;
LAB_800ffd84:
    cha->f_28_mb_prio = maybePriority;
    cha->f_40_my_mid = mid;
    cha->f44_ptr_code = func1;
    i1 = q1;
  }
  return i1;
}




int f_800fecf8_vol_calc(short vv,int a2)
{
  short s2;
  int i1;
  
  i1 = ((int)vv * g_8011fcb0_ar_vol_sht[a2]) / 0x7f;
  s2 = 1;
  if (i1 < 0) {
    s2 = -1;
  }
  return (int)(short)((short)((i1 * i1) / 0x3fff) * s2);
}






void f_801000a0_snd_chan_prio_destr(int chanInd)
{
  if (g_80145ac0_chans[chanInd].f_28_mb_prio != 0x7f) {
    g_80145ac0_chans[chanInd].f00_first = 0;
  }
  if (g_80145ac0_chans[chanInd].f44_ptr_code != 0x0) {
    (*g_80145ac0_chans[chanInd].f44_ptr_code)(chanInd,g_80145ac0_chans[chanInd].f_40_my_mid,2);
  }
  g_80122184_snd_msk3 = g_80122184_snd_msk3 & ~(1 << (chanInd & 0x1fU));
  return;
}







int f_800fee3c_snd_he3(uint uu)
{
  int i1;
  uint u2;
  
  u2 = uu & 0xff;
  if (u2 < 0x40) {
    i1 = u2 * 0x5a;
    if (false) {
      i1 = i1 + 0x3f;
    }
    return (i1 >> 6) + 0x10e;
  }
  return ((int)((u2 - 0x40) * 0x5a) / 0x3f) * 0x10000 >> 0x10;
}




void f_800ffbec_snd_callbacks(void)
{
  PFN_VOID ff;
  
  ff = g_80122174_snd_cb_x2;
  g_80122170_snd_x1 = 0;
  if (g_80122174_snd_cb_x2 != 0x0) {
    g_80122174_snd_cb_x2 = 0x0;
    (*ff)();
  }
  if (g_80122168_voice_env_req != 0) {
    f_801078a4_spu_voice_env();
    g_80122168_voice_env_req = 0;
  }
  return;
}



int f_800ffbbc_snd_set_cb_x2(PFN_VOID cb)
{
  if (g_80122170_snd_x1 != 0) {
    if (cb != 0x0) {
      g_80122174_snd_cb_x2 = cb;
    }
    return 0;
  }
  g_80122170_snd_x1 = 1;
  return 1;
}




void f_80101764_mid_he2(HeadMID *mid)
{
  SndChan *chan;
  int ind;
  uint uVar1;
  
  ind = 0;
  uVar1 = mid->f_07_s3 & 0xf;
  mid->f_42_msk1 = mid->f_42_msk1 & ~(ushort)(1 << uVar1);
  f_800ffbbc_snd_set_cb_x2( 0x0 );
  do {
    chan = f_80100318_snd_chan_by_index(ind);
    if ((((chan->f00_first == 1) && (chan->f_40_my_mid == mid)) && ((int)chan->f_10_mini == uVar1))
       && (chan->f_14_i == 1)) {
      f_801001c4_snd_chan_he2(ind);
    }
    ind = ind + 1;
  } while (ind < 0x18);
  f_800ffbec_snd_callbacks();
  return;
}






int f_800fca90_sbank_rn(HeadSBNK *sb,int ind,int a3,BankProps **arr)
{
  BankProps *pr;
  int qq;
  uint uVar1;
  int ii;
  
  ii = 0;
  if (sb->f_1a_s2 <= ind) {
    return 0;
  }
  uVar1 = (uint)sb->f_24_tabs[ind].smp_ind;
  pr = sb->f_24_tabs[ind].p_juice;
  qq = 0;
  if (uVar1 != 0) {
    do {
      if (((int)(uint)pr->f_06_rng1 <= a3) && (a3 <= (int)(uint)pr->f_07_rng2)) {
        *arr = pr;
        arr = arr + 1;
        ii = ii + 1;
      }
      qq = qq + 1;
      pr = pr + 1;
    } while (qq < (int)uVar1);
  }
  return ii;
}





int f_80029054_mtx_lv(VECTOR *v0,MATRIX *mtx,VECTOR *dst)
{
  ApplyMatrixLV(mtx,v0,dst);
  dst->vx = dst->vx + mtx->t[0];
  dst->vy = dst->vy + mtx->t[1];
  dst->vz = dst->vz + mtx->t[2];
  return 0;
}

















// called at wpn switch
void f_80057f84_wpn_sub_unk(DonkSub1 *st)
{
  int i8;
  int i1;
  int i2;
  int i5;
  int i9;
  short *qq;
  short *ss;
  
  i8 = st->f_04_i;
  if (0 < i8) {
    i9 = 0;
    i5 = 0;
    i1 = 0;
    if (0 < i8) {
      i2 = st->f_08_i2;
      do {
        ss = (short *)(i2 + 4);
        qq = (short *)(i2 + 6);
        i2 = i2 + 0x2c;
        i5 = i5 + 1;
        i9 = i9 + *ss;
        i1 = i1 + *qq;
      } while (i5 < i8);
    }
    i8 = st->f_04_i;
    if (i8 == 0) {
      trap(0x1c00);
    }
    if ((i8 == -1) && (i9 == -0x80000000)) {
      trap(0x1800);
    }
    i5 = st->f_04_i;
    if (i5 == 0) {
      trap(0x1c00);
    }
    if ((i5 == -1) && (i1 == -0x80000000)) {
      trap(0x1800);
    }
    st->f_00_sho1 = (short)(i9 / i8);
    st->f_02_sho2 = (short)(i1 / i5);
    
  }
  return;
}




// called at weapon switch
DonkSub2C * f_800580e4_wpn_rel_fills_str(uint ii,DonkSub2C *pt)
{
  if ((pt == (DonkSub2C *)0x0) || (0x52 < ii)) {
    pt = (DonkSub2C *)0x0;
  }
  else {
    pt->f_00_i = g_80132084_wpn_icons_tab[ii].f_0_u;
    pt->f_0c_bbb = g_80132084_wpn_icons_tab[ii].f_2_shsh;
    pt->f_e_by1 = g_80132084_wpn_icons_tab[ii].f_6_qq;
    pt->f_f_by2 = g_80132084_wpn_icons_tab[ii].f_7_ub;
    pt->f_08_s3_mb_arr = g_80132084_wpn_icons_tab[ii].f_8_x1;
    pt->f_0a_aaa = g_80132084_wpn_icons_tab[ii].f_a_x2;
    pt->f_10_s1 = g_80132084_wpn_icons_tab[ii].f_c_sh2;
    pt->f_12_s2 = g_80132084_wpn_icons_tab[ii].f_e_sh3;
    pt->f_18_x1 = (ushort)g_80132084_wpn_icons_tab[ii].f_8_x1 >> 1;
    pt->f_1a_x2 = g_80132084_wpn_icons_tab[ii].f_a_x2 >> 1;
  }
  return pt;
}





void f_80058190_wpn_helper1(int val,int num,DonkSub2C *pt)
{
  short *ppp;
  int ii;
  short s1;
  short s2;
  short sss;
  
  s1 = pt->f_04_s1;
  s2 = pt->f_06_s2;
  ii = 0;
  if (0 < num) {
    ppp = &pt->f_08_s3_mb_arr;
    do {
      f_800580e4_wpn_rel_fills_str(val + ii,pt);
      sss = *ppp;
      ii = ii + 1;
      ppp[-2] = s1;
      ppp[-1] = s2;
      ppp = ppp + 0x16;
      s1 = s1 + sss;
      pt = pt + 1;
    } while (ii < num);
  }
  return;
}




void f_80057e04_wpn_two_shorts(DonkSub1 *s,short s1,short s2)
{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  sVar1 = s->f_00_sho1;
  iVar4 = 0;
  sVar2 = s->f_02_sho2;
  if (0 < s->f_04_i) {
    iVar5 = 0;
    do {
      iVar4 = iVar4 + 1;
      iVar3 = s->f_08_i2 + iVar5;
      *(short *)(iVar3 + 4) = *(short *)(iVar3 + 4) + (s1 - sVar1);
      *(short *)(iVar3 + 6) = *(short *)(iVar3 + 6) + (s2 - sVar2);
      iVar5 = iVar5 + 0x2c;
    } while (iVar4 < s->f_04_i);
  }
  s->f_00_sho1 = s1;
  s->f_02_sho2 = s2;
  return;
}



int f_8005ed6c_mini1(char aa,int *ret)
{
  
  if (aa == '\0') {
    if (*ret < 0) {
      return 0;
    }
    *ret = *ret + -1;
  }
  else {
    if (0xb < *ret) {
      return 0;
    }
    *ret = *ret + 1;
  }
  return 1;
}





int f_80028344_mtx_rot_yxz(VECTOR *q,VECTOR *ret)
{
  MATRIX mmm;
  int svsv [4];
  
  memset(svsv + 2,0,8);
  svsv[0] = q->vx & 0xffffU | q->vy << 0x10;
  svsv[3] = q->vz & 0xffffU | (uint)__EvilGet2_2(&svsv[3]) << 0x10;
  svsv[1] = svsv[3];
  svsv[2] = svsv[0];

  RotMatrixYXZ((SVECTOR *)svsv,&mmm);
  ret->vx = (int)mmm.m[2];
  ret->vy = (int)mmm.m[5];
  ret->vz = (int)mmm.m[8];
  return 0;
}




void f_8005584c_mtx_rotz_yxz(PlaStAtF4 *unk_st,VECTOR *vc)
{
  long lVar1;
  long lVar2;
  long lVar3;
  
  if (vc != 0x0) {
    lVar1 = vc->vy;
    lVar2 = vc->vz;
    lVar3 = vc->pad;
    (unk_st->f_224_vc).vx = vc->vx;
    (unk_st->f_224_vc).vy = lVar1;
    (unk_st->f_224_vc).vz = lVar2;
    (unk_st->f_224_vc).pad = lVar3;
    f_80028344_mtx_rot_yxz(vc,&unk_st->f_234_vc2);
  }
  lVar1 = (unk_st->f_224_vc).vy;
  lVar2 = (unk_st->f_224_vc).vy;
  unk_st->f_214_i = 0;
  unk_st->f_21c_i2 = 0;
  unk_st->f_218_i3 = lVar1;
  unk_st->f_220_i4 = lVar2;
  return;
}




void f_80050ca8_setupz(PlaStAtF4 *st)
{
  uint i1;
  
  f_8005584c_mtx_rotz_yxz(st,(VECTOR *)0x0);
  i1 = st->f_18_bits;
  (st->f_234_vc2).vx = 0;
  (st->f_234_vc2).vy = 0;
  (st->f_234_vc2).vz = 0;
  st->f_20c_qqq = 0;
  st->f_2c4_ii = 0;
  st->f_2c6_i2 = 0;
  st->f_2c8_i3 = 0;
  st->f_2cc_i5 = 0;
  st->f_2ce_i8 = 0;
  st->f_2d0_shhshh = 0;
  st->f_2d4 = 0;
  st->f_2d6 = 0;
  st->f_2d8 = 0;
  st->f_18_bits = i1 & 0xfffffff9;
  return;
}






void f_800558bc_vec_u7(PlaStAtF4 *s,VECTOR *vc)
{
  uint u1;
  long i1;
  long i3;
  long i2;
  
  s->f_218_i3 = (s->f_224_vc).vy;
  s->f_214_i = s->f_21c_i2;
  if (vc != (VECTOR *)0x0) {
    s->f_220_i4 = vc->vy;
  }
  u1 = s->f_220_i4 - s->f_218_i3 & 0xfff;
  s->f_21c_i2 = u1;
  if (0x800 < u1) {
    s->f_21c_i2 = u1 - 0x1000;
  }
  if (vc != (VECTOR *)0x0) {
    i1 = vc->vy;
    i3 = vc->vz;
    i2 = vc->pad;
    (s->f_224_vc).vx = vc->vx;
    (s->f_224_vc).vy = i1;
    (s->f_224_vc).vz = i3;
    (s->f_224_vc).pad = i2;
    f_80028344_mtx_rot_yxz(vc,&s->f_234_vc2);
  }
  return;
}








// menu weaponry tims
int f_80025f10_load_images_vram(ImgDerp *q)
{
  int i1;
  RECT rc1;
  RECT rc2;
  

  DrawSync(0);
  i1 = 0x13;
  if (q != (ImgDerp *)0xfffffff4) {
    rc1.x = (q->f_0c_gs_img).px;
    rc1.y = (q->f_0c_gs_img).py;
    rc1.w = (q->f_0c_gs_img).pw;
    rc1.h = (q->f_0c_gs_img).ph;
    LoadImage(&rc1,(q->f_0c_gs_img).pixel);
    if (((q->f_0c_gs_img).pmode >> 3 & 1) != 0) {
      rc2.x = (q->f_0c_gs_img).cx;
      rc2.y = (q->f_0c_gs_img).cy;
      rc2.w = (q->f_0c_gs_img).cw;
      rc2.h = (q->f_0c_gs_img).ch;
      LoadImage(&rc2,(q->f_0c_gs_img).clut);
    }
    q->f_09_mb_uploaded = 1;
    i1 = 0;
  }
  return i1;
}





int f_80025eac_get_tim_info(ImgDerp *rrr)
{
  int i1;
  int *pp;
  
  pp = (int *)rrr->f_00_ptr;
  if ((pp == (int *)0x0) || (*pp != 0x10)) {
    i1 = 0x13;
  }
  else {
    GsGetTimInfo((ulong *)(pp + 1),&rrr->f_0c_gs_img);
    i1 = 0;
    rrr->f_28_dunno = 0;
    rrr->f_09_mb_uploaded = 0;
    rrr->f_08_dunno = 0;
  }
  return i1;
}






int f_800277ac_str_tab_search(StrTabHead *tt,char *nam,int *ret)
{
  int i1;
  byte *p;
  int i2;
  int i3;
  byte b;
  
  
  if ((((tt == (StrTabHead *)0x0) || (tt->ptr_dun == (byte *)0x0)) || (nam == (char *)0x0)) ||
     (i2 = 0, ret == (int *)0x0)) {
    i2 = 1;
  }
  else {
    i3 = 0;
    if (0 < *(int *)(tt->ptr_dun + 4)) {
      do {
        i1 = strcmp(nam,(char *)(tt->ptr_dun + i2 + *(int *)(tt->ptr_dun + 0xc)));
        if (i1 == 0) break;
        p = tt->ptr_dun;
        i1 = i2 + *(int *)(p + 0xc);
        i2 = i2 + 1;
        if (p[i1] != 0) {
          p = p + i2 + *(int *)(p + 0xc);
          do {
            b = *p;
            p = p + 1;
            i2 = i2 + 1;
          } while (b != 0);
        }
        i3 = i3 + 1;
      } while (i3 < *(int *)(tt->ptr_dun + 4));
      p = tt->ptr_dun;
      if (i3 < *(int *)(p + 4)) {
        *ret = (int)(p + *(int *)(p + i3 * 4 + *(int *)(p + 8)) + *(int *)(p + 0x10));
        return 0;
      }
    }
    i2 = 5;
  }
  return i2;
}





int f_800276b0_str_tab_get_count(StrTabHead *unun)
{
  int ii;
  
  ii = 1;
  if ((unun != (StrTabHead *)0x0) && (unun->ptr_dun != (byte *)0x0)) {
    ii = *(int *)(unun->ptr_dun + 4);
  }
  return ii;
}




int f_80027744_str_tab_he1(StrTabHead *unun,int ii,int *out)
{
  int i;
  byte *b;
  
  i = 1;
  if (((unun != (StrTabHead *)0x0) && (b = unun->ptr_dun, b != (byte *)0x0)) && (i = 0xe, -1 < ii))
  {
    if (ii < *(int *)(b + 4)) {
      i = 0;
      *out = *(int *)((int)(b + ii * 4 + *(int *)(b + 8)) + 4) -
             *(int *)(b + ii * 4 + *(int *)(b + 8));
    }
    else {
      i = 0xe;
    }
  }
  return i;
}




int f_800278f8_str_fn(StrTabHead *unun,char *fn)
{
  int i2;
  int rr;
  byte *pp;
  int ii;
  byte b1;
  
  pp = unun->ptr_dun;
  rr = 0;
  ii = 0;
  if (0 < *(int *)(pp + 4)) {
    do {
      i2 = strcmp(fn,(char *)(pp + rr + *(int *)(pp + 0xc)));
      if (i2 == 0) break;
      pp = unun->ptr_dun;
      i2 = rr + *(int *)(pp + 0xc);
      rr = rr + 1;
      if (pp[i2] != 0) {
        pp = pp + rr + *(int *)(pp + 0xc);
        do {
          b1 = *pp;
          pp = pp + 1;
          rr = rr + 1;
        } while (b1 != 0);
      }
      pp = unun->ptr_dun;
      ii = ii + 1;
    } while (ii < *(int *)(pp + 4));
  }
  rr = -1;
  if (ii < *(int *)(unun->ptr_dun + 4)) {
    rr = ii;
  }
  return rr;
}



int f_800276d4_str_tab_get_p(StrTabHead *unun,int ind,byte *im)
{
  int i;
  byte *b;
  

  i = 1;
  if ((((unun != (StrTabHead *)0x0) && (b = unun->ptr_dun, b != (byte *)0x0)) && (im != (byte *)0x0)
      ) && (i = 0xe, -1 < ind)) {
    i = 0;
    if (ind < *(int *)(b + 4)) {
      *(byte **)im = b + *(int *)(b + ind * 4 + *(int *)(b + 8)) + *(int *)(b + 0x10);
    }
    else {
      i = 0xe;
    }
  }
  return i;
}





uint f_8002c7bc_mode_check(void)
{
  uint r;
  
  r = 0;
  if ((g_80121b88_main_mode != 0) && (1 < g_80121b88_main_mode - 5)) {
    r = (uint)(g_80121b88_main_mode != 9);
  }
  return r;
}



int f_8001ce40_util1(uint v)
{
  int i1;
  
  if (v == 0) {
    i1 = 0x2000;
  }
  else {
    i1 = (v & 0xffff) + ((int)(0x1000 - (v & 0xffff)) >> (((int)v >> 0x10) - 1U & 0x1f));
  }
  return i1;
}




int f_80022ffc_util3(int p1,int p2,int *out)
{
  int i1;
  
  *out = p1;
  if (p2 == 0) {
    return 1;
  }
  if (p1 < 0) {
    i1 = p1 + p2;
  }
  else {
    i1 = p1 - p2;
    if (p1 < p2) goto LAB_80023028;
  }
  *out = i1;
LAB_80023028:
  i1 = *out;
  if ((i1 < 0) || (p2 <= i1)) {
    if (p2 == 0) {
      trap(0x1c00);
    }
    if ((p2 == -1) && (i1 == -0x80000000)) {
      trap(0x1800);
    }
    *out = i1 % p2;
  }
  return 0;
}




int f_80023080_sin_cos(int ang,uint *out)
{
  uint u1;
  uint bb;
  int i1;
  
  u1 = rsin(ang);
  bb = rcos(ang);
  if (bb == 0) {
    *out = 0;
    i1 = 7;
  }
  else {
    u1 = f_80010698_bits(u1,bb);
    *out = u1;
    i1 = 0;
  }
  return i1;
}



// mad skillz
int f_80023374_vec_calc_smt(VECTOR *vec,int *out)
{
  undefined uVar1;
  undefined2 uVar2;
  undefined4 ii3;
  int iVar3;
  uint u4;
  uint uVar4;
  int p3;
  int *plVar4;
  VECTOR *p1;
  VECTOR *p2;
  int i2;
  VECTOR loc;
  
  loc.vx = vec->vx;
  p1 = &loc;
  p2 = &loc;
  if (loc.vx < 0) {
    loc.vx = -loc.vx;
  }
  loc.vy = vec->vy;
  loc.vz = vec->vz;
  if (loc.vy < 0) {
    loc.vy = -loc.vy;
  }
  if (loc.vz < 0) {
    loc.vz = -loc.vz;
  }
  if (loc.vx < loc.vy) {
    p3 = (int)&loc.vy;
    if (true) {
      u4 = 4;
      if (false) {
        u4 = 2;
      }
    }
    else {
      u4 = 1;
    }
    if (u4 == 0) {
      trap(0x1c00);
    }
    i2 = 4 / u4 - 1;
    if (i2 != -1) {
      do {
        if (u4 == 2) {
          uVar2 = *(undefined2 *)p1;
          *(undefined2 *)p1 = *(undefined2 *)p3;
          *(undefined2 *)p3 = uVar2;
        }
        else if (u4 < 3) {
          if (u4 == 1) {
            uVar1 = *(undefined *)p1;
            *(undefined *)p1 = *(undefined *)p3;
            *(undefined *)p3 = uVar1;
          }
        }
        else if (u4 == 4) {
          ii3 = p1->vx;
          p1->vx = *(undefined4 *)p3;
          *(undefined4 *)p3 = ii3;
        }
        p1 = (VECTOR *)((int)p1 + u4);
        i2 = i2 + -1;
        p3 = p3 + u4;
      } while (i2 != -1);
    }
  }
  if (loc.vx < loc.vz) {
    plVar4 = &loc.vz;
    if (true) {
      uVar4 = 4;
      if (false) {
        uVar4 = 2;
      }
    }
    else {
      uVar4 = 1;
    }
    if (uVar4 == 0) {
      trap(0x1c00);
    }
    i2 = 4 / uVar4 - 1;
    if (i2 != -1) {
      do {
        if (uVar4 == 2) {
          uVar2 = *(undefined2 *)p2;
          *(undefined2 *)p2 = *(undefined2 *)plVar4;
          *(undefined2 *)plVar4 = uVar2;
        }
        else if (uVar4 < 3) {
          if (uVar4 == 1) {
            uVar1 = *(undefined *)p2;
            *(undefined *)p2 = *(undefined *)plVar4;
            *(undefined *)plVar4 = uVar1;
          }
        }
        else if (uVar4 == 4) {
          iVar3 = p2->vx;
          p2->vx = *plVar4;
          *plVar4 = iVar3;
        }
        p2 = (VECTOR *)((int)p2 + uVar4);
        i2 = i2 + -1;
        plVar4 = (int *)((int)plVar4 + uVar4);
      } while (i2 != -1);
    }
  }
  *out = loc.vx + (loc.vy + loc.vz >> 2);
  
  return 1;
}







int f_80023bf4_node_mtx_transp_lv(Node *nnn,MATRIX *mt)
{
  VECTOR vv;
  
  TransposeMatrix(&nnn->f_00_mtx,mt);
  mt->t[0] = (nnn->f_00_mtx).t[0];
  mt->t[1] = (nnn->f_00_mtx).t[1];
  mt->t[2] = (nnn->f_00_mtx).t[2];
  vv.vx = -(nnn->f_00_mtx).t[0];
  vv.vy = -(nnn->f_00_mtx).t[1];
  vv.vz = -(nnn->f_00_mtx).t[2];
  ApplyMatrixLV(mt,&vv,&vv);
  mt->t[0] = vv.vx;
  mt->t[1] = vv.vy;
  mt->t[2] = vv.vz;
  return 0;
}




int f_800239c4_vec_node_lv(VECTOR *v1,Node *no,VECTOR *out)
{
  MATRIX mt;
  
  f_80023bf4_node_mtx_transp_lv(no,&mt);
  ApplyMatrixLV(&mt,v1,out);
  out->vx = out->vx + mt.t[0];
  out->vy = out->vy + mt.t[1];
  out->vz = out->vz + mt.t[2];
  return 0;
}




int f_80024668_nodes_calc_mtx_recursive(Node *nn)
{
  int r1;
  undefined4 uVar1;
  long lVar2;
  undefined4 uVar3;
  long lVar4;
  undefined4 uVar5;
  long lVar6;
  Node *n2;
  Node *n3;
  
  if (nn == (Node *)0x0) {
    r1 = 0x18;
  }
  else {
    n2 = nn->f_20_n1;
    if (n2 == (Node *)0x0) {
LAB_80024698:
      r1 = 0x2b;
    }
    else {
      n3 = n2->f_20_n1;
      if (n3 == (Node *)0x0) {
        if (n2->f_2c_b0 == 1) {
          uVar1 = *(undefined4 *)((n2->f_00_mtx).m + 2);
          uVar3 = *(undefined4 *)((n2->f_00_mtx).m + 4);
          uVar5 = *(undefined4 *)((n2->f_00_mtx).m + 6);
          *(undefined4 *)(nn->f_00_mtx).m = *(undefined4 *)(n2->f_00_mtx).m;
          *(undefined4 *)((nn->f_00_mtx).m + 2) = uVar1;
          *(undefined4 *)((nn->f_00_mtx).m + 4) = uVar3;
          *(undefined4 *)((nn->f_00_mtx).m + 6) = uVar5;
          lVar2 = (n2->f_00_mtx).t[0];
          lVar4 = (n2->f_00_mtx).t[1];
          lVar6 = (n2->f_00_mtx).t[2];
          *(undefined4 *)((nn->f_00_mtx).m + 8) = *(undefined4 *)((n2->f_00_mtx).m + 8);
          (nn->f_00_mtx).t[0] = lVar2;
          (nn->f_00_mtx).t[1] = lVar4;
          (nn->f_00_mtx).t[2] = lVar6;
        }
      }
      else {
        r1 = f_80024668_nodes_calc_mtx_recursive(n3);
        if (r1 != 0) {
          return r1;
        }
        if (nn->f_20_n1->f_2c_b0 == 1) {
          CompMatrixLV(&n3->f_00_mtx,&nn->f_20_n1->f_00_mtx,&nn->f_00_mtx);
        }
      }
      nn->f_20_n1->f_2c_b0 = 0;
      n2 = nn->f_20_n1->f_24_n3;
      while (r1 = 0, n2 != (Node *)0x0) {
        if (n2->f_20_n1 == (Node *)0x0) goto LAB_80024698;
        n2->f_20_n1->f_2c_b0 = 1;
        n2 = n2->f_20_n1->f_24_n2;
      }
    }
  }
  return r1;
}




int f_80024b28_node_shuff(Node *no)
{
  Node *n3;
  int i1;
  Node *n1;
  Node *n2;
  
  if (no == (Node *)0x0) {
    return 0;
  }
  n2 = no->f_20_n1;
  if (n2 == (Node *)0x0) {
    return 0x2b;
  }
  if (n2->f_20_n1 == (Node *)0x0) {
    return 0;
  }
  n1 = n2->f_20_n1->f_20_n1;
  if (n1 == (Node *)0x0) {
    return 0x2b;
  }
  n3 = n1->f_24_n3;
  if (n3 == (Node *)0x0) {
LAB_80024bd8:
    i1 = 0x2b;
  }
  else {
    if (no == n3) {
      n1->f_24_n3 = n2->f_24_n2;
    }
    else {
      do {
        n2 = n3;
        n1 = n2->f_20_n1;
        if (n1 == (Node *)0x0) {
          return 0x2b;
        }
        n3 = n1->f_24_n2;
      } while ((n3 != (Node *)0x0) && (n3 != no));
      n2 = n2->f_20_n1;
      if (n2 == (Node *)0x0) {
        return 0x2b;
      }
      if (n2->f_24_n2 == (Node *)0x0) goto LAB_80024bd8;
      n2->f_24_n2 = no->f_20_n1->f_24_n2;
    }
    i1 = 0;
    no->f_20_n1->f_20_n1 = (Node *)0x0;
    no->f_20_n1->f_2c_b0 = 1;
  }
  return i1;
}




int f_80024c14_node_calc_all(Node *nnn)
{
  int i;
  
  i = f_80024668_nodes_calc_mtx_recursive(nnn);
  return i;
}




int f_80024c34_mtx_shuffles(MATRIX *aa,MATRIX *bb,MATRIX *cc)
{
  int t3;
  MATRIX mt;
  short t1;
  short t2;
  
  if (bb == aa) {
    cc->m[0] = g_8010f0d0_mtx_ident.m[0];
    cc->m[1] = g_8010f0d0_mtx_ident.m[1];
    cc->m[2] = g_8010f0d0_mtx_ident.m[2];
    cc->m[3] = g_8010f0d0_mtx_ident.m[3];
    cc->m[4] = g_8010f0d0_mtx_ident.m[4];
    cc->m[5] = g_8010f0d0_mtx_ident.m[5];
    cc->m[6] = g_8010f0d0_mtx_ident.m[6];
    cc->m[7] = g_8010f0d0_mtx_ident.m[7];
    cc->m[8] = g_8010f0d0_mtx_ident.m[8];
  }
  else if (bb == (MATRIX *)0x0) {
    cc->m[0] = aa->m[0];
    cc->m[1] = aa->m[1];
    cc->m[2] = aa->m[2];
    cc->m[3] = aa->m[3];
    cc->m[4] = aa->m[4];
    cc->m[5] = aa->m[5];
    cc->m[6] = aa->m[6];
    cc->m[7] = aa->m[7];
    cc->m[8] = aa->m[8];
  }
  else if (aa == (MATRIX *)0x0) {
    TransposeMatrix(bb,cc);
    cc->t[0] = bb->t[0];
    cc->t[1] = bb->t[1];
    cc->t[2] = bb->t[2];
  }
  else {
    TransposeMatrix(bb,&mt);
    mt.t[0] = bb->t[0];
    mt.t[1] = bb->t[1];
    mt.t[2] = bb->t[2];
    MulMatrix0(&mt,aa,cc);
  }
  t1 = cc->m[1];
  t2 = cc->m[5];
  cc->t[0] = 0;
  cc->t[1] = 0;
  cc->t[2] = 0;
  cc->m[1] = -t1;
  cc->m[5] = -t2;
  t3 = cc->t[1];
  cc->m[3] = -cc->m[3];
  t1 = cc->m[7];
  cc->t[1] = -t3;
  cc->m[7] = -t1;
  return 0;
}




int f_80025198_node_calcz2_mtx(Node *n1,Node *n2,MATRIX *out)
{
  short sVar1;
  int iVar2;
  Node *m0;
  MATRIX *pMVar3;
  Node *m2;
  MATRIX loc_mtx_ar [2];
  
  if (n1 == (Node *)0x0) {
    return 0x18;
  }
  out->m[1] = -out->m[1];
  out->m[5] = -out->m[5];
  iVar2 = out->t[1];
  out->m[3] = -out->m[3];
  sVar1 = out->m[7];
  out->t[1] = -iVar2;
  out->m[7] = -sVar1;
  m2 = n1->f_20_n1;
  if (m2 == (Node *)0x0) {
    if (n2 == (Node *)0x0) {
      (n1->f_00_mtx).m[0] = out->m[0];
      (n1->f_00_mtx).m[1] = out->m[1];
      (n1->f_00_mtx).m[2] = out->m[2];
      (n1->f_00_mtx).m[3] = out->m[3];
      (n1->f_00_mtx).m[4] = out->m[4];
      (n1->f_00_mtx).m[5] = out->m[5];
      (n1->f_00_mtx).m[6] = out->m[6];
      (n1->f_00_mtx).m[7] = out->m[7];
      (n1->f_00_mtx).m[8] = out->m[8];
    }
    else {
      MulMatrix0(&n2->f_00_mtx,out,&n1->f_00_mtx);
    }
    goto LAB_80025458;
  }
  m0 = m2->f_20_n1;
  if (n2 == m0) {
    (m2->f_00_mtx).m[0] = out->m[0];
    (n1->f_20_n1->f_00_mtx).m[1] = out->m[1];
    (n1->f_20_n1->f_00_mtx).m[2] = out->m[2];
    (n1->f_20_n1->f_00_mtx).m[3] = out->m[3];
    (n1->f_20_n1->f_00_mtx).m[4] = out->m[4];
    (n1->f_20_n1->f_00_mtx).m[5] = out->m[5];
    (n1->f_20_n1->f_00_mtx).m[6] = out->m[6];
    (n1->f_20_n1->f_00_mtx).m[7] = out->m[7];
    (n1->f_20_n1->f_00_mtx).m[8] = out->m[8];
  }
  else {
    pMVar3 = out;
    if (n2 == (Node *)0x0) {
      if (m0 == (Node *)0x0) {
LAB_80025334:
        MulMatrix0(&n2->f_00_mtx,out,loc_mtx_ar + 1);
        TransposeMatrix(&n1->f_20_n1->f_20_n1->f_00_mtx,loc_mtx_ar);
        loc_mtx_ar[0].t[0] = (n1->f_20_n1->f_20_n1->f_00_mtx).t[0];
        loc_mtx_ar[0].t[1] = (n1->f_20_n1->f_20_n1->f_00_mtx).t[1];
        loc_mtx_ar[0].t[2] = (n1->f_20_n1->f_20_n1->f_00_mtx).t[2];
        n2 = (Node *)loc_mtx_ar;
        m2 = n1->f_20_n1;
        pMVar3 = loc_mtx_ar + 1;
      }
      else {
        TransposeMatrix(&m0->f_00_mtx,loc_mtx_ar);
        loc_mtx_ar[0].t[0] = (n1->f_20_n1->f_20_n1->f_00_mtx).t[0];
        loc_mtx_ar[0].t[1] = (n1->f_20_n1->f_20_n1->f_00_mtx).t[1];
        loc_mtx_ar[0].t[2] = (n1->f_20_n1->f_20_n1->f_00_mtx).t[2];
        n2 = (Node *)loc_mtx_ar;
        m2 = n1->f_20_n1;
      }
    }
    else if (m0 != (Node *)0x0) goto LAB_80025334;
    MulMatrix0(&n2->f_00_mtx,pMVar3,&m2->f_00_mtx);
  }
  n1->f_20_n1->f_2c_b0 = 1;
LAB_80025458:
  out->m[1] = -out->m[1];
  out->m[5] = -out->m[5];
  iVar2 = out->t[1];
  out->m[3] = -out->m[3];
  sVar1 = out->m[7];
  out->t[1] = -iVar2;
  out->m[7] = -sVar1;
  return 0;
}




void f_800250ac_node_yxz(Node *no,Node *nnn,VECTOR *vvv)
{
  MATRIX mtmt;
  int sht [2];
  uint sv;
  undefined4 tt;
  
  memset(&sv,0,8);
  sht[0] = vvv->vx & 0xffffU | vvv->vy << 0x10;
  tt = vvv->vz & 0xffffU | __EvilGet2_2(&tt) << 0x10;
  sht[1] = tt;
  sv = sht[0];
  RotMatrixYXZ( (SVECTOR *)sht, &mtmt );
  f_80025198_node_calcz2_mtx(no,nnn,&mtmt);
  return;
}




void f_80025070_node_again(Node *n1,VECTOR *vc)
{
  Node *nnn;
  
  if (n1->f_20_n1 == (Node *)0x0) {
    nnn = (Node *)0x0;
  }
  else {
    nnn = n1->f_20_n1->f_20_n1;
  }
  f_800250ac_node_yxz(n1,nnn,vc);
  return;
}



int f_800254ec_node_mtx(Node *n1,Node *n2,MATRIX *out)
{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  Node *nnn;
  undefined4 uVar4;
  long lVar5;
  undefined4 uVar6;
  long lVar7;
  MATRIX *p_mtx;
  Node *m2;
  MATRIX ar_mtx_loc [2];
  short s1;
  
  if (n1 == (Node *)0x0) {
    return 0x18;
  }
  out->m[1] = -out->m[1];
  out->m[5] = -out->m[5];
  iVar1 = out->t[1];
  out->m[3] = -out->m[3];
  s1 = out->m[7];
  out->t[1] = -iVar1;
  out->m[7] = -s1;
  m2 = n1->f_20_n1;
  if (m2 == (Node *)0x0) {
    if (n2 == (Node *)0x0) {
      uVar2 = *(undefined4 *)(out->m + 2);
      uVar4 = *(undefined4 *)(out->m + 4);
      uVar6 = *(undefined4 *)(out->m + 6);
      *(undefined4 *)(n1->f_00_mtx).m = *(undefined4 *)out->m;
      *(undefined4 *)((n1->f_00_mtx).m + 2) = uVar2;
      *(undefined4 *)((n1->f_00_mtx).m + 4) = uVar4;
      *(undefined4 *)((n1->f_00_mtx).m + 6) = uVar6;
      lVar3 = out->t[0];
      lVar5 = out->t[1];
      lVar7 = out->t[2];
      *(undefined4 *)((n1->f_00_mtx).m + 8) = *(undefined4 *)(out->m + 8);
      (n1->f_00_mtx).t[0] = lVar3;
      (n1->f_00_mtx).t[1] = lVar5;
      (n1->f_00_mtx).t[2] = lVar7;
    }
    else {
      CompMatrixLV(&n2->f_00_mtx,out,&n1->f_00_mtx);
    }
    goto LAB_80025698;
  }
  nnn = m2->f_20_n1;
  if (n2 == nnn) {
    uVar2 = *(undefined4 *)(out->m + 2);
    uVar4 = *(undefined4 *)(out->m + 4);
    uVar6 = *(undefined4 *)(out->m + 6);
    *(undefined4 *)(m2->f_00_mtx).m = *(undefined4 *)out->m;
    *(undefined4 *)((m2->f_00_mtx).m + 2) = uVar2;
    *(undefined4 *)((m2->f_00_mtx).m + 4) = uVar4;
    *(undefined4 *)((m2->f_00_mtx).m + 6) = uVar6;
    lVar3 = out->t[0];
    lVar5 = out->t[1];
    lVar7 = out->t[2];
    *(undefined4 *)((m2->f_00_mtx).m + 8) = *(undefined4 *)(out->m + 8);
    (m2->f_00_mtx).t[0] = lVar3;
    (m2->f_00_mtx).t[1] = lVar5;
    (m2->f_00_mtx).t[2] = lVar7;
  }
  else {
    p_mtx = out;
    if (n2 == (Node *)0x0) {
      if (nnn == (Node *)0x0) {
LAB_800255f0:
        CompMatrixLV(&n2->f_00_mtx,out,ar_mtx_loc + 1);
        f_80023bf4_node_mtx_transp_lv(n1->f_20_n1->f_20_n1,ar_mtx_loc);
        n2 = (Node *)ar_mtx_loc;
        m2 = n1->f_20_n1;
        p_mtx = ar_mtx_loc + 1;
      }
      else {
        f_80023bf4_node_mtx_transp_lv(nnn,ar_mtx_loc);
        n2 = (Node *)ar_mtx_loc;
        m2 = n1->f_20_n1;
      }
    }
    else if (nnn != (Node *)0x0) goto LAB_800255f0;
    CompMatrixLV(&n2->f_00_mtx,p_mtx,&m2->f_00_mtx);
  }
  n1->f_20_n1->f_2c_b0 = 1;
LAB_80025698:
  out->m[1] = -out->m[1];
  out->m[5] = -out->m[5];
  iVar1 = out->t[1];
  out->m[3] = -out->m[3];
  s1 = out->m[7];
  out->t[1] = -iVar1;
  out->m[7] = -s1;
  return 0;
}





void f_8002515c_node_more(Node *n,MATRIX *m)
{
  Node *n2;
  
  if (n->f_20_n1 == (Node *)0x0) {
    n2 = (Node *)0x0;
  }
  else {
    n2 = n->f_20_n1->f_20_n1;
  }
  f_80025198_node_calcz2_mtx(n,n2,m);
  return;
}



void f_800254b0_node_more2(Node *nn,MATRIX *ooo)
{
  Node *n2;
  
  if (nn->f_20_n1 == (Node *)0x0) {
    n2 = (Node *)0x0;
  }
  else {
    n2 = nn->f_20_n1->f_20_n1;
  }
  f_800254ec_node_mtx(nn,n2,ooo);
  return;
}




void f_80025758_mtx_mini(MATRIX *m1,MATRIX *m2,VECTOR *rr)
{
  MATRIX mmm;
  
  f_80024c34_mtx_shuffles(m1,m2,&mmm);
  rr->vx = (int)mmm.m[2];
  rr->vy = (int)mmm.m[5];
  rr->vz = (int)mmm.m[8];
  return;
}



int f_800257a8_nodes_lv2(Node *n1,Node *n2,VECTOR *dst)
{
  MATRIX mt1;
  MATRIX mmm;
  
  if (n2 == n1) {
    dst->vx = 0;
    dst->vy = 0;
    dst->vz = 0;
  }
  else if (n2 == (Node *)0x0) {
    dst->vx = (n1->f_00_mtx).t[0];
    dst->vy = (n1->f_00_mtx).t[1];
    dst->vz = (n1->f_00_mtx).t[2];
  }
  else if (n1 == (Node *)0x0) {
    f_80023bf4_node_mtx_transp_lv(n2,&mt1);
    dst->vx = mt1.t[0];
    dst->vy = mt1.t[1];
    dst->vz = mt1.t[2];
  }
  else {
    dst->vx = (n1->f_00_mtx).t[0];
    dst->vy = (n1->f_00_mtx).t[1];
    dst->vz = (n1->f_00_mtx).t[2];
    f_80023bf4_node_mtx_transp_lv(n2,&mmm);
    ApplyMatrixLV(&mmm,dst,dst);
    dst->vx = dst->vx + mmm.t[0];
    dst->vy = dst->vy + mmm.t[1];
    dst->vz = dst->vz + mmm.t[2];
  }
  dst->vy = -dst->vy;
  return 0;
}



// works
int f_80024e28_node_mtx_sht9(Node *n1,Node *n2,MATRIX *ooo)
{
  short sVar1;
  undefined4 uVar2;
  long i1;
  undefined4 uVar3;
  long i2;
  int iVar4;
  undefined4 uVar5;
  long i3;
  MATRIX loc;
  
  uVar3 = __EvilGet0_4(&g_8010f0d0_mtx_ident);
  uVar2 = __EvilGet4_4(&g_8010f0d0_mtx_ident);
  
  if (n2 == n1) {
    *(undefined4 *)ooo->m = __EvilGet0_4(&g_8010f0d0_mtx_ident);
    *(undefined4 *)(ooo->m + 2) = uVar2;
    *(undefined4 *)(ooo->m + 4) = uVar3;
    i1 = g_8010f0d0_mtx_ident.t[0];
    uVar2 = __EvilGet16_4(&g_8010f0d0_mtx_ident);;
    *(undefined4 *)(ooo->m + 6) = __EvilGet12_4(&g_8010f0d0_mtx_ident);
    *(undefined4 *)(ooo->m + 8) = uVar2;
    ooo->t[0] = i1;
    i1 = g_8010f0d0_mtx_ident.t[2];
    ooo->t[1] = g_8010f0d0_mtx_ident.t[1];
    ooo->t[2] = i1;
  }
  else if (n2 == (Node *)0x0) {
    uVar2 = *(undefined4 *)((n1->f_00_mtx).m + 2);
    uVar3 = *(undefined4 *)((n1->f_00_mtx).m + 4);
    uVar5 = *(undefined4 *)((n1->f_00_mtx).m + 6);
    *(undefined4 *)ooo->m = *(undefined4 *)(n1->f_00_mtx).m;
    *(undefined4 *)(ooo->m + 2) = uVar2;
    *(undefined4 *)(ooo->m + 4) = uVar3;
    *(undefined4 *)(ooo->m + 6) = uVar5;
    i1 = (n1->f_00_mtx).t[0];
    i2 = (n1->f_00_mtx).t[1];
    i3 = (n1->f_00_mtx).t[2];
    *(undefined4 *)(ooo->m + 8) = *(undefined4 *)((n1->f_00_mtx).m + 8);
    ooo->t[0] = i1;
    ooo->t[1] = i2;
    ooo->t[2] = i3;
  }
  else if (n1 == (Node *)0x0) {
    f_80023bf4_node_mtx_transp_lv(n2,ooo);
  }
  else {
    f_80023bf4_node_mtx_transp_lv(n2,&loc);
    CompMatrixLV(&loc,&n1->f_00_mtx,ooo);
  }
  ooo->m[1] = -ooo->m[1];
  ooo->m[5] = -ooo->m[5];
  iVar4 = ooo->t[1];
  ooo->m[3] = -ooo->m[3];
  sVar1 = ooo->m[7];
  ooo->t[1] = -iVar4;
  ooo->m[7] = -sVar1;
  return 0;
}




int f_80025dc4_node_more3(VECTOR *vc,Node *no,Node *no2,VECTOR *out)
{
  int i1;
  MATRIX mt;
  
  i1 = f_80024e28_node_mtx_sht9(no,no2,&mt);
  ApplyMatrixLV(&mt,vc,out);
  out->vx = out->vx + mt.t[0];
  out->vy = out->vy + mt.t[1];
  out->vz = out->vz + mt.t[2];
  return i1;
}




int f_800258d4_node_more4(Node *n1,Node *n2,VECTOR *vv)
{
  int i1;
  VECTOR t1;
  VECTOR t2;
  
  if (n1->f_20_n1 == (Node *)0x0) {
    i1 = f_80025dc4_node_more3(vv,n2,(Node *)0x0,&t2);
    (n1->f_00_mtx).t[0] = t2.vx;
    (n1->f_00_mtx).t[1] = -t2.vy;
    (n1->f_00_mtx).t[2] = t2.vz;
  }
  else {
    i1 = f_80025dc4_node_more3(vv,n2,n1->f_20_n1->f_20_n1,&t1);
    (n1->f_20_n1->f_00_mtx).t[0] = t1.vx;
    (n1->f_20_n1->f_00_mtx).t[1] = -t1.vy;
    (n1->f_20_n1->f_00_mtx).t[2] = t1.vz;
    n1->f_20_n1->f_2c_b0 = 1;
  }
  return i1;
}




void f_800259a0_node_mini(Node *n1,VECTOR *vc)
{
  Node *n2;
  
  if (n1->f_20_n1 == (Node *)0x0) {
    n2 = (Node *)0x0;
  }
  else {
    n2 = n1->f_20_n1->f_20_n1;
  }
  f_800258d4_node_more4(n1,n2,vc);
  return;
}




int f_800259dc_shuf_vc(MATRIX *a0,MATRIX *a1,VECTOR *out)
{
  MATRIX m;
  
  f_80024c34_mtx_shuffles(a0,a1,&m);
  out->vx = (int)m.m[2];
  out->vy = (int)m.m[5];
  out->vz = (int)m.m[8];
  return 0;
}




int f_80025a2c_mtx_separate_vecs(MATRIX *mtx1,MATRIX *mtx2,VECTOR *ov1,VECTOR *ov2,VECTOR *ov3)
{
  MATRIX mt;
  
  f_80024c34_mtx_shuffles(mtx1,mtx2,&mt);
  ov1->vx = (int)mt.m[0];
  ov1->vy = (int)mt.m[3];
  ov1->vz = (int)mt.m[6];
  ov2->vx = (int)mt.m[1];
  ov2->vy = (int)mt.m[4];
  ov2->vz = (int)mt.m[7];
  ov3->vx = (int)mt.m[2];
  ov3->vy = (int)mt.m[5];
  ov3->vz = (int)mt.m[8];
  return 0;
}




int f_80025e54_mtx_mini2(VECTOR *ve1,MATRIX *mt1,MATRIX *mt2,VECTOR *ve2)
{
  int i1;
  MATRIX loca;
  
  i1 = f_80024c34_mtx_shuffles(mt1,mt2,&loca);
  ApplyMatrixLV(&loca,ve1,ve2);
  return i1;
}





int f_800231bc_vec_sqsq(VECTOR *v0,int *out)
{
  long i3;
  int i1;
  int i2;
  int q1;
  int q2;
  int q3;
  int q4;
  VECTOR aa1;
  VECTOR aa2;

  aa1.vx = g_8010b634_glo_vc3.vx;
  aa1.vy = g_8010b634_glo_vc3.vy;
  aa1.vz = g_8010b634_glo_vc3.vz;
  aa2.vx = g_8010b634_glo_vc3.vx;
  aa2.vy = g_8010b634_glo_vc3.vy;
  aa2.vz = g_8010b634_glo_vc3.vz;
  aa2.pad = g_8010b634_glo_vc3.pad;
  i1 = v0->vx;
  i2 = i1;
  if (i1 < 0) {
    i2 = -i1;
  }
  if (i2 < 0x1a20be) {
    q2 = v0->vy;
    q4 = q2;
    if (q2 < 0) {
      q4 = -q2;
    }
    if (q4 < 0x1a20be) {
      q1 = v0->vz;
      q3 = q1;
      if (q1 < 0) {
        q3 = -q1;
      }
      if (q3 < 0x1a20be) {
        if (((i2 < 0x6883) && (q4 < 0x6883)) && (q3 < 0x6883)) {
          i3 = SquareRoot0(i1 * i1 + q2 * q2 + q1 * q1);
          *out = i3;
          return 0;
        }
        i2 = v0->vx;
        if (i2 != 0) {
          aa1.vx = f_80010654_longlong_mult(i2,i2);
        }
        i2 = v0->vy;
        if (i2 != 0) {
          aa1.vy = f_80010654_longlong_mult(i2,i2);
        }
        i2 = v0->vz;
        if (i2 != 0) {
          aa1.vz = f_80010654_longlong_mult(i2,i2);
        }
        i3 = SquareRoot12(aa1.vx + aa1.vy + aa1.vz);
        *out = i3;
        return 0;
      }
    }
  }
  f_80027d88_vec_xyz_sht(&aa2,v0,out);
  return 0;
}




int f_80011484_vecs_two_xz(VECTOR *aa,VECTOR *bb)
{
  int q1;
  int q2;
  int q3;
  int q4;
  
  q4 = aa->vx - bb->vx;
  if (q4 < 0) {
    q4 = bb->vx - aa->vx;
  }
  q1 = aa->vz - bb->vz;
  if (q1 < 0) {
    q1 = bb->vz - aa->vz;
  }
  q2 = q4 + q1;
  q3 = q4 - q1;
  if (q3 < 0) {
    q3 = q1 - q4;
  }
  if (q3 < q2 >> 1) {
    q2 = q2 - (q2 >> 2);
  }
  else if (q3 <= (q2 >> 1) + (q2 >> 2)) {
    q2 = q2 - (q2 >> 3);
  }
  return q2;
}



int f_80027c44_vcs(VECTOR *vvv,VECTOR *vc2,int *out)
{
  VECTOR v1;
  
  v1.vx = vvv->vx - vc2->vx;
  v1.vy = vvv->vy - vc2->vy;
  v1.vz = vvv->vz - vc2->vz;
  f_800231bc_vec_sqsq(&v1,out);
  return 0;
}



int f_80027ca0_vcs_xz(VECTOR *v1,VECTOR *v2,int *out)
{
  VECTOR vv;
  
  vv.vx = v1->vx - v2->vx;
  vv.vy = 0;
  vv.vz = v1->vz - v2->vz;
  f_800231bc_vec_sqsq(&vv,out);
  return 0;
}





int f_800238bc_vec_bits_mults(VECTOR *vc1,int val,VECTOR *out)
{
  uint u1;
  int i3;
  long i5;
  long i6;
  long i2;
  uint hmm [2];
  
  if (val == 0) {
    out->vz = 0;
    out->vy = 0;
    out->vx = 0;
  }
  else {
    f_800231bc_vec_sqsq(vc1,(int *)hmm);
    if (val < 0) {
      val = -val;
    }
    if (val < (int)hmm[0]) {
      u1 = f_80010698_bits(vc1->vx,hmm[0]);
      out->vx = u1;
      u1 = f_80010698_bits(vc1->vy,hmm[0]);
      out->vy = u1;
      u1 = f_80010698_bits(vc1->vz,hmm[0]);
      out->vz = u1;
      i3 = f_80010654_longlong_mult(out->vx,val);
      out->vx = i3;
      i3 = f_80010654_longlong_mult(out->vy,val);
      out->vy = i3;
      i3 = f_80010654_longlong_mult(out->vz,val);
      out->vz = i3;
    }
    else {
      i5 = vc1->vy;
      i6 = vc1->vz;
      i2 = vc1->pad;
      out->vx = vc1->vx;
      out->vy = i5;
      out->vz = i6;
      out->pad = i2;
    }
  }
  return 0;
}




int f_800235c0_vec_v(VECTOR *vc,int val,VECTOR *out)
{
  int q1;
  int q2;
  int hmm [2];
  
  f_800231bc_vec_sqsq(vc,hmm);
  q1 = 7;
  if (hmm[0] != 0) {
    q1 = vc->vx * val;
    if (hmm[0] == 0) {
      trap(0x1c00);
    }
    if ((hmm[0] == -1) && (q1 == -0x80000000)) {
      trap(0x1800);
    }
    out->vx = q1 / hmm[0];
    q1 = vc->vy * val;
    if (hmm[0] == 0) {
      trap(0x1c00);
    }
    if ((hmm[0] == -1) && (q1 == -0x80000000)) {
      trap(0x1800);
    }
    out->vy = q1 / hmm[0];
    q2 = vc->vz * val;
    if (hmm[0] == 0) {
      trap(0x1c00);
    }
    if ((hmm[0] == -1) && (q2 == -0x80000000)) {
      trap(0x1800);
    }
    q1 = 0;
    out->vz = q2 / hmm[0];
  }
  return q1;
}




int f_800236f8_vc_drp(VECTOR *vc1,int val,VECTOR *out)
{
  int iVar1;
  uint aa;
  uint aa_00;
  uint aa_01;
  uint hmm [2];
  
  f_800231bc_vec_sqsq(vc1,(int *)hmm);
  iVar1 = 7;
  if (hmm[0] != 0) {
    aa = f_80010698_bits(vc1->vx,hmm[0]);
    aa_00 = f_80010698_bits(vc1->vy,hmm[0]);
    aa_01 = f_80010698_bits(vc1->vz,hmm[0]);
    iVar1 = f_80010654_longlong_mult(aa,val);
    out->vx = iVar1;
    iVar1 = f_80010654_longlong_mult(aa_00,val);
    out->vy = iVar1;
    iVar1 = f_80010654_longlong_mult(aa_01,val);
    out->vz = iVar1;
    iVar1 = 0;
  }
  return iVar1;
}





int f_800237b4_vc_drp2(VECTOR *vv,int val,VECTOR *out)
{
  uint uVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  uint hmmm [2];
  
  if (val == 0) {
    out->vz = 0;
    out->vy = 0;
    out->vx = 0;
  }
  else {
    f_800231bc_vec_sqsq(vv,(int *)hmmm);
    if (val < 0) {
      val = -val;
    }
    if (val < (int)hmmm[0]) {
      uVar1 = f_80010698_bits(vv->vx,hmmm[0]);
      out->vx = uVar1;
      uVar1 = f_80010698_bits(vv->vy,hmmm[0]);
      out->vy = uVar1;
      uVar1 = f_80010698_bits(vv->vz,hmmm[0]);
      out->vz = uVar1;
      iVar2 = f_80010654_longlong_mult(out->vx,val);
      out->vx = iVar2;
      iVar2 = f_80010654_longlong_mult(out->vy,val);
      out->vy = iVar2;
      iVar2 = f_80010654_longlong_mult(out->vz,val);
      out->vz = iVar2;
    }
    else {
      lVar3 = vv->vy;
      lVar4 = vv->vz;
      lVar5 = vv->pad;
      out->vx = vv->vx;
      out->vy = lVar3;
      out->vz = lVar4;
      out->pad = lVar5;
    }
  }
  return 0;
}


int f_800290f0_apply_transp_lv(VECTOR *v1,MATRIX *mtx,VECTOR *v2)
{
    ApplyTransposeMatrixLV(mtx,v1,v2);
    return 0;
}


int f_800290d0_vec_node_lv_wrap(VECTOR *vv,Node *no,VECTOR *out)
{
  f_800239c4_vec_node_lv(vv,no,out);
  return 0;
}



int f_80027fd4_xform_xyz(VECTOR *v1,VECTOR *v2,VECTOR *out)
{
  long lVar1;
  long lVar2;
  long lVar3;
  MATRIX mtx;
  int tttt [4];
  
  if (((v1->vx == 0) && (v1->vy == 0)) && (v1->vz == 0)) {
    lVar1 = v1->vy;
    lVar2 = v1->vz;
    lVar3 = v1->pad;
    out->vx = v1->vx;
    out->vy = lVar1;
    out->vz = lVar2;
    out->pad = lVar3;
  }
  else {
    memset(tttt + 2,0,8);
    tttt[0] = v2->vx & 0xffffU | v2->vy << 0x10;
    tttt[3] = v2->vz & 0xffffU | (uint)__EvilGet2_2(&tttt[3]) << 0x10;
    tttt[1] = tttt[3];
    tttt[2] = tttt[0];
    RotMatrixYXZ((SVECTOR *)tttt,&mtx);
    ApplyTransposeMatrixLV(&mtx,v1,out);
  }
  return 0;
}




int f_800281e4_mtx_calcz99(MATRIX *m1,VECTOR *out_vc)
{
  long i1;
  VECTOR v0;
  VECTOR v1;
  VECTOR v2;
  VECTOR qqq;
  
  v0.vx = (long)m1->m[0];
  v0.vy = (long)m1->m[3];
  v0.vz = (long)m1->m[6];
  v1.vx = (long)m1->m[1];
  v1.vy = (long)m1->m[4];
  v1.vz = (long)m1->m[7];
  v2.vx = (long)m1->m[2];
  v2.vy = (long)m1->m[5];
  v2.vz = (long)m1->m[8];
  f_80028150_vec_mag_and_ratan(&v2,&out_vc->vx);
  if ((v2.vx == 0) && (v2.vz == 0)) {
    out_vc->vy = 0;
  }
  else {
    i1 = ratan2(v2.vx,v2.vz);
    out_vc->vy = i1;
  }
  qqq.vx = out_vc->vx;
  qqq.vy = out_vc->vy;
  qqq.vz = 0;
  f_80027fd4_xform_xyz(&v0,&qqq,&v0);
  i1 = ratan2(v0.vy,v0.vx);
  out_vc->vz = i1;
  return 0;
}







// untested
int f_800292ac_mtx_sv_sh(VECTOR *v1,SVECTOR *sv1,MATRIX *mt)
{
  int i1;
  undefined4 ttt;
  SVECTOR *p_sv;
  uint uVar1;
  VECTOR vv;
  int loc_mtx [4];
  short s1;
  
  printf("f_800292ac_mtx_sv_sh %p\n", v1);
  
  if ((v1 == (VECTOR *)0x0) || (sv1 == (SVECTOR *)0x0)) {
    i1 = 1;
  }
  else {
    sv1->vx = (short)v1->vx;
    sv1->vy = (short)v1->vy;
    sv1->vz = (short)v1->vz;
    if (mt == (MATRIX *)0x0) {
      loc_mtx[1] = __EvilGet4_4(&g_8010f0d0_mtx_ident);
      loc_mtx[3] = __EvilGet12_4(&g_8010f0d0_mtx_ident);
      loc_mtx[0] = __EvilGet0_4(&g_8010f0d0_mtx_ident) & 0xffff0000 | (uint)(ushort)((short)v1[1].vx - (short)v1->vx);
      loc_mtx[2] = __EvilGet8_4(&g_8010f0d0_mtx_ident) & 0xffff0000 | (uint)(ushort)((short)v1[1].vy - (short)v1->vy);
      s1 = (short)v1[1].vz - (short)v1->vz;
    }
    else {
      ApplyMatrixSV(mt,sv1,sv1);
      sv1->vx = sv1->vx + (short)mt->t[0];
      sv1->vy = sv1->vy + (short)mt->t[1];
      sv1->vz = sv1->vz + (short)mt->t[2];
      vv.vx = v1[1].vx - v1->vx;
      vv.vy = v1[1].vy - v1->vy;
      vv.vz = v1[1].vz - v1->vz;
      loc_mtx[0] = *(int *)mt->m;
      loc_mtx[1] = *(int *)(mt->m + 2);
      loc_mtx[2] = *(int *)(mt->m + 4);
      loc_mtx[3] = *(int *)(mt->m + 6);
      s1 = (short)*(undefined4 *)(mt->m + 8);
      ScaleMatrix((MATRIX *)loc_mtx,&vv);
    }
    uVar1 = 1;
    p_sv = sv1 + 1;
    do {
      ttt = *(undefined4 *)&sv1->vz;
      *(undefined4 *)p_sv = *(undefined4 *)sv1;
      *(undefined4 *)&p_sv->vz = ttt;
      if ((uVar1 & 1) != 0) {
        p_sv->vx = p_sv->vx + (short)loc_mtx[0];
        p_sv->vy = p_sv->vy + __EvilGet2_2( &loc_mtx[1] );
        p_sv->vz = p_sv->vz + (short)loc_mtx[3];
      }
      if ((uVar1 & 2) != 0) {
        p_sv->vx = p_sv->vx + __EvilGet2_2( &loc_mtx[0] );
        p_sv->vy = p_sv->vy + (short)loc_mtx[2];
        p_sv->vz = p_sv->vz + __EvilGet2_2( &loc_mtx[3] );
      }
      if ((uVar1 & 4) != 0) {
        p_sv->vx = p_sv->vx + (short)loc_mtx[1];
        p_sv->vy = p_sv->vy + __EvilGet2_2( &loc_mtx[2] );
        p_sv->vz = p_sv->vz + s1;
      }
      uVar1 = uVar1 + 1;
      p_sv = p_sv + 1;
    } while ((int)uVar1 < 8);
    i1 = 0;
  }
  return i1;
}





//---------------------------------------------------------

ListElem * f_80026460_list_add(DaList *list,void *ee)
{
  ListElem *e2;
  ListElem *e1;
  
  e1 = g_80121b24_list_elem_free;
  e2 = (ListElem *)0x0;
  if (g_80121b24_list_elem_free != (ListElem *)0x0) {
    g_80121b24_list_elem_free = g_80121b24_list_elem_free->f08_prev;
    g_80121b24_list_elem_free->f04_next = (ListElem *)0x0;
    e1->f00_my_data = ee;
    e2 = list->first;
    e1->f04_next = (ListElem *)0x0;
    e1->f08_prev = e2;
    if (list->first != (ListElem *)0x0) {
      list->first->f04_next = e1;
    }
    list->first = e1;
    g_80121b28_list_elem_tot_cnt = g_80121b28_list_elem_tot_cnt + 1;
    e2 = list->first;
  }
  return e2;
}


ListElem * f_800263a8_list_search(DaList *list,ListElem *link,void *data)
{
  ListElem *x1;
  ListElem *e;
  
  e = list->first;
  while (((x1 = (ListElem *)0x0, e != (ListElem *)0x0 && (x1 = e, e != link)) &&
         (e->f00_my_data != data))) {
    e = e->f08_prev;
  }
  return x1;
}




void f_80026560_list_remove_elem(DaList *list,ListElem *myLink)
{
  ListElem *p1;
  ListElem *p2;
  ListElem **tmp;
  
  if ((((myLink != (ListElem *)0x0) && (list->first != (ListElem *)0x0)) &&
      ((uint)myLink >> 0x18 == 0x80)) &&
     (((0xffff < ((uint)myLink & 0xffffff) && (myLink < (ListElem *)(0x801ff001))) &&
      (((uint)myLink & 3) == 0)))) {
    p2 = myLink->f08_prev;
    p1 = f_800263a8_list_search(list,myLink,(void *)0x0);
    if (p1 != (ListElem *)0x0) {
      if (myLink->f04_next == (ListElem *)0x0) {
        list->first = p2;
      }
      else {
        myLink->f04_next->f08_prev = myLink->f08_prev;
      }
      if (p2 != (ListElem *)0x0) {
        p2->f04_next = myLink->f04_next;
      }
      p1 = g_80121b24_list_elem_free;
      g_80121b28_list_elem_tot_cnt = g_80121b28_list_elem_tot_cnt + -1;
      tmp = &g_80121b24_list_elem_free->f04_next;
      g_80121b24_list_elem_free = myLink;
      *tmp = myLink;
      myLink->f04_next = (ListElem *)0x0;
      myLink->f08_prev = p1;
    }
  }
  return;
}





void f_80026650_list_clear_maybe(DaList *lst)
{
  ListElem *e2;
  ListElem *e1;
  
  e1 = lst->first;
  while (e1 != (ListElem *)0x0) {
    e2 = e1->f08_prev;
    f_80026560_list_remove_elem(lst,e1);
    e1 = e2;
  }
  lst->first = (ListElem *)0x0;
  return;
}





void f_80026304_lists_pool_init(void)
{
  ListElem *p1;
  int i;
  ListElem *p2;
  
  printf("LIST POOLS INIT !\n");
  
  g_80121b28_list_elem_tot_cnt = 0;
  i = 0;
  p1 = g_80126708_list_elem_pool + 2;
  p2 = g_80126708_list_elem_pool;
  do {
    if (i < 0x2a9c) {
      *(ListElem **)((int)&g_80126708_list_elem_pool[1].f08_prev + i) = p1;
    }
    else {
      *(undefined4 *)((int)&g_80126708_list_elem_pool[1].f08_prev + i) = 0;
    }
    if (i == 0) {
      g_80126708_list_elem_pool[1].f04_next = (ListElem *)0x0;
    }
    else {
      *(ListElem **)((int)&g_80126708_list_elem_pool[1].f04_next + i) = p2;
    }
    *(undefined4 *)((int)&g_80126708_list_elem_pool[1].f00_my_data + i) = 0xbadbadff;
    i = i + 0xc;
    p2 = p2 + 1;
    p1 = p1 + 1;
  } while (i < 10920);
  g_80121b24_list_elem_free = g_80126708_list_elem_pool + 1;
  return;
}




//-----------------------



void f_80016174_ap_reset_pool(void)
{
  int i1;
  
  i1 = 0x8bc;
  do {
    *(undefined4 *)((int)g_80122908_ar_anim_players[0].f_3c_derp1 + i1 + -0x3c) = 0;
    i1 = i1 + -0xac;
  } while (-1 < i1);
  return;
}


AnimPlayer * f_80016198_ap_get_free(void)
{
  int i1;
  int i2;
  AnimPlayer *rr;
  
  i2 = 0;
  rr = g_80122908_ar_anim_players;
  i1 = 0;
  do {
    if (*(int *)((int)g_80122908_ar_anim_players[0].f_3c_derp1 + i1 + -0x3c) == 0) {
      return rr;
    }
    rr = rr + 1;
    i2 = i2 + 1;
    i1 = i1 + 0xac;
  } while (i2 < 0xe);
  return (AnimPlayer *)0x0;
}


byte * f_80016268_ap_get_juice(AnimPlayer *ap)
{
  byte *b1;
  uint u2;
  byte *b2;
  
  u2 = *(uint *)(ap->f_0c_an_data_start + -4);
  b1 = (byte *)0x0;
  if ((u2 & 0xffff) == 0xefef) {
    b2 = ap->f_0c_an_data_start + -(((int)u2 >> 8 & 0xff00U) + (u2 >> 0x18));
    b1 = (byte *)0x0;
    if (*b2 == 0xea) {
      b1 = b2 + 4;
    }
  }
  return b1;
}


//---------------------------


void f_80016660_hmd_inits(HmdHead *hmd)
{
  byte *b1;
  char *b2;
  int i1;
  int i3;
  
  printf("HMD initz @ %08X\n", hmd);
  
  i3 = 0;
  i1 = 0;
  b2 = hmd->f_1c_name + hmd->f_08_num_faces4 * 4 + 8;
  if (0 < hmd->f_04_num_bones) {
    do {
      i3 = i3 + 1;
      i1 = i1 + *(int *)(b2 + 8);
      b2 = b2 + *(int *)b2;
    } while (i3 < hmd->f_04_num_bones);
  }
  if (g_80122234_hmd_re1 < i1) {
    g_80122234_hmd_re1 = (short)i1;
  }
  if (hmd->f_04_num_bones == 0xf) {
    b1 = hmd->f_14_off_sht;
    *(undefined4 *)(b1 + (int)(hmd->f_1c_name + 0x188)) = 0xffffffcd;
    *(undefined4 *)(b1 + (int)(hmd->f_1c_name + 0x198)) = 0xfffffff6;
    b1 = hmd->f_14_off_sht;
    *(undefined4 *)(b1 + (int)(hmd->f_1c_name + 0x1a8)) = 0xffffffec;
    *(undefined4 *)(b1 + (int)(hmd->f_1c_name + 0x1b8)) = 0x14;
  }
  return;
}





int f_80021f88_get_screen_info(short *out_w,short *out_h)
{
  *out_w = g_8012225a_scr_w;
  *out_h = g_8012225c_scr_h;
  return 0;
}



void f_80012f24_clear_screen(void)
{
  RECT rc;
  short hmm [4];
  
  f_80021f88_get_screen_info(hmm,hmm + 1);
  rc.y = 0;
  rc.x = 0;
  rc.h = hmm[1] << 1;
  rc.w = hmm[0];
  ClearImage(&rc,0,0,0);
  DrawSync(0);
  return;
}


// ret value affects FOV
int f_8001587c_screen_related(int val,uint *ret)
{
  int iVar1;
  uint uVar2;
  short hmm [4];
  
  if (val < 0x800) {
    f_80021f88_get_screen_info(hmm,hmm + 1);
    iVar1 = f_80023080_sin_cos(val / 2,(uint *)(hmm + 2));
    if (iVar1 == 0) {
      uVar2 = f_80010698_bits(((int)((uint)(ushort)hmm[0] << 0x10) >> 0x10) -
                              ((int)((uint)(ushort)hmm[0] << 0x10) >> 0x1f) >> 1,  __EvilGet4_4(&hmm[0])  );
      *ret = uVar2;
      
      iVar1 = 0;
    }
  }
  else {
    iVar1 = 1;
  }
  return iVar1;
}







#include "init_ovl.c"




