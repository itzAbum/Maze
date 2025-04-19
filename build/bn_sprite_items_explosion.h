#ifndef BN_SPRITE_ITEMS_EXPLOSION_H
#define BN_SPRITE_ITEMS_EXPLOSION_H

#include "bn_sprite_item.h"

//{{BLOCK(explosion_bn_gfx)

//======================================================================
//
//	explosion_bn_gfx, 8x8@4, 
//	+ palette 16 entries, not compressed
//	+ 1 tiles not compressed
//	Total size: 32 + 32 = 64
//
//	Time-stamp: 2024-11-30, 14:39:25
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_EXPLOSION_BN_GFX_H
#define GRIT_EXPLOSION_BN_GFX_H

#define explosion_bn_gfxTilesLen 32
extern const bn::tile explosion_bn_gfxTiles[1];

#define explosion_bn_gfxPalLen 32
extern const bn::color explosion_bn_gfxPal[16];

#endif // GRIT_EXPLOSION_BN_GFX_H

//}}BLOCK(explosion_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item explosion(sprite_shape_size(sprite_shape::SQUARE, sprite_size::SMALL), 
            sprite_tiles_item(span<const tile>(explosion_bn_gfxTiles, 1), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(explosion_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

