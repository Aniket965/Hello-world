year = int(input("Enter Year: "))
if year%4!=0:
    print(year, "isn't a Leap Year")
elif year%100==0 and year%400!=0:
    print(year, "isn't a Leap Year")
else:
    print(year, "is a Leap Year")
