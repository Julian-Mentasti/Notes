.pos 0x100
        ld $array, r0 # r0 = addr of arr
        ld (r0), r0 # r0 is addr of arr
        ld (r0, $2, 4), r1 # t = arr[2]
        mv r1, r2 # r2 = arr[2]
        inca r1 # t += 4
        add r1, r2 # r2 += t
        st r2, (r0, $1, 4) # arr[1] = arr[2] + t
        st r1, (r0, $0, 4) # arr[0] = t
        ld $t, r3 # r3 = addr of t
        st r1, (r3) # t = r1
        halt # end

.pos 0x1000
t:      .long 0x0 # t = 0
.pos 0x1004
array:  .long 0x3000 # array = 0x3000

.pos 0x3000
array_data: .long 0x7 # array[0] = 7 
            .long 0x2 # array[1] = 2
            .long 0xb # array[2] = 11
