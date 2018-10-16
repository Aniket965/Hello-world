def is_isogram(string):
    char_only = ''
    s = string.lower()
    for c in s:
        if c.isalpha():
            char_only += c

    if len(''.join(char_only)) == len(''.join(set(char_only))):
        return True
    else:
        return False
