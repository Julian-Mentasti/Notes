.pos 0x100
                 ld $t, r0                # r0 = address of t
                 ld (r0), r1              # r1 = value of t
                 ld $array, r2            # r2 = address of array
                 ld   $0x0, r4           # r3 = value of 1
                 ld   $0x1, r5            # r4 = value of 2
                 ld   $0x2, r6            # r5 = value of 3

                 ld (r2, r6, 4), r1      #array[2] into r1
                 st r1, (r0)             #store t's new value
                 inca r1                 #t = t+4
                 st r1, (r0)             #store t's new value
                 ld (r2, r6, 4), r3    #array[2] into r3
                 add r1, r3              #array[2]+t into r3
                 st r3, (r2, r5, 4)    #array[1] = array[2]+t
                 ld (r0), r1             #r1 = t
                 st r1, (r2, r4, 4)    #array[0] = t

halt

.pos 0x1000
t:                  .long 0x0                # t = 0 initially
.pos 0x2000
array:              .long 0xffffffff         # array[0] = -1    initially
                    .long 0xffffffff         # array[1] = -1    initially
                    .long 0xffffffff         # array[2] = -1    initially