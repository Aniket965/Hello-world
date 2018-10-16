use16               ;Generate 16bit code
org 100h            ;Program starts with byte 100h
 
    mov dx,hello    ;the string adress is in DX
    mov ah,9        ;Number of function in DOS interrupt
    int 21h         ;Calling DOS interrupt
 
    mov ax,4C00h    ;\
    int 21h         ;/ Closing the app
;-------------------------------------------------------
hello db 'Hello, world!$'