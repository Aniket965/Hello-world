import random

LETTERS = 'HW elord!'
def monkeyTyping(textToFind):
    """
    A monkey has a writing machine that only contains the keys
    that can write "Hello, World ! "
    the objective is to have the message typed by the monkey until he gets
    the good sentence written on the computer
    """
    text = ""
    index = 0
    lastMax = 0
    while (index < len(textToFind)):
        keyStroke = random.choice(LETTERS)
        text += keyStroke
        index += 1
        if (textToFind[index - 1] != keyStroke):
            if (index - 1 > lastMax):
                print(index - 1)
                lastMax = index - 1
            index = 0
    return text
def monkeyCrypting(textToFind):
    """the objective is to have a monkey adding random characters into
        the good sentence
        """
    text = ""
    index = 0
    while (index < len(textToFind)):
        keyStroke = random.choice(LETTERS)
        text += keyStroke

        if (textToFind[index] == keyStroke):
            index += 1
    return text
def printSpace():
    print("")
    print("*******************")
    print("")
print(monkeyCrypting("Hello"))
printSpace()
print(monkeyTyping("Hello"))
printSpace()
print(monkeyCrypting("Hello World!"))
printSpace()
print(monkeyTyping("Hello World!"))
printSpace()
