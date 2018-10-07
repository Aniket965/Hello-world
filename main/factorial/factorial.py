while(True):
    num = int(input("Enter the number you want to find factorial: "))
    fact = 1
    if(num==0):
        fact = 1
    elif(num==1):
        fact = 1
    else:
        i=num
        while(i!=0):
            fact = fact*i
            i = i-1
    print("Factorial of "+str(num)+" is: "+str(fact))
    res = input("Do You Want to Enter Again?(y/n): ")
    if(res=='n'):
        import sys
        sys.exit(0)
    else:
        continue