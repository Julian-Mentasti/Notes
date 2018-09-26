
.pos 0x100
                 ld   $t, r0              # r0 = addr of t
                 ld   (r0), r1            # r1 = value of t
                 ld   $array, r2              # r2 = addr of a
                 ld   $0x2, r7            # r7 = 8
                 ld   (r2, r7, 4), r3     # r3 = value of a[2]
                 mov  r3, r1              # t = a[2]
                 inc  r1                  # t++
                 inc  r1                  # t++
                 inc  r1                  # t++
                 inc  r1                  # t++
                 st   r1, (r0)            # store memory of t
                 ld   $0x1, r7            # r7 = 4
                 add  r1, r3              # r3 = a[2] + t
                 st   r3, (r2, r7, 4)     # a[1] = r3
                 ld   $0x0, r7            # r7 = 0
                 st   r1, (r2, r7, 4)     # a[0] = r1
                 halt                     # halt

.pos 0x1000
t:               .long 0x0                # t = 0

.pos 0x2000
array:           .long 0x9                # a[0] = 1
                 .long 0xe                # a[1] = 2
                 .long 0x5                # a[2] = 3
