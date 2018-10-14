from math import sqrt, sin, radians


# Basic Formula
def calculate_area_basic(height, base):
    return 0.5 * height * base


# Heron's Formula
def calculate_area_heron(a, b, c):
    s = (a + b + c) / 2
    return sqrt(s * (s - a) * (s - b) * (s - c))


# Using Trigonometry
def calculate_area_trigonometry(angle, b, c):
    return 0.5 * b * c * sin(radians(angle))


if __name__ == '__main__':
    print("Basic Formula")
    height = float(input("Enter height of the triangle: "))
    base = float(input("Enter base of the triangle: "))
    print("Area: {}\n\n".format(calculate_area_basic(height, base)))

    print("Heron's Formula")
    a = float(input("Length of the first arm: "))
    b = float(input("Length of the second arm: "))
    c = float(input("Length of the third arm: "))
    print("Area: {}\n\n".format(calculate_area_heron(a, b, c)))

    print("Trigonometry Formula")
    b = float(input("Length of first arm: "))
    c = float(input("Length of second arm: "))
    angle = float(input("Angle between the arms(degrees): "))
    print("Area: {}".format(calculate_area_trigonometry(angle, b, c)))
