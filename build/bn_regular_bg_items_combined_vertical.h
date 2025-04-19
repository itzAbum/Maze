#ifndef BN_REGULAR_BG_ITEMS_COMBINED_VERTICAL_H
#define BN_REGULAR_BG_ITEMS_COMBINED_VERTICAL_H

#include "bn_regular_bg_item.h"

//{{BLOCK(combined_vertical_bn_gfx)

//======================================================================
//
//	combined_vertical_bn_gfx, 256x512@4, 
//	+ palette 16 entries, not compressed
//	+ 454 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x64 
//	Total size: 32 + 14528 + 4096 = 18656
//
//	Time-stamp: 2025-04-13, 15:15:05
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_COMBINED_VERTICAL_BN_GFX_H
#define GRIT_COMBINED_VERTICAL_BN_GFX_H

#define combined_vertical_bn_gfxTilesLen 14528
extern const bn::tile combined_vertical_bn_gfxTiles[454];

#define combined_vertical_bn_gfxMapLen 4096
extern const bn::regular_bg_map_cell combined_vertical_bn_gfxMap[2048];

#define combined_vertical_bn_gfxPalLen 32
extern const bn::color combined_vertical_bn_gfxPal[16];

#endif // GRIT_COMBINED_VERTICAL_BN_GFX_H

//}}BLOCK(combined_vertical_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item combined_vertical(
            regular_bg_tiles_item(span<const tile>(combined_vertical_bn_gfxTiles, 454), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(combined_vertical_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(combined_vertical_bn_gfxMap[0], size(32, 64), compression_type::NONE, 1, false));
}

#endif

