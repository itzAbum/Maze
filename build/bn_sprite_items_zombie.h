#ifndef BN_SPRITE_ITEMS_ZOMBIE_H
#define BN_SPRITE_ITEMS_ZOMBIE_H

#include "bn_sprite_item.h"

//{{BLOCK(zombie_bn_gfx)

//======================================================================
//
//	zombie_bn_gfx, 8x8@4, 
//	+ palette 16 entries, not compressed
//	+ 1 tiles not compressed
//	Total size: 32 + 32 = 64
//
//	Time-stamp: 2024-11-30, 14:18:05
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_ZOMBIE_BN_GFX_H
#define GRIT_ZOMBIE_BN_GFX_H

#define zombie_bn_gfxTilesLen 32
extern const bn::tile zombie_bn_gfxTiles[1];

#define zombie_bn_gfxPalLen 32
extern const bn::color zombie_bn_gfxPal[16];

#endif // GRIT_ZOMBIE_BN_GFX_H

//}}BLOCK(zombie_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item zombie(sprite_shape_size(sprite_shape::SQUARE, sprite_size::SMALL), 
            sprite_tiles_item(span<const tile>(zombie_bn_gfxTiles, 1), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(zombie_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

