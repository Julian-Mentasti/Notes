.pos 0x100
                 ld   $a, r0              # r0 = address of a
                 ld   (r0), r1            # r1 = value of a
                 ld   $b, r2              # r2 = address of b
                 ld   (r2), r2            # r2 = value of b = address of b[0]
                 st   r1, (r2, r1, 4)     # b[a] = a
                 inc  r1                  # r1++
                 st   r1, (r0)            # a = r1
                 halt                     # halt
.pos 0x1000
a:               .long 0x4                # a
.pos 0x2000
b:               .long 0x00003000         # address of b[0]; loaded dynamically
.pos 0x3000
b_data:          .long 0xffffffff         # b[0]
                 .long 0xffffffff         # b[1]
                 .long 0xffffffff         # b[2]
                 .long 0xffffffff         # b[3]
                 .long 0xffffffff         # b[4]
                 .long 0xffffffff         # b[5]
                 .long 0xffffffff         # b[6]
                 .long 0xffffffff         # b[7]
                 .long 0xffffffff         # b[8]
                 .long 0xffffffff         # b[9]
