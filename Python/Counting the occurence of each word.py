string=input("Enter string:").split(" ")
word=input("Enter word:")
from collections import Counter
word_count=Counter(string)
print(word_count)
final_count=word_count[word]
print("Count of the word is:")
print(final_count)
