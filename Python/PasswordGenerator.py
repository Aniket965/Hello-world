import random

alfabeto = "abcdefghijklmnopqrstuvwxyz"
keyboard = "qwertyuiopasdfghjklzxcvbnm"
num = "0123456789"
xpecial = "@*!%;:."

sizeLetras = (len(alfabeto) - 1)
sizeNum = (len(num) - 1)
fifth = random.randint(0, 1)

def gerarSenha():

    preSenha = []
    fifth = random.randint(0, 1)

    sizeRequired = int(input("Password size: "))
    required = input("Are special characters required?(Y/N) ").upper()

    if required == "Y":
        sizeRequired -= 1
        preSenha.append(xpecial[random.randint(0, (len(xpecial) - 1))])
        

    for i in range (sizeRequired):

        a = random.randint(0, sizeLetras)
        b = random.randint(0, sizeNum)
        
        selection = random.randint(0, 2)
        fifth = random.randint(0, 1)

        if selection == 0:
            if fifth == 0:
                preSenha.append((alfabeto[a].upper()))
            else:
                preSenha.append(alfabeto[a])
        elif selection == 1:
            if fifth == 0:
                preSenha.append((keyboard[a].upper()))
            else:
                preSenha.append(keyboard[a])
        else:
            preSenha.append(num[b])                     

    return preSenha

def validarSenha(preSenha):

    existeNum, existeLower, existeUpper = 0, 0, 0

    for j in range (len(preSenha)):
        
        if preSenha[j] in num:
            existeNum = 1

        if preSenha[j] in alfabeto:
            existeLower = 1
            
        if preSenha[j] in alfabeto.upper():
            existeUpper = 1


    if existeNum == 0:
        preSenha[random.randint(1, (len(preSenha) - 1))] = num[random.randint(0, sizeNum)]
        
    if existeLower == 0:
        preSenha[random.randint(0, (len(preSenha) - 1))] = alfabeto[(random.randint(0, sizeLetras))]
        
    if existeUpper == 0:
        preSenha[random.randint(0, (len(preSenha) - 1))] = alfabeto[(random.randint(0, sizeLetras))].upper()

    return preSenha

def gerarSenhaFinal(preSenha):

    senha = ""
    
    for i in range(len(preSenha)):
        x = random.randint(0, (len(preSenha) - 1))
        senha += preSenha[x]
        preSenha.remove(preSenha[x])
    return senha

def salvarSenha(senha, servico):
    
    file = open("pass.txt", "a")
    file.write("\n" + "-" * 40)
    file.write("\nServices: " + servico)
    file.write("\nPassword: " + senha)
    file.close()

def gerarSenhaPorFrase():

    frase = input("Type a phrase to generate a password(number of words = Password size): ")
    senha = ""

    senha += frase[0]
    
    for i in range(len(frase)):
        if frase[i] == " ":
            senha += frase[i + 1]
    print(senha)
    
def gerarSenhaAleatoria():
    salvar = "X"

    servico = input("What's the service name? ")
    preSenhaFinal = validarSenha(gerarSenha())
    senha = gerarSenhaFinal(preSenhaFinal)
    while salvar != "Y" and salvar != "N":
        salvar = input("Do you wish to save your password?(Y/N) ").upper()

    if salvar == "Y":
        salvarSenha(senha, servico)
    print("Your password is:", senha)

gerarSenhaAleatoria()
