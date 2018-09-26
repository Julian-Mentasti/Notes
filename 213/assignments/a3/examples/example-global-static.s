.pos 0x100
                 ld   $a, r0              # r0 = address of a
                 ld   (r0), r1            # r1 = value of a
                 ld   $b, r2              # r2 = address of b
                 st   r1, (r2, r1, 4)     # b[a] = a
                 inc  r1                  # r1 = r1 + 1 = a + 1
                 st   r1, (r0)            # a = r1
                 halt                     # halt
.pos 0x1000
a:               .long 0x4                # a = 4
.pos 0x2000
b:               .long 0xffffffff         # b[0] = -1
                 .long 0xffffffff         # b[1] = -1
                 .long 0xffffffff         # b[2] = -1
                 .long 0xffffffff         # b[3] = -1
                 .long 0xffffffff         # b[4] = -1
                 .long 0xffffffff         # b[5] = -1
                 .long 0xffffffff         # b[6] = -1
                 .long 0xffffffff         # b[7] = -1
                 .long 0xffffffff         # b[8] = -1
                 .long 0xffffffff         # b[9] = -1
