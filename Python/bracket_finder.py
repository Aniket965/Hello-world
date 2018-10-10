'''
Write a function matched(s) that takes as input a string s and checks if the brackets "(" and ")" in s are matched: that is, every "(" has a matching ")" after it and every ")" has a matching "(" before it. Your function should ignore all other symbols that appear in s. Your function should return True if s has matched brackets and False if it does not.

Here are some examples to show how your function should work.

>>> matched("a)*(?")
  False
>>> matched("((jkl)78(A)&l(8(dd(FJI:),):)?)")
  True
'''


def matched(s):
    charlist = []
    for char in s:
        if char == '(':
            charlist = charlist + [char]
        elif char == ')':
            if len(charlist) == 0:
                return 'False'
            else:
                charlist.pop()
    return len(charlist) == 0