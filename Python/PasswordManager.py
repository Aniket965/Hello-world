#! /usr/bin/python3
# Password_locker.py An insecure Password locker program
Passwords={}
x=input('Enter the website you want a password for')
y=input('ENter the password')
Passwords[x]=y
import pyperclip
if len(sys.argv) < 2:
    print('Usage: python Password_locker.py [account] - copy account password')
    sys.exit()
account = sys.argv[1]  # first command line arg is the account name
if account in Passwords:
    pyperclip.copy(Passwords[account])
    print('Password for', account, 'is copied to clipboard.')
else:
    print('There is no account named', account)
