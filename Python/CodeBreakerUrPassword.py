import random
import time
lista = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
         'q', 'r', 's', 't', 'u', 'w', 'v', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F',
         'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'W',
         'V', 'X', 'Y', 'Z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0']


password = str(input('Digite a senha (Quanto maior, mais tempo irá levar): '))
breaker = ''
inicio = time.time()
cout = 0
while password != breaker:
    breaker = random.sample(lista, len(password))
    breaker = ''.join(breaker)
    print(breaker)
    cout += 1
fim = time.time()
print('\nA senha "{}" foi descoberta em {:.2f}s'.format(breaker, fim - inicio))
print(cout)