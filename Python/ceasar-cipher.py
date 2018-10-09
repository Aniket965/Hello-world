#!/usr/bin/env python3
import sys

if len(sys.argv) < 4:
    print('Usage: ' + sys.argv[0] + ' [mode (enc|dec)] [key] [message...]')
    sys.exit(1)

SYMBOLS = 'abcdefghijklmnopqrstuvwxyz'
TRANSLATED = ''

if sys.argv[1].lower().startswith('e'):
    MODE = 'ENCRYPT'
else:
    mode = 'DECRYPT'

KEY = int(sys.argv[2])

WORDS = list()
for pos in range(3, len(sys.argv)):
    WORDS.append(sys.argv[pos])

MESSAGE = ' '.join(WORDS).lower()

for symbol in MESSAGE:
    if symbol in SYMBOLS:
        symbolIndex = SYMBOLS.find(symbol)

        if MODE == 'ENCRYPT':
            translatedIndex = symbolIndex + KEY
        elif MODE == 'DECRYPT':
            translatedIndex = symbolIndex - KEY

        if translatedIndex >= len(SYMBOLS):
            translatedIndex = translatedIndex - len(SYMBOLS)
        elif translatedIndex < 0:
            translatedIndex = translatedIndex + len(SYMBOLS)

        TRANSLATED = TRANSLATED + SYMBOLS[translatedIndex]
    else:
        TRANSLATED = TRANSLATED + symbol

print(TRANSLATED)
