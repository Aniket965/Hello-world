import time
from lists import command_list
from lists import math_commands

print('Hello my name is AIM. How may I help you?')

while True:
    Question = input('')
    if Question == 'what does aim mean':
        print('Aim means: Artificial Information Machine')
    elif Question == 'hi':
        print('Greetings earthling! How may I assist you?')
    elif Question == 'hello':
        print('Live long and prosper sentient being! What can I assist you with?')
    elif Question == "what can you do":
        print('Everything')
        print('Anything')
        print('What do you want me to do?')
    elif Question == 'what is the answer to life':
        print(42)
    elif Question == 'math':
        print('enter equation one variable at a time, starting with the numbers:')
        x = float(input())
        y = float(input())
        numbers = input()
        if numbers == 'muiltiply':
            print(x*y)
        elif numbers == 'divide':
            print(x/y)
        elif numbers == 'minus':
            print(x-y)
        elif numbers == 'add':
            print(x+y)
    elif Question == 'thanks':
        print('You are very welcome bag filled with dirty water')
        if Question == 'what did you say?':
            print('Star Trek')
        
    elif Question == 'shutdown':
        print('Shutting down in')
        print(3)
        sleep(1)
        print(2)
        sleep(1)
        print(1)
        sleep(1)
        print('Powered Off')
        sleep(1)
        break
    elif Question == '-help':
        print('Here is a list of known commands:')
        for elem in command_list:
            print(elem)
        sleep(5)
        print('Not finding what you are looking for?')
        sleep(2)
        print('Maybe it is in a sub folder of one of the catagories.')
        sleep(2)
        print ('Try entering one of the catagories by inputing it')
    elif Question == 'math operations':
        for elem in math_commands:
            print(elem)
        
    else:
        print('Unrecognized command. Type -help for a list of commands.')
