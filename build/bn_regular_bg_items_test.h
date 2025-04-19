#ifndef BN_REGULAR_BG_ITEMS_TEST_H
#define BN_REGULAR_BG_ITEMS_TEST_H

#include "bn_regular_bg_item.h"

//{{BLOCK(test_bn_gfx)

//======================================================================
//
//	test_bn_gfx, 256x512@4, 
//	+ palette 16 entries, not compressed
//	+ 124 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x64 
//	Total size: 32 + 3968 + 4096 = 8096
//
//	Time-stamp: 2025-04-12, 13:09:42
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_TEST_BN_GFX_H
#define GRIT_TEST_BN_GFX_H

#define test_bn_gfxTilesLen 3968
extern const bn::tile test_bn_gfxTiles[124];

#define test_bn_gfxMapLen 4096
extern const bn::regular_bg_map_cell test_bn_gfxMap[2048];

#define test_bn_gfxPalLen 32
extern const bn::color test_bn_gfxPal[16];

#endif // GRIT_TEST_BN_GFX_H

//}}BLOCK(test_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item test(
            regular_bg_tiles_item(span<const tile>(test_bn_gfxTiles, 124), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(test_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(test_bn_gfxMap[0], size(32, 64), compression_type::NONE, 1, false));
}

#endif

