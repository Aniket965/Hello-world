from random import randint

import matplotlib as mpl
import matplotlib.pyplot as plt


import numpy as np

from sympy import *



def check_row(x,y):
    return x != y

def check_col(x,y):
    return x != y

def check_diagonal(r1,r2,c1,c2):
    return abs(r1-r2) != abs(c1-c2)

def get_num(board, col, n):
    lst = [] 
    for v in range(n):
        num_attack = 0
        #print(v)
        
        for i in range(n):
            if not check_row(board[i],v):
                num_attack += 1  
        #print(num_attack)
        
        for j in range(n):
            if not check_diagonal(v, board[j],col, j) and (not (v == board[j] and  col == j)):
                #print(str(v) + " " + str(col) + "    "+ str(board[j]) + " "+str(j))
                num_attack += 1
        #print(num_attack)
        lst.append(num_attack)   

    return lst         


            
def genetic_algorithm(population):
    p = 0.2
    
    new_popultion = []
    n = len(population)
    while(True):
        for i in range(n):
            x = population[randint(0,n-1)]
            y = population[randint(0,n-1)]
            while x == y:
                y = population[randint(0,n-1)]
            
            child = reproduce(x,y)
            if rand(0,1) <= p:
                mutate(child)
                
            new_popultion.append(child)    
        population = new_popultion      
        ch = check(population)
        if check != None:
            return ch

def check(population):
    m = len(population)
    for i in range(m):
        board = population[i]
        n = len(board)
        temp = n
        sum = 0
        while temp != 0:
            sum += (temp - 1)
            temp -= 1
        
        count = 0
        for i in range(n):
            for j in range(i+1,n):
                if (check_row(board[i], board[j]) and check_col(i,j) and check_diagonal(board[i], board[j],i,j)):
                    count += 1
 
        if count == sum:
            print('successful')
            print('the result is')
            return board  
    return None    
def reproduce(x,y):
    center = randint(0,len(x)-1)
    #print(center)
    new = [x[i] for i in range(center)]
    new += [y[j] for j in range(center, len(x))]
    
    return new

def mutate(x):
    row = randint(0,len(x)-1)
    col = randint(0,len(x)-1)
    x[col] = row
    return x

def generate_random_board(n):
    board = []
    #board = [randint(0, n - 1) for i in range(n)]
    #how(board)
    while(len(board) < n):
        x = randint(0, n - 1)
        if x not in board:
            board.append(x)
    #print(board)
    return board

def max_attack(board):
    lst = []
    n = len(board)
    for i in range(n):
        count = 0
        for j in range(i+1,n):
            if not check_row(board[i],board[j]):
                count += 1
            if not check_diagonal(board[i],board[j], i, j):
                count += 1
                
        lst.append(count)        
    return lst            
                

def apply_nqueens(n):
    board = generate_random_board(n)
    #show(board)
    sum = 0
    temp = n
    while temp != 0:
        sum += (temp - 1)
        temp -= 1
    #print(sum)
    #print (sum)
    test = []    
    while(True):
        count = 0
    
        for i in range(n):
            for j in range(i+1,n):
                if (check_row(board[i], board[j]) and check_col(i,j) and check_diagonal(board[i], board[j],i,j)):
                    count += 1
                #else:
                    #print(str(board[i]) + " " + str(i) +"    " + str(board[j]) + " " + str(j))
    #    print(count)
        #break
        if count == sum:
            print('successful')
            print('the result is')
            return board
        else:    
            #rand_num = randint(0, 7)
            lt = max_attack(board)
            _max = max(lt)
            for i in range(n):
                if _max == lt[i]:
                    num = i
            lst = []
            lst = get_num(board, num,n)
            #print(lst)
            _min = min(lst)
            for i in range(n):
                if _min == lst[i]:
                    c = i
            board[num] = c
            test.append(count)
            if test.count(count) == n * n:
                break               
                                


def displayBoard(locations, shape):
    
    r = c = shape
    cmap = mpl.colors.ListedColormap(['#f5ecce', '#f5ecce'])
    img = mpl.image.imread('three.jpg').astype(np.float)
    boxprops = {"facecolor": "#614532", "edgecolor": "none"}

    x, y = np.meshgrid(range(c), range(r))
    plt.matshow(x % 2 ^ y % 2, cmap=cmap)
    #plt.axis("off")  # eliminate borders from plot

    fig = plt.gcf()
    fig.set_size_inches([r, c])
    scale = 0.6*fig.get_dpi() / max(img.shape)
    ax = plt.gca()
    word = ['one.jpg', 'two.jpg', 'three.jpg', 'four.png', 'five.jpg','six.jpg']
    i = 0
    for dim in locations:
        print(y)
        print(x)
        img = mpl.image.imread(word[i]).astype(np.float)
        scale = 0.6*fig.get_dpi() / max(img.shape)
        i += 1
        box = mpl.offsetbox.OffsetImage(img, zoom=scale)
        ab = mpl.offsetbox.AnnotationBbox(box, (dim[1],dim[0]), bboxprops=boxprops)
        ax.add_artist(ab)

    plt.show()
    return fig


def show(board):
        """Display a chessboard with queens drawn in the locations specified by an
        assignment
        
        Parameters
        ----------
        assignment : dict(sympy.Symbol: Integer)
            A dictionary mapping CSP variables to row assignment of each queen
            
        """
        size = len(board)
        locations = [(i, board[i]) for i in range(size)]
        displayBoard(locations, size)
     

location = [(0,0),(0,1),(0,2),(1,0),(1,1),(1,2),(2,0),(2,1)]
size = 3
displayBoard(location, size)

"""        
arr1 = [0,1,2,3,4,5,6,7]
arr2 = [7,6,5,4,3,2,1,0]
print(reproduce(arr1,arr2))
  for i in range(10):
    x = apply_nqueens(4)
    if x != None:
        show(x)
popu = []    
for i in range(4):
    popu.append(generate_random_board)

print(popu)    
"""