import turtle

"""You need to install turtle on your OS to run this properly. This will draw circle using squares. Use python 3"""

def draw_square(_turtle):
	for i in range (1, 5):
		_turtle.forward(100)
		_turtle.right(90)

def start_draw():
	window = turtle.Screen()
	window.bgcolor("black")

	brad = turtle.Turtle()
	brad.shape("turtle")
	brad.color("yellow")
	brad.speed(5)

	for i in range (1, 37):
		draw_square(brad)
		brad.right(10)

	window.exitonclick()

start_draw()
