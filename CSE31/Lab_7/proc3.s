
        .data
x:      .word 1
y:      .word 2
z:      .word 3

colon:		.asciiz "z: "
newline:	.asciiz "\n"
pPlusq:		.asciiz "p + q: "

MAIN:   .text
        la $t0, x
        lw $s0, 0($t0)      # $s0 = x
        la $t0, y
        lw $s1, 0($t0)      # $s1 = y
        la $t0, z
        lw $s2, 0($t0)      # $s2 = z

        add $a0, $zero, $s0 # Function argument stores x
        add $a1, $zero, $s1 # Function argument stores y
        add $a2, $zero, $s2 # Function argument stores z

        jal FOO
        add $t0, $s0, $s1
        add $t1, $s2, $v0
        add $s2, $t1, $t0

	li $v0, 4
	la $a0, colon
	syscall

	# print z
        li $v0, 1
        add $a0, $s2, $zero
        syscall
        
	li $v0, 4
	la $a0, newline
	syscall

        j END

FOO:
	addi $sp, $sp, -24
	sw $ra, 0($sp) # ra
	sw $a2, 4($sp) # o
	sw $a1, 8($sp) # n
	sw $a0, 12($sp) # m
	sw $s1, 16($sp) # q
	sw $s0, 20($sp) # p
	# m + o, n + o, m + n
	
	add $t0, $a0, $a2 # m + o
	add $t1, $a1, $a2 # n + o
	add $t2, $a0, $a1 # m + n
	
	add $a0, $t0, $zero # a
	add $a1, $t1, $zero # b
	add $a2, $t2, $zero # c
	
	jal BAR
	add $s0, $v0, $zero
	
	lw $a2, 4($sp) # o
	lw $a1, 8($sp) # n
	lw $a0, 12($sp) # m
	
	# m - o, n - m, n + n
	sub $t0, $a0, $a2 # m -o
	sub $t1, $a1, $a0 # n - m
	add $t2, $a1, $a1 # n + n
	
	add $a0, $t0, $zero
	add $a1, $t1, $zero
	add $a2, $t2, $zero
	
	jal BAR
	add $s1, $v0, $zero
	
	add $t0, $s0, $s1
	li $v0, 4
	la $a0, pPlusq
	syscall

	# print z
        li $v0, 1
        add $a0, $t0, $zero
        syscall
        
	li $v0, 4
	la $a0, newline
	syscall

        add $v0, $t0, $zero
        
	lw $ra, 0($sp) # ra
	lw $a2, 4($sp) # o
	lw $a1, 8($sp) # n
	lw $a0, 12($sp) # m
	lw $s1, 16($sp) # q
	lw $s0, 20($sp) # p
	addi $sp, $sp, 24
        jr $ra

BAR:
	# (b - a) << (c);  
	sub $t0, $a1, $a0
	sllv $v0, $t0, $a2
	jr $ra
	
END:
