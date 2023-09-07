#include "types.h"

#define EXTEXT(adr,ty) (*(ty*)(adr))  

//------ funcs

#define ApplyMatrixLV   ( (VECTOR*(FNC*)(MATRIX*,VECTOR*,VECTOR*)) 0x800f3c60 )

#define memset   	    ( (void*(FNC*)(void*,byte,int)) 0x800f6f00 )

#define printf   	    ( (int(FNC*)(char*,...)) 0x800f6f10 )

#define SquareRoot12   	( (long(FNC*)(long)) 0x800f9204 )

#define RotMatrixYXZ   ( (MATRIX*(FNC*)(SVECTOR*,MATRIX*)) 0x800f9938 )







//-------- data


typedef int ARR_TMP1[4];
#define g_8011fcb0_ar_vol_sht           EXTEXT(0x8011fcb0,ARR_TMP1)




#define g_80122130_midi_speed           EXTEXT(0x80122130,uint)

#define g_80122138_music_danger_timer   EXTEXT(0x80122138,int)

#define g_80122154_snd_banks            EXTEXT(0x80122154,HeadSBNK*)
#define g_80122158_ptr_MMID             EXTEXT(0x80122158,HeadMMID*)

#define g_80122168_voice_env_req        EXTEXT(0x80122168,int)

#define g_80122178_snd_some_mask        EXTEXT(0x80122178,uint)
#define g_8012217c_snd_mask2            EXTEXT(0x8012217c,uint)

#define g_80122184_snd_msk3             EXTEXT(0x80122184,uint)

#define g_8012218c_current_MID_ptr      EXTEXT(0x8012218c,HeadMID*)
#define g_80122190_midi_u9              EXTEXT(0x80122190,int)
#define g_801221b0_snd_rela99           EXTEXT(0x801221b0,int)



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
  
  //printf("snd bank find.. for %p\n");
  
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
  
  //printf("midi inits.. %p\n", da);
  
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
  long i3;
  
  i1 = f_80010654_longlong_mult(v0->vx,v0->vx);
  i2 = f_80010654_longlong_mult(v0->vz,v0->vz);
  i3 = SquareRoot12(i1 + i2);
  *v1 = i3;
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


inline ushort __EvilGet2_2(void* src)
{
	ushort* s = (ushort*)src;
	return s[1];
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



