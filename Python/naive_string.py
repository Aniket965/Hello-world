# An implementation of the Naive String Matching Algorithm In Python

text = input('Enter the text to search in: ')
text = text.lower()

pattern = input('Enter pattern to search for: ')
pattern = pattern.lower()

indexes = []
n = len(text)
m = len(pattern)

for i in range(n - m + 1):
    if text[i] == pattern[0]:
        j = 0
        while j < m:
            if pattern[j] != text[j + i]:
                break
            j = j + 1
        if j == m:
            indexes.append(i + 1)

if indexes:
    print('The Pattern occurs at position:', end=' ')
    for i in indexes:
        print(i, end=', ')
    print()
else:
    print('Pattern Not Found!')
