def bisect(year):
    if year % 4 != 0:
        return False
    elif year % 100 != 0:
        return True
    elif year % 400 != 0:
        return False
    else:
        return True 

print("Introduce an year and a day(1-365) and it will show the day and month for that day")
an = int(input("Year: "))
zi = int(input("Day: "))


if zi<1 or bisect(an)>366 or not bisect(an)>365:
    print("The day you have typed is not a valid date")
else:    
    luni = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    luna = ["Ianuarie", "Februarie", "Martie", "Aprilie", "Mai",
            "Iunie", "Iulie", "August", "Septembrie", "Octombrie"
            "Noiembrie", "Decembrie"]

    if bisect(an):
        luni[1] = 29

    for i in range(12):
        if zi <= luni[i]:
            print("Day:", zi, "Month:", luna[i], "Year:", an)
            break
        zi = zi - luni[i]
