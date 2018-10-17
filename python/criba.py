## Programa 3: Programar la criba de erastotenes
## Implementacion realizada siguiendo el pseudocodigo de Wikipedia: https://es.wikipedia.org/wiki/Criba_de_Erat%C3%B3stenes
import sys
import math

def cribaErastotenes(n):
    marcados = []
    # Aqui tambien casteo porq si no lo interpreta como float -> peta
    for i in range(2,int(math.sqrt(n))):
        if i not in marcados:
            for j in range(i,int(n/i)+1):
                marcados.append(i*j)
    cribados = []

    for i in range(2,n+1):
        if i not in marcados:
            cribados.append(i)

    return cribados

if len(sys.argv) < 2:
    print ("Ademas de llamar al programa indique el numero natural cuyos primos menores desea obtener")
elif len(sys.argv) > 2:
    print ("Demasiados argumentos: Solo indique %s + el numero del que quiera obtener sus primos menores", sys.argv[0])
elif len(sys.argv) == 2 and not sys.argv[1].isdigit():
    print ("Error: Segundo argumento no es un numero")
else:
    # casteo a int porq si no peta 
    #en la llamada a sqrt en la func
    n = int(sys.argv[1])
    primos = cribaErastotenes(n)
    print(primos)



