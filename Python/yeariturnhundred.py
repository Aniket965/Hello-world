#Predicts the year you turn hundred using python modules a fun little script for beginners

from datetime import datetime #importing a class
cyear =datetime.now().year #calling classes 

print(cyear)

#name=str(input("Name:")) 

age=raw_input("Age:") 
hage=cyear-age+100

print("Hi "+name,"You will turn a 100 years in the year ",hage)
