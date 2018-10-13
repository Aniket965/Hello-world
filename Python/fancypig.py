from sys import argv
w=argv[1]
vowel=('a','e','i','o','u')
consonants=('b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z')

if w[0] in vowel:
	print(w + 'way')
	
elif (w[0] in consonants) and (w[1] in consonants) and (w[2] in consonants) and (w[3] in consonants):
	w= w[4:] + w[0:4] + 'ay'
	
elif (w[0] in consonants) and (w[1] in consonants) and (w[2] in consonants):
	w= w[3:] + w[0:3] + 'ay'

elif (w[0] in consonants) and (w[1] in consonants):
	w= w[2:] + w[0:2]+ 'ay'

else:
	w= w[1:] + w[0] + 'ay'
	
print(w)