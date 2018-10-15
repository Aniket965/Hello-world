#  this is a code formater  in python 

#  this program indents a minified  line based on parantheses {'(',')'}

a=open("input.txt").read() # this is the input file just paste the sql string in here
k=open ("output.txt",'w') # expect the output in such file

c = 0 # kept for indentation level count

for i in range(len(a)):
    if a[i] == '(':
        c += 1
        k.write('\n'+'   '*c+a[i] )
    elif a[i] == ')':
        c -= 1
        k.write(a[i] + '\n'+'   ' * c)
    else:
        k.write (a[i])
