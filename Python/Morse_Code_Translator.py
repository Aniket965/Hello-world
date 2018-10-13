import sys
'''
This code provides an English to Morse Code translator
example usage: python3 Morse_Code_Translator.py HELLO
'''

code = {'A': '.-', 'B': '-...', 'C': '-.-.', 'D': '-..', 'E': '.', 'F': '..-.', 'G': '--.', 'H': '....',
        'I': '..', 'J': '.---', 'K': '-.-', 'L': '.-..', 'M': '--', 'N': '-.', 'O': '---', 'P': '.--.',
        'Q': '--.-', 'R': '.-.', 'S': '...', 'T': '-', 'U': '..-', 'V': '...-', 'W': '.--', 'X': '-..-',
        'Y': '-.--', 'Z': '--..', '0': '-----', '1': '.----', '2': '..---', '3': '...--', '4': '....-',
        '5': '.....', '6': '-....', '7': '--...', '8': '---..', '9': '----.', '.': '.-.-.-', ',': '--..--',
        '?': '..--..', '=': '-...-'}


def translate(inp):
    s = ""
    for i in inp:
        if i == ' ':
            s = s + '|'
        else:
            s = s + code[i] + ' '

    return s

# use system args to parse the value you are converting
inp = str(sys.argv[1])
inp = inp.upper()
print("Your String: " + inp)
s = ""
s = translate(inp)
print("Morse Code: " + s)
