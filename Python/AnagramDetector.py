"""
Write a function in your favorite programming language that will accept any two 
strings as parameters and return "1" if they are anagrams and "0" if they are not.
For simplicity's sake, focus only on strings composed from uppercase 
letters (in hex ASCII - from 41 (A) to 5A (Z)) and space characters.
"""
def are_anagrams(a,b):
    letters = {}
	
	# Contamos las ocurrencias de cuantas veces aparece una letra, por tanto, 
	# la llave del dict son las letras y los values son las veces q aparecen en los 
	# string q pasamos como caracteres, si aun no esta su valor sera 1 pero si ya esta, 
	# se le resta 1 letters = {'A':1}
    for c in a:
        if c.isupper():
            letters[c] = letters.get(c, 0) + 1
            
    for c in b:
        if c.isupper():
            letters[c] = letters.get(c, 0) - 1

	# devuelve true si no tiene valores [0, False, '', 0.0, [], {}, None] 
	# (which all have boolean values of False) then any(letters.values()) would be False
    if any(letters.values()): 
        return 0 # they not anagrams 
    else:
        return 1 # they do 
		
print are_anagrams("SOMA", "AMOS")
print are_anagrams("SOMA", "AMOSS")
