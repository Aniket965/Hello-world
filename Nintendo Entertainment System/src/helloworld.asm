;*********************************************
; NES Hello World
; Made by: Pedro A. Fabri
; Based on Nerdy Nights Tutorials
;*********************************************

;*********************************************
; Variables
;*********************************************
  .rsset $0000

;*********************************************
; NES Header
;*********************************************
  .inesprg 1   ; 1x 16KB PRG code
  .ineschr 1   ; 1x  8KB CHR data
  .inesmap 0   ; mapper 0 = NROM, no bank swapping
  .inesmir 1   ; background mirroring

  
;*********************************************
; Bank 0
;*********************************************
  .bank 0

  .org $C000 

RESET:
  SEI          ; disable IRQs
  CLD          ; disable decimal mode
  LDX #$40
  STX $4017    ; disable APU frame IRQ
  LDX #$FF
  TXS          ; Set up stack
  INX          ; now X = 0
  STX $2000    ; disable NMI
  STX $2001    ; disable rendering
  STX $4010    ; disable DMC IRQs

  JSR vblankwait

clrmem:
  LDA #$00
  STA $0000, x
  STA $0100, x
  STA $0200, x
  STA $0400, x
  STA $0500, x
  STA $0600, x
  STA $0700, x
  LDA #$FE
  STA $0300, x
  INX
  BNE clrmem

  JSR vblankwait

;*********************************************
; Load Palettes
;*********************************************
LoadPalettes:
  LDA $2002             ; read PPU status to reset the high/low latch
  LDA #$3F
  STA $2006             ; write the high byte of $3F00 address
  LDA #$00
  STA $2006             ; write the low byte of $3F00 address
  LDX #$00              ; start out at 0
LoadPalettesLoop:
  LDA palette, x        ; load data from address (palette + the value in x)
  STA $2007             ; write to PPU
  INX                   ; X = X + 1
  CPX #$20              ; Compare X to hex $10, decimal 16 - copying 16 bytes = 4 sprites
  BNE LoadPalettesLoop  ; Branch to LoadPalettesLoop if compare was Not Equal to zero

;*********************************************
; Load Sprites
;*********************************************
LoadSprites:
  LDX #$00              ; start at 0
LoadSpritesLoop:
  LDA sprites, x        ; load data from address (sprites +  x)
  STA $0200, x          ; store into RAM address ($0200 + x)
  INX                   ; X = X + 1
  CPX #$28              ; Compare X to hex $14, decimal 20
  BNE LoadSpritesLoop   ; Branch to LoadSpritesLoop if compare was Not Equal to zero
            
  LDA #%10001000        ; enable NMI, sprites from Pattern Table 1
  STA $2000

  LDA #%00010000        ; enable sprites
  STA $2001

;*********************************************
; Main Logic
;*********************************************

Forever:
  JMP Forever     ;jump back to Forever, infinite loop

;*********************************************
; NMI Interrupt
;*********************************************
NMI:

  LDA #$00
  STA $2003       ; set the low byte (00) of the RAM address
  LDA #$02
  STA $4014       ; set the high byte (02) of the RAM address, start the transfer



  RTI             ; return from interrupt

;*********************************************
; General Functions
;*********************************************
;*********************************************
; VBlank Wait
;*********************************************
vblankwait:
  BIT $2002
  BPL vblankwait
  RTS

;*********************************************
; Read Buttons
;*********************************************

  RTS

;*********************************************
; Bank 1 - DBs
;*********************************************
  .bank 1
  .org $E000

palette:

  .db $0F,$31,$32,$33,$34,$35,$36,$37,$38,$39,$3A,$3B,$3C,$3D,$3E,$0F
  .db $0F,$1C,$15,$14,$31,$02,$38,$3C,$0F,$1C,$15,$14,$31,$02,$38,$3C

sprites:
     ; X  tile  attr  Y
  .db $60, $11, $00, $68   ; H
  .db $60, $0E, $00, $70   ; E
  .db $60, $15, $00, $78   ; L
  .db $60, $15, $00, $80   ; L
  .db $60, $18, $00, $88   ; O
  .db $70, $20, $00, $68   ; W
  .db $70, $18, $00, $70   ; O
  .db $70, $1B, $00, $78   ; R
  .db $70, $15, $00, $80   ; L
  .db $70, $0D, $00, $88   ; D


  .org $FFFA     ;first of the three vectors starts here
  .dw NMI        ;when an NMI happens (once per frame if enabled) the 
  .dw RESET      ;when the processor first turns on or is reset, it will jump
  .dw 0          ;external interrupt IRQ is not used in this tutorial

;*********************************************
; Bank 2 - Graphic Binary
;*********************************************
  .bank 2

  .org $0000

  .incbin "mario.chr"   ;includes 8KB graphics file from SMB1