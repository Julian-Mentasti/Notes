.pos 0x100
start:	
        ld   $sb, r5 # r5 = $sb
        inca r5 # r5 = r5 + 4
        gpc  $6, r6 # r6 = 6
        j    main
        halt

.pos 0x200
main:	
	deca r5
	st   r6, (r5) # r5 = r6
	ld   $-12, r1 # r1 = -12
	add  r1, r5 # r5 = r5 -12
	ld   $a, r0 # r0 = &a
	st   r0, 0x0(r5)
	ld   $val, r0
	ld   (r0), r0
	st   r0, 0x4(r5)
	ld   $size, r0
	ld   (r0), r0
	st   r0, 0x8(r5)
	gpc  $6, r6
	j    search
	ld   $12, r1
	add  r1, r5
	ld   $ret, r1
	st   r0, (r1)
	ld   (r5), r6
	inca r5
	j    (r6)
	
.pos 0x300
search:	
	deca r5
	st   r6, (r5)
	ld   0xC(r5), r0
	beq  r0, L3
	ld   0x4(r5), r1
	ld   0x8(r5), r2
	mov  r0, r3
	shr  $1, r3
	mov  r3, r4
	shl  $2, r4
	add  r1, r4
	ld   (r4), r7
	not  r7
	inc  r7
	add  r2, r7
	beq  r7, L2
	bgt  r7, L0
	br   L1
L0:
	mov  r4, r1
	inca r1
	not  r3
	add  r0, r3
L1:
	ld   $-12, r4
	add  r4, r5
	st   r1, 0x0(r5)
	st   r2, 0x4(r5)
	st   r3, 0x8(r5)
	gpc  $6, r6
	j    search
	ld   $12, r1
	add  r1, r5
	br   L3
L2:
	mov  r4, r0
L3:
	ld   (r5), r6
	inca r5
	j    (r6)

.pos 0x1000
a:	.long 0x1
        .long 0x3         
        .long 0x4
	.long 0x7         
	.long 0x9         
        .long 0xA         
        .long 0xC         
	.long 0x10         
	.long 0x12         
        .long 0x13
	.long 0x14
	.long 0x17
	.long 0x1A
	.long 0x1B
	.long 0x1F
	
size:	.long 15
val:	.long 0x12
ret:	.long 0xFFFFFFFF
	
.pos 0x8000
stack:	
	# These are here so you can see (some of) the stack contents.
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
sb: 	.long 0
