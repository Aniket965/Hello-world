#!/usr/bin/env python

"""
This program validates the CPF, unique set of 11 numbers used to identify a person in Brasil. This script validate it
Python3 compatibility.
"""
__author__ = "Matheus de Sousa Barros"
__license__ = "MIT"
__maintainer__ = "Matheus de Sousa Barros"
__github__ = "bmatheus91"

import os

def DV_maker(v):
    if v >= 2:
        return 11 - v
    return 0


def validate_cpf():
    """
        CPF e um conjunto de 11 digitos que passa pelo seguinte processo de validacao:
        
        1 - Multiplica-se os 9 primeiros dígitos pela sequência decrescente de números 
        de 10 à 2 e soma os resultados. Depois multiplicarmos esse resultado por 10 
        e dividirmos por 11. Se ele for igual ao primeiro dígito verificador 
        (primeiro dígito depois do '-'), a primeira parte da validação está correta.

        Obs: Se o resto da divisão for igual a 10, nós o consideramos como 0

        2 - Considera-se os 9 primeiros dígitos, mais o primeiro dígito verificador, e 
        multiplica-se esses 10 números pela sequencia decrescente de 11 a 2. Depois 
        multiplicarmos esse resultado por 10 e dividirmos por 11. Verifica-se, se o 
        resto corresponde ao segundo dígito verificador.
    """

    print('Digite um CPF para validar')
    value = str(input())

    if not value.isdigit():
        print('CPF deve conter apenas números.')
        return False

    if len(value) != 11:
        print('CPF deve ter 11 números.')
        return False

    #Verifica CPFs do tipo 1111111111, 8888888888
    for n in range(0,10):
        invalid_cpf = str(n) * 11
        if value == invalid_cpf:
            print('Digite um CPF válido.')
            return False

    #Primeira Validacao
    v1 = sum( [ int(value[i]) * w for i, w in enumerate(range(10,1, -1))])
    mod1 = (v1 * 10) % 11
    dv1 = 0 if mod1 == 10 else mod1

    if dv1 != int(value[-2]):
        print('CPF inválido.', 'invalid')
        return False

    #Segunda validacao
    v2 = sum( [ int(value[i]) * w for i, w in enumerate(range(11,1, -1))])
    mod2 = (v2 * 10) % 11
    dv2 = 0 if mod2 == 10 else mod2

    if dv2 != int(value[-1]):
        print('CPF inválido.', 'invalid')
        return False

    print('CPF Valido')

validate_cpf()