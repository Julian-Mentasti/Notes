.pos 0x0
        ld   $n,r0  # r0 = &n
        ld   (r0),r0    # r0 = n => number of students  
        ld   $s,r1  # r1 = &s => base addr
        ld   (r1),r1    # r1 = s
avg:
        beq  r0,enda     # if r0 == 0 then goto end
        ld   4(r1),r2   # r2 = r1[1] // grade 0
        ld   8(r1),r7   # r7 = r1[2] // grade 1
        add  r7,r2  # r2 = grade 0 + grade 1
        ld   12(r1),r7  # r7 = r1[3] // grade 2
        add  r7,r2  # r2 = grade 0 + grade 1 + grade 2
        ld   16(r1),r7  # r7 = grade 3
        add  r7,r2  # r2 = grade 0 + grade 1 + grade 2 + grade 3
        shr  $2,r2  # r2 = r2 >> 2 // get the average grade
        st   r2,20(r1)  # r1 = r2 // store the students average
        dec  r0     # decrease the student count
        beq r0, enda    # if counter == 0 goto enda // prevent going over the stack
        ld   $24,r2 # r2 = 24
        add  r2,r1  # r1 = r1 + 24 // move r1 to the next student
        br   avg   # return to the top of the loop
enda:
        ld   $n,r3  # r3 = &n
        ld   (r3),r3    # r3 = n
        ld   $s,r4  # r4 = &s
        ld   (r4),r4    # r4 = s => loading the first student
        br min

sel:
        beq  r0,ends    # if r0 == 0 then goto ends
        ld   20(r1),r6  # r6[20] is the average of the student
        mov  r7,r5  # r5 = r7 previous grade average
        not  r5     # r5 = ~r5
        inc  r5     # r5 = -r5
        add  r5,r6  # r6 = r6 - r5 
        bgt  r6,store    # check is not lower if r6 is greater than r5 goto store
        mov  r1,r2  # r2 = r1 position of the next student
        ld   20(r2),r7  # r7 = grade of the next student
        br store

min:
        beq  r3,endsel    # if r3 == 0 goto r3, the counter n
        mov  r3,r0  # r0 = r3
        mov  r4,r1  # r1 = r4, s is the location
        mov  r1,r2  # r2 = r1 is the next student
        ld   20(r2),r7  # r7 = a[4] // its the average
        ld   $24,r6 # r6 = 24
        add  r6,r1  # r1 = location of the next student
        dec  r0     # reduce the counter
        br sel

store:
        ld   $24,r6     # r6 = 24
        add  r6,r1  # r1 = r6 + 24 Next student
        dec  r0     # r0 = r0 - 1 decrease the counter
        br   sel  # goto sel

endsel:  # students have now been sorted
        ld   $n,r0  # r0 = &n
        ld   (r0),r0    # r0 = n
        shr  $1,r0  # r0 = r0 >> 1, div 2
        mov  r0,r1  # r1 = r0
        shl  $3,r0  # r0 = r0 << 2^3
        shl  $4,r1  # r1 = r1 << 2^3
        add  r1,r0  # r0 = r0 + r1
        ld   $s,r1  # r1 = &s
        ld   (r1),r1    # r1 = s
        add  r0,r1  # r1 = s + r0
        ld   0(r1),r2   # r2 = r1
        ld   $m,r7  # r7 = $m
        st   r2,(r7)    # m = r2
        halt

ends:
        ld   0(r4),r6   # swap student ids of the first and the last
        ld   0(r2),r5   # r5 =  
        st   r6,0(r2)
        st   r5,0(r4)
        ld   4(r4),r6 # swap grade 0
        ld   4(r2),r5
        st   r6,4(r2)
        st   r5,4(r4)
        ld   8(r4),r6 # swap grade 1
        ld   8(r2),r5
        st   r6,8(r2)
        st   r5,8(r4)
        ld   12(r4),r6 # swap grade 2
        ld   12(r2),r5
        st   r6,12(r2)
        st   r5,12(r4)
        ld   16(r4),r6 # swap grade 3
        ld   16(r2),r5
        st   r6,16(r2)
        st   r5,16(r4)
        ld   20(r4),r6 # swap average
        ld   20(r2),r5
        st   r6,20(r2)
        st   r5,20(r4)
        ld   $24,r6 # r6 = 24
        add  r6,r4  # r4 = r6 + 24 next position
        dec  r3     # decrease the programme counter
        br   min  # goto min

.pos 0x2000
n:    .long 5     
m:    .long 50     
s:    .long base  
base: .long 0001  
      .long 50    
      .long 50   
      .long 50    
      .long 50    
      .long 0     
      .long 0002
      .long 20
      .long 20
      .long 20
      .long 20
      .long 0
      .long 0003
      .long 10
      .long 30
      .long 0
      .long 10
      .long 0
      .long 0004
      .long 70
      .long 40
      .long 70
      .long 40
      .long 0
      .long 0005
      .long 100
      .long 90
      .long 80
      .long 70
      .long 0