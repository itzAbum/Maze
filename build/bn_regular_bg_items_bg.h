#ifndef BN_REGULAR_BG_ITEMS_BG_H
#define BN_REGULAR_BG_ITEMS_BG_H

#include "bn_regular_bg_item.h"

//{{BLOCK(bg_bn_gfx)

//======================================================================
//
//	bg_bn_gfx, 256x256@8, 
//	+ palette 176 entries, not compressed
//	+ 394 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 352 + 25216 + 2048 = 27616
//
//	Time-stamp: 2025-04-13, 15:15:05
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BG_BN_GFX_H
#define GRIT_BG_BN_GFX_H

#define bg_bn_gfxTilesLen 25216
extern const bn::tile bg_bn_gfxTiles[788];

#define bg_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell bg_bn_gfxMap[1024];

#define bg_bn_gfxPalLen 352
extern const bn::color bg_bn_gfxPal[176];

#endif // GRIT_BG_BN_GFX_H

//}}BLOCK(bg_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item bg(
            regular_bg_tiles_item(span<const tile>(bg_bn_gfxTiles, 788), bpp_mode::BPP_8, compression_type::NONE), 
            bg_palette_item(span<const color>(bg_bn_gfxPal, 176), bpp_mode::BPP_8, compression_type::NONE),
            regular_bg_map_item(bg_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
}

#endif

