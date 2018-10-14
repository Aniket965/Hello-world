# cook your dish here
import re
s=input("Write a text to find email addresses from them :\n")
my_list=re.findall("[a-zA-Z0-9\.\_\-]+[@]\w+[.][com|org|in|edu]+",s)
for i,j in enumerate(my_list):
    print(f"{i+1} : {j}")
