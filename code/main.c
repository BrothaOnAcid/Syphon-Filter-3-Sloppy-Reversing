#include "types.h"

#define EXTEXT(ty,adr) (*(ty*)(adr))  

//------ funcs

#define printf   	( (int(FNC*)(char*,...)) 0x800f6f10 )



//-------- data



#define g_80122138_music_danger_timer   EXTEXT(int,0x80122138)

#define g_80122154_snd_banks            EXTEXT(HeadSBNK*,0x80122154)

#define g_80122158_ptr_MMID             EXTEXT(HeadMMID*,0x80122158)

#define g_8012218c_current_MID_ptr      EXTEXT(HeadMID*,0x8012218c)

#define g_80122190_midi_u9              EXTEXT(int,0x80122190)



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
  
  printf("snd bank fin by %d\n", by);
  
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
  
  //printf("MMID find.. %08X\n", nam);
  
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
  
  printf("big sht...\n");
  
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






