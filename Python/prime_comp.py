def PrintPrimes(n):
  iteracao = 0
  lista = []
  #Preenche a lista só com números ímpares
  for i in range(n):
    iteracao+=1
    if(i % 2 != 0):
      lista.append(i)
      #print (i)
  lista.insert(1, 2)
  
  #percorre a lista de impares com o número "2" adicionado
  for i in lista:
    cont , x = 0 , 1
    while x <= i:
      iteracao+=1
      if(i % x == 0):
        cont+=1
      x+=1
      if (cont>2):
        break
    #Verifica Se tem mais de 2 divisores e imprime
    if (cont==2):
      print (i, " é um número primo!")
  print("Foram necessárias %i comparações!" %iteracao)
#Executa o método com o valor selecionado
PrintPrimes(10000)
