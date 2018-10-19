.pos 0x100
                 ld $s, r0  #r0 = address of s
                 ld $i, r2  #r2 = address of i
                 ld (r2), r2  #r2 = i
                 ld (r0, r2, 4), r0  #r0 = s.x[i]
                 ld $v0, r1   #r1 = address of v0
                 st r0, (r1)  #v0 = s.x[i]

                 ld $s, r0  #r0 = address of s
                 ld 8(r0), r0  #r0 = s.y address
                 ld $i, r2  #r2 = address of i
                 ld (r2), r2  #r2 = i
                 ld (r0, r2, 4), r0  #r0 = s.y[i]
                 ld $v1, r1   #r1 = address of v1
                 st r0, (r1)  #v1 = s.x[i]

                 ld $s, r0  #r0 = address of s
                 ld 12(r0), r0  #r0 = s.z address
                 ld $i, r2  #r2 = address of i
                 ld (r0, r2, 4), r0  #r0 = s.z->x[i]
                 ld $v2, r1   #r1 = address of v2
                 st r0, (r1)  #v2 = s.z->x[i]

                 ld $s, r0  #r0 = address of s
                 ld 12(r0), r0  #r0 = s.z address
                 ld $i, r2  #r2 = address of i
                 ld 12(r0), r0  #r0 = s.z->z
                 ld 8(r0), r0   #r0 = s.z->z.y (pointer)
                 ld (r0, r2, 4), r0  #r0 = s.z->z->y[i]
                 ld $v2, r1   #r1 = address of v3
                 st r0, (r1)  #v3 = s.z->z->y[i]


                 halt


.pos 0x2000
static:
i:  .long 0
v0: .long 0
v1: .long 0
v2: .long 0
v3: .long 0
s:  .long 0    # x[0]
    .long 0    # x[1]
    .long 0x3000 # y (pointer)
    .long 0x3008 # z (pointer)


.pos 0x3000
heap:
s_y: .long 0 # s.y[0]
     .long 0 # s.y[1]
s_z: .long 0 # s.z->x[0]
     .long 0 # s.z->x[1]
     .long 0 # s.z->y
     .long s_z_z # s.z->z
s_z_z:
     .long 0 # s.z.z->x[0]
     .long 0 # s.z.z->x[1]
     .long s_z_z_y # s.z.z->y (pointer)
     .long 0x3300 # s.z.z.z
s_z_z_y:
     .long 0 # s.z.z.y[0]
     .long 0 # s.z.z.y[1]