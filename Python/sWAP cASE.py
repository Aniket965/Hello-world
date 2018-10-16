s = 'Hacktoberfest is going on.'

out = ""

for i in s:
  if i.islower():
    out += i.upper()
  elif i.isupper():
    out += i.lower()
  else:
    out += i
  
print out
