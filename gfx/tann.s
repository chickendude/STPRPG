
@{{BLOCK(tann)

@=======================================================================
@
@	tann, 64x64@4, 
@	+ palette 256 entries, not compressed
@	+ 64 tiles Metatiled by 2x2 not compressed
@	Total size: 512 + 2048 = 2560
@
@	Time-stamp: 2022-02-04, 20:56:18
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global tannTiles		@ 2048 unsigned chars
	.hidden tannTiles
tannTiles:
	.word 0x22222000,0x22222200,0x22222220,0x22212220,0x12112220,0x12112200,0x11112000,0x21120000
	.word 0x00002222,0x00222222,0x02222222,0x02222222,0x02222121,0x02221121,0x00221111,0x00002112
	.word 0x11212000,0x22121200,0x21222120,0x22221120,0x12212200,0x21222000,0x22211200,0x02222200
	.word 0x00021211,0x00212122,0x02122212,0x02112222,0x00221221,0x00022212,0x00211222,0x00222220
	.word 0x00000000,0x22222000,0x22222200,0x22222220,0x22212220,0x12112220,0x12112200,0x11112000
	.word 0x00000000,0x00022222,0x00222222,0x02222222,0x02222222,0x02222121,0x02221121,0x00221111
	.word 0x21122000,0x11221200,0x22222120,0x22222112,0x12222212,0x12120220,0x21112000,0x22222000
	.word 0x00022112,0x00021211,0x00212222,0x00211122,0x00021221,0x00002222,0x00022222,0x00022220

	.word 0x22222000,0x22222200,0x22222220,0x22212220,0x12112220,0x12112200,0x11112000,0x21120000
	.word 0x00002222,0x00222222,0x02222222,0x02222222,0x02222121,0x02221121,0x00221111,0x00002112
	.word 0x11212000,0x22121200,0x21222120,0x22221120,0x12212200,0x21222000,0x22211200,0x02222200
	.word 0x00021211,0x00212122,0x02122212,0x02112222,0x00221221,0x00022212,0x00211222,0x00222220
	.word 0x00000000,0x22222000,0x22222200,0x22222220,0x22212220,0x12112220,0x12112200,0x11112000
	.word 0x00000000,0x00002222,0x00222222,0x02222222,0x02222222,0x02222121,0x02221121,0x00221111
	.word 0x21122000,0x11212000,0x22221200,0x22111200,0x12212000,0x22220000,0x22220000,0x02220000
	.word 0x00022112,0x00222211,0x02212222,0x21122122,0x21221221,0x02202121,0x00021112,0x00022222

	.word 0x22222000,0x22222200,0x22222220,0x22222220,0x22222220,0x22222200,0x22222000,0x22220000
	.word 0x00002222,0x00222222,0x02222222,0x02222222,0x02222222,0x00222222,0x00022222,0x00002222
	.word 0x21212000,0x11121200,0x22121120,0x22222120,0x21212200,0x22222000,0x22221200,0x02222200
	.word 0x00021122,0x00212111,0x02112122,0x02122222,0x00221212,0x00022222,0x00212222,0x00222220
	.word 0x00000000,0x22222000,0x22222200,0x22222220,0x22222220,0x22222220,0x22222200,0x22222000
	.word 0x00000000,0x00002222,0x00222222,0x02222222,0x02222222,0x02222222,0x00222222,0x00022222
	.word 0x22222000,0x11121200,0x22121200,0x22222000,0x21212000,0x22222000,0x22222000,0x02220000
	.word 0x00002222,0x00021211,0x00211222,0x00212222,0x00222212,0x00002122,0x00021212,0x00002020

	.word 0x22222000,0x22222200,0x22222220,0x22222220,0x22222220,0x22222200,0x22222000,0x22220000
	.word 0x00002222,0x00222222,0x02222222,0x02222222,0x02222222,0x00222222,0x00022222,0x00002222
	.word 0x21212000,0x11121200,0x22121120,0x22222120,0x21212200,0x22222000,0x22221200,0x02222200
	.word 0x00021122,0x00212111,0x02112122,0x02122222,0x00221212,0x00022222,0x00212222,0x00222220
	.word 0x00000000,0x22222000,0x22222200,0x22222220,0x22222220,0x22222220,0x22222200,0x22222000
	.word 0x00000000,0x00002222,0x00222222,0x02222222,0x02222222,0x02222222,0x00222222,0x00022222
	.word 0x22220000,0x11212000,0x22211200,0x22221200,0x21222200,0x22120000,0x21212000,0x02020000
	.word 0x00022222,0x00212111,0x00212122,0x00222222,0x00021212,0x00022222,0x00022222,0x00002220

	.word 0x22220000,0x22222000,0x22222000,0x22212000,0x21212000,0x11212000,0x11112000,0x11220000
	.word 0x00000222,0x00022222,0x00222222,0x02222222,0x02222222,0x02222222,0x00222221,0x00022211
	.word 0x12200000,0x22000000,0x12000000,0x12200000,0x21200000,0x22200000,0x21120000,0x22220000
	.word 0x00002221,0x00000222,0x00002211,0x00002212,0x00002212,0x00000222,0x00000222,0x00000222
	.word 0x00000000,0x22220000,0x22222000,0x22222000,0x22212000,0x21212000,0x11212000,0x11112000
	.word 0x00000000,0x00000222,0x00022222,0x00222222,0x02222222,0x02222222,0x02222222,0x00222221
	.word 0x11220000,0x12200000,0x22200000,0x12120000,0x21112000,0x22220000,0x11200000,0x22200000
	.word 0x00022211,0x00002221,0x00002222,0x00021212,0x00022212,0x00000222,0x00000222,0x00000022

	.word 0x22220000,0x22222000,0x22222000,0x22212000,0x21212000,0x11212000,0x11112000,0x11220000
	.word 0x00000222,0x00022222,0x00222222,0x02222222,0x02222222,0x02222222,0x00222221,0x00022211
	.word 0x12200000,0x22000000,0x12000000,0x12200000,0x21200000,0x22200000,0x21120000,0x22220000
	.word 0x00002221,0x00000222,0x00002211,0x00002212,0x00002212,0x00000222,0x00000222,0x00000222
	.word 0x00000000,0x22220000,0x22222000,0x22222000,0x22212000,0x21212000,0x11212000,0x11112000
	.word 0x00000000,0x00000222,0x00022222,0x00222222,0x02222222,0x02222222,0x02222222,0x00222221
	.word 0x11220000,0x12200000,0x22220000,0x12220000,0x11200000,0x22220000,0x22120000,0x02200000
	.word 0x00022211,0x00002221,0x00000222,0x00000222,0x00000221,0x00000222,0x00002222,0x00002220

	.word 0x22200000,0x22222000,0x22222200,0x22222220,0x22222220,0x22222220,0x12222200,0x11222000
	.word 0x00002222,0x00022222,0x00022222,0x00021222,0x00021212,0x00021211,0x00021111,0x00002211
	.word 0x12220000,0x22200000,0x11220000,0x21220000,0x21220000,0x22200000,0x22200000,0x22200000
	.word 0x00000221,0x00000022,0x00000021,0x00000221,0x00000212,0x00000222,0x00002112,0x00002222
	.word 0x00000000,0x22200000,0x22222000,0x22222200,0x22222220,0x22222220,0x22222220,0x12222200
	.word 0x00000000,0x00002222,0x00022222,0x00022222,0x00021222,0x00021212,0x00021211,0x00021111
	.word 0x11222000,0x12220000,0x22220000,0x21212000,0x21222000,0x22200000,0x22200000,0x22000000
	.word 0x00002211,0x00000221,0x00000222,0x00002121,0x00021112,0x00002222,0x00000211,0x00000222

	.word 0x22200000,0x22222000,0x22222200,0x22222220,0x22222220,0x22222220,0x12222200,0x11222000
	.word 0x00002222,0x00022222,0x00022222,0x00021222,0x00021212,0x00021211,0x00021111,0x00002211
	.word 0x12220000,0x22200000,0x11220000,0x21220000,0x21220000,0x22200000,0x22200000,0x22200000
	.word 0x00000221,0x00000022,0x00000021,0x00000221,0x00000212,0x00000222,0x00002112,0x00002222
	.word 0x00000000,0x22200000,0x22222000,0x22222200,0x22222220,0x22222220,0x22222220,0x12222200
	.word 0x00000000,0x00002222,0x00022222,0x00022222,0x00021222,0x00021212,0x00021211,0x00021111
	.word 0x11222000,0x12220000,0x22200000,0x22200000,0x12200000,0x22200000,0x22220000,0x02220000
	.word 0x00002211,0x00000221,0x00002222,0x00002221,0x00000211,0x00002222,0x00002122,0x00000220

	.section .rodata
	.align	2
	.global tannPal		@ 512 unsigned chars
	.hidden tannPal
tannPal:
	.hword 0x0000,0x7FFF,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0421,0x0421,0x0421,0x0421,0x0421,0x0421,0x0421,0x0421
	.hword 0x0842,0x0842,0x0842,0x0842,0x0842,0x0842,0x0842,0x0842
	.hword 0x0C63,0x0C63,0x0C63,0x0C63,0x0C63,0x0C63,0x0C63,0x0C63
	.hword 0x1084,0x1084,0x1084,0x1084,0x1084,0x1084,0x1084,0x1084
	.hword 0x14A5,0x14A5,0x14A5,0x14A5,0x14A5,0x14A5,0x14A5,0x14A5
	.hword 0x18C6,0x18C6,0x18C6,0x18C6,0x18C6,0x18C6,0x18C6,0x18C6
	.hword 0x1CE7,0x1CE7,0x1CE7,0x1CE7,0x1CE7,0x1CE7,0x1CE7,0x1CE7

	.hword 0x2108,0x2108,0x2108,0x2108,0x2108,0x2108,0x2108,0x2108
	.hword 0x2529,0x2529,0x2529,0x2529,0x2529,0x2529,0x2529,0x2529
	.hword 0x294A,0x294A,0x294A,0x294A,0x294A,0x294A,0x294A,0x294A
	.hword 0x2D6B,0x2D6B,0x2D6B,0x2D6B,0x2D6B,0x2D6B,0x2D6B,0x2D6B
	.hword 0x318C,0x318C,0x318C,0x318C,0x318C,0x318C,0x318C,0x318C
	.hword 0x35AD,0x35AD,0x35AD,0x35AD,0x35AD,0x35AD,0x35AD,0x35AD
	.hword 0x39CE,0x39CE,0x39CE,0x39CE,0x39CE,0x39CE,0x39CE,0x39CE
	.hword 0x3DEF,0x3DEF,0x3DEF,0x3DEF,0x3DEF,0x3DEF,0x3DEF,0x3DEF

	.hword 0x4210,0x4210,0x4210,0x4210,0x4210,0x4210,0x4210,0x4210
	.hword 0x4631,0x4631,0x4631,0x4631,0x4631,0x4631,0x4631,0x4631
	.hword 0x4A52,0x4A52,0x4A52,0x4A52,0x4A52,0x4A52,0x4A52,0x4A52
	.hword 0x4E73,0x4E73,0x4E73,0x4E73,0x4E73,0x4E73,0x4E73,0x4E73
	.hword 0x5294,0x5294,0x5294,0x5294,0x5294,0x5294,0x5294,0x5294
	.hword 0x56B5,0x56B5,0x56B5,0x56B5,0x56B5,0x56B5,0x56B5,0x56B5
	.hword 0x5AD6,0x5AD6,0x5AD6,0x5AD6,0x5AD6,0x5AD6,0x5AD6,0x5AD6
	.hword 0x5EF7,0x5EF7,0x5EF7,0x5EF7,0x5EF7,0x5EF7,0x5EF7,0x5EF7

	.hword 0x6318,0x6318,0x6318,0x6318,0x6318,0x6318,0x6318,0x6318
	.hword 0x6739,0x6739,0x6739,0x6739,0x6739,0x6739,0x6739,0x6739
	.hword 0x6B5A,0x6B5A,0x6B5A,0x6B5A,0x6B5A,0x6B5A,0x6B5A,0x6B5A
	.hword 0x6F7B,0x6F7B,0x6F7B,0x6F7B,0x6F7B,0x6F7B,0x6F7B,0x6F7B
	.hword 0x739C,0x739C,0x739C,0x739C,0x739C,0x739C,0x739C,0x739C
	.hword 0x77BD,0x77BD,0x77BD,0x77BD,0x77BD,0x77BD,0x77BD,0x77BD
	.hword 0x7BDE,0x7BDE,0x7BDE,0x7BDE,0x7BDE,0x7BDE,0x7BDE,0x7BDE
	.hword 0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x7FFF

@}}BLOCK(tann)