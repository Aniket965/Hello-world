# Hannah Guo
# This program identifies properties of triangle based on user inputs. The user has the option to enter in a triangle's
# three angles or three sides. Based on these inputs, the program will output the triangle's type based on side length
# (equilateral, isosceles or scalene) and the triangle's type based on angles (right angle, obtuse or acute).

import math

print("This program calculates a triangle's type based on either three sides or three angles inputted by the user.")

keepCalculating = True
while keepCalculating:
    angleOne, angleTwo, angleThree, sideOne, sideTwo, sideThree = (0.0,) * 6
    mode = str(input("Will you be entering three angles (enter 'A') or three sides (enter 'S')? "))
    triangleType = ""

    if mode == 'A':
        while True:
            try:
                angleOne = float(input("Input your first angle (in degrees): "))
            except ValueError:
                print("Invalid input, please input a valid first angle "
                      "(greater than 0.0 and less than or equal to 178.0).")
            else:
                if 0 < angleOne < 180:
                    break
                print("Invalid input, please input a valid first angle "
                      "(greater than 0.0 and less than or equal to 178.0).")

        while True:
            try:
                angleTwo = float(input("Input your second angle (in degrees): "))
            except ValueError:
                print("Invalid input, please input a valid second angle "
                      "(greater than 0.0 and less than or equal to " + str(180.0 - angleOne) + ").")
            else:
                if 0 < angleTwo < 180 - angleOne:
                    break
                print("Invalid input, please input a valid second angle "
                      "(greater than 0.0 and less than or equal to " + str(180.0 - angleOne) + ").")

        while True:
            try:
                angleThree = float(input("Input your third angle (in degrees): "))
            except ValueError:
                print("Invalid input, please input a third angle "
                      "(greater than 0.0 and less than or equal to " + str(180.0 - angleOne - angleTwo) + ").")
            else:
                if 0 < angleThree <= 180 - angleOne - angleTwo:
                    break
                print("Invalid input, please input a third angle "
                      "(greater than 0.0 and less than or equal to " + str(180.0 - angleOne - angleTwo) + ").")

        if angleOne + angleTwo + angleThree != 180:
            print("This is not a valid triangle, please try again. The angles must add up to 180 degrees. ")
            continue

    elif mode == 'S':
        print("Remember to use the same units for each side length. "
              "(e.g. All side lengths are entered in centimeters, all side lengths are entered in metres, etc.)")
        while True:
            try:
                sideOne = float(input("Input your first side length (a number greater than 0.0): "))
            except ValueError:
                print("Invalid input, please input a number greater than 0.0. ")
            else:
                if sideOne > 0:
                    break
                print("Invalid input, please input a number greater than 0.0. ")

        while True:
            try:
                sideTwo = float(input("Input your second side (a number greater than 0.0): "))
            except ValueError:
                print("Invalid input, please input a number greater than 0.0. ")
            else:
                if sideTwo > 0:
                    break
                print("Invalid input, please input a number greater than 0.0. ")

        while True:
            try:
                sideThree = float(input("Input your third side (a number greater than 0.0): "))
            except ValueError:
                print("Invalid input, please input a number greater than 0.0. ")
            else:
                if sideThree > 0:
                    break
                print("Invalid input, please input a number greater than 0.")

        if sideOne + sideTwo > sideThree and sideTwo + sideThree > sideOne and sideOne + sideThree > sideTwo:
            angleOne = math.degrees(math.acos(((sideOne ** 2) + (sideTwo ** 2) - (sideThree ** 2))
                                              / (2 * sideOne * sideTwo)))
            angleTwo = math.degrees(math.acos(((sideTwo ** 2) + (sideThree ** 2) - (sideOne ** 2))
                                              / (2 * sideTwo * sideThree)))
            angleThree = math.degrees(math.acos(((sideThree ** 2) + (sideOne ** 2) - (sideTwo ** 2))
                                                / (2 * sideThree * sideOne)))
            print("The three angles of this triangle (rounded to the nearest hundredth) are " + str(round(angleOne, 2))
                  + " degrees, " + str(round(angleTwo, 2)) + " degrees, and " + str(round(angleThree, 2)) + " degrees.")
        else:
            print("Invalid triangle, please try again. The sum of any two sides of the triangle must be more than "
                  "the length of the third.")

    else:
        print("Invalid mode entered, please try again. ")
        continue

    if (angleOne == angleTwo) ^ (angleTwo == angleThree) and (angleTwo == angleThree) ^ (angleThree == angleOne):
        triangleType = "isosceles"
    elif not(angleOne == angleTwo == angleThree):
        triangleType = "scalene"

    if angleOne < 60 and angleTwo < 60 and angleThree < 60:
        print("This triangle is an acute " + triangleType + " triangle.\nAcute means that all of the triangle's angles "
              "are less than 90.0 degrees.")
    elif angleOne == 90 or angleTwo == 90 or angleThree == 90:
        print("This is a " + triangleType + " right angle triangle.\nThis means that the triangle has a 90 degree "
              "angle.")
    elif angleOne == angleTwo == angleThree:
        print("This triangle is an equilateral triangle.\nThis means that all the triangle's side are equal lengths "
              "and that the triangle has three 60.0 degree angles.")
    else:
        print("This triangle is an obtuse " + triangleType + " triangle. "
              "\nObtuse means the triangle has an angle that is greater than 90.0 degrees.")

    if triangleType == "isosceles":
        print("This triangle is also isosceles, "
              "which means that it has two side lengths and two angles that are equal.")
    elif triangleType == "scalene":
        print("This triangle is also scalene, "
              "which means that it has three unique side lengths and three unique angles.")

    while True:
        userInput = str(input("Enter 'continue' to solve another triangle (restart the program), "
                              "enter 'quit' to exit. "))
        if userInput == "quit":
            keepCalculating = False
            print("The program has ended.")
        elif userInput == "continue":
            print("Program restarting... ")
        else:
            print("Invalid input, please try again. ")
            continue
        break
