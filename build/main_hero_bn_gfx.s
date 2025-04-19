
@{{BLOCK(main_hero_bn_gfx)

@=======================================================================
@
@	main_hero_bn_gfx, 8x8@4, 
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
	.global main_hero_bn_gfxTiles		@ 32 unsigned chars
	.hidden main_hero_bn_gfxTiles
main_hero_bn_gfxTiles:
	.word 0x00011000,0x00111000,0x00055000,0x03333330,0x50333305,0x50333305,0x00222200,0x00200200

	.section .rodata
	.align	2
	.global main_hero_bn_gfxPal		@ 32 unsigned chars
	.hidden main_hero_bn_gfxPal
main_hero_bn_gfxPal:
	.hword 0x03E0,0x001F,0x7C00,0x7F20,0x7620,0x027F,0x0000,0x0000
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

@}}BLOCK(main_hero_bn_gfx)
