main:
	li $v0 5
	syscall
	move $t0 $v0
	
	move $t1 $t0
	addu $t2 $zero 1
	
	loop:
		beq $t0 $t2 exit
		mul $t1 $t1 $t2
		add $t2 $t2 1
		b loop
	
	exit:
		move $a0 $t1
		li $v0 1
		syscall
		
		li $v0 10
		syscall
