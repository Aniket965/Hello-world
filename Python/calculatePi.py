PI = 3.1415926535897932384626433832795028841971693993751058209
 
def calculate_pi(accuracy):
    pi = 1.0
    den = 3
    add = False
    while( abs(4*pi - PI) > pow(10, -accuracy) ):
        if(add):
            pi += (1.0/den)
        else:
            pi -= (1.0/den)
        den += 2
        add = not add
    print("{}".format(round(4*pi, accuracy)))
