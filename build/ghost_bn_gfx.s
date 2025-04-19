
@{{BLOCK(ghost_bn_gfx)

@=======================================================================
@
@	ghost_bn_gfx, 8x8@4, 
@	+ palette 16 entries, not compressed
@	+ 1 tiles not compressed
@	Total size: 32 + 32 = 64
@
@	Time-stamp: 2025-04-15, 23:11:52
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global ghost_bn_gfxTiles		@ 32 unsigned chars
	.hidden ghost_bn_gfxTiles
ghost_bn_gfxTiles:
	.word 0x00111100,0x01777710,0x17171771,0x17777771,0x17717771,0x17777771,0x01717171,0x00101010

	.section .rodata
	.align	2
	.global ghost_bn_gfxPal		@ 32 unsigned chars
	.hidden ghost_bn_gfxPal
ghost_bn_gfxPal:
	.hword 0x03E8,0x0000,0x001F,0x0210,0x4000,0x4010,0x4200,0x6739
	.hword 0x4211,0x001F,0x03E0,0x211F,0x7C00,0x7C1F,0x001F,0x7FFF

@}}BLOCK(ghost_bn_gfx)
