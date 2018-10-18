# Ron Swanson from "Parks and Rec" Quote Generator

import urllib
import json
import time

quotes = input('How many Ron Swanson quotes do you want? ')
print ('\n')
jsonaddress = 'http://ron-swanson-quotes.herokuapp.com/v2/quotes/' + quotes
url = urllib.request.urlopen(jsonaddress)
data = json.loads(url.read().decode())

for i in range(0, len(data)):
    print(data[i])
