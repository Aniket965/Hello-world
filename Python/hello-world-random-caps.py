from random import choice

a = "hello world"
choices = ["up", "low"]
n = 0
c = ""


for i in a:
  b = choice(choices)
  if b == "up":
    c = c + a[n].upper()
  else:
    c = c + a[n].lower()
  n +=1
print(c)
