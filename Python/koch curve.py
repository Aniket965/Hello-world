# Your basic Koch triangle
import turtle
import math

# Get the screen size and set some scaling
wn = turtle.Screen()
wx = wn.window_width()*.5
wh = wn.window_height()*.5
base_triangle_length = 2.0/math.sqrt(3.0)*wh

# Parameters of the Koch triangle
depth = 2

# Set up the turtle
Koch = turtle.Turtle()
Koch.speed(50*(depth+1))
Koch.penup()
Koch.setposition((-wx/2,-wh/2))
Koch.pendown()
Koch.left(60)

def draw_koch_segment(t, run, mydepth, depth):
  if mydepth == depth:
    # Just draw a segment
    t.fd(run)
  else:
    myrun = run/3.0
    # Make each straight bit into a smaller version of ourselves
    draw_koch_segment(t, myrun, mydepth+1, depth)
    t.left(60)
    draw_koch_segment(t, myrun, mydepth+1, depth)
    t.right(120)
    draw_koch_segment(t, myrun, mydepth+1, depth)
    t.left(60)
    draw_koch_segment(t, myrun, mydepth+1, depth)

# Draw the basic triangle outline
for ii in range(3):
  draw_koch_segment(Koch, base_triangle_length, 0, depth)
  Koch.right(120)

# A challenge: can you get it to do a square?