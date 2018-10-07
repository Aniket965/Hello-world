.data

message: .asciiz "\nHello, World!\n"

.text

ori $v0, 4
la $a0, message
syscall

ori $v0, 10
syscall
