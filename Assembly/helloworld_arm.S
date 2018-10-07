msg:                                                                                    
        .ascii "Hello, World!\n"       
len = . - msg                                                                           
                                                                                        
.text                                                                                   
        .globl  main                                                                    
main:                                                                                   
        mov     r2, #len                                                                
        ldr     r1, msgaddr                                                             
        mov     r0, #1                                                                  
        mov     r7, #4                                                                  
        swi     #0                                                                      
                                                                                        
        .align  4
msgaddr:
        .long   msg

