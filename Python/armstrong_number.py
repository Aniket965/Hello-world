def isArmstrong(num):
    copynum = num
    total = 0
    while(num>0):
        digit = num%10
        total = total + (digit ** 3)
        num = num // 10
    if total == copynum:
        return True
    else:
        return False


user_input = int(input("Enter a number: "))
print(isArmstrong(user_input))