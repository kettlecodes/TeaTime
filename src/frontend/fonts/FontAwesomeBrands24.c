/*******************************************************************************
 * Size: 24 px
 * Bpp: 2
 * Opts:
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef FONTAWESOMEBRANDS24
#define FONTAWESOMEBRANDS24 1
#endif

#if FONTAWESOMEBRANDS24

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+F293 "" */
    0x0, 0xb, 0xff, 0x90, 0x0, 0x2, 0xff, 0xff,
    0xf0, 0x0, 0x3f, 0xfd, 0xff, 0xf4, 0x2, 0xff,
    0xf1, 0xff, 0xf0, 0xf, 0xff, 0xc1, 0xff, 0xd0,
    0xbf, 0xff, 0x1, 0xff, 0xc3, 0xff, 0xfc, 0x11,
    0xff, 0xf, 0xe2, 0xf0, 0xd2, 0xfd, 0x3f, 0xc2,
    0xc3, 0x47, 0xf5, 0xff, 0xc2, 0x4, 0x7f, 0xe7,
    0xff, 0xc0, 0x7, 0xff, 0x9f, 0xff, 0xc0, 0x3f,
    0xfe, 0x7f, 0xff, 0x1, 0xff, 0xf9, 0xff, 0xf4,
    0x1, 0xff, 0xe7, 0xff, 0x40, 0x2, 0xff, 0x9f,
    0xf4, 0x70, 0xc2, 0xfe, 0x3f, 0x47, 0xc3, 0x83,
    0xf4, 0xff, 0x7f, 0x8, 0x3f, 0xc2, 0xff, 0xfc,
    0x3, 0xff, 0x3, 0xff, 0xf0, 0x3f, 0xf8, 0xb,
    0xff, 0xc3, 0xff, 0xc0, 0xf, 0xff, 0x3f, 0xfd,
    0x0, 0xb, 0xff, 0xff, 0xd0, 0x0, 0x2, 0xff,
    0xe4, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 336, .box_w = 19, .box_h = 24, .ofs_x = 1, .ofs_y = -3}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 62099, .range_length = 1, .glyph_id_start = 1,
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
const lv_font_t FontAwesomeBrands24 = {
#else
lv_font_t FontAwesomeBrands24 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 24,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if FONTAWESOMEBRANDS24*/
