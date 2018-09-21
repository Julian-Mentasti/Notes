.pos 0x100
                    ld $sum, r0         #r0 = address of sum
                    ld (r0), r1         #r1 = value of sum
                    ld $and, r2         #r2 = address of and
                    ld (r2), r3         #r3 = value of add
                    ld $b, r4           #r4 = address of b

                    ld $0, r5
                    ld $1, r6
                    ld (r4, r5, 4), r7  #r7 = value of b[0]
                    ld (r4, r6, 4), r1  #r0 = value of b[1]
                    add r7, r1          #r1 = b[0] + b[1]
                    st r1, (r0)         #storing r1 into memory at r0

                    ld (r4, r6, 4), r3  #r3 = value of b[1]
                    and r7, r3          #add them and put them in r3
                    st r3, (r2)         #store value back to memory


halt

.pos 0x1000
                    sum:               .long 0x4                # sum = 4
                    and:               .long 0x4                # and = 4
.pos 0x2000
b:                  .long 0xffffffff         # b[0] = -1
                    .long 0xffffffff         # b[1] = -1




