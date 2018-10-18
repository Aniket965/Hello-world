# Program to find the number of words and letters in given sentence

def main():
    # s stores the input sentence
    s = input("Please enter your sentence: ")
    # words is an array that stores the words of the sentence 
    words = s.split()
    # wordCount stores the no of words in your senetence
    wordCount = len(words)
    # Printing the number of words
    print("Your word count is:", wordCount) 
    # Printing "Your word count"
main()


