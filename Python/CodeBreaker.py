import random
import time
inicio = time.time()
lista = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
         'q', 'r', 's', 't', 'u', 'w', 'v', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F',
         'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'W',
         'V', 'X', 'Y', 'Z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0']

semipassword = random.sample(lista, 3)
password = ''.join(semipassword)
breaker = ''
while password != breaker:
    breaker = random.sample(lista, 3)
    breaker = ''.join(breaker)
    print(breaker)
fim = time.time()
print('\nA senha "{}" foi descoberta em {:.2f}s'.format(breaker, fim - inicio))
