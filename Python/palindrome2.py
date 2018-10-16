#checks for palindrome

def is_palindrome():
  word = input('Enter a string')
  word = word.lower()
  word.replace(' ','')
  if word == word[::-1]:
    return True
  return False
