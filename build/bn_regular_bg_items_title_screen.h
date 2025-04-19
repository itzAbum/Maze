#ifndef BN_REGULAR_BG_ITEMS_TITLE_SCREEN_H
#define BN_REGULAR_BG_ITEMS_TITLE_SCREEN_H

#include "bn_regular_bg_item.h"

//{{BLOCK(title_screen_bn_gfx)

//======================================================================
//
//	title_screen_bn_gfx, 256x256@8, 
//	+ palette 256 entries, not compressed
//	+ 335 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 512 + 21440 + 2048 = 24000
//
//	Time-stamp: 2024-11-26, 17:36:37
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_TITLE_SCREEN_BN_GFX_H
#define GRIT_TITLE_SCREEN_BN_GFX_H

#define title_screen_bn_gfxTilesLen 21440
extern const bn::tile title_screen_bn_gfxTiles[670];

#define title_screen_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell title_screen_bn_gfxMap[1024];

#define title_screen_bn_gfxPalLen 512
extern const bn::color title_screen_bn_gfxPal[256];

#endif // GRIT_TITLE_SCREEN_BN_GFX_H

//}}BLOCK(title_screen_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item title_screen(
            regular_bg_tiles_item(span<const tile>(title_screen_bn_gfxTiles, 670), bpp_mode::BPP_8, compression_type::NONE), 
            bg_palette_item(span<const color>(title_screen_bn_gfxPal, 256), bpp_mode::BPP_8, compression_type::NONE),
            regular_bg_map_item(title_screen_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
}

#endif

