
org 100h
mov bx, offset str
mov cx,0

start:
mov ah,1
int 21h  
cmp al, 0dh
je next
mov [bx],al
inc bx
inc cx
jmp start

next:
dec bx
mov si,offset str
shr cx,1

compare:
mov al,[si]
cmp al,[bx]
jne no
inc si
dec bx
loop compare

mov ah,2
mov dl,0dh
int 21h
mov dl,0ah
int 21h
mov dx,offset pal
mov ah,9
int 21h

jmp exit
no:
mov ah,2
mov dl,0dh
int 21h
mov dl,0ah
int 21h
mov dx,offset notpal
mov ah,9
int 21h
exit:
ret
pal db 'Yes$'
notpal db 'No$'
str db 100 dup(?)


