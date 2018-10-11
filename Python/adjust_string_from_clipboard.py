"""
This program will help with string manipulation

- Obtain string from clipboard

- Manipulate string

- Deliver string to clipboard

"""


import pyperclip


text = pyperclip.paste()

lines = text.split('\n')

for i in range(len(lines)):
    lines[i] = '* ' + lines[i]

text = '\n'.join(lines)

pyperclip.copy(text)
