import string
import random

helloWorld = ''

while (helloWorld != "Hello World!"):
    helloWorld = ''
    
    for i in range(11):
        if i == 5:
            helloWorld += ' '
        else:
            helloWorld += random.choice(string.ascii_letters)
    
    helloWorld += '!'

print(helloWorld)
