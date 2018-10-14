from pwn import *
import re
import binascii
# connect to host
URL = 'ctf.example.com'
r = remote(URL, 1337)
# receive data
data = r.recv()

def binary_data_to_word(data):
    bin_word = get_binary_from_string(data)
    # convert 0b110110 (example binary) to word
    word = binascii.unhexlify('%x' % int(bin_word, 2))
    return word

def hex_data_to_word(data):
    hex_string = get_hex_from_string(data)
    return hex_string.decode('hex')

def get_binary_from_string(string):
    # get all numbers from 3 digits
    extracted = re.findall('(\d{3,})', data)
    # merge all numbers to string
    bin_word =  '0b' + ''.join(extracted)
    return bin_word

def get_hex_from_string(string):
    # get all numbers from 3 digits
    extracted = re.search('the (\w+) '[0], data).group(1)
    print('extracted {}', extracted)
    return extracted
print(binary_data_to_word('cPlease give me the 01100011 01100001 01101011 01100101 as a word.'))
word = binary_data_to_word(data)
print('[+] Sending {} to the server'.format(word))
r.send(word + '\n')
response = r.recv()
print('[+] Got response from server {}'.format(word))
word = hex_data_to_word(response)
print('[+] Sending {} to the server'.format(word))
r.send(word + '\n')
resporse = r.recv()
print('[+] Got response from server {}'.format(word))
