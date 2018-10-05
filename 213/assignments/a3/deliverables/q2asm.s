.pos 0x100
                ld  $0x0, r7 # r7 = 0
                ld  $tmp, r0 # r0 = addr of tmp
                st  r7, (r0) # tmp = 0
                ld  $tos, r1 # r1 = addr of tos
                st  r7, (r1) # tos = 0
                ld  (r1), r3	# r3 = val of tos
                ld  (r0), r2	# r2 = val of tmp
                ld  $s, r4	# r4 = addr of s
                ld  (r4), r4	# r4 = addr of s[0]
                ld  (r4, r3, 4), r5# r5 = s[tos]
                add r3, r5	# r5 = s[tos] + tos
                ld  $a, r6	# r6 = address of a[0]
                st  r5, (r6)	# a[0] = s[tos] + tos (r5)
                inc r3		# r3++
                st  r3, (r1)	# tos = r3
                ld  (r4, r3, 4),r5  # r5 = s[tos]
                add r3, r5  	# r5 = s[tos]+tos
                st  r5, 4(r6)	# a[1] = r5 =s[tos] + tos
                inc r3		# r3++
                st r3, (r1)	# tos = r3
                ld  (r4, r3, 4),r5 # r5 = s[tos]
                add r3, r5 	# r5 = s[tos] + tos
                st  r5, 8(r6)	# a[2] = r5 =s[tos] + tos
                inc r3  	# r3++
                st r3, (r1)	# tos = r3
                dec r3		# r3--
                st r3, (r1)	# tos = r3
                ld  (r6, r3, 4), r5 # r5 = a[tos]
                st  r5, (r0)	# tmp = a[tos]
                dec r3		# r3--
                st r3, (r1)	# tos = r3
                ld  (r6, r3, 4), r2    # r2 = val of a[tos]
                add r5, r2	# r2 = tmp + a[tos]
                st  r2, (r0)	# tmp = tmp + a[tos]
                dec r3		# r3--
                st  r3, (r1)	# tos--
                ld  (r6, r3, 4), r5 # r2 = val of a[tos]
                add r5, r2	# r2 = tmp + a[tos]
                st  r2, (r0)	# tmp = tmp + a[tos]	
                st  r2, (r4)	# s[0] = tmp 
                halt            # end



.pos 0x1000
a:   .long 0	# a[0] = 0
     .long 0	# a[1] = 0
     .long 0	# a[2] = 0

.pos 0x2000
s:   .long 0x3000   # s = 0x3000
tos: .long 0	    # tos = 0
tmp: .long 0	    # tmp = 0

.pos 0x3000
s_ar:   .long 0x0 # s[0] = 0
	.long 0x1 # s[1] = 1
	.long 0x3 # s[2] = 3
	.long 0x5 # s[3] = 5
        .long 0x7 # s[4] = 7
