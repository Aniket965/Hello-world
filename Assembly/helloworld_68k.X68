*-------------------------------------------------------------------
* Title      : helloworld
* Written by : linuxgemini
* Date       : 2018 - 10 - 14
* Description: Written and tested with EASy68K.
*              The PC value should be 00002018 after execution.
*-------------------------------------------------------------------

    ORG    $2008                            ; set current address to $2008
    
START:                                      ; first instruction of program

    lea     blastfromthepast, a1            ; load variable into address register A1
    move.b  #14, d0                         ; move byte[14] to data register D0
    trap    #15                             ; call hardware interrupt
    SIMHALT                                 ; halt simulator

blastfromthepast DC.B   'Hello, world',0    ; define constant 'Hello, world' with a null terminator at the end

    END    START                            ; last line of source
