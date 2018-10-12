import random

def resposta(nresp):
    if nresp== 1:
        return('Esta correto')
    elif nresp == 2:
        return('Quase certo')
    elif nresp == 3:
        return('Sim')
    elif nresp == 4:
        return('Tente novamente')
    elif nresp == 5:
        return('Não foi dessa vez')
    
for i in range(5):
    sorte = resposta(random.randint(1, 5))
    print(sorte)

print('gato', 'gatorro', 'papagaio', end='') #retira a quebra de linha
print('Olar')
print('gato', 'gatorro', 'papagaio', sep='/') # separa os carac com o que quiser
