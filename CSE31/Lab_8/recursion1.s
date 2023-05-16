.data

str:	.asciiz "Please enter a number: "

.text
main:		addi $sp, $sp, -4	# Moving stack pointer to make room for storing local variables (push the stack frame)
	
		li $v0, 4		# Display input prompt
		la $a0 str
		syscall

		addi $v0, $zero, 5	# Read user input
		syscall
		add $a0, $v0, $zero

		jal recursion		# Call recursion
		
		sw $v0, 0($sp)
		li $v0, 1
		lw $a0, 0($sp)
		syscall

		j end
	

recursion:	addi $sp, $sp, -12	# Push stack frame for local storage
		sw $ra, 0($sp)
		
		addi $t0, $zero, -1
		bne $a0, $t0, not_minus_one
		
		addi $v0, $zero, 3
		
		j end_recur	

not_minus_one:	
		addi $t0, $zero, -2
		bgt $a0, $t0, greater_than_two
		
		beq $a0, $t0, equal_minus_two
	
		addi $v0, $zero, 2	
	
		j end_recur	

equal_minus_two:	addi $v0, $zero, 1

			j end_recur


greater_than_two: 	 sw $a0, 4($sp)
			 addi $a0, $a0, -3
			 
			 jal recursion 	# Call recursion (m - 3)
			 
			 sw $v0, 8($sp)
			 
			 lw $a0, 4($sp)
			 addi $a0, $a0, -2
			 
			 jal recursion  # Call recursion (m - 2)
			 lw $a0, 4($sp)
			 
			 lw $t0, 8($sp)
			 
			 add $v0, $t0, $v0
			 add $v0, $v0, $a0
			 
			 j end_recur
			 
# End of recursion function	
end_recur: # TPS 2 #15 
	lw $ra, 0($sp)
	addi $sp, $sp, 12	# Pop stack frame 
	jr $ra

# Terminating the program
end:	addi $sp, $sp 4		# Moving stack pointer back (pop the stack frame)
	li $v0, 10 
	syscall
