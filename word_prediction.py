from collections import Counter
import random
file_1=open("word.txt")
l_1=file_1.read()
l_1=l_1.split("\n")
print("------------------")
print("All the lines printed in the line that are given in file")
print("\n \n")
for i in range(len(l_1)):
    l_1[i]=(l_1[i]).strip()
    print(l_1[i])
print("------------------")
print("Made the list of all the lines given")
print("\n \n")
print(l_1)
d={}
l_2=[]
for i in range(0,len(l_1)):
    var=l_1[i].split(" ")
    if var!='':
        l_2.append(var)
l_2=l_2[:-1:]
print("------------------")
print("Made the list of list which seperates each line and each word in the given line")
print("\n \n")



for i in range(0,len(l_2)):
    for j in range(0,len(l_2[i])-1):
        if l_2[i][j] not in d:
            d[l_2[i][j]]=str(l_2[i][j+1])+" "
        else:
            d[l_2[i][j]]+=str(l_2[i][j+1])+" "

for k,v in d.items():
    v=(v.strip()).split()
    d[k]=dict((Counter(v)))
print("------------------")
print("Made the dictionary of dictionary against each words and value is a dictionary again with value of number of times word is occuring")
print("\n \n")
print(d)

gab=[]
def f(i_1):
    try:
        if len(gab)<3:
            ls=[]
            a=0
            z=d[i_1]
            var_1=0
            print(z)
            for k,v in z.items():
                var_1+=v   
            for k,v in z.items():
                a+=v/var_1  
                ls.append(a)
            arand=random.uniform(0,1)
            print("------------------")
            print("This is a random number")
            print(arand)
            print("This is the list of cummulative frequency of probability")
            print(ls)
            for i in range(0,len(ls)-1):
                if arand<=ls[i]:
                    a=ls[i]
                    break
                elif ls[i]<=arand<=ls[i+1]:
                    a=ls[i+1]
                    break
            a=ls.index(a)
            ls=[]
            for k,v in z.items(): 
                ls.append(k)
            k=ls[a]
            gab.append(k)
            print(f(k))
        elif len(gab)>=3:
            return False
    except:
        return False
print("")
i_1=input("Enter the word to predict next words:  ")
f(i_1)
print(gab)
print("------------------")
print("The final word is:",end=" ")
print(i_1+" "+" ".join(gab))


l_3=[]
a=""
for j in range(0,len(l_2)):
  a=""
  for i in range(0,len(l_2[j])-1):
    a+=l_2[j][i]+" "+l_2[j][i+1]+"\n"
  l_3.append((a.split("\n"))[:-1])
      
d_1={}
for i in range(0,len(l_3)):
    for j in range(0,len(l_3[i])-1):
        if l_3[i][j] not in d_1:
            d_1[l_3[i][j]]=str(((l_3[i][j+1]).split())[1])+" "
        else:
            d_1[l_3[i][j]]+=str(((l_3[i][j+1]).split())[1])+" "

for k,v in d_1.items():
    v=(v.strip()).split()
    d_1[k]=dict((Counter(v)))
print(d_1)
gab=[]
def gg(i_1):
     try:
        if len(gab)<3:
            ls=[]
            a=0
            z=d_1[i_1]
            var_1=0
            print(z)
            for k,v in z.items():
                var_1+=v   
            for k,v in z.items():
                a+=v/var_1  
                ls.append(a)
            arand=random.uniform(0,1)
            print("------------------")
            print("This is a random number")
            print(arand)
            print("This is the list of cummulative frequency of probability")
            print(ls)
            for i in range(0,len(ls)-1):
                if arand<=ls[i]:
                    a=ls[i]
                    break
                elif ls[i]<=arand<=ls[i+1]:
                    a=ls[i+1]
                    break
            a=ls.index(a)
            ls=[]
            for k,v in z.items(): 
                ls.append(k)
            k=ls[a]
            gab.append(k)
            print(f(k))
        elif len(gab)>=3:
            return False
     except:
        return False
print("")
i_1=input("Enter the word to predict next words:  ")
gg(i_1)
print(gab)
print("------------------")
print("The final word is:",end=" ")
print(i_1+" "+" ".join(gab[0:2]))




l_3=[]
a=""
for j in range(0,len(l_2)):
  a=""
  for i in range(0,len(l_2[j])-2):
    a+=l_2[j][i]+" "+l_2[j][i+1]+" "+l_2[j][i+2]+"\n"
    l_3.append((a.split("\n"))[:-1])
      
d_1={}
for i in range(0,len(l_3)):
    for j in range(0,len(l_3[i])-1):
        if l_3[i][j] not in d_1:
            d_1[l_3[i][j]]=str(((l_3[i][j+1]).split())[2])+" "
        else:
            d_1[l_3[i][j]]+=str(((l_3[i][j+1]).split())[2])+" "

for k,v in d_1.items():
    v=(v.strip()).split()
    d_1[k]=dict((Counter(v)))
print(d_1)
gab=[]
def gg(i_1):
     try:
        if len(gab)<3:
            ls=[]
            a=0
            z=d_1[i_1]
            var_1=0
            print(z)
            for k,v in z.items():
                var_1+=v   
            for k,v in z.items():
                a+=v/var_1  
                ls.append(a)
            arand=random.uniform(0,1)
            print("------------------")
            print("This is a random number")
            print(arand)
            print("This is the list of cummulative frequency of probability")
            print(ls)
            for i in range(0,len(ls)-1):
                if arand<=ls[i]:
                    a=ls[i]
                    break
                elif ls[i]<=arand<=ls[i+1]:
                    a=ls[i+1]
                    break
            a=ls.index(a)
            ls=[]
            for k,v in z.items(): 
                ls.append(k)
            k=ls[a]
            gab.append(k)
            print(f(k))
        elif len(gab)>=3:
            return False
     except:
        return False
print("")
i_1=input("Enter the word to predict next words:  ")
gg(i_1)
print(gab)
print("------------------")
print("The final word is:",end=" ")
print(i_1+" "+" ".join(gab[0:1]))
    




