# Scrape images from your favorite website!

import requests
from bs4 import BeautifulSoup as bs
import os

# website with images
url = 'insert website here'

# download page for parsing
page = requests.get(url)
soup = bs(page.text, 'html.parser')

# locate all elements with image tag
image_tags = soup.findAll('img')

# create directory for images
if not os.path.exists('picture'):
    os.makedirs('pictures')

# move to new directory
os.chdir('pictures')

# image file name variable
x = 0

# writing images
for image in image_tags:
    try:
        url = image['src']
        response = requests.get(url)
        if response.status_code == 200:
            with open('picture-' + str(x) + '.jpg', 'wb') as f:
                f.write(requests.get(url).content)
                f.close()
                x += 1
    except:
        pass

