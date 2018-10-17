org 100h

include 'emu8086.inc'

call PTHIS            ;Llamamos la funcion PTHIS
db 13,10, 'Introduce un numero en hexadecimal:',0 ;La funcion imprime la cadena
call PTHIS            ;Llamamos la funcion PTHIS
db 13,10, 'Hexadecimal:',0 ;La funcion imprime la cadena
MOV DX,5              ;Asignamos el no. max de caracteres aceptados
MOV [SI],0h           ;Inicializamos los primeros registros con 0
MOV [SI+1],0h         ;Inicializamos los primeros registros con 0
MOV [SI+2],0h         ;Inicializamos los primeros registros con 0
MOV [SI+3],0h         ;Inicializamos los primeros registros con 0
CALL GET_STRING       ;Se llama a la funcion GETSTRING
CMP [SI+1],0h         ;Comparamos si+1 con 0 para saber la cant de caracteres
JZ  char1             ;Si es 0 entonces hay un caracter
CMP [SI+2],0h         ;Comparamos si+2 con 0 para saber la cant de caracteres
JZ  char2             ;Si es 0 entonces hay dos caracteres
CMP [SI+3],0h         ;Comparamos si+3 con 0 para saber la cant de caracteres
JZ  char3             ;Si es 0 entonces hay tres caracteres 
CALL convert          ;Llamamos a la siguiente funcion
  
convert: 
MOV AX,0              ;Inicializamos AX=0
MOV BL,[SI]           ;Ponemos en BL lo que hay en la dir de memoria de SI
CMP BL,'A'            ;Comparamos BL con 'A'
JAE letterAF          ;Si es una letra salta a letterAF
SUB BL,48             ;Si no, convierte el ascii a numero en hex  
MOV [result+si], BL   ;Ponemos en [result+SI] lo que obtuvimos en BL
JMP continue          ;Saltamos a continue

letterAF:             ;Convertimos letra a numero 
SUB BL,55             ;Convertimos el ascii de la letra a numero hex 
MOV [result+SI],BL    ;Ponemos en [result+SI] lo que obtuvimos en BL
                      
continue:             ;Continuamos con la conversion
OR AL,BL              ;Limpiamos AL
INC cont              ;Incrementamos cont (nuestro contador)
INC SI                ;Incrementamos tambien SI 
CMP [SI],0            ;Comparamos SI con 0
JNZ convert           ;Si es 0 quiere decir que ya no hay mas por convertir 


hex:                  ;Empezamos a convertir a decimal
LEA SI,[cont]         ;Ponemos en SI la direccion de memoria del contador
CMP [SI],4            ;Comparamos lo que hay en SI con 4 
JZ po4                ;SI=4 quiere decir que se introdujeron 4 caracteres
CMP [SI],3            ;Comparamos lo que hay en SI con 3
JZ po3                ;SI=3 quiere decir que se introdujeron 3 caracteres
CMP [SI],2            ;Comparamos lo que hay en SI con 2
JZ po2                ;SI=2 quiere decir que se introdujeron 2 caracteres
CMP [SI],1            ;Comparamos lo que hay en SI con 1
JMP suma              ;SI=1 quiere decir que ya terminamos y pasamos a suma

                      ;Para la conversion tenemos que:
                      ;16^3 = 4096 º 16^2=256 º 16^1=16 º 16^0=1

po4:                  ;Estamos en el 4to caracter (de der a izq)
MOV CH, 10h           ;Ponemos en CH 10h       
MOV CL,00h            ;Ponemos en CL 00 , asi CX = 4096 
LEA SI,[result]       ;Ponemos en SI la dir de result
MOV AL, result        ;Ponemos en AL lo que hay en result
MUL CX                ;Multiplicamos: AX=AX*CX
MOV [rpo4],AH         ;Movemos a rpo4 lo que hay en AH
MOV [rpo4+1],AL       ;Movemos a rpo4+1 lo que hay en AL para no perder los 16 bits
DEC cont              ;Decrementamos contador
JMP hex               ;Saltamos a hex para ver si hay mas por convertir    

po3:                  ;Estamos en el 3er caracter (de der a izq) 
MOV CH,01h            ;Ponemos en CH 01h 
MOV CL,00h            ;Ponemos en CL 00 y asi CX = 256
LEA SI,[result+1]     ;Ponemos en SI lo que hay en result+1 
MOV AL, result+1      ;En al ponemos lo que hay en result+1
MUL CX                ;Mutiplicamos AX=AX*CX
MOV [rpo3],AH         ;Ponemos en rpo3 lo que hay en AH
MOV [rpo3+1],AL       ;Ponemos en rpo3+1 lo que hay en AL para no perder bits
DEC cont              ;Decrementamos el contador
JMP hex               ;Saltamos a hex para ver si hay mas por convertir  

