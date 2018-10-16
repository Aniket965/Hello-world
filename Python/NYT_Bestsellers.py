import requests

# My NYT Books API Key
apiKey = ""

print("Welcome to the New York Times Best Sellers List!\n")

bool = True
while (bool == True):
    bool = False
    # User inputs category
    print("Categories: Fiction, Nonfiction, Children's, Monthly Lists")
    category = str(input("Select a category: "))
    # Fiction
    if(category == "Fiction"):
        print("\n~Fiction~")
        print("Combined Print & E-Book Fiction, Hard Cover Fiction, Paperback Trade Fiction")
        type = str(input("Select a type: "))
        if(type == "Hard Cover Fiction"):
            categoryType = "hardcover-fiction"
        elif(type == "Paperback Trade Fiction"):
            categoryType = "trade-fiction-paperback"
        else:
            categoryType = "combined-print-and-e-book-fiction"
    # Nonfiction
    elif(category == "Nonfiction"):
        print("\n~Nonfiction~")
        print("Combined Print & E-Book Nonfiction, Hardcover Nonfiction, Paperback Nonfiction, Advice, How-to & Miscellaneous")
        type = str(input("Select a type: "))
        if(type == "Hard Cover Nonfiction"):
            categoryType = "hardcover-nonfiction"
        elif(type == "Paperback Nonfiction"):
            categoryType = "paperback-nonfiction"
        elif(type == "Advice, How-to & Miscellaneous"):
            categoryType = "advice-how-to-and-miscellaneous"
        else:
            categoryType = "combined-print-and-e-book-nonfiction"
    # Children's
    elif(category == "Children's"):
        print("\n~Children's~")
        print("Middle Grade Hardcover, Picture Books, Series, Young Adult Hardcover")
        type = str(input("Select a type: "))
        if(type == "Middle Grade Hardcover"):
            categoryType = "childrens-middle-grade-hardcover"
        elif(type == "Picture Books"):
            categoryType = "picture-books"
        elif(type == "Series"):
            categoryType = "series-books"
        else:
            categoryType = "young-adult-hardcover"
    # Monthly Lists
    elif(category == "Monthly Lists"):
        print("\n~Monthly Lists~")
        print("Audio Fiction, Audio Nonfiction, Business, Science, Sports & Fitness")
        type = str(input("Select a type: "))
        if(type == "Audio Fiction"):
            categoryType = "audio-fiction"
        elif(type == "Audio Nonfiction"):
            categoryType = "audio-nonfiction"
        elif(type == "Business"):
            categoryType = "business-books"
        elif(type == "Science"):
            categoryType = "science"
        else:
            categoryType = "sports"
    else:
        print("Not a valid entry. Try again.")
        bool = True

# Request for current NYT Best Sellers
r = requests.get("http://api.nytimes.com/svc/books/v3/lists/current/"+categoryType+".json?&api-key="+apiKey)
data = r.json()

# Determines how many books are in a category
index = 0
for i in enumerate(data['results']['books']):
    index+=1

# Prints list of best sellers
print()
for x in range(index):
    print(str(x+1)+". "+ str(data['results']['books'][x]['title'])+" by "+str(data['results']['books'][x]['author']))
