import numpy as np
from sympy import *

A = np.array ([
    [6, 4],
    [-1, -8]]
    )

B = np.array ([
    [5, -3],
    [-2, -4]]
    )

print("Solution is: \n", 5* np.linalg.solve(A, B))
