# Conways game of life

# Test Grids
blinkerGrid = [[0,0,0,0,0],
               [0,0,0,0,0],
               [0,1,1,1,0],
               [0,0,0,0,0],
               [0,0,0,0,0]]

toadGrid = [[0,0,0,0,0],
            [0,0,0,0,0],
            [0,1,1,1,0],
            [1,1,1,0,0],
            [0,0,0,0,0]]

beaconGrid = [[0,0,0,0,0],
              [1,1,0,0,0],
              [1,0,0,0,0],
              [0,0,0,1,0],
              [0,0,1,1,0]]

# Logic to individually check
# for neighbors in each surrounding
# cell. 
def checkNeighbor(x,y,dArray):
    # Boundary Flags
    lBounds = True
    rBounds = True

    # Check x boundaries
    if x == 0:
        lBounds = False
    elif x == (len(dArray[0])-1):
        rBounds = False

    totalNeighbors = 0

    # Count top cells
    if not(y == 0):
        if lBounds:
            if dArray[(y-1)][(x-1)] == 1:
                totalNeighbors += 1
        if rBounds:
            if dArray[(y-1)][(x+1)] == 1:
                totalNeighbors += 1
        if dArray[(y-1)][(x)] == 1:
            totalNeighbors += 1

    # Count left cell
    if lBounds:
        if dArray[(y)][(x-1)] == 1:
                totalNeighbors += 1

    # Count right cell
    if rBounds:
        if dArray[(y)][(x+1)] == 1:
                totalNeighbors += 1

    # Count bottom cells
    if not (y == (len(dArray)-1)):
        if lBounds:
            if dArray[(y+1)][(x-1)] == 1:
                totalNeighbors += 1
        if rBounds:
            if dArray[(y+1)][(x+1)] == 1:
                totalNeighbors += 1
        if dArray[(y+1)][(x)] == 1:
            totalNeighbors += 1

    return totalNeighbors

# Conway's Game of Life logic
# A cell dies if it has <2
# or >3 neighbors. A cell is
# born if it has exactly 3 neighbors
def assignStatus(currStatus, neighborCount):
    newStatus = currStatus
    if currStatus == 0:
        if neighborCount == 3:
            newStatus = 1
    if currStatus == 1:
        if neighborCount < 2:
            newStatus = 0
        if neighborCount > 3:
            newStatus = 0
    
    return newStatus

# Overall main function
# to handle cycling through
# generations
def gameOfLife(gen, dArray):
    genArray = dArray
    for i in xrange(gen):
        print "%i Generation" % (i+1)
        printArray(genArray)
        genArray = cycleArray(genArray)

# Function to cycle through
# 2d array and return a new
# one using the rules for
# conways game of life
def cycleArray(dArray):
    # Create new 2d array
    # using the dimensions
    # of our starting grid
    newArray = [[0]*len(dArray) for i in range(len(dArray))]

    y = 0
    while y < len(dArray):
        x = 0
        while x < len(dArray[y]):
            newArray[y][x] = assignStatus((dArray[y][x]),(checkNeighbor(x,y,dArray)))
            x = x + 1
        y = y + 1

    return newArray

# Simple function to print
# a grid to the command line
def printArray(dArray):
    print "*****************"
    for y in dArray:
        print y


def userIO():
    userOptions()
    handleInput(inputValidation(raw_input("> ")))

def userOptions():
    print "User Options:"
    print "Press 1 for prefabricated simulations"
    print "Press 2 to quit the program"

# Need to make the validInput
# to be created based on which
# module has called it.
def inputValidation(uInput):
    validInput = ["1", "2", "3"]
    checkedInput = uInput
    i = True
    while i:
        if checkedInput not in validInput:
            print "Incorrect Selection: Please type 1, 2, or 3"
            checkedInput = raw_input("> ")
        else:
            i = False
    return checkedInput

def handleInput(uInput):
    if uInput == "1":
        handlePrefab()
    else:
        print "EXITING PROGRAM"
        exit(0)

def handlePrefab():
    print "Current prefabs are merely oscillators"
    print "1. For the Blinker"
    print "2. For the Toad"
    print "3. For the Beacon"
    userInput = inputValidation(raw_input("> "))
    if userInput == "1":
        gameOfLife(5, blinkerGrid)
    elif userInput == "2":
        gameOfLife(5, toadGrid)
    else:
        gameOfLife(5, beaconGrid)
    print "*****************"


def main():
    print "Welcome to the Conway's Game of Life Sim!"
    while True:
        userIO()

main()