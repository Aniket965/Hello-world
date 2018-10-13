from random import randint
from random import choice
from os import system

def simulacao():

    print("Bem vindo ao simulador do problema de Monty Hall!\n")

    quant_simulacoes = int(input("Digite a quantidade de simulações que você deseja realizar\n"))
    system('cls')

    portas  = cria_portas(quant_simulacoes)
    acertos, erros = jogando_sem_trocar (quant_simulacoes, portas)
    calculo_probabilidade(quant_simulacoes,acertos, erros)

    acertos, erros = jogando_com_trocar(quant_simulacoes, portas)
    calculo_probabilidade(quant_simulacoes, acertos, erros)

    return (0)

def cria_portas(quant_simulacoes):                              #gera uma matriz de portas com valores aleatórios
    portas = []

    for i in range(quant_simulacoes):                           #Gera uma matriz com 3 portas em que somente uma delas está com o valor 1.
        porta = [0, 0, 0]
        porta_correta = randint(0, 2)
        porta[porta_correta] = 1

        portas.append(porta)                                    # Adciona a porta simulada em uma matriz

    return (portas)

def jogando_sem_trocar(quant_simulacoes, portas):               #Modo de jogo em que as portas não são trocadas

    acertos, erros = 0, 0                                       # Iniciando acerto e erros igual a 0

    for i in range(quant_simulacoes):                           #Escolhe um valor, compara com o da porta e contabiliza acertos e erros
        tentativa = randint(0,2)
        if(portas[i][tentativa] == 1):
            acertos = acertos + 1
        else:
            erros = erros + 1

    return (acertos, erros)

def jogando_com_trocar(quant_simulacoes, portas):

    acertos, erros = 0,0                            #Iniciando acerto e erros igual a 0

    for i in range(quant_simulacoes):
        tentativa = randint(0,2)                    #Escolhe uma porta aleatória
        for j in range(3):                          #encontrando a porta correta
            if (portas[i][j] == 1):
                posicao_porta_certa = j

        posibilidades = [0,1,2]                     #Irei utilizar essa lista de possibilidades como para remover uma porta incorreta
        posibilidades.remove(tentativa)             #neste caso o usuário sempre irá trocar de porta quando o apresentador oferecer esta opção, logo a primeira tentativa é removida das possibilidades

        while(len(posibilidades)==2):               #Esse loop serve para retirar uma porta vazia
            aux = choice(posibilidades)             #Guardo em aux uma valor aleatório da possibilidade
            if(aux != posicao_porta_certa):         #Confiro se este valor aleatório não é a resposta certa (Equivalente ao apresetador abrir uma porta vazia)
                posibilidades.remove(aux)           #removo essa porta vazia das possibilidades

        tentativa = choice(posibilidades)           #trocando a porta escolhida, pela porta remanecente

        if(portas[i][tentativa] == 1):
            acertos = acertos + 1
        else:
            erros = erros + 1

    return (acertos, erros)


def calculo_probabilidade(quant_simulacoes, acertos, erros):

    # calculando a probabilidade de acertos sem troca de portas
    prob_Acertos = float(acertos*100)/float(quant_simulacoes)
    # calculando a probabilidade de erros sem troca de portas
    prob_Erros = float(erros*100)/float(quant_simulacoes)

    print("Estatistica de Acertos: {:.1f}%".format(prob_Acertos))
    print("Estatistica de Erros: {:.1f}%".format(prob_Erros))

    print("==~~=="*10)

    return (0)


simulacao()
