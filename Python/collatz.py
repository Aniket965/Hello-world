#Sequencia de Collatz
"""
Escreva uma função chamada collatz () que tenha um parâmetro chamado number. E se
number is even, então collatz () deve imprimir o número // 2 e retornar este valor.
Se o número for ímpar, então collatz () deve imprimir e retornar 3 * number + 1.
"""

def collatz(n):
    if n % 2 == 0:
        n = n / 2
        return int(n)
    else:
        n = 3 * n + 1
        return int(n)

# captura o numero e verifica se não é letra
num = 0
while num == 0:
    try:
        num = int(input('Digite um número: '))
    except ValueError:
        print('Digite um numero, não letras')

#chama a função primeira vez
num = collatz(num)
loop = 1

#loop para chegar ao numero 1
while num != 1:
    print('Tentando outra vez o número foi: ' +str(num)+', loop numero: ' + str(loop))
    num = collatz(num)
    collatz(num)
    loop = loop + 1

print('1,')
