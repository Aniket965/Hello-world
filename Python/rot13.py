#The most secure encryption in the world

#Input a string to the rot13 function to get back a super secret encrypted version!
def rot13(input):
    output = ""
    for character in input.lower():
        output += chr(ord(character)+13).lower()
    return output