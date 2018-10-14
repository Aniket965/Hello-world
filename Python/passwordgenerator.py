# Created for Github Hacktoberfest 2018
import random
import string

password = ""

passwordlength = int(input("How many characters would you like your randomly generated password to have? "))
passwordcontent = input("Would you like your randomly generated password to have numbers? [Y/N] ")
if (passwordcontent == 'N' or passwordcontent == 'n'):
    for i in range(passwordlength):
        password += random.choice(string.ascii_letters)

if (passwordcontent == 'Y' or passwordcontent == 'y'):
    numbers = "1234567890"
    for i in range(passwordlength):
        password += random.choice(string.ascii_letters)
    
    password = list(password)

    for i in range(passwordlength // 2):
       if (i // 2 == 0):
           password[i] = random.choice(numbers)
    password = "".join(password)
    
input("Your randomly generated password is: " + password + "\n"
      + "Thank you for using Password Generator! (Press ENTER to exit program)")

