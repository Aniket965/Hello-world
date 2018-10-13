import string


def print_rangoli(size):
    letter = string.ascii_lowercase
    letter_list = []

    for i in range(size):
        text = "-".join(letter[i:size])
        letter_list.append((text[::-1] + text[1:]))

    width = len(letter_list[0])

    for j in range(size - 1, 0, -1):
        print(letter_list[j].center(width, "-"))

    for i in range(0, size, 1):
        print(letter_list[i].center(width, "-"))


if __name__ == '__main__':
    n = int(input())
    print_rangoli(n)
