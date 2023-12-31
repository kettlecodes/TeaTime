/*******************************************************************************
 * Size: 16 px
 * Bpp: 2
 * Opts:
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef FONT_DVSB_CAPS_16
#define FONT_DVSB_CAPS_16 1
#endif

#if FONT_DVSB_CAPS_16

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0041 "A" */
    0x0, 0xff, 0x0, 0x0, 0x3f, 0xe0, 0x0, 0x1f,
    0xfc, 0x0, 0xf, 0xef, 0x0, 0x3, 0xe7, 0xe0,
    0x2, 0xf4, 0xfc, 0x0, 0xfc, 0x2f, 0x40, 0x7f,
    0x7, 0xe0, 0x2f, 0xff, 0xfc, 0xf, 0xff, 0xff,
    0x47, 0xe0, 0x7, 0xf2, 0xf4, 0x0, 0xfc,

    /* U+0042 "B" */
    0xbf, 0xfe, 0x2, 0xff, 0xff, 0xb, 0xe0, 0xfe,
    0x2f, 0x41, 0xf8, 0xbe, 0xf, 0xc2, 0xff, 0xfe,
    0xb, 0xff, 0xfd, 0x2f, 0x41, 0xfc, 0xbd, 0x3,
    0xf2, 0xf8, 0x1f, 0xcb, 0xff, 0xfe, 0x2f, 0xff,
    0xd0,

    /* U+0043 "C" */
    0x0, 0xbf, 0xe0, 0x1f, 0xff, 0xe0, 0xfe, 0x46,
    0x8b, 0xe0, 0x0, 0x3f, 0x0, 0x0, 0xfc, 0x0,
    0x3, 0xf0, 0x0, 0xf, 0xc0, 0x0, 0x2f, 0x80,
    0x0, 0x3f, 0x91, 0xa0, 0x7f, 0xff, 0x80, 0x2f,
    0xf8,

    /* U+0044 "D" */
    0xbf, 0xfe, 0x0, 0xbf, 0xff, 0xe0, 0xbe, 0x5b,
    0xf4, 0xbd, 0x1, 0xfc, 0xbd, 0x0, 0xfd, 0xbd,
    0x0, 0xbd, 0xbd, 0x0, 0xbd, 0xbd, 0x0, 0xfd,
    0xbd, 0x1, 0xfc, 0xbe, 0x5b, 0xf4, 0xbf, 0xff,
    0xe0, 0xbf, 0xfe, 0x0,

    /* U+0045 "E" */
    0xbf, 0xff, 0xaf, 0xff, 0xeb, 0xe5, 0x52, 0xf4,
    0x0, 0xbe, 0x55, 0x2f, 0xff, 0xdb, 0xff, 0xf6,
    0xf4, 0x0, 0xbd, 0x0, 0x2f, 0x95, 0x4b, 0xff,
    0xfe, 0xff, 0xff,

    /* U+0046 "F" */
    0xbf, 0xff, 0xaf, 0xff, 0xeb, 0xe5, 0x52, 0xf4,
    0x0, 0xbe, 0x55, 0x2f, 0xff, 0xdb, 0xff, 0xf6,
    0xf4, 0x0, 0xbd, 0x0, 0x2f, 0x40, 0xb, 0xd0,
    0x2, 0xf4, 0x0,

    /* U+0047 "G" */
    0x0, 0xbf, 0xf4, 0x7, 0xff, 0xfe, 0xf, 0xf4,
    0x5e, 0x2f, 0x80, 0x0, 0x3f, 0x0, 0x0, 0x3f,
    0x2, 0xff, 0x3f, 0x2, 0xff, 0x3f, 0x0, 0x3f,
    0x2f, 0x80, 0x3f, 0xf, 0xe4, 0x7f, 0x7, 0xff,
    0xff, 0x0, 0xbf, 0xe4,

    /* U+0048 "H" */
    0xbd, 0x0, 0xfe, 0xf4, 0x3, 0xfb, 0xd0, 0xf,
    0xef, 0x40, 0x3f, 0xbe, 0x55, 0xfe, 0xff, 0xff,
    0xfb, 0xff, 0xff, 0xef, 0x40, 0x3f, 0xbd, 0x0,
    0xfe, 0xf4, 0x3, 0xfb, 0xd0, 0xf, 0xef, 0x40,
    0x3f,

    /* U+0049 "I" */
    0xbd, 0xbd, 0xbd, 0xbd, 0xbd, 0xbd, 0xbd, 0xbd,
    0xbd, 0xbd, 0xbd, 0xbd,

    /* U+004A "J" */
    0xb, 0xd0, 0xbd, 0xb, 0xd0, 0xbd, 0xb, 0xd0,
    0xbd, 0xb, 0xd0, 0xbd, 0xb, 0xd0, 0xbd, 0xb,
    0xd0, 0xbd, 0x6f, 0xcf, 0xf8, 0xfd, 0x0,

    /* U+004B "K" */
    0xbd, 0x2, 0xfc, 0xbd, 0xb, 0xf0, 0xbd, 0x2f,
    0xc0, 0xbd, 0xbf, 0x0, 0xbf, 0xfc, 0x0, 0xbf,
    0xf0, 0x0, 0xbf, 0xf4, 0x0, 0xbf, 0xfd, 0x0,
    0xbd, 0x7f, 0x40, 0xbd, 0x1f, 0xd0, 0xbd, 0x7,
    0xf4, 0xbd, 0x1, 0xfd,

    /* U+004C "L" */
    0xbd, 0x0, 0x2f, 0x40, 0xb, 0xd0, 0x2, 0xf4,
    0x0, 0xbd, 0x0, 0x2f, 0x40, 0xb, 0xd0, 0x2,
    0xf4, 0x0, 0xbd, 0x0, 0x2f, 0x95, 0x4b, 0xff,
    0xfe, 0xff, 0xff,

    /* U+004D "M" */
    0xbf, 0x80, 0x2f, 0xdb, 0xfc, 0x3, 0xfd, 0xbf,
    0xd0, 0x7f, 0xdb, 0xfe, 0xf, 0xfd, 0xbd, 0xf1,
    0xf7, 0xdb, 0xdb, 0xae, 0x7d, 0xbd, 0x7f, 0xc7,
    0xdb, 0xd3, 0xfc, 0x7d, 0xbd, 0x1f, 0x47, 0xdb,
    0xd0, 0xa0, 0x7d, 0xbd, 0x0, 0x7, 0xdb, 0xd0,
    0x0, 0x7d,

    /* U+004E "N" */
    0xbf, 0x0, 0xfe, 0xfe, 0x3, 0xfb, 0xfc, 0xf,
    0xef, 0xf8, 0x3f, 0xbe, 0xf0, 0xfe, 0xf7, 0xe3,
    0xfb, 0xd7, 0xcf, 0xef, 0x4f, 0xbf, 0xbd, 0xf,
    0xfe, 0xf4, 0x2f, 0xfb, 0xd0, 0x3f, 0xef, 0x40,
    0xbf,

    /* U+004F "O" */
    0x0, 0xbf, 0xd0, 0x1, 0xff, 0xff, 0x1, 0xfe,
    0x5f, 0xf0, 0xfe, 0x0, 0xfd, 0x3f, 0x0, 0x2f,
    0x8f, 0xc0, 0x7, 0xf3, 0xf0, 0x1, 0xfc, 0xfc,
    0x0, 0xbe, 0x3f, 0x80, 0x3f, 0x47, 0xf9, 0x7f,
    0xc0, 0x7f, 0xff, 0xc0, 0x2, 0xff, 0x40,

    /* U+0050 "P" */
    0xbf, 0xfe, 0x2, 0xff, 0xff, 0x4b, 0xe0, 0xbf,
    0x2f, 0x40, 0xfc, 0xbd, 0x3, 0xf2, 0xf8, 0x2f,
    0xcb, 0xff, 0xfd, 0x2f, 0xff, 0x80, 0xbd, 0x0,
    0x2, 0xf4, 0x0, 0xb, 0xd0, 0x0, 0x2f, 0x40,
    0x0,

    /* U+0051 "Q" */
    0x0, 0xbf, 0xe0, 0x1, 0xff, 0xff, 0x1, 0xfe,
    0x1f, 0xf0, 0xfe, 0x0, 0xfd, 0x3f, 0x0, 0x2f,
    0x8f, 0xc0, 0x7, 0xf3, 0xf0, 0x1, 0xf8, 0xfc,
    0x0, 0xbe, 0x3f, 0x40, 0x3f, 0x47, 0xf8, 0x7f,
    0xc0, 0x7f, 0xff, 0xc0, 0x2, 0xff, 0xc0, 0x0,
    0x1, 0xf4, 0x0, 0x0, 0x1f, 0x40,

    /* U+0052 "R" */
    0xbf, 0xfe, 0x2, 0xff, 0xff, 0xb, 0xe1, 0xfd,
    0x2f, 0x42, 0xf4, 0xbd, 0xb, 0xd2, 0xf8, 0x3f,
    0xb, 0xff, 0xf0, 0x2f, 0xff, 0xd0, 0xbd, 0x1f,
    0xc2, 0xf4, 0x2f, 0x8b, 0xd0, 0x3f, 0x2f, 0x40,
    0x7e,

    /* U+0053 "S" */
    0xb, 0xfe, 0x43, 0xff, 0xf8, 0xbd, 0x16, 0x8f,
    0xc0, 0x0, 0xbf, 0x40, 0x3, 0xff, 0xe0, 0xb,
    0xff, 0xc0, 0x1, 0xfc, 0x0, 0xb, 0xdf, 0x51,
    0xfc, 0xff, 0xff, 0x82, 0xff, 0xd0,

    /* U+0054 "T" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf5, 0x5f, 0xd5,
    0x0, 0x3f, 0x0, 0x0, 0xfc, 0x0, 0x3, 0xf0,
    0x0, 0xf, 0xc0, 0x0, 0x3f, 0x0, 0x0, 0xfc,
    0x0, 0x3, 0xf0, 0x0, 0xf, 0xc0, 0x0, 0x3f,
    0x0,

    /* U+0055 "U" */
    0xbd, 0x1, 0xfa, 0xf4, 0x7, 0xeb, 0xd0, 0x1f,
    0xaf, 0x40, 0x7e, 0xbd, 0x1, 0xfa, 0xf4, 0x7,
    0xeb, 0xd0, 0x1f, 0xaf, 0x80, 0xbd, 0x7e, 0x2,
    0xf4, 0xfd, 0x5f, 0xc2, 0xff, 0xfd, 0x1, 0xbf,
    0x90,

    /* U+0056 "V" */
    0xbd, 0x0, 0x3f, 0x1f, 0x80, 0xf, 0xc3, 0xf0,
    0xb, 0xd0, 0xbd, 0x3, 0xf0, 0x1f, 0x81, 0xf8,
    0x3, 0xf0, 0xbd, 0x0, 0xbd, 0x3f, 0x0, 0xf,
    0x9f, 0x80, 0x3, 0xff, 0xc0, 0x0, 0x7f, 0xf0,
    0x0, 0xf, 0xf8, 0x0, 0x3, 0xfc, 0x0,

    /* U+0057 "W" */
    0x7d, 0x2, 0xf4, 0xf, 0xc3, 0xe0, 0x3f, 0x80,
    0xfc, 0x3f, 0x3, 0xfc, 0x1f, 0x82, 0xf0, 0x7b,
    0xc2, 0xf4, 0x1f, 0x4b, 0x7d, 0x2f, 0x0, 0xf8,
    0xf2, 0xe3, 0xf0, 0xf, 0xcf, 0x1f, 0x3e, 0x0,
    0xfd, 0xe0, 0xf7, 0xd0, 0xb, 0xfe, 0xf, 0xfc,
    0x0, 0x7f, 0xd0, 0xbf, 0xc0, 0x3, 0xfc, 0x7,
    0xf8, 0x0, 0x3f, 0xc0, 0x3f, 0x80,

    /* U+0058 "X" */
    0x3f, 0x0, 0xbe, 0xb, 0xe0, 0x7f, 0x0, 0xfd,
    0x3f, 0x0, 0xf, 0xef, 0x80, 0x2, 0xff, 0xc0,
    0x0, 0x3f, 0xc0, 0x0, 0xf, 0xf4, 0x0, 0xb,
    0xff, 0x0, 0x7, 0xf7, 0xe0, 0x3, 0xf0, 0xfd,
    0x2, 0xf4, 0xf, 0xc1, 0xfc, 0x1, 0xf8,

    /* U+0059 "Y" */
    0x3f, 0x40, 0x3f, 0x43, 0xf0, 0x1f, 0xc0, 0xbe,
    0xf, 0xc0, 0xf, 0xdb, 0xe0, 0x1, 0xff, 0xf0,
    0x0, 0x2f, 0xf0, 0x0, 0x3, 0xf8, 0x0, 0x0,
    0xbd, 0x0, 0x0, 0x2f, 0x40, 0x0, 0xb, 0xd0,
    0x0, 0x2, 0xf4, 0x0, 0x0, 0xbd, 0x0,

    /* U+005A "Z" */
    0x3f, 0xff, 0xf8, 0xff, 0xff, 0xe1, 0x55, 0x7f,
    0x0, 0x3, 0xf4, 0x0, 0x3f, 0x80, 0x2, 0xfc,
    0x0, 0x1f, 0xc0, 0x0, 0xfc, 0x0, 0xf, 0xd0,
    0x0, 0xbf, 0x55, 0x57, 0xff, 0xff, 0xdf, 0xff,
    0xff
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 198, .box_w = 13, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 39, .adv_w = 195, .box_w = 11, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 72, .adv_w = 188, .box_w = 11, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 105, .adv_w = 213, .box_w = 12, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 141, .adv_w = 175, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 168, .adv_w = 175, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 195, .adv_w = 210, .box_w = 12, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 231, .adv_w = 214, .box_w = 11, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 264, .adv_w = 95, .box_w = 4, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 276, .adv_w = 95, .box_w = 6, .box_h = 15, .ofs_x = -1, .ofs_y = -3},
    {.bitmap_index = 299, .adv_w = 198, .box_w = 12, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 335, .adv_w = 163, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 362, .adv_w = 255, .box_w = 14, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 404, .adv_w = 214, .box_w = 11, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 437, .adv_w = 218, .box_w = 13, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 476, .adv_w = 188, .box_w = 11, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 509, .adv_w = 218, .box_w = 13, .box_h = 14, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 555, .adv_w = 197, .box_w = 11, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 588, .adv_w = 184, .box_w = 10, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 618, .adv_w = 175, .box_w = 11, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 651, .adv_w = 208, .box_w = 11, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 684, .adv_w = 198, .box_w = 13, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 723, .adv_w = 282, .box_w = 18, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 777, .adv_w = 197, .box_w = 13, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 816, .adv_w = 185, .box_w = 13, .box_h = 12, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 855, .adv_w = 186, .box_w = 11, .box_h = 12, .ofs_x = 0, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 65, .range_length = 26, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 2,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t font_dvsb_caps_16 = {
#else
lv_font_t font_dvsb_caps_16 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 15,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if FONT_DVSB_CAPS_16*/
