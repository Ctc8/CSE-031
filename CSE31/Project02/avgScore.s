.data 

orig: .space 100	# In terms of bytes (25 elements * 4 bytes each)
sorted: .space 100

str0: .asciiz "Enter the number of assignments (between 1 and 25): "
str1: .asciiz "Enter score: "
str2: .asciiz "Original scores: "
str3: .asciiz "Sorted scores (in descending order): "
str4: .asciiz "Enter the number of (lowest) scores to drop: "
str5: .asciiz "Average (rounded down) with dropped scores removed: "

spacing: .asciiz " "
newLine: .asciiz "\n"

.text 

# This is the main program.
# It first asks user to enter the number of assignments.
# It then asks user to input the scores, one at a time.
# It then calls selSort to perform selection sort.
# It then calls printArray twice to print out contents of the original and sorted scores.
# It then asks user to enter the number of (lowest) scores to drop.
# It then calls calcSum on the sorted array with the adjusted length (to account for dropped scores).
# It then prints out average score with the specified number of (lowest) scores dropped from the calculation.
main: 
	addi $sp, $sp -4
	sw $ra, 0($sp)
	li $v0, 4 
	la $a0, str0 
	syscall 
	li $v0, 5	# Read the number of scores from user
	syscall
	move $s0, $v0	# $s0 = numScores
	move $t0, $0
	la $s1, orig	# $s1 = orig
	la $s2, sorted	# $s2 = sorted
loop_in:
	li $v0, 4 
	la $a0, str1 
	syscall 
	sll $t1, $t0, 2
	add $t1, $t1, $s1
	li $v0, 5	# Read elements from user
	syscall
	sw $v0, 0($t1)
	addi $t0, $t0, 1
	bne $t0, $s0, loop_in
	
	move $a0, $s0
	jal selSort	# Call selSort to perform selection sort in original array
	
	li $v0, 4 
	la $a0, str2 
	syscall
	move $a0, $s1	# More efficient than la $a0, orig
	move $a1, $s0
	jal printArray	# Print original scores
	li $v0, 4 
	la $a0, str3 
	syscall 
	move $a0, $s2	# More efficient than la $a0, sorted
	jal printArray	# Print sorted scores
	
	li $v0, 4 
	la $a0, str4 
	syscall 
	li $v0, 5	# Read the number of (lowest) scores to drop
	syscall
	move $a1, $v0
	sub $a1, $s0, $a1	# numScores - drop
	move $a0, $s2
	jal calcSum	# Call calcSum to RECURSIVELY compute the sum of scores that are not dropped
	
	# Your code here to compute average and print it
	
	jal calcSum # Call calcSum
	
	div $t0, $v0, $a1
	mflo $t0
	li $v0, 4
	la $a0, str5 # Print string
	syscall
	
	li $v0, 1
	move $a0, $t0
	syscall
	
	
	lw $ra, 0($sp)
	addi $sp, $sp 4
	li $v0, 10 
	syscall
	
	j bottom
	
	
# printList takes in an array and its size as arguments. 
# It prints all the elements in one line with a newline at the end.
printArray:
	addi $sp, $sp, -12	# Push stack frame for local storage
	sw $ra, 0($sp)
	sw $a0, 4($sp)
	sw $a1, 8($sp)
	
	move $t1, $a1 # t1 = length
	move $t0, $a0 
	addi $t2, $zero, 0 # i = 0
	
	loop1: 	bge $t2, $t1, loop2	# i < length
		
		lw $a0, 0($t0)
		li $v0, 1
		syscall
		
		li $v0, 4	# Printing integer
		la $a0, spacing	# Print spacing
		syscall
		
		addi $t2, $t2, 1
		addi $t0, $t0, 4 # Increment i 
		j loop1
	
	loop2:	li $v0, 4	# Printing integer
		la $a0, newLine	# Print new line
		syscall
		
		lw $ra, 0($sp)	# Pop stack frame
		lw $a0, 4($sp)
		lw $a1, 8($sp)
		addi $sp, $sp, 12

		jr $ra
	
# selSort takes in the number of scores as argument. 
# It performs SELECTION sort in descending order and populates the sorted array
selSort:	
	addi $sp, $sp, -20	# Push stack frame for local storage
	sw $ra, 0($sp)
	sw $a0, 4($sp)
	sw $s0, 8($sp)
	sw $s1, 12($sp)
	sw $s2, 16($sp)
	
	addi $t2, $zero, 0 # i = 0
	
	loop3:  bge $t2, $a0, loop4 # i < len 
		la $s0, orig
		la $s1, sorted
		sll $t1, $t2, 2
		add $s0, $t1, $s0
		add $s1, $t1, $s1
		lw $s2, ($s0)
		sw $s2, ($s1)
		
		addi $t2, $t2, 1 # i = i + 1
		
		j loop3
	
	
	loop4: 
	
		addi $t2, $zero, 0 # i = 0
		
	loop5:  addi $t0, $a0, -1 # i < len - 1
		bge $t2, $t0, loop6
		addi $t1, $t2, 0 # maxIndex = i
		
		addi $t3, $t2, 1 # j = i + 1
		
		loop7:  bge $t3, $a0, loop8 # j < len
			la $s1, sorted
			sll $t0, $t3, 2
			add $t0, $t0, $s1
			lw $t0, ($t0) # sorted[j]
			
			sll $t4, $t1, 2
			add $t4, $t4, $s1
			lw $t4, ($t4) # sorted[maxIndex]
			
			ble $t0, $t4, end
			
			add $t1, $zero, $t3 # maxIndex = j
			
			end:  
			addi $t3, $t3, 1 # j = j + 1
			j loop7
				
		loop8:	
		la $s1, sorted 
		
		sll $t4, $t1, 2
		add $t4, $t4, $s1 
		lw $t5, ($t4) # sorted[maxIndex]
		
		sll $t0, $t2, 2
		add $t0, $t0, $s1
		lw $t6, ($t0) # sorted[i]
		
		sw $t6, ($t4)
		sw $t5, ($t0)
			
		addi $t2, $t2, 1
		j loop5
		
		
	loop6:  
	
	lw $ra, 0($sp)
	lw $a0, 4($sp)
	lw $s0, 8($sp)
	lw $s1, 12($sp)
	lw $s2, 16($sp)
	
	addi $sp, $sp, 20	# Push stack frame for local storage
	
	jr $ra
	
	
# calcSum takes in an array and its size as arguments.
# It RECURSIVELY computes and returns the sum of elements in the array.
# Note: you MUST NOT use iterative approach in this function.
calcSum:
	addi $sp, $sp, -12	# Push stack frame for local storage
	sw $ra, 0($sp)
	sw $a0, 4($sp)
	sw $a1, 8($sp)
	
	bgt $a1, $zero, lessThanEqualZero
	
	addi $v0, $zero, 0
	j recursion

	lessThanEqualZero: addi $a1, $a1, -1
			   jal calcSum
			   
			   lw $ra, 0($sp)
			   
			   sll $t1, $a1, 2 # $t1 = len - 1
			   add $t1, $t1, $a0 
			   lw $t2, 0($t1)
			   add $v0, $v0, $t2
			   
			
	recursion: 	# pop stack frame for local storage
			lw $ra, 0($sp)
			lw $a0, 4($sp)
			lw $a1, 8($sp) 
			addi $sp, $sp, 12
	
			jr $ra
				
	
bottom: 
