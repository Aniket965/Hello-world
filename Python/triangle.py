import math


def basic_formula(b, h):
    return b*h/2


def herons_formula(a, b, c):
    s = (a+b+c)/2
    return math.sqrt(s*(s-a)*(s-b)*(s-c))


def trigonometry(a, b, angle):
    theta = angle * math.pi / 180
    return a*b*math.sin(theta)/2


print("""Triangle Area Calculator
Which formula do you want to use?
1] Basic Formula (given base and height)
2] Heron's Formula (given all sides)
3] With Trigonometry (given two adjacent sides and the angle between them)""")
selection = int(input("(Type 1 / 2 / 3 to select): "))

if selection == 1:
    print("Basic Formula:")
    base = float(input("Give me the base of the triangle: "))
    height = float(input("Give me the height of the triangle: "))

    res = basic_formula(base, height)
    print("The area of the triangle with a base of {} and a height of {} is {}".format(base, height, res))
elif selection == 2:
    print("Heron's Formula:")
    a = float(input("Give me the first side of the triangle: "))
    b = float(input("Give me the second side of the triangle: "))
    c = float(input("Give me the third side of the triangle: "))

    res = herons_formula(a, b, c)
    print("The area of the triangle with sides ({}, {}, {}) is {}".format(a, b, c, res))
elif selection == 3:
    print("Using Trigonometry:")
    a = float(input("Give me the first of the two adjacent sides: "))
    b = float(input("Give me the second of the two adjacent sides: "))
    angle = float(input("Give me the angle between them (in degrees): "))

    res = trigonometry(a, b, angle)
    print("The are of the triangle with two adjacent sides ({}, {}) and an angle of {} degrees between them is {}".format(a, b, angle, res))
