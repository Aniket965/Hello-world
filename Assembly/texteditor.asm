; Text Editor Project
; By Arman @armanatory
; https://github.com/armanatory


;#####  INSTRUCTION  ######
; 
;
;   Key chars from 0-9 , a-z , A-Z to show on the editor
;
;   kye the # to EXIT the program and SAVE the text in root :C:\emu8086\MyBuild by name : ArmanRahimi.txt
;
;   Change the text color by keying - , * , / and +
;
;   Delete the first char by pressing %
;
;   Movement left and right by pressing ! for left and @ for right
;
; 

data segment
    ; add your data here!
    pkey db 0AH,"press any key...$"
    
    current_char db ?
    
    my_string db 100 dup(0),'$' 
    my_string2 db 'hello world.','$'
    
    counter db 0
    counter2 db 0
    
    temp db 0 
    temp_w dw 0
    temp2_w dw 0
    i db 0
    col db 0
    
    front db 0
    rear db 0
    cursor db 0
    
    color db 0ah ; light green BY DEFAULT
    bg_color db 0h ; black green BY DEFAULT
    
    filename db 'ArmanRahimi.txt',0 
    ;buff db "8086 ALP $"
    fhandle dw ? 
    
    path_name db 'e:\mytext.txt',00h
    handel dw ?
    
ends

stack segment
    dw   128  dup(0)
ends

