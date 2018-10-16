#-*- coding: utf8 -*-
'''
Implementando o algoritmo da potência recursiva.

@version 6/08/2018
@author Vinicius Barbosa
'''

def ehPar(numero):
	return numero % 2 == 0

def ehImpar(numero):
	return  not ehPar(numero)

def potencia(x,n):

	if x == 0:
		return 0

	if n == 0:
		return 1

	if n < 0:
		base = potencia(x, -n)
		return 1 / base

	if ehPar(n):
		p = potencia(x, n / 2)
		return p * p

	if ehImpar(n):
		return potencia(x, n -1) * x


assert potencia(0,-1) == 0
assert potencia(0,0) == 0
assert potencia(0,3) == 0

assert potencia(3,0) == 1
assert potencia(3,1) == 3
assert potencia(3,2) == 9
assert potencia(3,-1) == 1 / 3 
assert potencia(3,-2) == 1 / 9

assert potencia(-2,1) == -2
assert potencia(-2,2) ==  4
assert potencia(-2,3) == -8

