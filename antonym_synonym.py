# Hello-world
#Add any  Program in any language you like or add a hello world Program ❣️ if you like give us :star:


from nltk.corpus import wordnet
synonyms=[]
antonyms=[]
word=input();
for sys in wordnet.synsets(word):
    for l in sys.lemmas():
        synonyms.append(l.name())
        if l.antonyms():
            antonyms.append(l.antonyms()[0].name())


print(set(synonyms))
print(set(antonyms))
