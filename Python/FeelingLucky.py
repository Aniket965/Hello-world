# Program implemeting the Google's I am Feeling Lucky Feature in Pyhton
# Prints the link found on Clicking I am Feeling Lucky

#Requirenments
# ->Python3
# ->Requests
# ->Beautifoul Soup 3/4

import requests
from bs4 import BeautifulSoup

query = "Boss"

page = requests.get('https://www.google.com/search?q=' + query)

soup = BeautifulSoup(page.text, 'html.parser')

print (soup.find('cite').text)


