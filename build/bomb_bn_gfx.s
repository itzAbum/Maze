
@{{BLOCK(bomb_bn_gfx)

@=======================================================================
@
@	bomb_bn_gfx, 8x8@4, 
@	+ palette 16 entries, not compressed
@	+ 1 tiles not compressed
@	Total size: 32 + 32 = 64
@
@	Time-stamp: 2024-11-30, 14:39:25
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global bomb_bn_gfxTiles		@ 32 unsigned chars
	.hidden bomb_bn_gfxTiles
bomb_bn_gfxTiles:
	.word 0x00B00000,0x000B0000,0x00044000,0x00444400,0x04474440,0x00444400,0x00000000,0x00000000

	.section .rodata
	.align	2
	.global bomb_bn_gfxPal		@ 32 unsigned chars
	.hidden bomb_bn_gfxPal
bomb_bn_gfxPal:
	.hword 0x0000,0x0010,0x0200,0x0210,0x14A5,0x4010,0x4200,0x6318
	.hword 0x46AC,0x001F,0x03E0,0x033F,0x7C00,0x7C1F,0x7FE0,0x7FFF

@}}BLOCK(bomb_bn_gfx)
