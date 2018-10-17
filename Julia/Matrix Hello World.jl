


GreetString = "Hello     World"
grtMat = fill('A',3, 5)#creating a char matrix
k=1
#filling up
for i in 1:3, j in 1:5
    grtMat[i,j] = GreetString[k]
    k+=1
end
display(grtMat)
