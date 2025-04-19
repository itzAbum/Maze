#ifndef BN_SPRITE_ITEMS_GHOST_H
#define BN_SPRITE_ITEMS_GHOST_H

#include "bn_sprite_item.h"

//{{BLOCK(ghost_bn_gfx)

//======================================================================
//
//	ghost_bn_gfx, 8x8@4, 
//	+ palette 16 entries, not compressed
//	+ 1 tiles not compressed
//	Total size: 32 + 32 = 64
//
//	Time-stamp: 2025-04-15, 23:11:52
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_GHOST_BN_GFX_H
#define GRIT_GHOST_BN_GFX_H

#define ghost_bn_gfxTilesLen 32
extern const bn::tile ghost_bn_gfxTiles[1];

#define ghost_bn_gfxPalLen 32
extern const bn::color ghost_bn_gfxPal[16];

#endif // GRIT_GHOST_BN_GFX_H

//}}BLOCK(ghost_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item ghost(sprite_shape_size(sprite_shape::SQUARE, sprite_size::SMALL), 
            sprite_tiles_item(span<const tile>(ghost_bn_gfxTiles, 1), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(ghost_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

