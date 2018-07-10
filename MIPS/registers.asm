.data
	newLine: .asciiz "\n"
.text
	main: 
		addi $s0, $zero, 20
		
		jal increaseMyRegister
		
		
		#print the new line
		li $v0, 4
		la $a0, newLine
		syscall
		
		#Print Value
		li $v0, 1
		move $a0, $s0
		syscall
	
	#This line is going to singal the end of the programme. 
	li $v0, 10
	syscall
	
	increaseMyRegister:
		addi $sp, $sp, -4 #allocating four bytes, its negative because you are allocating
		sw $s0, 0($sp) #store the value in the stack
		
		addi $s0, $s0, 30 # 10 + 30
		
		#print new value in function
		
		li $v0, 1
		move $a0, $s0
		syscall
		
		lw $s0, 0($sp)
		addi $sp, $sp, 4 #restore the stack
		
		jr $ra
		
		#Prevents the modification of the s register