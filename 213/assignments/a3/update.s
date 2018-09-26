.pos 0x100
                 ld   $array, r0        # r0 = address of array
                 ld   $2, r1
                 ld   (r0, r1, 4), r1   # t = r1 = array[2]
                 mov  r1, r2            # r2 = array[2]
                 inca r1                # t = t + 4
                 add  r1, r2            # r2 = array[2] + t
                 ld   $1, r3            # r3 = 1
                 st   r2, (r0, r3, 4)   # array[1] = r2 = array[2] + t
                 ld   $0, r3            # r3 = 0
                 st   r1, (r0, r3, 4)   # array[0] = t
                 ld   $t, r3            # r3 = address of t
                 st   r1, (r3)          # t = r1
                 halt                   # halt

.pos 0x1000
t:               .long 0x0              # t = 0
.pos 0x2000
array:           .long 0x8              # array[0] = 8
                 .long 0x5              # array[1] = 5
                 .long 0xa              # array[2] = 10

