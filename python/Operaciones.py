from functools import wraps


# Definimos un decorador que nos permita verificar que los numeros sean pares
def numeros_pares_con_limite(limite_superior):
    def numeros_pares( func ):
        
        @wraps(func)
        def funcion_decorada(*args, **kwargs):
            for i in args:
                if i % 2 == 0 and i < limite_superior:
                    return func(*args, **kwargs)
                else:
                    return "Los numeros no cumplen las especificaciones"
        return funcion_decorada
    return numeros_pares
# Este programa realiza una opeación y valida si el operando es valido

# Definimos la funcion principal

@numeros_pares_con_limite(100)
def suma(a = 0, b = 0):
    return a + b

@numeros_pares_con_limite(50)
def resta(a = 0, b = 0):
    return a - b

resultado = suma(20, 10)
print(resultado)

resultado2 = resta(48, 12)
print(resultado2)
