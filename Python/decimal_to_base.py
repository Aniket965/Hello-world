
def decimal_to_base(n, base):
    """Convert decimal number to any base (2-16)"""

    chars = "0123456789ABCDEF"
    stack = []
    is_negative = False

    if n < 0:
        n = abs(n)
        is_negative = True

    while n > 0:
        remainder = n % base
        stack.append(remainder)
        n = n // base

    result = ""

    while stack:
        result = result + chars[stack.pop()]

    if is_negative:
        return "-"+result
    else:
        return result

