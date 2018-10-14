def rev_string(word):
    if not check_string(word):
        raise TypeError('expected string, but got %r'%type(word))
    
    if word == '':
        return ''
    
    return word[-1] + rev_string(word[:-1])

def check_string(word):
    return type(word) == str

def main():
    userInput = input("Enter a string: ")
    rev_userInput = rev_string(userInput)
    print(rev_userInput)
    
    if rev_userInput == userInput:
        print('%r is a palindrome.'%userInput)

if __name__ == '__main__':
    main()
