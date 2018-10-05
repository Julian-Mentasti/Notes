.pos 0x100
            ld $0x3, r0 # r0 = 3
            ld $j, r1 # r1 = address of j
            st r0, (r1) # j = 3
            ld $a, r2 # r2 = address of array[0]
            ld (r2, r0, 4), r3 # r3 = value of a[j]
            ld $i, r4 # r4 = address of i
            st r3, (r4) # i = a[j]
            ld (r4), r5 # r5 = value of i
            ld $0x9, r0 # r0 = 9
            and r0, r5
            st r5, (r4) # i = a[1]
            ld (r2, r5, 4), r5 # r5 = a[i]
            st r5, (r4) # i = i & 9
            ld $p, r0 # r0 = &p
            st r1, (r0) # p = &j
            ld (r1), r5 # r5 = j
            inc r5 # r5++
            st r5, (r1) # j = r5
            ld (r0), r3 # r3 = p
            ld (r3), r4 # r4 = *p
            dec r4 # r4--
            dec r4 # r4--
            st r4, (r3) # *p = r4 
            ld (r1), r5 # r5 = j
            ld (r2, r5, 4), r5 # r5 = a[j] 
            shl $0x2, r5 # r5 = r5 * 4
            add r2, r5 # r5 += r5
            st r5, (r0)
            ld $0x4, r5 # r5 = 4
            ld (r0), r4 # r4 = addr of *p
            ld (r4), r3 # r3 = val of *p
            ld (r2, r5, 4), r5 # r5 = val of a[r5]
            add r5, r3 # r3 = r5 + r3
            st r3, (r4) # *p = r4

            halt

.pos 0x1000
i:          .long 0x0 # i = 0

.pos 0x1004
j:          .long 0x0 # j = 0

.pos 0x1008
p:          .long 0x1000 # p = 0x1000

.pos 0x2000
a:          .long 0x0 # a[0] = 0 
            .long 0x5 # a[1] = 3
            .long 0x3 # a[2] = 5
            .long 0x4 # a[3] = 4
            .long 0x5 # a[4] = 7
            .long 0x0 # a[5] = 0
            .long 0x0 # a[6] = 0
            .long 0x0 # a[7] = 0
            .long 0x0 # a[8] = 0
            .long 0x0 # a[9] = 0
