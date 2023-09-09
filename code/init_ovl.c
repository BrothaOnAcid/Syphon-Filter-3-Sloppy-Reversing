 




int f_init_ovl_8016c164_img_find_stuff(StrTabHead *unun,char *nam,ImgDerp *imm)
{
  int i1;
  uint u2;
  
  i1 = f_800277ac_str_tab_search(unun,nam,(int *)imm);
  u2 = (uint)(i1 == 0);
  if ((u2 == 1) && (i1 = f_80025eac_get_tim_info(imm), i1 != 0)) {
    u2 = 0;
  }
  return u2;
}



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




int f_init_ovl_80161924_get_val_const(void)
{
  return 392;
}






void f_init_ovl_8016c850_alloc_md_array(void)
{
  int i1;
  int i2;
  int i4;
  byte **bb;
  
  printf("alloc md array\n");
  
  g_80122204_md_array2 = (byte **)f_80026274_heap_alloc((int)g_801219e0_cnt_some << 2);
  g_80122220_ptr_to_array_of_mds =
       (MaybeMd78 **)f_80026274_heap_alloc((int)g_801219e0_cnt_some << 2);
  bb = g_80122204_md_array2;
  i4 = (int)g_801219e0_cnt_some;
  g_801219e2_md_count = 0;
  i2 = 0;
  if (0 < i4) {
    i1 = 0;
    do {
      *(undefined4 *)((i1 >> 0xe) + (int)bb) = 0;
      i2 = i2 + 1;
      i1 = i2 * 0x10000;
    } while (i2 * 0x10000 >> 0x10 < i4);
  }
  return;
}






MaybeMd78 * f_init_ovl_8016c8e4_cr_cr_cr(byte *md_data,EntData1C *sa,uint fla)
{
  MaybeMd78 *mdmd;
  int iVar1;
  byte **ppbVar2;
  MaybeMd78 *rtrt;
  int iVar3;
  int indind;
  
  printf("cr cr cr %p\n", md_data);
  
  iVar3 = -1;
  if (g_801219e2_md_count == -1) {
    f_init_ovl_8016c850_alloc_md_array();
  }
  indind = iVar3;
  if (md_data != (byte *)0xffffffff) {
    iVar1 = 0;
    ppbVar2 = g_80122204_md_array2;
    if (0 < g_801219e0_cnt_some) {
      do {
        indind = iVar3;
        if ((*ppbVar2 == (byte *)0x0) || (indind = iVar1, *ppbVar2 == md_data)) break;
        iVar1 = iVar1 + 1;
        ppbVar2 = ppbVar2 + 1;
        indind = iVar3;
      } while (iVar1 < g_801219e0_cnt_some);
    }
  }
  if (indind == -1) {
    indind = (int)g_801219e2_md_count;
    mdmd = (MaybeMd78 *)f_80026274_heap_alloc(0x78);
    iVar3 = (int)g_801219e2_md_count;
    g_80122220_ptr_to_array_of_mds[iVar3] = mdmd;
    g_801219e2_md_count = g_801219e2_md_count + 1;
    g_80122204_md_array2[iVar3] = md_data;
    mdmd->f_28_fla = fla;
    mdmd->f_74_int = -1;
    if ((fla & 0x400000) != 0) {
      if (*(int *)md_data == -0x45245300) {
        mdmd->f_28_fla = mdmd->f_28_fla | 0x800000;
      }
      else {
        f_80016660_hmd_inits((HmdHead *)md_data);
      }
    }
  }
  rtrt = g_80122220_ptr_to_array_of_mds[indind];
  rtrt->f_20_ptr_hmd = (HmdHead *)0x0;
  rtrt->f_24_ptpt = (byte *)0x0;
  rtrt->f_2c_p_un = (int *)0x0;
  if (sa != (EntData1C *)0x0) {
    sa->f_10_ptr_md = rtrt;
  }
  return rtrt;
}





MaybeMd78 * f_init_ovl_8016d090_cr_md(HmdHead *hmd,uint fla)

{
  MaybeMd78 *ss;
  
  if (hmd == (HmdHead *)0x0) {
    ss = (MaybeMd78 *)0x0;
  }
  else {
    ss = f_init_ovl_8016c8e4_cr_cr_cr((byte *)hmd,(EntData1C *)0x0,fla);
    if ((fla & 0x1000000) == 0) {
      f_800182f4_model_setup(ss,(byte *)hmd);
    }
    ss->f_20_ptr_hmd = hmd;
  }
  return ss;
}





int f_init_ovl_8016cf84_creation1(HmdHead *hmd,Node *nn,uint fla,EntData1C **ret_dd)
{
  int iVar1;
  EntData1C *ed;
  MaybeMd78 *p_md;
  
  if (hmd == (HmdHead *)0x0) {
    iVar1 = 1;
  }
  else {
    ed = (EntData1C *)f_80026274_heap_alloc(0x1c);
    *ret_dd = ed;
    p_md = f_init_ovl_8016c8e4_cr_cr_cr((byte *)hmd,ed,fla);
    (*ret_dd)->f_10_ptr_md = p_md;
    if ((fla & 0x1000000) == 0) {
      f_800182f4_model_setup(p_md,(byte *)hmd);
    }
    p_md->f_20_ptr_hmd = hmd;
    *(undefined *)&(*ret_dd)->f_08_fla = 0;
    *(undefined *)((int)&(*ret_dd)->f_08_fla + 1) = 0x40;
    (*ret_dd)->f_0a_u1 = 0;
    (*ret_dd)->f_0b_u2 = 0;
    ((*ret_dd)->f_0c_nodes).nodes = nn;
    (*ret_dd)->f_00_my_link = (ListElem *)0x0;
    *(undefined4 *)&(*ret_dd)->f_04_dun_se = 0;
    *(undefined2 *)&(*ret_dd)->f_14_flfl = 0;
    iVar1 = 0;
    (*ret_dd)->f_18_ptr_arr_nodes = (Node **)0x0;
  }
  return iVar1;
}




