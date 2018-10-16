import random
l=['acres','adult','advice','arrangement','attempt','August','Autumn','border','breeze','brick','calm','canal','Casey','cast','chose','claws','coach','constantly','contrast','cookies','customs','damage','Danny','deeply','depth','discussion','doll','donkey','Egypt','Ellen','essential','exchange','exist','explanation','facing','film','finest','fireplace','floating','folks','fort','garage','grabbed','grandmother','habit','happily','Harry','heading','hunter','Illinois','image','independent','instant','January','kids','label','Lee','lungs','manufacturing','Martin','mathematics','melted','memory','mill','mission','monkey','Mount','mysterious','neighborhood','Norway','nuts','occasionally','official','ourselves','palace','Pennsylvania','Philadelphia','plates','poetry','policeman','positive','possibly','practical','pride','promised','recall','relationship','remarkable','require']
word=random.choice(l)
guess=5
p=[]
ans=list("_ "*len(word))
while(guess!=0):
    let=input("Guess a letter")
    if let not in ans and let.isalpha():
        startposition=0
        while True:
            i = word.find(let, startposition)
            if i == -1:
                break
            ans[2*i]=let
            p.append(i)
            startposition = i + 1
        if not p:
            guess=guess-1
            print("The letter you guessed is not there.","You have ",guess," guesses left")
        else:
            print("".join(ans))
            p=[]
    else:
        print("input is repeated or invalid")
        continue
    if "_" not in ans:
        print("Congrats!!! You Won!")
        break
else:
    print("Sorry you are out of guesses. The word was ",word)