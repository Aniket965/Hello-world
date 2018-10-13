"""
Password management script -- Not safe
"""


import sys, pyperclip


PASSWORDS = {'email': 'dssjdopjap9scancfHCPIWDFHASDCOKDSC',
             'blog': 'cdcpwdekdjw0efunwtvtvnninrf9mask3xcSXAs',
             'lugagge': '24355'
            }

if len(sys.argv) < 2:
    print('Usage: python password_manager.py - copy account password')
    sys.exit()

account = sys.argv[1]

if account in PASSWORDS:
    pyperclip.copy(PASSWORDS[account])
    print('Password for ' + account + ' copied to clipboard')
else:
    print("There's no account named " + account)
