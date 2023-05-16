.data
n:	.word 25
str1: 	.asciiz "Less than\n"
str2: 	.asciiz "Less than or equal to\n"
str3: 	.asciiz "Greater than\n"
str4: 	.asciiz "Greater than or equal to\n"

.text
main: 	li	$v0, 5			   # Take in an integer
		syscall
		add $s1, $v0, $zero	   # Add v0 into s1
		lw $s2, n		   # Load value of n into s2
		
		ble $s1, $s2, lessThan	   # Branch if less than
		bge $s1, $s2, greaterEqual # Branch if greater than or equal
		bgt $s1, $s2, greaterThan  # Branch if greater than
		ble $s1, $s2, lessEqual	   # Branch if less than or equal
		
	
lessThan:	la $a0, str1
		j print

greaterEqual:	la $a0, str4
		j print

greaterThan:	la $a0, str3
		j print

lessEqual:	la $a0, str2
		j print
		
print: 		li $v0, 4
		syscall
