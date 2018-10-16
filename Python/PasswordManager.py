#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Aug  1 10:51:39 2018

@author: piyush
"""

# This is basically a insecure password locker. 


import sys, pyperclip
from Crypto.Cipher import XOR
import base64, pickle, getpass


if len(sys.argv) < 2:
    print('Account name is missing')
    sys.exit()

                
account = sys.argv[1]

PASSWORDS = pickle.load( open( "Locker.p", "rb" ) )


def encrypt(key, plaintext):
  cipher = XOR.new(key)
  return base64.b64encode(cipher.encrypt(plaintext))

def decrypt(key, ciphertext):
  cipher = XOR.new(key)
  return cipher.decrypt(base64.b64decode(ciphertext))


if (account not in PASSWORDS):
    print("No account named \'" + account + "\' exists.")
    print("Do you want to :- \n1. Add account \n2. Exit")
    menu2 = int(input("Enter 1 or 2 please.\n"))
    
    if (menu2 == 2):
        sys.exit()
    elif (menu2 == 1):
        account_name = input("Enter account's name\n")
        account_pass = getpass.getpass("Enter account's password\n")
        encrypted_pass = (encrypt('16BIT0234',account_pass)).decode('UTF-8')
        data = {account_name:encrypted_pass}
        PASSWORDS[account_name] = encrypted_pass
        pickle.dump( PASSWORDS, open( "Locker.p", "wb" ) )
        print("Account successfully added!\n")

    else:
        print("Invalid input.\n")
        sys.exit()
    
else:
    
    print("Do you want to :- \n1. Copy \n2. Exit")
    menu1 = int(input("Enter 1 or 2 please.\n"))
    
    if (menu1 == 2):
        sys.exit()
    elif(menu1==1):
        PASSWORDS_READ = pickle.load( open( "Locker.p", "rb" ) )
        pyperclip.copy((decrypt('16BIT0234',PASSWORDS_READ[account])).decode('UTF-8'))
        print('Password for ' + account + ' copied to clipboard.')
    else:
        print("Invalid input.\n")
        sys.exit()
        
        


    
    
    
    