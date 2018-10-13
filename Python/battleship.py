# Date: 15/10/2017
from random import randint

exe = True
# to run the game as long as user wishes
while exe:
    # we define a grid for our board
    r1 = [" * ", " * ", " * ", " * ", " * "]
    r2 = r3 = r4 = r5 = r1.copy()
    grid = [r1, r2, r3, r4, r5]
    # we define our internal board
    grid_internal = [r1.copy(), r1.copy(), r1.copy(), r1.copy(), r1.copy()]
    print("\tWelcome to BATTLESHIP\n")
    for j in range(0, 5):
        print(''.join(grid[j]))
    print('')
    # we randomize the positions
    x1 = randint(0, 4)
    x2 = randint(0, 4)
    x3 = randint(0, 4)
    y1 = randint(0, 4)
    y2 = randint(0, 4)
    y3 = randint(0, 4)
    x = [x1, x2, x3]
    y = [y1, y2, y3]
    for i in range(0, 3):
        grid_internal[y[i]][x[i]] = ' X '
    counter = 1
    # we add a counter
    while counter <= 10:
        print("\nChance:", counter)
        # takes input from user
        xin = int(input("Enter x coordinate(1-5):")) - 1
        yin = int(input("Enter y coordinate(1-5):")) - 1
        # penalty if wrong input
        if xin not in range(0, 5) or yin not in range(0, 5):
            print("Invalid input. As a penalty, you lose this chance.")
            counter += 1
            continue
        # determines hit or miss
        if xin in x and yin == y[x.index(xin)]:
            print("\nIt is a hit!\n")
            grid[yin][xin] = ' X '
        else:
            print("\nThat's a miss.\n")
            grid[yin][xin] = ' 0 '
            grid_internal[yin][xin] = ' 0 '
        # prints the board after a Chance
        for j in range(4, -1, -1):
            print(''.join(grid[j]))
        # Ends the game if won
        if grid_internal[y1][x1] == grid[y1][x1] and grid_internal[y2][x2] == grid[y2][x2] and grid_internal[y3][x3] ==\
           grid[y3][x3]:
            print("You win!")
            break
        counter += 1
        # Ends the game if lost
        if counter == 11 and grid_internal != grid:
            print("\n\tGAME OVER\n")
    #This is to ensure correct input
    while True:
        # This is to ask if user wants to play the game again
        playagain = input("If you want to play again, press 'y'.\nIf you want to quit, press 'q'.\n")
        if playagain == 'y':
            exe = True
            break
        else:
            if playagain == 'q':
                exe = False
                break
            else:
                print('Invalid input, try again.\n')
                continue
