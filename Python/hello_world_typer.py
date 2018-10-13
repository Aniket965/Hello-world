from sys import stdout as stdout
from time import sleep

HELLO = "Hello, World! "
i = 0
while True:
    stdout.write("\r" + " "*len(HELLO))
    stdout.write("\r" + HELLO[0:(i%len(HELLO))])
    stdout.flush()
    i += 1
    sleep(0.1)
    
