# https://projecteuler.net/ 
# Problem 6
# Sum square difference

def check(s):
    for i in range(0, int(len(s)/2)):
        if s[i] != s[(len(s)-1)-i]:
            return False
    return True

def palindrome():
    large = 9009
    smallest = 
    for i in range(999, 99, -1):
        for j in range(999, 99, -1):
            num = i * j
            st = str(num)
            if check(st) and num > large:
                large = num
    return large

print(palindrome())
