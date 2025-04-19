
@{{BLOCK(key_bn_gfx)

@=======================================================================
@
@	key_bn_gfx, 8x8@4, 
@	+ palette 16 entries, not compressed
@	+ 1 tiles not compressed
@	Total size: 32 + 32 = 64
@
@	Time-stamp: 2024-11-26, 20:33:39
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global key_bn_gfxTiles		@ 32 unsigned chars
	.hidden key_bn_gfxTiles
key_bn_gfxTiles:
	.word 0x000B0000,0x00B0B000,0x000B0000,0x000B0000,0x000B0000,0x000BBB00,0x000B0000,0x000BBB00

	.section .rodata
	.align	2
	.global key_bn_gfxPal		@ 32 unsigned chars
	.hidden key_bn_gfxPal
key_bn_gfxPal:
	.hword 0x0000,0x0010,0x0200,0x0210,0x4000,0x4010,0x4200,0x4210
	.hword 0x6318,0x001F,0x03E0,0x03FF,0x7C00,0x7C1F,0x7FE0,0x7FFF

@}}BLOCK(key_bn_gfx)
