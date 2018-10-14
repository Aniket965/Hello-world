#Do the imports
from nltk import word_tokenize
from nltk.corpus import stopwords

#Read the sentence
sentence = input()

#Tokenize the words
words = word_tokenize(sentence)

#Get stopwords
stop_words = set(stopwords.words('english'))

#Get words in sentence without stopwords
filtered_sentence = [word for word in words if not word in stop_words]

print(filtered_sentence)
