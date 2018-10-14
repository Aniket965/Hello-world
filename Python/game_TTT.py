from random import randint
from random import choice
l=[[1,2,3],[4,5,6],[7,8,9]]
board=[1,2,3,4,5,6,7,8,9]
def print_board():
    print()
    print()
    for i in range(0,3):
        for j in range(0,3):
            print(l[i][j],end=" ")
        print()
    print()
def chk_empty_assign(x,ele):
    chk=0
    for i in range(0,3):
        for j in range(0,3):
            if x==l[i][j]:
                l[i][j]=ele
                chk=1
                board.remove(x)
                return
    if chk==0:
        print("OOPS!!!! this is already filled")
        y=int(input("Enter another position:"))
        chk_empty_assign(y,'x')
        return
def check_board(step):
    for i in range(0,3):
        if l[i].count(step)==3:
            print("Player:{} win".format(step))
            return step
    for i in range(0,3):
        c=0
        for j in range(0,3):
            if l[j][i]==step:
                c+=1
                if c==3:
                    print("Player:{} win".format(step))
                    return step
    c=0
    for i in range(0,3):
        if l[i][i]==step:
            c+=1
            if c==3:
                print("Player:{} win".format(step))
                return step
    if l[0][2]==l[1][1]==l[2][0]==step:
        print("Player:{} win".format(step))
        return step
    if board==[]:
        print("Its a tie!!!!!!!!!!!")
        return '0'
    return '1'
print("WELCOME to TIC TAC TOE".center(100,"*"))
print_board()
print("Lets assign you as player 1 and you have assigned x")
chance=randint(1,2)
ch='y'
player1=0
player2=0
while ch=='y':
    l=[[1,2,3],[4,5,6],[7,8,9]]
    board=[1,2,3,4,5,6,7,8,9]
    print("As per random toss player:{} win".format(chance))
    while board!=[]:
        if chance==1:
            x=int(input("Enter any number its your turn:"))
            chk_empty_assign(x,'x')
            chk=check_board('x')
        else:
            o=choice(board)
            chk_empty_assign(o,'o')
            print("player:{} choosed no {}th position".format(chance,o))
            chk=check_board('o')
        print_board()
        if chance==1:
            chance=2
        else:
            chance=1
        
        if chk=='x':
            player1+=1
            break
        elif chk=='o':
            player2+=1
            break
        elif chk=='0':
            break
        else:
            continue
    print()
    print(" "*20,"player:1"," "*10,"player:2")
    print()
    print(" "*25,player1," "*15,player2)
    print()
    print("Thank you")
    ch=input("Do you want to play again(y/n)...").strip().lower()
