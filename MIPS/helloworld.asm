.data
	hello: .asciiz "Hello world!"

.text
	li $v0,4
	la $a0,hello
	syscall
	