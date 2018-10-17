def make_burger(f):
    def new_f():
        print('/-----\\')
        f()
        print('\-----/')
    return new_f

@make_burger
def chop():
    print("-------")

chop()