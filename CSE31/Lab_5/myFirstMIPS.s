.data
.text

main:   add $t0, $s0, $zero 	#$t0 = $s0
        sub $t1, $t0, 7		#$t1 = $t0 - 7
        add $t2, $t1, $t0	#$t2 = $t1 + $t0
        addi $t3, $t2, 2	#$t3 = $t3 + 2
        add $t4, $t3, $t2	#$t4 = $t3 + $t2
        sub $t5, $t4, 28	#$t5 = $t4 - 28
        sub $t6, $t4, $t5	#$t6 = $t4 - $t5
        addi $t7, $t6, 12	#$t7 = $t6 + 12
	li      $v0, 10		# End program
		syscall