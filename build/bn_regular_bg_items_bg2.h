#ifndef BN_REGULAR_BG_ITEMS_BG2_H
#define BN_REGULAR_BG_ITEMS_BG2_H

#include "bn_regular_bg_item.h"

//{{BLOCK(bg2_bn_gfx)

//======================================================================
//
//	bg2_bn_gfx, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 61 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 1952 + 2048 = 4032
//
//	Time-stamp: 2025-04-12, 13:22:27
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BG2_BN_GFX_H
#define GRIT_BG2_BN_GFX_H

#define bg2_bn_gfxTilesLen 1952
extern const bn::tile bg2_bn_gfxTiles[61];

#define bg2_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell bg2_bn_gfxMap[1024];

#define bg2_bn_gfxPalLen 32
extern const bn::color bg2_bn_gfxPal[16];

#endif // GRIT_BG2_BN_GFX_H

//}}BLOCK(bg2_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item bg2(
            regular_bg_tiles_item(span<const tile>(bg2_bn_gfxTiles, 61), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(bg2_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(bg2_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
}

#endif

