#ifndef BN_SPRITE_ITEMS_KEY_H
#define BN_SPRITE_ITEMS_KEY_H

#include "bn_sprite_item.h"

//{{BLOCK(key_bn_gfx)

//======================================================================
//
//	key_bn_gfx, 8x8@4, 
//	+ palette 16 entries, not compressed
//	+ 1 tiles not compressed
//	Total size: 32 + 32 = 64
//
//	Time-stamp: 2024-11-26, 20:33:39
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_KEY_BN_GFX_H
#define GRIT_KEY_BN_GFX_H

#define key_bn_gfxTilesLen 32
extern const bn::tile key_bn_gfxTiles[1];

#define key_bn_gfxPalLen 32
extern const bn::color key_bn_gfxPal[16];

#endif // GRIT_KEY_BN_GFX_H

//}}BLOCK(key_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item key(sprite_shape_size(sprite_shape::SQUARE, sprite_size::SMALL), 
            sprite_tiles_item(span<const tile>(key_bn_gfxTiles, 1), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(key_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

