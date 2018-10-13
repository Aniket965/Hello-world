cpu "8085.tbl"            ;      CPU Table monitor command
hof "int8"                ;      HEX Format

org 9000h                 ;      Puts location pointer at prompt at 9000

;Pneumonics
GTHEX: EQU 030EH          ;      This routinue collects the hex digits entered from keyboard
RDKBD: EQU 03BAH          ;      Reads keyboard.
HXDSP: EQU 034FEH         ;      This routinue expands hex digits for display and stores in the specified buffer
OUTPUT: EQU 0389H         ;      Outputs characters to display
CLEAR: EQU 02BEH          ;      Clears the display 
UPDDT: EQU 044CH          ;      Update data field display using the current data at location FFF9H     
UPDAD: EQU 0440H          ;      Update the address field display using the current address stored at location FFF7H and FFF8H
CURAD: EQU 8FEFH          ;      Displays the number stored in the address field of UPDAD
CURDT: EQU 8FF1H          ;      Stores 8bit data and shows in the Data display.

BEGIN: LXI H,0000H        ;      Begin funtion : loads 0000H into HL register

MIN:                      ;      Min Function ( Minutes function / Shows both Minutes and Hours hand )
SHLD CURAD                ;      Store data in HL at address of CURAD and display it.( minimum clock time is 00hr 00 min)
MVI A,00H                 ;      move 00H to register A ( Initializing A to be 00 )

SEC:                      ;      SEC Function ( Seconds Function )
STA CURDT                 ;      Show content of accumulator on Data Display ( Data Display represents Seconds Hand)
CALL UPDAD                ;      Keep updating Address field all these time

CALL UPDDT                ;      Show the data display
CALL DELAY                ;      Call function DELAY

LDA CURDT                 ;      Load the value in address data display to accumulator 
ADI 01H                   ;      Increment the value of data display by 1( next second increment )
DAA                       ;      Binary decimal adder by 2's complement method
CPI 60H                   ;      Compare the value in accumulator with 60H
JNZ SEC                   ;      If the value in accumulator is not 60 then jump to SEC function 

;If the value of seconds hand is 60 it must be put to 0 and update Minutes hand.

LHLD CURAD                ;      Load the value in Address Display to HL register

MOV A,L                   ;      Move the value in register L to Accumulator
ADI 01H                   ;      Add 01H in accumulator 
DAA                       ;      Binary Addition
MOV L,A                   ;      Move the value in Register L to accumulator

CPI 60H                   ;      Compare the value in accumulator to 60H
JNZ MIN                   ;      If the value in accumulator is not 60 them jump to MIN function

;If the value of seconds hand is 60 it must be put to 0 and update Hours hand.

MVI L,00H                 ;      Move value 00H into L register
MOV A,H                   ;      Move value of H into Accumulator
ADI 01H                   ;      Add 01H in accumulator
DAA                       ;      Binary Addition
MOV H,A                   ;      Move the value in accumulator to Regsiter H

CPI 24H                   ;      Compare the value in accumulator to 24 ( max hour hand is 24 )
JNZ MIN                   ;      If the value in accumulator is not 24 jump to MIN function
JMP BEGIN                 ;      Unconditional jump to BEGIN function 

; If hours hand exceeds 23 we need to change it to 0

DELAY:                    ;      Delay function
MVI C,03H                 ;      Move the value 03H to register C

OUTLOOP:                  ;      OUTLOOP function
LXI D,9FFFH               ;      Loads the value 9FFFH into DE register

INLOOP:                   ;      INLOOP function
DCX D                     ;      decrement the content of memory location DE by 1
MOV A,D                   ;      Move value in register D to Accumulator
ORA E                     ;      OR with value in Register E
JNZ INLOOP                ;      If the flag isn't 1 then go to INLOOP
DCR C                     ;      Contents of memory of C is decremented by 1
JNZ OUTLOOP               ;      As long as the memory of C is not 00H jump to OUTLOOP
RET                       ;      Return 

; Delay of 1 second is brought by function DELAY by calling the required number of times. the frequency is 6.144MHz. 