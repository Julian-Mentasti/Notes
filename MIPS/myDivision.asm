.data


.text
	addi $t0, $zero, 30
	addi $t1, $zero, 5
	
	div $t0, $t1
	
	mflo $s0 #Quotient
	mfhi $s1 #Remainder
	
	li $v0, 1
	add $a0, $zero, $s0
	syscall