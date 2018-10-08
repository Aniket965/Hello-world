year = int(input("Enter Year: "))

# Leap Year Check
if not year % 400:
    print(year, "is a Leap Year")
elif not year % 4 and year % 100:
    print(year, "is a Leap Year")
else:
    print(year, "is not a Leap Year")
