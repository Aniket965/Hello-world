oldHello = "hello world"
newHello = ""

for i in range(len(oldHello)):
	if i%2 == 0:
		newHello = newHello + oldHello[i]
	else: 
		newHello = oldHello[i] + newHello
		

print(newHello)
