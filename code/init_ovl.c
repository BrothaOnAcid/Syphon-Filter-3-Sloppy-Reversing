 




void f_init_ovl_8016c1c4_fill_wpn_ics(ImgDerp *im,int ii)
{
  uint u3;
  uint i5;
  ushort i9;
  ushort u1;
  
  u1 = (im->f_0c_gs_img).py;
  i9 = (im->f_0c_gs_img).px;
  i5 = (im->f_0c_gs_img).pmode & 3;
  g_80132084_wpn_icons_tab[ii].f_0_u = i5 << 0x18;
  u3 = (i9 & 0x3ff) >> 6;
  i5 = 2 - i5;
  g_80132084_wpn_icons_tab[ii].f_2_shsh = u1 >> 4 & 0x10 | (ushort)u3;
  g_80132084_wpn_icons_tab[ii].f_6_qq = (byte)((int)(im->f_0c_gs_img).px + u3 * -0x40 << (i5 & 0x1f));
  g_80132084_wpn_icons_tab[ii].f_7_ub = (byte)(im->f_0c_gs_img).py;
  g_80132084_wpn_icons_tab[ii].f_8_x1 = (im->f_0c_gs_img).pw << (i5 & 0x1f);
  g_80132084_wpn_icons_tab[ii].f_a_x2 = (im->f_0c_gs_img).ph;
  g_80132084_wpn_icons_tab[ii].f_c_sh2 = (im->f_0c_gs_img).cx;
  g_80132084_wpn_icons_tab[ii].f_e_sh3 = (im->f_0c_gs_img).cy;
  return;
}

