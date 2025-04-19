
@{{BLOCK(zombie_bn_gfx)

@=======================================================================
@
@	zombie_bn_gfx, 8x8@4, 
@	+ palette 16 entries, not compressed
@	+ 1 tiles not compressed
@	Total size: 32 + 32 = 64
@
@	Time-stamp: 2024-11-30, 14:18:05
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global zombie_bn_gfxTiles		@ 32 unsigned chars
	.hidden zombie_bn_gfxTiles
zombie_bn_gfxTiles:
	.word 0x00000000,0x00022000,0x00022000,0x02999920,0x00099000,0x00099000,0x00099000,0x00022000

	.section .rodata
	.align	2
	.global zombie_bn_gfxPal		@ 32 unsigned chars
	.hidden zombie_bn_gfxPal
zombie_bn_gfxPal:
	.hword 0x0000,0x0010,0x0200,0x0210,0x4000,0x4010,0x4200,0x6318
	.hword 0x4210,0x000A,0x03E0,0x03FF,0x7C00,0x7C1F,0x7FE0,0x7FFF

@}}BLOCK(zombie_bn_gfx)
