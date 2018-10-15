number = int(input("Enter a number to check if it is happy or '0' to quit: "))

while number!=0:
    list = set()
    while 1:
        if number == 1:
            print("This Number is a happy number")
            break
        number = sum(int(c) ** 2 for c in str(number))
        if number in list:
            print("Number is not happy")
            break
        list.add(number)

    number = int(input("Enter a number to check if it is happy '0' to quit: "))
