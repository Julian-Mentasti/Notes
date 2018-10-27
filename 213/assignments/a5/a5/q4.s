.pos 0x1000
	   ld $n, r0	# r0 = &n
	   ld (ro), r0	# r0 = n
	   ld $s, r1	# r1 = &s
	   ld (r1), r1	# r1 = s

avg:
    	beq r0, enda	# if counter == 0 goto enda
    	ld 4(r1), r2 	# r2 = r1[1] grade 0
    	ld 8(r1), r3	# r2 = r3[2] grade 1
    	add r3, r2	    # r2 = grade 0 + grade 1
    	ld 16(r1), r3	# r2 = grade 2
    	add r3, r2	    # r2 = grade 0 + grade 1 + grade 2
    	ld 20(r1), r3	# r2 = grade 3
    	add r3, r2	    # r2 = grade 0 + grade 1 + grade 2 + grade 3
    	ld $2, r3	    # r3 = 2
    	shr r3, r2	    # r2 /= 4 average grade
    	st r2, 20(r1)	# store the average in the field
    	dec r0		    # counter--
    	beq r0, enda	# if counter == 0 goto enda // prevent going over the stack
    	ld $24, r3	    # r3 = 24
    	add r3, r1	    # r1 = r1 + 24 (next student)
    	br avg

enda:
    	ld $n, r3	# r3 = &n
    	ld (r3), r3	# r3 = n
    	ld $s, r4	# r4 = &s
    	ld (r4), r4	# r6 = s (load the first student)
        br sel

min: 
        beq r0, ends       # if r0 == 0 then goto end2
        ld 20(r1), r6     # r6[20] is the average of the student
        mov r7, r5         # r5 = r7 previous grade average
        not r5             # r5 = ~r5
        inc r5             # r5 = -r5
        add r5, r6         # r4 = r4 - r5 
        bgt r6, store      # check is not lower if r6 is greater than r5 goto keep
        mov r1, r2         # r2 = r1 position of the next student
        ld 20(r2), r7     # r7 = grade of the next student
        br store

sel:
        beq r3, endsel  # if n == 0 goto endsel
        mov r3, r0      # r0 = r3 (n)
        mov r4, r1      # r1 = r4 (s)
        mov r1, r2      # r2 = r1 (clone the student)
        ld 20(r2), r3   # r3 = avg of the first student
        ld $24, r6      # r6 = 24
        add r6, r1      # r1 = next student
        dec r0          # r0--
        br min

store:  ld $24, r6  #r4 = 24
        add r6, r1  #r1 = r1 + r6
        dec r0      # counter --
        br min      # goto find the min value

endsel: ld $n,r0  # r0 = &n
        ld (r0),r0    # r0 = n
        shr $1,r0  # r0 = r0 >> 1, div 2
        mov r0,r1  # r1 = r0
        shl $3,r0  # r0 = r0 << 2^3
        shl $4,r1  # r1 = r1 << 2^3
        add r1,r0  # r0 = r0 + r1
        ld $s,r1  # r1 = &s
        ld (r1),r1    # r1 = s
        add r0,r1  # r1 = s + r0
        ld 0(r1),r2   # r2 = r1
        ld $m,r7  # r7 = $m
        st r2,(r7)    # m = r7
        halt

ends:   ld   0(r4), r6   # swap student ids of the first and the last
        ld   0(r2), r5   # r5 placeholder
        st   r6, 0(r2)   
        st   r5, 0(r4)
        ld   4(r4), r6   # swap grade 0
        ld   4(r2), r5
        st   r4, 4(r2)
        st   r5, 4(r4)
        ld   8(r4), r6   # swap grade 1
        ld   8(r2), r5
        st   r6, 8(r2)
        st   r5, 8(r4)
        ld   12(r4), r6  # swap grade 2
        ld   12(r2), r5
        st   r6, 12(r2)
        st   r5, 12(r4)
        ld   16(r4), r6  # swap grade 3
        ld   16(r2), r5
        st   r6, 16(r2)
        st   r5, 16(r4)
        ld   20(r4), r6  # swap average
        ld   20(r2), r5
        st   r6, 20(r2)
        st   r5, 20(r4)
        ld   $24, r6     # r6 = 24
        add  r6, r4      #r4 = r6 + 24 next position
        dec  r3          # decrease the programme counter
        br   sel         # goto selection