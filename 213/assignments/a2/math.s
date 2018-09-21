.pos 0x100
                 ld $a, r0              # r0 = address of a
                 ld (r0), r1              # r1 = value of a
                 ld $b, r2              # r2 = address of b
                 ld (r2), r3              # r3 = value of b

                 ld $0x1, r4              #loading 1 in
                 add r3, r4              #use r3 and r4 and store in r4
                 shr $0x1, r3             #divide b by 2 and store result in value of b. Now = b/2
                 add r4, r3              # (b+1) + b/2
                 ld (r2), r5             #r5 = value of b
                 and r5, r3              #anding
                 shl $0x2, r3            #shift
                 st r3, (r2)             #store value to a
halt

.pos 0x1000
                    a:               .long 0x7                # sum = 4
                    b:               .long 0xfffffff9                # and = -7