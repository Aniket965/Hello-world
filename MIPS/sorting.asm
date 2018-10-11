.text	
	.globl __start
__start:
	la $a0,askc
	li $v0,4
	syscall
	li $v0,5
	syscall
	sw $v0,count
	move $t7,$v0
	add $t7,$t7,1
	li $t8,1
	la $t0,array
lask:	la $a0,ask
	li $v0,4
	syscall
	
	move $a0,$t8
	li $v0,1
	syscall
	la $a0,thing
	li $v0,4
	syscall
	li $v0,5
	syscall
	sw $v0,($t0)
	add $t0,$t0,4
	add $t8,$t8,1
	bne $t8,$t7,lask
	la $t0,array
	la $t1,arrys
	lw $t2,count
	lw $t3,($t0)
	la $t4,0 #outer loop count
	la $t5,1
	#la $t0,array
loopi:	lw $t6,($t0)
	ble $t3,$t6,noswap
	move $t3,$t6
noswap:	add $t0,$t0,4
	add $t4,$t4,1
	ble $t4,$t2,loopi
	sw $t3,($t1)
	add $t1,$t1,4
	la $t4,1
loop1:	#la $t3,0
	la $t0,array
	lw $t6,($t0)
	add $t0,$t0,4
	la $t5,1
loop2:	lw $t7,($t0)
	j if1
back:	add $t5,$t5,1
	add $t0,$t0,4
	ble $t5,$t2,loop2
	sw $t6,($t1)
	add $t1,$t1,4
	add $t4,$t4,1
	move $t3,$t6
	ble $t4,$t2,loop1
	j endsort
	
if1:	ble $t7,$t6,if2
	j elif
if2:	ble $t7,$t3,back
swt:	move $t6,$t7
	j back
elif:	ble $t6,$t3,swt
	j back
endsort:
	la $t0,arrys	
	lw $t4,count
	add $t4,$t4,1
	la $t8,1
prnum:	la $a0,de
	li $v0,4
	syscall
	
prr:	move $a0,$t8
	li $v0,1
	syscall
	la $a0,thing
	li $v0,4
	syscall
	lw $a0,($t0)
	li $v0,1
	syscall
	la $a0,endl
	li $v0,4
	syscall
	add $t0,$t0,4
	add $t8,$t8,1
	beq $t8,$t4,dn
	j prr
dn:	li $v0,10	
	syscall
	.data
array:	.space 80
arrys:	.space 80
count:	.word 0
askc:	.asciiz "Enter count: "
ask:	.asciiz "Enter number "
thing:	.asciiz ": "
de:	.asciiz "Sorted array:\n"
endl:	.asciiz "\n"
