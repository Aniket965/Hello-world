class PallindromeChecker:
    @staticmethod
    def checker(s):
        is_palin = True
        for i in range(0, int(len(s) / 2)):
            if s[i] != s[len(s) - i - 1]:
                is_palin = False

        return is_palin


if __name__ == "__main__":
    s = input("Please enter string to check\n")
    if PallindromeChecker.checker(s):
        print(s, "is a pallindrome")
    else:
        print(s, "is not a pallindrome")
