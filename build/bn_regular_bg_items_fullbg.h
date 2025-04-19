#ifndef BN_REGULAR_BG_ITEMS_FULLBG_H
#define BN_REGULAR_BG_ITEMS_FULLBG_H

#include "bn_regular_bg_item.h"

//{{BLOCK(fullbg_bn_gfx)

//======================================================================
//
//	fullbg_bn_gfx, 256x512@8, 
//	+ palette 256 entries, not compressed
//	+ 399 tiles (t|f reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x64 
//	Total size: 512 + 25536 + 4096 = 30144
//
//	Time-stamp: 2025-04-13, 15:40:11
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_FULLBG_BN_GFX_H
#define GRIT_FULLBG_BN_GFX_H

#define fullbg_bn_gfxTilesLen 25536
extern const bn::tile fullbg_bn_gfxTiles[798];

#define fullbg_bn_gfxMapLen 4096
extern const bn::regular_bg_map_cell fullbg_bn_gfxMap[2048];

#define fullbg_bn_gfxPalLen 512
extern const bn::color fullbg_bn_gfxPal[256];

#endif // GRIT_FULLBG_BN_GFX_H

//}}BLOCK(fullbg_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item fullbg(
            regular_bg_tiles_item(span<const tile>(fullbg_bn_gfxTiles, 798), bpp_mode::BPP_8, compression_type::NONE), 
            bg_palette_item(span<const color>(fullbg_bn_gfxPal, 256), bpp_mode::BPP_8, compression_type::NONE),
            regular_bg_map_item(fullbg_bn_gfxMap[0], size(32, 64), compression_type::NONE, 1, false));
}

#endif

