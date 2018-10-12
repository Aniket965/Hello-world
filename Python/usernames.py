#!/usr/bin/python3

from collections import OrderedDict
import re
import sys
words = []

def clean(word):
    """Removes any non A-Z characters and any vowels from a word"""
    cleanWord = re.sub('[^A-Za-z]', '', word) #remove any special characters (non A-Z chars)
    cleanWord = re.sub('[AaEeIiOoUu]', '', cleanWord) #remove any vowels
    return cleanWord

def sortWords(wordList):
    """Removes duplicates from a list, then sorts alphabetically then by length"""
    sortedWords = list(OrderedDict.fromkeys(wordList)) #remove duplicate words
    sortedWords = sorted(sortedWords) #sort A-Z
    sortedWords = sorted(sortedWords, key=len) #sort by length
    return sortedWords

def saveWords(wordList):
    """Saves a list to a text file"""
    with open('potential_usernames.txt', 'w') as file:
        file.writelines('%s\n' % word for word in wordList)


def getWords(filepath):
    """Gets words from a text file"""    
    with open(filepath, 'r') as f:
        for word in f:
            word = clean(word)
            if(len(word) > minLength and len(word) < maxLength):
                words.append(word)
            else:
                continue

if len(sys.argv) != 4:
    print("Usage: words FILE MIN MAX")
    exit(1)
else:
    try:
        inputfile = sys.argv[1]
        minLength = int(sys.argv[2])
        maxLength = int(sys.argv[3])
    except Exception as e:
        print("Error")
        print(e)
        exit(1)
    
getWords(inputfile)
finalWords = sortWords(words)
saveWords(finalWords)
print(str(len(finalWords)) + " potential usernames found. Good luck.")

exit(0)
