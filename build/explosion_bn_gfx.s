
@{{BLOCK(explosion_bn_gfx)

@=======================================================================
@
@	explosion_bn_gfx, 8x8@4, 
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
	.global explosion_bn_gfxTiles		@ 32 unsigned chars
	.hidden explosion_bn_gfxTiles
explosion_bn_gfxTiles:
	.word 0x30040403,0x24323230,0x43233240,0x32232420,0x33232420,0x24422430,0x04244230,0x00022000

	.section .rodata
	.align	2
	.global explosion_bn_gfxPal		@ 32 unsigned chars
	.hidden explosion_bn_gfxPal
explosion_bn_gfxPal:
	.hword 0x0000,0x0010,0x02BF,0x001F,0x015F,0x4010,0x4200,0x6318
	.hword 0x4210,0x001F,0x03E0,0x03FF,0x7C00,0x7C1F,0x7FE0,0x7FFF

@}}BLOCK(explosion_bn_gfx)
