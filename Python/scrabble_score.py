# https://dev.jrgnsn.net/matthew/scrabble_score

import argparse


def argParse():
    parser = argparse.ArgumentParser()
    parser.add_argument('name', nargs='?', default=None)
    return parser.parse_args()


def count_score(name):
    chars = list(name.lower())

    letter_scores = {
        1: ('e', 'a', 'i', 'o', 'n', 'r', 't', 'l', 's', 'u'),
        2: ('d', 'g'), 3: ('b', 'c', 'm', 'p'),
        4: ('f', 'h', 'v', 'w', 'y'), 5: ('k'),
        8: ('j', 'x'), 10: ('q', 'z'),
    }

    score = 0
    for char in chars:
        for k, v in letter_scores.items():
            if char in v:
                score += k
    return score


def main():
    args = argParse()

    if args.name:
        name = args.name
        print(count_score(name))
    else:
        while True:
            name = input('What is your name? ')
            try:
                print('Scrabble score: {}'.format(count_score(name)))
            except KeyboardInterrupt:
                quit()


if __name__ == '__main__':
    main()
