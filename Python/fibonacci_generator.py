def fib(max_num):
    a, b = 0, 1
    while a < max_num:
        yield a
        a, b = b, a + b


for n in fib(100):
    print(n)
