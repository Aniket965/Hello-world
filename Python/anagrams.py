#Python 2.7
#No guarantee the anagram will actually be a word

from random import sample
from math import factorial as fac
from itertools import permutations

def anagrams(s, v=10000):
    anagrams = []
    while len(anagrams) < v and len(anagrams) < fac(len(s)):
        candidate = ''.join(sample(s, len(s)))
        if candidate not in anagrams:
            anagrams.append(candidate)
    return anagrams


def fastanagrams(s):
    anagrams = list(permutations(s, len(s)))
    out = []
    for entry in anagrams:
        out.append(''.join(entry))
    return out
