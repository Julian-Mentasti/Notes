.pos 0x100
main:            ld   $btm, r5       # r5 = addr bottm of stack
                 inca r5             # r5 = addr of next value of stack
                 gpc  $0x6, r6       # save the return address
                 j    copy           # jump to copy
                 halt                     

copy:            ld $0xfffffff4, r0     # r0 = -12 back three frames
                 add r0, r5              # move the btm three spots back
                 st r6, 0x8(r5)         # save the return address
                 ld $0, r2              # r2 = 0 the i counter

loop:            ld $arr, r0          # r0 = &arr
                 ld (r0, r2, 4), r0   # r0 = arr[i]
                 beq r0, end           # if arr[i] == 0 goto end

                 st r0, (r5, r2, 4)   # btm[i] = arr[i]
                 inc  r2                # i++

                 br   loop              # goto beginning of while loop

end:        ld   $0, r0               # r0 = 0
                 st r0, (r5, r2, 4) # dst[i] = 0

                 ld   8(r5), r6           # load return address from stack
                 ld   $12, r0             # r0 = 12 = sizeof callee frame
                 add  r0, r5              # deallocate copy's frame (callee)
                 j    0x0(r6)             # return
.pos 0x1000
arr:             .long 0x1                # arr[0]
                 .long 0x2                # arr[1]
                 .long 0x100c             # address of the next address
                 .long 0x0000FFFF # addr val
                 .long 0xFFFF0100
                 .long 0xFFFFFFFF
                 .long 0x0200FFFF
                 .long 0xFFFF0300
                 .long 0xFFFFFFFF
                 .long 0x0400FFFF
                 .long 0xFFFF0500
                 .long 0xFFFFFFFF
                 .long 0x0600FFFF
                 .long 0xFFFF0700
                 .long 0xFFFFFFFF
                 .long 0xF0000000 #l


.pos 0x250
stackTop:        .long 0x0
                 .long 0x0
btm: .long 0x0