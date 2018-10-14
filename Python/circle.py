#make circle out of Square
#install python-tk package using pip
#For Python3 use "sudo apt-get install python3-tk" in your terminal


import turtle
def draw(some_turtle):
    for i in range(1,5):
        some_turtle.forward(100)
        some_turtle.right(90)

def art():
    window = turtle.screen()
    window.bgcolor("Green")

    raju = turtle.Turtle()
    raju.color("red")
    for i in range(1,5):
        draw(raju)
        raju.right(10)
    window.exitonclick()

art()
