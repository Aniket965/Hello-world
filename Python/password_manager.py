import sys
import pyperclip

account = {'facebook': '12345', 'gmail': '123456'}
if len(sys.argv) < 2:
    print('Please enter the account for password')
    sys.exit()
password = sys.argv[1]
if password in account:
    pyperclip.copy(account[password])
    print('Your password is copied')
else:
    print("You did't saved your password here")
