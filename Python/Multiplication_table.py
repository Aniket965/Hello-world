print ("    Multiplication Table(1-12)")

for j in range (1,13):
    print ("    ",j,end = '')
print ()
print ("__________________________________________________")

for i in range (1,13):
    print (i,"|",end = '')
    for j in range (1,13):
        print(format(i*j,"6d"),end ='')
        
    print ()
print ("____________________________________________________")