po2:                  ;Estamos en el 2do caracter (de der a izq)
MOV CH,00h            ;CH = 0    
MOV CL,10h            ;Ponemos en ch 10h y asi en cx = 16 
LEA SI,[result+2]     ;Ponemos en si lo que hay en result+2
MOV AL, result+2      ;Ponemos en al lo que hay en result+2
MUL CL                ;Multiplicamos AX=AX*CX
MOV [rpo2],AH         ;Ponemos en rpo2 lo que hay en ah
MOV [rpo2+1],AL       ;Ponemos en rpo2+a lo que hay en al para no perder bits
DEC cont              ;Decrementamos el contador
JMP hex               ;Saltamos a hex para ver si hay mas por convertir
    

suma:                 ;Funcion para imprimir
LEA SI,[rpo4]         ;Ponemos en SI la direccion de rpo4
MOV BH,[SI]           ;Ponemos en BH lo que hay en SI
MOV BL,[SI+1]         ;Ponemos en BL lo que hay en SI+1
LEA SI,[rpo3]         ;Ponemos en SI la direccion de rpo3
MOV AH,[SI]           ;Ponemos en AH lo que hay en SI
MOV AL,[SI+1]         ;Ponemos en AL lo que hay en SI
ADD AX,BX             ;Sumamos AX = AX + BX
LEA SI,[rpo2]         ;Ponemos en SI la direccion de rpo2
MOV BH,[SI]           ;Ponemos en BH lo que hay en si
MOV BL,[SI+1]         ;Ponemos en BL lo que hay en si+1
ADD AX,BX             ;Sumamos AX = AX + BX
MOV BH,00h            ;Ponemos en BH 00h
MOV BL,[result+3]     ;Ponemos en BL lo que hay en result+3
ADD AX,BX             ;Sumamos AX = AX + BX
CALL print

char1:                ;Se introdujo un caracter, y lo moveremos al final
MOV SI, 0             ;Ponemos en SI 0
MOV BL, [SI]          ;Ponemos en BL el caracter que esta en SI
MOV [SI],30h          ;Limpiamos SI 
MOV [SI+1],30h        ;Limpiamos SI+1 
MOV [SI+2],30h        ;Limpiamos SI+2 
MOV [SI+3],BL         ;Ponemos en SI+3 el caracter que esta en SI
CALL convert          ;Llamamos la siguiente funcion

char2:                ;Se introdujeron 2 caracteres, los moveremos al final
MOV SI, 0             ;Ponemos en SI=0
MOV BL, [SI]          ;Ponemos en BL el caracter que esta en SI
MOV [SI+2],BL         ;Ponemos en SI+2 lo que hay en BL 
MOV BL, [SI+1]        ;Ponemos en BL el caracter que esta en SI
MOV [SI+3],BL         ;Ponemos en SI+3 lo que hay en BL 
MOV [SI],30h          ;Limpiamos SI
MOV [SI+1],30h        ;Limpiamos SI+1
CALL convert          ;Llamamos la siguiente funcion
  
char3:                ;Se introdujeron 3 caracteres, los movemos una posicion
MOV SI, 0             ;Ponemos en SI=0
MOV BL, [SI]          ;Ponemos en BL el caracter que esta en SI
MOV [SI], 30h         ;Limpiamos SI
MOV AL, [SI+1]        ;Ponemos en AL el caracter que esta en SI+1
MOV [SI+1], BL        ;Ponemos en SI+1 lo que guardamos en BL
MOV BL, [SI+2]        ;Ponemos en BL el caracter que esta en SI+2
MOV [SI+2], AL        ;Ponemos en SI+2 lo que guardamos en AL
MOV [SI+3], BL        ;Ponemos en SI+3 lo que guardamos en BL
CALL convert          ;Llamamos la siguiente funcion

print: 
CALL PTHIS            ;Llamamos la funcion PTHIS
db 13,10, 'Numero convertido exitosamente!',0    ;La funcion imprime la cadena
CALL PTHIS            ;Llamamos la funcion PTHIS
db 13,10, 'Decimal:',0;La funcion imprime la cadena
CALL PRINT_NUM_UNS    ;Llamamos la funcion PRINT_NUM_UNS 
                      ;Imprime lo que tenemos en AX
INT 20H               ;Cerramos el programa con la INT 20     
                       
 
DEFINE_PTHIS
DEFINE_GET_STRING 
DEFINE_PRINT_STRING    
DEFINE_PRINT_NUM_UNS 
           
cont db 0  

result db 0,0,0,0 

rpo4 db 0,0
rpo3 db 0,0
rpo2 db 0,0
               
END




