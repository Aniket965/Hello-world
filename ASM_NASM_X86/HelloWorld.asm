org 0x7c00
jmp 0x0000:start

hello db 'Hello, World!', 13, 10, 0

start:
	xor ax, ax 
	mov ds, ax
	mov es, ax

	mov ah,0 
	mov al,0x12
	int 10h

	;mov ah,0xb
	;mov bh,0
	;mov bl,9
	;int 10h

	;codigo
	mov bl,1
	mov si, hello
	call print_string 

	jmp done

print_string:
	lodsb
	cmp al,0
	je .done

	mov ah, 0eh
	mov bh,0
	inc bl
	int 10h

	jmp print_string

	.done:
		ret

done:
	jmp $ 

times 510 - ($ - $$) db 0
dw 0xaa55
