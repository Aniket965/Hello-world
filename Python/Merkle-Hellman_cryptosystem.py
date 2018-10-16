from functools import reduce
from itertools import compress
from math import gcd
from random import randint, shuffle


def egcd(a, b):
    if a == 0:
        return b, 0, 1
    else:
        g, x, y = egcd(b % a, a)
        return g, y - (b // a) * x, x


def mulinv(b, n):
    g, x, _ = egcd(b, n)
    if g == 1:
        return x % n


def text_to_bits(text):
    bits = bin(int.from_bytes(text.encode(encoding='utf-8', errors='ignore'), 'big'))[2:]
    return bits.zfill(8 * ((len(bits) + 7) // 8))


def text_from_bits(bits):
    n = int(bits, 2)
    return n.to_bytes((n.bit_length() + 7) // 8, 'big').decode(encoding='utf-8', errors='ignore') or '\0'


def bits_to_list(bits):
    return [int(bit) for bit in bits]


def bits_from_sum_superincreasing_subsequence(superincreasing_sequence, s):
    bits = []
    for b in superincreasing_sequence[::-1]:
        if s >= b:
            bits.append(1)
            s -= b
        else:
            bits.append(0)
    return bits[::-1]


def generate_superincreasing_sequence(count_elements):
    b = []
    for _ in range(count_elements):
        b.append(sum(b) + randint(1, 16))
    return b


def generate_key(n, t):
    a = generate_superincreasing_sequence(n)
    key = a.copy()
    m = []
    w = []
    for _ in range(t):
        m_j = sum(key) + randint(1, 16)
        w_j = randint(1, m_j - 1)
        while gcd(w_j, m_j) != 1:
            w_j = randint(1, m_j - 1)
        key = list(map(lambda x: (x * w_j) % m_j, key))
        m.append(m_j)
        w.append(w_j)
    p = list(range(n))
    shuffle(p)
    key = [key[i] for i in p]
    keys = dict(public=key, private=dict(p=p, m=m, w=w, a=a))
    return keys


def encrypt(plain_text, public_key):
    bits = bits_to_list(text_to_bits(plain_text))
    bits = [0] * (len(public_key) - len(bits)) + bits
    cipher = reduce(lambda a, x: a + x, compress(public_key, bits))
    return cipher


def decrypt(cipher, private_key):
    a = private_key['a']
    p = private_key['p']
    w = private_key['w']
    m = private_key['m']
    d_j = cipher
    for w_j, m_j in zip(w[::-1], m[::-1]):
        d_j = (mulinv(w_j, m_j) * d_j) % m_j
    r = bits_from_sum_superincreasing_subsequence(a, d_j)
    raw = ''.join(str(r[i]) for i in p)
    plain_text = text_from_bits(raw)
    return plain_text


if __name__ == '__main__':
    m = 'Hello World!'
    n = 1024
    t = 8
    keys = generate_key(n, t)
    public_key = keys['public']
    private_key = keys['private']
    c = encrypt(m, public_key)
    print(c)
    p = decrypt(c, private_key)
    print(p)
