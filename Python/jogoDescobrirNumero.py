#Jogo para adivinhar o numero

import random

numeroSecreto = random.randint(1, 20)
print('Vou pensar em um numero de 1 até 20')

#Peça para o jogador adivinhar 6 vezes
for tentativas in range(1,7):
    print('Tente uma vez')
    tentativa = int(input())

    if tentativa < numeroSecreto:
        print('Numero muito baixo')
    elif tentativa > numeroSecreto:
        print('Numero muito alto')
    else:
        break  #condição caso o numero esteja correto

if tentativa == numeroSecreto:
    print('Parabéns você acerto na ' +str(tentativas) +' tentativa')
else:
    print('Errado eu pensei no número ' +str(numeroSecreto))

