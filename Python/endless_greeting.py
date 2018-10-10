from time import time

first_time = time()

while(True):
    print("Hello world")

print("Almost the end")

second_time = time()

print(second_time - first_time)
