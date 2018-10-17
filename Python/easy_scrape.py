import requests
from bs4 import BeautifulSoup

#URL to scrape
url = "http://www.google.com"

html_content = requests.get(url).content

#parsing string to html via BS
soup = BeautifulSoup(html_content,'lxml')

#To print all href links
links = soup.find_all('a')

for link in links:
  print(link['href')
