#Elo ranking system
#Each person has a base rating of 1400
#At each given time, PlayerA has a rating Ra and PlayerB has a rating Rb
#when two players are matched up, the probability of winning is calculated with this formula
#P(a)=1/(1+10**((R(b)-R(a)/400)))

#obviously, P(a)+P(b)=1

import math
import random
import time

def Probability(rating1 ,rating2):
    Pa=1.0 * 1.0 / (1 + 1.0 * math.pow(10, 1.0 * (rating2 - rating1) / 400))
    Pb=1.0 * 1.0 / (1 + 1.0 * math.pow(10, 1.0 * (rating1- rating2) / 400))

    print("Probability of winning is")
    print("Pa =", round(Pa, 2)," Pb =", round(Pb, 2))
    return Pa,Pb


def EloRating(Ra, Rb, d):
    K=100
    Pa,Pb=Probability(Ra,Rb)

    #Player1 wins
    if(d==1):
        Ra = Ra + K*(1-Pa)
        Rb = Rb + K*(0-Pb)

    #Player2 wins
    else:
        Ra = Ra + K*(0-Pa)
        Rb = Rb + K*(1-Pb)


    return Ra,Rb


# Ra and Rb are current ELO ratings
Players={
    'Player1':1400,
    'Player2':1400,
    'Player3':1400,
}

i=0

Matches={}

copy=dict(Players)


for name1,rating1 in copy.items():
    for name2,rating2 in copy.items():
        if name1==name2:
            continue
        else:
            match= name1 + " and " + name2
            matchReverse= name2 + " and " + name1

            if matchReverse in Matches:
                continue
            else:
                Matches.update({match:0})


for name1,rating1 in copy.items():
    for name2,rating2 in copy.items():
        if name1==name2:
            continue
        else:
            match= name1 + " and " + name2
            matchReverse= name2 + " and " + name1

            if ((match in Matches) or (matchReverse in Matches)):

                if match in Matches:
                    t1=(Matches[match])
                else:
                    t1=(Matches[matchReverse])

                if ( t1<3):
                    print("Match between", name1,"and", name2)

                    if match in Matches:
                        a=(Matches[match])+1
                        Matches.update({match:a})

                    if matchReverse in Matches:
                        a=(Matches[matchReverse])+1
                        Matches.update({matchReverse:a})

                    # Currently winner is set in random
                    d=random.randint(1,3)
                    rating1=Players[name1]
                    rating2=Players[name2]
                    up1,up2=EloRating(rating1,rating2,d)
                    if(d==1):
                        print("Match won by:",name1)
                    else:
                        print("Match won by:",name2)
                    Players.update({name1:up1})
                    Players.update({name2:up2})

                    i=i+1

print(i)

print(Players)
print(Matches)
