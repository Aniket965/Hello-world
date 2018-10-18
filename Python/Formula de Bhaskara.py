# BHASKARA
from math import sqrt

a = float(input('Informe o valor de "a": '))
b = float(input('Informe o valor de "b": '))
c = float(input('Informe o valor de "c": '))
delta = pow(b, 2) - 4 * a * c
deltart = sqrt(delta)
x1 = ((-b) + deltart) / (2 * a)
x2 = ((-b) - deltart) / (2 * a)
print('\033[30mO valor de x1 =\033[m \033[31m{}\033[m\033[30m e x2 =\033[m \033[34m{}\033[m'.format(x1, x2))
