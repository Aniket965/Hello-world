import time
import requests
import os
from PIL import Image
from io import BytesIO
from selenium import webdriver
from selenium.webdriver.common.by import By

x=input("Enter category name: ")
ctr=0;
url = "https://www.amazon.in/gp/site-directory/"
driver= webdriver.Chrome(executable_path=r'chromedriver.exe')
driver.get(url)
driver.find_element_by_link_text(x).click();
driver.find_element_by_xpath("//span[text()='3 Stars & Up']").click();
a=[];
f = open('file.txt', 'w')
for e in driver.find_elements_by_tag_name("h2"):
	a.append(e.text)
	print(str(ctr+1)+". "+e.text)
	ctr+=1
	f.write(str(ctr+1)+". "+e.text+"\n")
	if(ctr==20):
		break
f.close()
i = 0
for image_element in driver.find_elements_by_tag_name("img"):
	i += 1
	if(i>15 and i<22):
		image_url = image_element.get_attribute("src")
		image_object = requests.get(image_url)
		image = Image.open(BytesIO(image_object.content)).convert("RGBA")
		image.save("image" + str(i-15) + ".png")
	if(i>26):
		image_url = image_element.get_attribute("src")
		image_object = requests.get(image_url)
		image = Image.open(BytesIO(image_object.content)).convert("RGBA")
		image.save("image" + str(i-21) + ".png")
	if(i==35+6):
		break;
