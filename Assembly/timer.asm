CPU "8085.TBL"            ;      CPU Table monitor command
HOF "INT8"                ;      HEX Format

ORG 8FBFH                 ;      Required for Interrupt
JMP RESUME                ;      Unconditional Jump to RESUME

;Pneumonics
ORG 9000h                 ;      Puts location pointer at prompt at 9000
GTHEX: EQU 030EH          ;      This routinue collects the hex digits entered from keyboard
RDKBD: EQU 03BAH          ;      Reads keyboard.
HXDSP: EQU 034FEH         ;      This routinue expands hex digits for display and stores in the specified buffer
OUTPUT: EQU 0389H         ;      Outputs characters to display
CLEAR: EQU 02BEH          ;      Clears the display
UPDDT: EQU 044CH          ;      Update data field display using the current data at location FFF9H
UPDAD: EQU 0440H          ;      Update the address field display using the current address stored at location FFF7H and FFF8H
CURAD: EQU 8FEFH          ;      Displays the number stored in the address field of UPDAD
CURDT: EQU 8FF1H          ;      Stores 8bit data and shows in the Data display.

MVI A,0BH                 ;      0BH is used for RST 7.5
SIM                       ;      Set Interrupt
EI                        ;      Enable Interupt

BEGIN:                    ;      Function BEGIN
MVI B,00H                 ;      move the value 00 to Register B
CALL GTHEX                ;      Collects digits from keyboard
MOV L, E                  ;      Move the value in Register E to L
MOV H, D                  ;      Move the value in Register D to H
SHLD CURAD                ;      Store values in HL registers in Address Field and displays it.
MVI B,01H                 ;      Move the value 01H into register B
CALL GTHEX                ;      Collects digits from Keyboard
MOV A, E                  ;      Move the value of register E to Accumulator
JMP SEC                   ;      Unconditional jump to SEC function

MIN:                      ;      Function MIN
SHLD CURAD                ;      Store values in HL registers in Address Field and displays it.

MVI A,59H                 ;      Move the value 59H to Accumulator

SEC:                      ;      Function SEC
STA CURDT                 ;      Show content of accumulator on Data Display ( Data Display represents Seconds Hand)
CALL UPDAD                ;      Keep updating Address field all these time
CALL UPDDT                ;      Show the data display


CALL DELAY                ;      Call function DELAY

LDA CURDT                 ;      Load the value in address data display to accumulator
ADI 99H                   ;      Increment the value of data display by 99(  Effectively One decrease )
DAA                       ;      Binary decimal adder by 2's complement method  ( Decimal Adjust Accumulator)     
CPI 99H                   ;      Compare the value in accumulator with 99H
JNZ SEC                   ;      If the value isn't 99H then jump to SEC function

;If the value of seconds hand is 0 it must be put to 59 and update Minutes hand.
LHLD CURAD                ;      Load the value in Address Display to HL register

MOV A,L                   ;      Move the value in register L to Accumulator
ADI 99H                   ;      Increment the value of data display by 99( Effectively One decrease )
DAA                       ;      Binary decimal adder by 2's complement method  ( Decimal Adjust Accumulator)
MOV L,A                   ;      Move the value in accumulator to Regsiter L
CPI 99H                   ;      Compare the value in accumulator with 99H
JNZ MIN                   ;      If the value isn't 99H then jump to MIN function

MVI L,59H                 ;      Move 59H value into Register L
MOV A,H                   ;      Move the value in Register H to accumulator
ADI 99H                   ;      Increment the value of data display by 99( Effectively One decrease )
DAA                       ;      Binary decimal adder by 2's complement method  ( Decimal Adjust Accumulator)
MOV H,A                   ;      Move the value in Accumulator to Register H

CPI 99H                   ;      Compare the value in accumulator with 99H    
JNZ MIN                   ;      If the value isn't 99H then jump to MIN function
MVI H, 00H                ;      Move the value 00H into register H
MVI L, 00H                ;      Move the value 00H into register L
MVI A, 00H                ;      Move the value 00H into Accumulator
JMP BEGIN                 ;      Unconditional Jump to BEGIN function

DELAY:                    ;      Delay Function
MVI C,03H                 ;      Move 03H value to C

OUTLOOP:                  ;      OUTLOOP Function
LXI D,9FFFH               ;      Loads the value 9FFFH into DE registers

INLOOP:                   ;      INLOOP Function
DCX D                     ;      Decrement the value in DE by 1
MOV A,D                   ;      Move the value in register D to accumulator
ORA E                     ;      OR Accumulator with Register E
JNZ INLOOP                ;      If the result isn't one jump to INLOOP
DCR C                     ;      Decrement the value in Register D by 1
JNZ OUTLOOP               ;      As long as the memory of C is not 00H jump to OUTLOOP
RET                       ;      RET

RESUME:                   ;      Function RESUME
CALL RDKBD                ;      Call Read keyboard
EI                        ;      Enable Interupt
LDA CURDT                 ;      Load the value in address data display to accumulator     
JMP SEC                   ;      Unconditional Jump to SEC Function


; The logic used is after 0 it goes to 99 when 99 comes compare and make it 59 and for delay make it repeat so that the clock total clock cycles amount to 1 sec ( frequency 6.44MHz)