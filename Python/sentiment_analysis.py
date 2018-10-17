import tweepy
from textblob import TextBlob
import csv

# Step 1 - Authenticate
consumer_key= '---'
consumer_secret= '----'

access_token='--'
access_token_secret='--'

auth = tweepy.OAuthHandler(consumer_key, consumer_secret)
auth.set_access_token(access_token, access_token_secret)

api = tweepy.API(auth)

#Step 3 - Retrieve Tweets
public_tweets = api.search('@aamir_khan')
file=open("tweet.csv","w")


#CHALLENGE - Instead of printing out each tweet, save each Tweet to a CSV file
#and label each one as either 'positive' or 'negative', depending on the sentiment 
#You can decide the sentiment polarity threshold yourself


for tweet in public_tweets:
    
    analysis=TextBlob(tweet.text)
    print(analysis.sentiment)
    if -1 < analysis.sentiment <=0 :
        file.write(tweet.text.encode('utf-8'))
        file.write("\n""negative")
        with open('tweet.csv') as f:

            print " ".join(line.strip() for line in f)  

    
        
    else:
        file.write(tweet.text.encode('utf-8'))
        file.write("\n""positive")
        with open('tweet.csv') as f:
            print " ".join(line.strip() for line in f)  
        
        
file.seek(0)    
    


    
