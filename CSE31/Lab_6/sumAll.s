.data
input:  	.asciiz "Please enter a number: "
sumOfEven: 	.asciiz "Sum of even numbers is: "
sumOfOdd:	.asciiz "\nSum of odd numbers is: "
.text

main: 		li $v0, 4 		# Get user input
		la $a0, input		# Store input
		syscall
		la $v0, 5		# Read integer
		syscall
		add $t0, $v0, $zero 	# Add $v0 into $t0 
		
loop:		beq $v0, $zero, print	# Branch if equal to 0
		srl $t1, $t0, 1		# Bit shift right (Dividing by 2)
		sll $t1, $t1, 1		# Bit shift left (Multiplying by 2)
		
		beq $t1, $t0, odd	# If odd
		bne $t1, $t0, even	# If even
		
		li $v0, 4
		la $a0, input
		syscall
		la $v0, 5
		syscall
		add $t0, $v0, $zero
					
		j loop
		
		
even:		add $t2, $t2, $v0	# Add even numbers
		j main
		
odd:		add $t3, $t3, $v0	# Add odd numbers
		j main
		
		
print: 		li $v0, 4
		la $a0, sumOfEven 	# Print even sum
		syscall
		li $v0, 1
		la $a0, 0($t3)
		syscall
		
		li $v0, 4
		la $a0, sumOfOdd	# Print odd sum
		syscall	
		li $v0, 1
		la $a0, 0($t2)
		syscall	
