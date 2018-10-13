import numpy as np
import plotly.plotly as py


def spiral(th):
    a = 1.120529
    b = 0.306349
    r = a * np.exp(-b * th)
    return (r * np.cos(th), r * np.sin(th))


nspiral = 2  # number of spiral loops

th = np.linspace(-np.pi / 13, 2 * np.pi * nspiral, 1000);  # angle
(x, y) = spiral(th)

# shift the spiral north so that it is centered
yshift = (1.6 - (max(y) - min(y))) / 2

s = dict(x=-x + x[0], y=y - y[0] + yshift,
         line=dict(color='white', width=3))

# Build the rectangles as a heatmap
# specify the edges of the heatmap squares
phi = (1 + np.sqrt(5)) / 2.
xe = [0, 1, 1 + (1 / (phi ** 4)), 1 + (1 / (phi ** 3)), phi]
ye = [0, 1 / (phi ** 3), 1 / phi ** 3 + 1 / phi ** 4, 1 / (phi ** 2), 1]

z = [[13, 3, 3, 5],
     [13, 2, 1, 5],
     [13, 10, 11, 12],
     [13, 8, 8, 8]
     ]

hm = dict(x=np.sort(xe),
          y=np.sort(ye) + yshift,
          z=z,
          type='heatmap',
          colorscale='Viridis')

axis_template = dict(range=[0, 1.6], autorange=False,
                     showgrid=False, zeroline=False,
                     linecolor='black', showticklabels=False,
                     ticks='')

layout = dict(margin=dict(t=200, r=200, b=200, l=200),
              xaxis=axis_template,
              yaxis=axis_template,
              showlegend=False,
              width=700, height=700,
              autosize=False)

figure = dict(data=[s, hm], layout=layout)

py.iplot(figure, filename='golden spiral', height=750)
