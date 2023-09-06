#include "types.h"

#define EXTEXT(ty,adr) (*(ty*)(adr))  

//------ funcs

#define printf   	( (int(FNC*)(char*,...)) 0x800f6f10 )



//-------- data

#define g_8012218c_current_MID_ptr EXTEXT(HeadMID*,0x8012218c)


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

