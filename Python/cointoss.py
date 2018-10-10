from bokeh.plotting import figure, output_file, show
import random
import math


initial_invesment = 100
y = []

for oo in range(0, 365):
    if random.randint(0,1) % 2 == 0:
        initial_invesment = initial_invesment + 0.5
        y.append(initial_invesment)
    else:
        initial_invesment = initial_invesment - 0.5
        y.append(initial_invesment)

# output to static HTML file
output_file("cointoss.html")

# create a new plot with a title and axis labels
p = figure(title="Performance", x_axis_label='days', y_axis_label='portfolio')

if y[0] < y[364]:
    color = "green"
else:
    color = "red"

p.line(range(0, 365), y, legend="Total Contribution", line_width=1, line_color=color)
# show the results
show(p)