memory = {0:0, 1:1}

def fibonacci(n):
    if n in memory:
        return memory[n]
    else:
        memory[n] = fibonacci(n-1) + fibonacci(n-2)
        return memory[n]
