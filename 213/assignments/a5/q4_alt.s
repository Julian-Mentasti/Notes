	ld $n, r0 #r0 = &n
	ld $m, r1 #r1 = &m
	ld $s, r2 #r2 = &s

	ld (r0), r3
	mv (r2), r4 #r4 = base
	inca r4 # r4 = &grade 0

avg:	beq r3, sort # goto sort if r3 == 0
	ld (r4), r5 # r5 = grade 0
	ld 4(r4), r6 # r6 = grade 1
	add r6, r5 # r5 = grade 0 + grade 1
	ld 8(r4), r6 # r6 = grade 2
	add r6, r5 # r5 = grade 0 + grade 1 + grade 2
	ld 0xc(r4), r6 # r6 = grade 3
	add r6, r5 # r5 = grade 0 + grade 1 + grade 2 + grade 3
	ld $2, r6 # r6 = 4
	shl r6, r5 # r5 /= 2^2
    	st r5, 16(r4) # store the new average
    	ld $24, r6 # r6 = 24
    	add r6, r4 # r4 = next addr of grade 0
    	dec r3 # r3 = r3 - 1
    	j avg
    	
sort:	ld (r0), r3 # r3 = n
	mv (r2), r4 # r4 = base
	ld $20, r6 # r6 = 24
	add r6, r4 # r4 = addr of first avg
	ld (r4), r5 # r5 = first avg
	gpc $
	j iter
	
# given a starting position, r4,  move 24 positions
next: 	ld $24, r6 # r6 = 24
	add r6, r5 # r4 = next address of average
	j (r7)
	
iter:	
