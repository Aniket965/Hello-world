def spam():
    global egg      #mudará o valor da varialvel GLOBAL
    print(egg)      #antes da mudança
    egg = 'Hello World!'    #depois da mudança

egg = 'GLOBAL'
spam()
print(egg)
