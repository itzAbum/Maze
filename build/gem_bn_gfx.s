
@{{BLOCK(gem_bn_gfx)

@=======================================================================
@
@	gem_bn_gfx, 8x8@4, 
@	+ palette 16 entries, not compressed
@	+ 1 tiles not compressed
@	Total size: 32 + 32 = 64
@
@	Time-stamp: 2024-11-26, 17:36:37
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global gem_bn_gfxTiles		@ 32 unsigned chars
	.hidden gem_bn_gfxTiles
gem_bn_gfxTiles:
	.word 0x00022000,0x00211200,0x02111120,0x21F11112,0x21FF1112,0x02111120,0x00211200,0x00022000

	.section .rodata
	.align	2
	.global gem_bn_gfxPal		@ 32 unsigned chars
	.hidden gem_bn_gfxPal
gem_bn_gfxPal:
	.hword 0x4411,0x7C1F,0x0000,0x7FE0,0x4000,0x7C00,0x4200,0x03E0
	.hword 0x0200,0x03FF,0x0210,0x001F,0x0010,0x0004,0x7FFF,0x6318

@}}BLOCK(gem_bn_gfx)
