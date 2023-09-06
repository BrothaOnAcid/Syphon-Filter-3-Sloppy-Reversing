#include "types.h"







uint f_80101244_midi_juice_stuff(byte *midiJuice,int *param_2)

{
  uint uVar1;
  int iVar2;
  

  uVar1 = (uint)*midiJuice;
  iVar2 = 1;
  if ((*midiJuice & 0x80) != 0) {
    uVar1 = uVar1 & 0x7f;
    do {
      midiJuice = midiJuice + 1;
      iVar2 = iVar2 + 1;
      uVar1 = uVar1 * 0x80 + (*midiJuice & 0x7f);
    } while ((*midiJuice & 0x80) != 0);
  }
  *param_2 = iVar2;
  return uVar1;
}
