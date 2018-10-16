#! /usr/bin/python3
# phoneandemail.py- Finds all the email addresses on the clipboard.

import pyperclip
import re


# regex for email
emailregex = re.compile(r'''(
[a-zA-Z0-9._%+-]+                       #username
@                                       #@ symbol
[a-zA-z0-9.-]+                          #domain name
(\.[a-zA-z]{2,4})                       #dot something
)''', re.VERBOSE)


# Find Matches in the Clipboard
text = str(pyperclip.paste())
matches = []
for groups in emailregex.findall(text):
    matches.append(groups[0])


# copy results to the clipboard
if len(matches) > 0:
    pyperclip.copy('\n'.join(matches))
    print('Results Found: ')
    print('\n'.join(matches))
else:
    print('No emails were found')
