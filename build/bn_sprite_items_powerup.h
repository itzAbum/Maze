#ifndef BN_SPRITE_ITEMS_POWERUP_H
#define BN_SPRITE_ITEMS_POWERUP_H

#include "bn_sprite_item.h"

//{{BLOCK(powerup_bn_gfx)

//======================================================================
//
//	powerup_bn_gfx, 8x8@4, 
//	+ palette 16 entries, not compressed
//	+ 1 tiles not compressed
//	Total size: 32 + 32 = 64
//
//	Time-stamp: 2025-04-15, 23:11:52
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_POWERUP_BN_GFX_H
#define GRIT_POWERUP_BN_GFX_H

#define powerup_bn_gfxTilesLen 32
extern const bn::tile powerup_bn_gfxTiles[1];

#define powerup_bn_gfxPalLen 32
extern const bn::color powerup_bn_gfxPal[16];

#endif // GRIT_POWERUP_BN_GFX_H

//}}BLOCK(powerup_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item powerup(sprite_shape_size(sprite_shape::SQUARE, sprite_size::SMALL), 
            sprite_tiles_item(span<const tile>(powerup_bn_gfxTiles, 1), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(powerup_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

