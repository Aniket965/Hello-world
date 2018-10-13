import sys
import os
def word_play():
    if sys.platform.startswith('win'):
        path = 'C://Users//' + str(os.getlogin()) + '//hactoberfest.txt'
        with open(path, 'w') as outFile:
            outFile.write('hello world')

word_play()
