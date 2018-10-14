PAIRINGS = {
    '(': ')',
    '{': '}',
    '[': ']'
}


def is_balanced(symbols):
    stack = []
    for s in symbols:
        if s in PAIRINGS.keys():
            stack.append(s)
        else:
            try:
                expected_opening_symbol = stack.pop()
            except IndexError:  # too many closing symbols
                return False
            if s != PAIRINGS[expected_opening_symbol]:  # mismatch
                return False
    return len(stack) == 0  # false if too many opening symbols

