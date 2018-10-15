from urllib import urlopen
import requests
from bs4 import BeautifulSoup
import re


page = "https://medium.com/towards-data-science"

pageContent = requests.get(page, headers={'User-Agent': 'Mozilla/5.0'})


webpage = pageContent.text
soup = BeautifulSoup(webpage,'html.parser')

first_information = soup.findAll('a',attrs={'class':'u-block'})

second_information = soup.findAll('div',attrs={'class':'u-letterSpacingTight'})

print(len(first_information),len(second_information))
j=0
for i in range(0,len(first_information)):
    string = first_information[i]['style'].split(" ")[1]
    a = re.search("(?<=\().*(?<=\")",string)
    print(a.group(0).strip("\"")) # The url to the image for the story
    print(first_information[i]['href']) # The link to the story
    print(second_information[j].text) # The title of the story
    print(second_information[j+1].text) # The summary of the story
    j=j+2



