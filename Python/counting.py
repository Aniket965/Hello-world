def how_many_times_in(string):

    char_results = dict()

    for char in string:
        if char not in char_results:
            char_results[char] = 1
        else:
            char_results[char] += 1

    return char_results

def main():

    char_results = how_many_times_in("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc accumsan sem ut ligula scelerisque sollicitudin. Ut at sagittis augue. Praesent quis rhoncus justo. Aliquam erat volutpat. Donec sit amet suscipit metus, non lobortis massa. Vestibulum augue ex, dapibus ac suscipit vel, volutpat eget massa. Donec nec velit non ligula efficitur luctus.")

    for character in sorted(char_results):
        print(character + ": " + str(char_results[character]))


if __name__ == "__main__":
    main()