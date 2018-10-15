#Write an assembly program to print the cube of a given number
.data
n:.asciiz "Enter the number: "
c:.asciiz "The cube is: "
.text
.globl main
main:
la $a0,n
li $v0,4
syscall
li $v0,5
syscall
move $t0,$v0
mul $t1,$t0,$t0
mul $t2,$t0,$t1
la $a0,c
li $v0,4
syscall
la $a0,($t2)
li $v0,1
syscall
li $v0,10
syscall
