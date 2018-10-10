def palindrome(n):
    for i in range(len(n)//2):
        if n[i]!=n[len(n)-i-1]:
            return False
    return True

print("YES") if palindrome(input()) else print("NO")