import turtle
import math
import time
import numpy as np

# Prompt the user for inputting two points
x1, y1 = eval(input("Enter x1 and y1 for point 1: "))
x2, y2 = eval(input("Enter x2 and y2 for point 2: "))
x3, y3 = eval(input("Enter x3 and y3 for point 3: "))

d= float(input("enter the angle of rotation: "))
s= math.sin(d)
c= math.cos(d)


n= np.array([[c,s,0],[-s,c,0],[0,0,1]])
for i in range(0,3):
    m= np.array([[1,0,0],[0,1,0],[-x[i-1],-y[i-1],1]])
    o= np.array([[1,0,0],[0,1,0],[x[i-1],y[i-1],1]])

    c=np.array([])
    c= []


# Bresenham Line Draw Algorithm


dx = abs(x2 - x1)
dy = abs(y2 - y1)

x = x1
y = y1

e = 2 * dy-dx

turtle.Turtle().penup()
# turtle.Turtle().width=4
turtle.Turtle().goto(x1, y1)
turtle.Turtle().pendown()
turtle.Turtle().write("Point 1")

i = 1
while(i <= dx):
    time.sleep(0.05)
    turtle.Turtle().goto(x, y)

    while(e >= 0):
        y = y + 1
        e = e - 2 * dx

    x = x + 1
    e = e + 2 * dy
    i = i + 1

turtle.Turtle().goto(x2, y2) # Draw a line to (x2, y2)
turtle.Turtle().write("Point 2")

turtle.Turtle().penup()
turtle.Turtle().hideturtle()
turtle.done()