# Python 2.7
# No guarantee the anagram will actually be a word

from random import sample
from math import factorial as fac
from itertools import permutations


def anagrams(s, v=10000):
    anagram_list = []
    while len(anagram_list) < v and len(anagram_list) < fac(len(s)):
        candidate = ''.join(sample(s, len(s)))
        if candidate not in anagram_list:
            anagram_list.append(candidate)
    return anagram_list


def fast_anagrams(s):
    anagram_list = list(permutations(s, len(s)))
    out = []
    for entry in anagram_list:
        out.append(''.join(entry))
    return out
