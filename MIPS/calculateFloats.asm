.data
name: .asciiz "Jonnathan\n"
prompt: .asciiz "Enter a number " #000b
space: .asciiz " " #001b
endLine: .asciiz "\n"
.text
.globl main
main:

	lui $a0, 0x1001
	addi $v0, $0, 4
	syscall
	jal readInts
	jal print
	
	addi $v0, $0, 10
	syscall
	
readInts:
	and $s0, $s0, $0
	addi $t0, $a0, 0x0020
	addi $t1, $t0, 40		#array with args $a0
	addi $a0, $a0, 0x000b 		#prompt
	add $t7, $0, $0 		#counter
	top:				#loop 10 times or when negative value
		slt $t2, $t0, $t1	
		beq $t2, $0, end
		addi $v0, $0, 4
		syscall 
		addi $v0, $0, 5
		syscall
		slt $t3, $0, $v0
		beq $t3, $0, end
		sw $v0, 0($t0)
		addi $t7, $t7, 1
		addi $t0, $t0, 4	#move array 1 position
		j top
	
	end:
		addi $a0, $a0, -0x00b	#reset $a0 
		addi $a0,$a0, 0x0020	#start of array index
		add $v0, $0, $t7	#counter returned in v0
		jr $ra
		
averageFloat:
	addi $sp, $sp, -4	#stack pointer storing return address
	sw $ra, 0($sp)
	add $t0, $0, $a0	#start index array
	add $t1, $0, $s7 	#counter
	add $s0, $0, $0		#value of sums
	beq $s7, $0, zero	#if array is empty
	
	topFloat:
		slt $t2, $0, $t1	#iterate and calculate the total sum 
		beq $0, $t2, endFloat
		lw $t3, 0($t0)
		add $s0, $s0, $t3
		addi $t0, $t0, 4
		addi $t1, $t1, -1
		j topFloat
		
	endFloat:
		mtc1 $s0, $f4		#move to c1 to calculate float
		mtc1 $s7, $f5
		div.s $f12,$f4, $f5
		addi $v0, $0, 2
		syscall
		lw $ra, 0($sp)		#restore the stack 
		addi $sp, $sp, 4
		jr $ra
	zero:
		mtc1 $0, $f12		#print 0.0
		addi $v0, $0, 2
		syscall
		jr $ra
	
	
print:
	addi $sp, $sp, -4	#stack pointer storing return address
	sw $ra, 0($sp)
	add $t0, $0, $a0	#start index array
	add $t1, $0, $v0 	#counter
	add $s0, $0, $0		#value of sums
	add $s7, $0, $v0	#counter 
	addi $t7, $0, 4
	mult $t7, $t1
	mflo $t7		#array range
	lui $t6, 0x1001
	addi $t6, $t6, 0x001b	#tab
		
	topPrint:
		slt $t2, $0, $t1	#iterate on the array and print values
		beq $0, $t2, endPrint
		lw $t3, 0($t0)
		addi $v0, $0, 1
		add $a0, $0, $t3
		syscall 
		add $a0, $0, $t6
		addi $v0, $0, 4
		syscall			#print the space for numbers
		add $s0, $s0, $t3
		addi $t0, $t0, 4
		addi $t1, $t1, -1
		j topPrint
	endPrint:
		lui $a0, 0x1001		#print new line
		addi $a0, $a0, 0x001d
		addi $v0, $0, 4
		syscall
		or $a0, $0, $t0
		sub $a0, $a0, $t7	#reset a0 to the start of the array
		jal averageFloat	#get average
		lw $ra, 0($sp)		#restore stack
		addi $sp, $sp, 4
		jr $ra
	
	
	