code segment
start:
; set segment registers:
    mov ax, data
    mov ds, ax
    mov es, ax
    main proc near                                                                                                                          
    
       ; call save_text
        
        call clrscr
        
        call get_char
         
        jmp end_program
    main endp
    
    
    
    get_char proc near 
        
        mov ax,0700H
        int 21h
        
        mov current_char, al
        
         
        
        ;check the char participation
        
            ;exit key : #
            cmp current_char,23H ; ASCII code of #
            je end_program
            
            ;color key
            call change_color
            
            call change_bg_color
            
            ;backspace key
            cmp current_char,08H ; ASCII code of BackSpace
            jne next_backspace
            
            call backspace
            jmp show_backspace
            
            next_backspace:
            
            ;arrow key and delete
            ;cmp ah,01H
            ;jne next_arrow       
            
                cmp current_char,40h ; right arrow
                jne next_arrow_check1
                    call right_arrow
                    jmp show_backspace
                
                next_arrow_check1:
                cmp current_char,21h ; left arrow
                jne next_arrow_check2
                    call left_arrow
                    jmp show_backspace
                
                
                next_arrow_check2:
                cmp current_char,25h ; delete key
                jne next_arrow
                    call delete
                    jmp show_backspace 
                    
                    
            next_arrow:
            
            ;check full queue
            cmp counter,100 ; check the queue is full of not
            je unauthorized 
            
            ;enter charecters
            ;check0 - cmp with space
            
            
            ;check1 - cmp with numbers
            check1:
                cmp current_char,30H ; ASCII code of 0
                jb check2
                cmp current_char,39H ; ASCII code of 9
                ja check2
                jmp authorized ; the enterd char is from authorized chars 
                 
            ;check2 - cmp with upper cases
                check2:
                cmp current_char,41H ; ASCII code of A
                jb check3
                cmp current_char,5AH ; ASCII code of Z
                ja check3
                jmp authorized ; the enterd char is from authorized chars 
            
            ;check3 - cmp with lower cases
                check3:
                cmp current_char,61H ; ASCII code of 0
                jb unauthorized
                cmp current_char,7AH ; ASCII code of 9
                ja unauthorized
                jmp authorized ; the enterd char is from authorized chars 
                 
            
        
        authorized:
        call store_char
        
        show_backspace:
            
        call clrscr
        
        call print  
        
        ;call set_cursor
         
        unauthorized:
        JMP get_char
        
        ret
    get_char endp
    
    
    
    clrscr proc
        ;clear screen
        mov ax,0600h
        mov bh,07h
        mov cx,0000h
        mov dx,184fh
        int 10h
                    
        mov ax,0200H
        mov bh,00
        mov dh,20h
        mov dl,20h
        int 10h
        
        ret   
    clrscr endp
    
     
     
     
    print proc
        ;print queue
        
        ;mov ax,0200h
        ;mov dh,15
        ;mov dl,10  
        ;mov bh,00
        
        int 10h
         
        lea bx,my_string

        add bl,front
        mov cl,front
        mov i,cl
        mov cl,counter
        mov ch,0
            
            
        
        ;print_queue:
        ;    mov ax,0200H
        ;    mov dl,[bx]
        ;    int 21h
        ;    add bl,1
        ;    inc i
        ;    mov cl,i
        ;    cmp cl,rear
        ;jb print_queue:

        mov dx,1510
        mov col,0
        
        
        print_queue:
            mov temp2_w,dx
            
            inc col
            
            mov ah, 02h
            mov dh,15
            mov dl,10
            add dl,col
            int 10h
            
            mov ah,09H
            mov dl,[bx]
            
            mov temp_W,0000
            mov temp_w,bx
            
            mov al,dl
            mov bh,00
            mov bl,color
            mov cl,1
            
            int 10h
            ;int 21h
            
            mov bx,0000
            mov bx,temp_w
            
            add bl,1
            inc i
            mov al,i
            cmp al,rear
            
            mov dx,temp_w
            
            
            
        jb print_queue:
        
        call set_cursor
        
        ret 
    print endp
    
    
    
    store_char proc
        mov cl,current_char 
        lea bx,my_string 
        add bl,counter
        mov [bx],cl
        inc counter
            
        cmp counter,30
        jbe flag1_store
        inc front  
        mov cursor,29
            
        flag1_store:
        inc rear
        inc cursor
        
        ret
    store_char endp
    
    
            
    backspace proc 
        lea bx,my_string 
        add bl,counter
        mov [bx],0
        dec counter
            
        cmp counter,30
        jbe flag1_backspace
        dec front  
            
        flag1_backspace:
        dec rear
        dec cursor
        
        ret    
    backspace endp


    
    delete proc ;****************EXTRA OPTION***************
        lea bx,my_string 
        mov [bx],0
        dec counter
            
        cmp counter,30
        ja flag1_delete
        inc front  
            
        flag1_delete:
        
        ret    
    delete endp
    

    set_cursor proc
        
        mov ax,0200h
        mov dh,15
        mov dl,10
        add dl,cursor
        ;inc dl   
        mov bh,00
        
        int 10h
        
        ret
    set_cursor endp

    right_arrow proc
        
        cmp cursor,100
        jae end_right_arrow
        
        inc cursor
        
        mov al,rear
        cmp cursor,al
        jae end_right_arrow
        inc rear
        jmp end_right_arrow2
        
        end_right_arrow:
        dec cursor
        end_right_arrow2:
        
        ret
    right_arrow endp
    
    
    
    left_arrow proc
        
        cmp cursor,0
        jbe end_right_arrow
        
        dec cursor
        
        mov al,front
        cmp cursor,al
        ja end_left_arrow
        
        cmp cursor,0
        jbe left_arrow_flag1
        
        cmp counter,30
        jbe left_arrow_flag2
        dec rear
        
        left_arrow_flag2:
        
        mov al,cursor
        mov front,al
        dec front
        jmp end_left_arrow
        
        left_arrow_flag1:
        mov cursor,0
        
        end_left_arrow:

        ret
    left_arrow endp


        
    save_text proc  ;****************EXTRA OPTION***************
        
            
        mov ax,data
        mov ds,ax
        
        mov ah,3ch;set function number to crate filename 
        xor cx,cx 
        mov dx,seg filename 
        mov ds,dx
        mov dx,offset filename
        int 21h
        
        mov ah,3dh;set function number to open file  
        mov al,1 ; set file access mode as 1 i.e. write access
        mov dx,seg filename
        mov ds,dx
        mov dx,offset filename
        int 21h
        mov fhandle,ax; mov flie handler of file ArmanRahimi.txt to fhandle 
         
        mov ah,40h;mov function number to ah to write into file
        mov dx,seg my_string
        mov ds,dx
        mov dx,offset my_string
        mov bx,fhandle
        mov cx,00 
        mov cl,counter; specify number of bytes to write into file
        int 21h
        
        mov ah,3eh;set function number to close file
        mov bx,fhandle
        int 21h
        
        
        ret
    save_text endp    
                   
                   
                   
    change_color proc ;************EXRTA OPTION**********
         
         cmp current_char,2bh ; ascci code if +
         jne next_color1
            mov color,0AH ; light green
            jmp end_color
         
         
         next_color1:
         cmp current_char,2dh ; ascci code if -
         jne next_color2
            mov color, 0Eh ; yellow
            jmp end_color
            
         
         next_color2:
         cmp current_char,2ah ; ascci code if *
         jne next_color3
            mov color,0Bh ; light cyan
            jmp end_color
         
         
         next_color3:       
         cmp current_char,2fh ; ascci code if /
         jne end_color
            mov color,0Ch ; light red
               
         
         
         end_color:
         
         ret
    change_color endp
    
    
    
    change_bg_color proc ;************EXRTA OPTION**********
        
        cmp current_char,3dh ; ascci code of =
         jne next_bg_color1
            mov bg_color,8H ; dark green
            jmp end_color
         
         
         next_bg_color1:
         cmp current_char,26h ; ascci code of &
         jne next_bg_color2
            mov color, 1h ; blue
            jmp end_color
        
        
        next_bg_color2:    
            
        mov ah,0bh
        mov bh,00
        mov bl, bg_color        
        int 10h
        
        ret
    change_bg_color endp
    
    
    beep proc ;************EXRTA OPTION**********
        
        mov ah, 02
        mov dl, 07h
        int 21h 
        
        int 20h
        
        ret
    beep endp
    
    
    end_program:
    
    call save_text
    call beep
    
    lea dx, pkey
    mov ah, 9
    int 21h        ; output string at ds:dx
    
    ; wait for any key....    
    mov ah, 1
    int 21h
    
    mov ax, 4c00h ; exit to operating system.
    int 21h    
ends

end start ; set entry point and stop the assembler.
