bits 64                 ; 64-bit program
default rel             ; Use relative addresses

global _start  	        ; Allow the "_start" function to be globally accessable

section .data           ; Declare variables

    ; Create a cstring with the name "hello"
    ; "db" means that each element is a byte
    ; "10" is the ascii code for newline
    hello: db "Hello, world!", 10

section .text           ; Code goes here

    _start:             ; Label called "_start". In our case it's acting as a function

	mov rax, 1	; Write system call ID
	mov rdi, 1	; Use stdout
	mov rsi, hello	; Message string
	mov rdx, 14	; Number of bytes
	syscall		; Execute system call

	mov rax, 60	; Exit system call ID
	mov rdi, 0	; Return 0
	syscall		; Exit program

