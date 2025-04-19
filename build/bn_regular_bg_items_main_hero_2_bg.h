#ifndef BN_REGULAR_BG_ITEMS_MAIN_HERO_2_BG_H
#define BN_REGULAR_BG_ITEMS_MAIN_HERO_2_BG_H

#include "bn_regular_bg_item.h"

//{{BLOCK(main_hero_2_bg_bn_gfx)

//======================================================================
//
//	main_hero_2_bg_bn_gfx, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 13 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 416 + 2048 = 2496
//
//	Time-stamp: 2024-11-30, 13:06:57
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_MAIN_HERO_2_BG_BN_GFX_H
#define GRIT_MAIN_HERO_2_BG_BN_GFX_H

#define main_hero_2_bg_bn_gfxTilesLen 416
extern const bn::tile main_hero_2_bg_bn_gfxTiles[13];

#define main_hero_2_bg_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell main_hero_2_bg_bn_gfxMap[1024];

#define main_hero_2_bg_bn_gfxPalLen 32
extern const bn::color main_hero_2_bg_bn_gfxPal[16];

#endif // GRIT_MAIN_HERO_2_BG_BN_GFX_H

//}}BLOCK(main_hero_2_bg_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item main_hero_2_bg(
            regular_bg_tiles_item(span<const tile>(main_hero_2_bg_bn_gfxTiles, 13), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(main_hero_2_bg_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(main_hero_2_bg_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
}

#endif

