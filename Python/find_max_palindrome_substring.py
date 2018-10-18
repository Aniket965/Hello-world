#! /usr/bin/python
# -*- coding: utf-8 -*-

from itertools import combinations


def is_palindrome(string):
    if string == string[::-1]:
        return True
    return False


def get_palindrome_length(string):
    palindrome_length = 0
    for string_sub_length in range(len(string)-1, 1, -1):
        for string_list in combinations(string, string_sub_length):
            sub_string = ''.join(string_list)
            if is_palindrome(sub_string):
                return len(sub_string)

    return palindrome_length


def max_palindrome_substring(s):
    unique_palindrome_length = set()

    for i in range(0, len(s)):
        initial_substring = s[:i]
        remaining_substring = s[i:]
        initial_substring_palindrome_length = get_palindrome_length(
            initial_substring)
        remaining_substring_palindrome_length = get_palindrome_length(
            remaining_substring)

        if (initial_substring_palindrome_length > 0) and (
                remaining_substring_palindrome_length > 0):
            unique_palindrome_length.add(
                initial_substring_palindrome_length * remaining_substring_palindrome_length)
    return max(unique_palindrome_length)


if __name__ == '__main__':
    string = input()
    max_palindrome_substring(string)
