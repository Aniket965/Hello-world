.data
    str1:	.space 1001
    str2:	.space 1001
    str3:	.space 1001
    prompt:	.asciiz "Enter String.\n"
    prompt1:	.asciiz "Enter Substring.\n"
    prompt2:	.asciiz "The Required String is \n"
    line:	.asciiz "\n"

.text
    main:
        #Prompt user to enter String
        la $a0, prompt
        li $v0, 4
        syscall
        
        #Read String and add Terminator
        la $a0, str1
        li $a1, 1001
        li $v0, 8
        syscall
        
        #Print NewLine
        la $a0, line
        li $v0, 4
        syscall	
        
        #Prompt user to enter SubString
        la $a0, prompt1
        li $v0, 4
        syscall
        
        #Read SubString and add Terminator
        la $a0, str2
        li $a1, 1001
        li $v0, 8
        syscall
        
        #Print NewLine
        la $a0, line
        li $v0, 4
        syscall	
        
    String1Len:
        add $t1,$zero,$zero
        la $a0, str1
        
    lenloop1:
        lb $t2, ($a0)
        beqz $t2, String2Len 
        addi $t1,$t1,1	#$t1 contains length of string
        addi $a0,$a0,1
        j lenloop1

    String2Len:
        add $t3,$zero,$zero
        la $a0, str2
        
    lenloop2:
        lb $t2, ($a0)
        beqz $t2,  go
        addi $t3,$t3,1	#$t3 contains length of substring
        addi $a0,$a0,1
        j lenloop2

    go:
        la $a0, str1
        la $a1, str2
        la $a2, str3
        subi $t1,$t1,1
        #$t1 = strlen(str1)
        add $t2,$t3,$zero
        subi $t2,$t2,1
        #$t2 = strlen(str2)	
        sub $s3,$s3,$s3	#i=0
        sub $t4,$t4,$t4 #j=0
        
        
        
    loop:
        bge $s3,$t1,loopend
        add $t5,$a0,$s3		
        #add $t6,$a1,$zero
        lb  $t7, ($t5)		#str1[i]
        lb  $t8, ($a1)		#str2[0]
        beq $t7,$t8 check
    addd:	sb $t7, str3($t4)	#Add to Str3[j]
        addi $t4,$t4,1		#j++
        addi $s3,$s3,1		#i++
        j loop
        
    check:
        add $t0,$s3,$a0		#str1[i]
        addi $t6,$a1,0		#str2[0]
        addi $t9,$zero,0
        
    loop2:
        beq $t9, $t2 del
        lb $s0, ($t0)
        lb $s1, ($t6)
        bne $s0,$s1 addd
        addi, $t0,$t0,1
        addi, $t6,$t6,1
        addi, $t9,$t9,1
        j loop2

    del:
        add $s3,$s3,$t2
        j loop

    loopend:
        #$t7 = strlen(Str3)
        #
        
        #Prompt to print String
        li $v0,4
        la $a0,prompt2
        syscall
        
        #Printing String
        li $v0,4
        la $a0,str3
        syscall
        
        #Exiting Program
        li $v0, 10
        syscall
