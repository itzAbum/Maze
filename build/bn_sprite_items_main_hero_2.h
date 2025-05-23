#ifndef BN_SPRITE_ITEMS_MAIN_HERO_2_H
#define BN_SPRITE_ITEMS_MAIN_HERO_2_H

#include "bn_sprite_item.h"

//{{BLOCK(main_hero_2_bn_gfx)

//======================================================================
//
//	main_hero_2_bn_gfx, 32x32@4, 
//	+ palette 16 entries, not compressed
//	+ 16 tiles not compressed
//	Total size: 32 + 512 = 544
//
//	Time-stamp: 2024-11-30, 12:39:45
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_MAIN_HERO_2_BN_GFX_H
#define GRIT_MAIN_HERO_2_BN_GFX_H

#define main_hero_2_bn_gfxTilesLen 512
extern const bn::tile main_hero_2_bn_gfxTiles[16];

#define main_hero_2_bn_gfxPalLen 32
extern const bn::color main_hero_2_bn_gfxPal[16];

#endif // GRIT_MAIN_HERO_2_BN_GFX_H

//}}BLOCK(main_hero_2_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item main_hero_2(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(main_hero_2_bn_gfxTiles, 16), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(main_hero_2_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

