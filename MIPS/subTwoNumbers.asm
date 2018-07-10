.data
	number1: .word 5
	number2: .word 10
.text
	lw $s0, number1
	lw $s1, number2
	
	sub $t0, $s0, $s1 # t2 = t0 + t1
	
	li $v0, 1
	move $a0, $t0 #move whats in t0
	syscall 