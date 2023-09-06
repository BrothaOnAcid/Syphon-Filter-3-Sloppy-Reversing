#include "types.h"

#define EXTEXT(ty,adr) (*(ty*)(adr))  

//------ funcs

#define printf   	( (int(FNC*)(char*,...)) 0x800f6f10 )



//-------- data

#define g_80122154_snd_banks            EXTEXT(HeadSBNK*,0x80122154)

#define g_80122158_ptr_MMID             EXTEXT(HeadMMID*,0x80122158)

#define g_8012218c_current_MID_ptr      EXTEXT(HeadMID*,0x8012218c)





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

