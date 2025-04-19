#ifndef BN_SPRITE_ITEMS_MAIN_HERO_H
#define BN_SPRITE_ITEMS_MAIN_HERO_H

#include "bn_sprite_item.h"

//{{BLOCK(main_hero_bn_gfx)

//======================================================================
//
//	main_hero_bn_gfx, 8x8@4, 
//	+ palette 16 entries, not compressed
//	+ 1 tiles not compressed
//	Total size: 32 + 32 = 64
//
//	Time-stamp: 2024-11-26, 17:36:37
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_MAIN_HERO_BN_GFX_H
#define GRIT_MAIN_HERO_BN_GFX_H

#define main_hero_bn_gfxTilesLen 32
extern const bn::tile main_hero_bn_gfxTiles[1];

#define main_hero_bn_gfxPalLen 32
extern const bn::color main_hero_bn_gfxPal[16];

#endif // GRIT_MAIN_HERO_BN_GFX_H

//}}BLOCK(main_hero_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item main_hero(sprite_shape_size(sprite_shape::SQUARE, sprite_size::SMALL), 
            sprite_tiles_item(span<const tile>(main_hero_bn_gfxTiles, 1), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(main_hero_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

