# Utilities
from time import sleep 
import math
import random

# Helper functions.
def clamp(minimum, x, maximum): return max(minimum, min(x, maximum))
def clear(): print("\n" * 100)

# DEFAULT GAME VARIABLES #
# Defines the order in which you should place ships with this length.
BATTLESHIP_LENS = [2, 3, 3, 4, 5]
# Creates 2 empty boards, 1 for the enemy and 1 for you.
PLAYER_BOARD = [[0] * 10 for i in range(10)]
ENEMY_BOARD = [[0] * 10 for i in range(10)]
# A cool seperator.
LINE = "-" * 60
# How many moves the AI has.
MAX_MOVES = 100 # Covers the whole board.

# FUNCTIONS #
def get_coordinates():
    print("Please enter values between 1 and 10 (transformed to fit arrays)")
    # Returns a tuple with 2 inputs (1 being the X value, one being the Y value)
    # Asks the user for an X and Y coordinate value.
    x = input("Coordinate x value: ")
    y = input("Coordinate y value: ")
    
    # Tries to return the integer values of both x and y.
    # If this fails, return the function so it keeps
    # asking the player. If we dont return the function,
    # it will error in the future.
    try:
        return (int(x), int(y))
    except ValueError:
        print("Invalid coordinate value!")
        return get_coordinates()
    
def get_orientation():
    print("Orientation of Ship: Enter Orientation")
    o = input("(either 1 for vertical or 2 for horizontal): ")
    # Checks if the input == 1, if it does then it returns
    # the integer 1 (which maps to vertical),
    # if not it returns the integer 2 (which maps to horizontal.)
    return o=="1" and 1 or 2
    
def print_board(board):
    # Prints a board (based on input)
    for x in range(len(board)):
        # Special case for when it starts printing.
        if x==0:
            # Sets up the first string.
            new_str = ""
            for i in range(len(board) - 1):
                # Adds spaces between the numbers.
                new_str += " " + str(i+1) + " "
            # Appends the roman numeral for 10 (because OCD)
            new_str += " X"
            # Actually prints the string.
            print(new_str)
        
        # Sets up the string.
        str_row = ""
        for y in range(len(board[x])):
            # A stupid 1 line if statement to append to the string.
            # value 0: blank, '[ ]'
            # value 1: ship is present, '[S]'
            # value 2: hit (ship), '[X]'
            # value 3: hit (miss), '[M]'
            str_row += (
                board[x][y]==0 and "[ ]" or (
                    board[x][y]==1 and "[S]" or (
                        board[x][y]==2 and "[X]" or "[M]"
                    )
                )
            )
        # Actually prints the nth row of the board.
        print(str_row + " " + str(x + 1))

def print_board_exclusion(board, exclude_num):
    # Prints a board without exclude_num
    # Useful for when the game starts.
    for x in range(len(board)):
        # Special case for when it starts printing.
        if x==0:
            # Sets up the first string.
            new_str = ""
            for i in range(len(board) - 1):
                # Adds spaces between the numbers.
                new_str += " " + str(i+1) + " "
            # Appends the roman numeral for 10 (because OCD)
            new_str += " X"
            # Actually prints the string.
            print(new_str)
        
        # Sets up the string.
        str_row = ""
        for y in range(len(board[x])):
            # A stupid 1 line if statement to append to the string.
            # value 0 (or exclude_num): blank, '[ ]'
            # value 1: ship is present, '[S]'
            # value 2: hit (ship), '[X]'
            # value 3: hit (miss), '[M]'
            str_row += (
                (board[x][y]==exclude_num or board[x][y]==0) and "[ ]" or (
                    board[x][y]==1 and "[S]" or (
                        board[x][y]==2 and "[X]" or "[M]"
                    )
                )
            )
        # Actually prints the nth row of the board.
        print(str_row + " " + str(x + 1))
        
def valid_ship_position(board, size, position = (1, 1), orientation = 1):
    x, y = position
    # Stupid workaround because of stupid board setup
    x, y = clamp(y - 1, 0, 9), clamp(x - 1, 0, 9) 
    # Clamped size.
    board_size = len(board) - 1
    # Check 1: if the positions are within the bounds of the 
    if y > board_size or x > board_size or y < 0 or x < 0:
        return False
    else:
        # remember that I flipped the X and Y axis.
        
        # If orientation is vertical
        if orientation == 1:
            # If ship bounds are greater than the horizontal height
            if math.floor(x / size) > math.ceil(board_size / size):
                return False
        # If orientation is horizontal
        elif orientation == 2:
            # If ship bounds are greater than the horizontal height
            if math.floor(y / size) > math.ceil(board_size / size):
                return False
        # Invalid orientations just return false.
        else:
            return False
    
    # Check 2: checks the spaces in front / behind the position specified.
    count = 0
    for i in range(size + 1):
        # Maths
        add = int(math.ceil(i / 2))
        # Increments count
        count += 1
        # If count modulus 2 (which is shortened: count % 2 == 0)
        if count % 2:
            # If orientation is vertical
            if orientation == 1:
                # More if statements and failsafes.
                if x - add < 0:
                    return False
                else:
                    if board[x - add][y] == 1:
                        return False
            # If orientation is horizontal
            else:
                # More if statements and failsafes.
                if y - add < 0:
                    return False
                else:
                    if board[x][y - add] == 1:
                        return False
        else:
            # If orientation is vertical
            if orientation == 1:
                # More if statements and failsafes.
                if x + add > board_size:
                    return False
                else:
                    if board[x + add][y] == 1:
                        return False
            # If orientation is horizontal
            else:
                # More if statements and failsafes.
                if y + add > board_size:
                    return False
                else:
                    if board[x][y + add] == 1:
                        return False
    return True
        
def add_ship_to_board(board, size = 3, position = (1, 1), orientation = 1):
    x, y = position
    # Another stupid workaround because of stupid board setup
    x, y = clamp(y - 1, 0, 9), clamp(x - 1, 0, 9)
    # Check if the placement is valid on the board.
    if valid_ship_position(board, size, position, orientation):
        # Initialize variable
        count = 0
        # Set the board at array X [array Y]
        # Goes down X, over Y (was reversed above)
        board[x][y] = 1
        # For loop which covers range (size + 1)
        for i in range(size + 1):
            # Something to help with indexing
            add = int(math.ceil(i / 2))
            # Adds 1 to the count to help for adding the ship pieces near board[x][y]
            count += 1
            # If count modulus 2 (count % 2 == 0 (which is divisible))
            if count % 2:
                if orientation == 1:
                    # If vertical, adds a ship piece above the origin (board[x][y])
                    board[x - add][y] = 1
                else:
                    # Else, adds a ship piece to the left of the origin (board[x][y])
                    board[x][y - add] = 1
            else:
                if orientation == 1:
                    # If vertical, adds a ship piece below the origin (board[x][y])
                    board[x + add][y] = 1
                else:
                    # Else, adds a ship piece to the right of the origin (board[x][y])
                    board[x][y + add] = 1
    else:
        print("Not a valid ship placement!")
    
def generate_enemy_queue():
    # Generates a moveset for the enemy.
    
    # Return value
    ret = []
    # Copies the player board.
    player_board_copy = list(PLAYER_BOARD)
    # Last position the enemy found a ship.
    LASTPOS = (1,1)
    # This is for the enemy when they find a ship on your board.
    # 1 = left, 2 = above, 3 = right, 4 = below
    SIDE = 1
    # Has the enemy found a ship?
    FOUNDSHIP = False
    # The length of the found ship.
    
    # Infinite loop protection
    iters = 0
    
    while True:
        # Iterates by one
        iters += 1
        # If the iterations are greater than the max amount of moves,
        # then break.
        if iters >= MAX_MOVES:
            break
        
        # Counter for the amount of player ships.
        player_ships = 0
        # Goes through the length of the copied board.
        for y in range(len(player_board_copy)):
            # Goes through the length of the (copied board)[y value]
            for x in range(len(player_board_copy[y])):
                # If there is a ship there, increment
                # player_ships by 1.
                if player_board_copy[y][x] == 1:
                    player_ships += 1
        
        # If there are no more ships, then break.
        if player_ships == 0:
            break
        else:
            # If the AI hasnt found a ship yet:
            if not FOUNDSHIP:
                # Chose random coordinates on the board.
                x, y = (random.randint(1, 10), random.randint(1, 10))
                # More stupid workarounds.
                x, y = clamp(y - 1, 0, 9), clamp(x - 1, 0, 9)
                
                # If the enemy has already chosen that spot, keep chosing more
                # random coordinates and then using the stupid workaround (again.)
                while (player_board_copy[x][y] == 2 or player_board_copy[x][y] == 3) or ((x, y) in ret):
                    x, y = (random.randint(1, 10), random.randint(1, 10))
                    x, y = clamp(y - 1, 0, 9), clamp(x - 1, 0, 9) 
                
                # Adds the desired coordinate to the enemy queue
                ret.append((x, y))
                # Sets the last position to the coordinates
                LASTPOS = (x, y)
                
                # If they hit a ship, set FOUNDSHIP to true to start
                # checking the sides.
                if player_board_copy[x][y] == 1:
                    FOUNDSHIP = True
            # Else, check sides.
            else:
                # Gets the last position. It is already clamped
                # so no stupid workarond here.
                x, y = LASTPOS
                # Have I found the next piece of a ship?
                found_next_ship = False
                
                # If the side is 1 (left)
                if SIDE == 1:
                    # Boundary checks. If y - 1 is negative,
                    # increment SIDE by 1.
                    if y - 1 < 0:
                        SIDE += 1
                    else:
                        # If the area to the left of the origin (x, y) has
                        # a ship, append to the queue and sets its last
                        # position to the position that the AI has found the ship.
                        # And, set "found_next_ship" to True, so it keeps checking for
                        # any more ships near the location.
                        # Else, just increment SIDE by 1.
                        if player_board_copy[x][y - 1] == 1:
                            ret.append((x, y - 1))
                            LASTPOS = (x, y - 1)
                            found_next_ship = True
                        else:
                            SIDE += 1
                # If the side is 2 (above)
                elif SIDE == 2:
                    # Boundary checks. If x - 1 is negative,
                    # increment SIDE by 1.
                    if x - 1 < 0:
                        SIDE += 1
                    else:
                        # If the area above the origin (x, y) has
                        # a ship, append to the queue and sets its last
                        # position to the position that the AI has found the ship.
                        # And, set "found_next_ship" to True, so it keeps checking for
                        # any more ships near the location.
                        # Else, just increment SIDE by 1.
                        if player_board_copy[x - 1][y] == 1:
                            ret.append((x - 1, y))
                            LASTPOS = (x - 1, y)
                            found_next_ship = True
                        else:
                            SIDE += 1
                # If the side is 3 (right)
                elif SIDE == 3:
                    # Boundary checks. If y + 1 is greater than
                    # the boundary length of the copied board, then
                    # increment SIDE by 1.
                    if y + 1 > len(player_board_copy):
                        SIDE += 1
                    else:
                        # If the area to the right of the origin (x, y) has
                        # a ship, append to the queue and sets its last
                        # position to the position that the AI has found the ship.
                        # And, set "found_next_ship" to True, so it keeps checking for
                        # any more ships near the location.
                        # Else, just increment SIDE by 1.
                        if player_board_copy[x][y + 1] == 1:
                            ret.append((x, y + 1))
                            LASTPOS = (x, y + 1)
                            found_next_ship = True
                        else:
                            SIDE += 1
                # Else (only option is 4 which is below)
                else:
                    # Boundary checks. If x + 1 is greater than
                    # the boundary length of the copied board, then
                    # increment SIDE by 1.
                    if x + 1 > len(player_board_copy):
                        SIDE = 1
                    else:
                        # If the area below the origin (x, y) has
                        # a ship, append to the queue and sets its last
                        # position to the position that the AI has found the ship.
                        # And, set "found_next_ship" to True, so it keeps checking for
                        # any more ships near the location.
                        # Else, just increment SIDE by 1.
                        if player_board_copy[x + 1][y] == 1:
                            ret.append((x + 1, y))
                            LASTPOS = (x + 1, y)
                            found_next_ship = True
                        else:
                            SIDE = 1
                
                # Have I found the next piece of a ship? If
                # not, then just set FOUNDSHIP to false.
                if found_next_ship == False:
                    FOUNDSHIP = False
    
    return ret
    
def start_game():
    # Actually starts the game.
    
    # Whos turn is it?
    # True: player's
    # False: enemy's
    TURN = True
    # Tracks what round you guys are on.
    ROUND = 0
    # Generates the queue for the enemy.
    QUEUE = generate_enemy_queue()
    
    # While true loop for playing the game.
    while True:
        # If it is your turn
        if TURN:
            print("It is your turn!")
            # Prints a line.
            print(LINE)
            
            # Another status message.
            print("Where to attack? (input coordinates)")
            
            # Gets the coordinates and then uses the
            # stupid workaround. 
            x, y = get_coordinates()
            x, y = clamp(y - 1, 0, 9), clamp(x - 1, 0, 9) 
            
            # If the player has already shot at that location,
            # keep chosing.
            while ENEMY_BOARD[x][y] == 2 or ENEMY_BOARD[x][y] == 3:
                print("You have already hit that spot! Choose another.")
                x, y = get_coordinates()
                x, y = clamp(y - 1, 0, 9), clamp(x - 1, 0, 9) 
            
            # Prints a line.
            print(LINE)
            
            # If there is a ship there, notify the player
            # and then add a "hitmarker" to (x, y)
            if ENEMY_BOARD[x][y] == 1:
                ENEMY_BOARD[x][y] = 2
                print("That was a hit!")
            # Else, just set the marker at the area to a miss.
            else:
                ENEMY_BOARD[x][y] = 3
                print("You missed.")
            
            # Prints the enemy board, but with only the hitmarkers.
            print_board_exclusion(ENEMY_BOARD, 1)
            # Makes it the enemies turn.
            TURN = False
        # Else
        else:
            print("It is the enemy's turn...")
            
            # Sleep for one second.
            sleep(1)
            
            # Get the X and Y values from the queue (already used
            # the workaround here.)
            x, y = QUEUE[0]
            
            # If there is a ship at the queue placement,
            # notify the player and then add a "hitmarker" to (x, y)
            if PLAYER_BOARD[x][y] == 1:
                PLAYER_BOARD[x][y] = 2
                print("The enemy hit one of your ships!")
            # Else, just set the marker at the area to a miss.
            else:
                PLAYER_BOARD[x][y] = 3
                print("The enemy missed.")
            
            # Prints your board.
            print_board(PLAYER_BOARD)
            
            # Pop the move from the queue, so it doesnt play again/
            QUEUE.pop(0)
            # Makes it the player's turn.
            TURN = True
            
        # Prints a line.
        print(LINE)
        # Increments the round counter.
        ROUND += 1
        
        # Since game_is_over returns 2 arguments,
        # status is the boolean and msg is the status message.
        status, msg = game_is_over()
        # If the status == true (game is over), then print stats.
        if status:
            # Game over after N rounds!
            print("Game over after " + str(ROUND) + " rounds!")
            
            # Another line.
            print(LINE)
            
            # Prints if you had win or not (with a stupid 1 line if statement.)
            print(msg == "ENEMY" and "You have lost to the enemy!" or "You have won against the enemy!")
            
            # Prints your board and the enemies board.
            print("Your board:")
            print_board(PLAYER_BOARD)
            print("The enemy's board:")
            print_board(ENEMY_BOARD)
            
            # Then, break the while true loop.
            break
        
        # Sleep for 1 second in between turns.
        sleep(1)
        
def game_is_over():
    # Counter for the amount of player ships.
    player_ships = 0
    # Goes through the length of the copied board.
    for y in range(len(PLAYER_BOARD)):
        # Goes through the length of the (copied board)[y value]
        for x in range(len(PLAYER_BOARD[y])):
            # If there is a ship there, increment
            # player_ships by 1.
            if PLAYER_BOARD[y][x] == 1:
                player_ships += 1
    
    # Counter for the amount of enemy ships.
    enemy_ships = 0
    # Goes through the length of the copied board.
    for y in range(len(ENEMY_BOARD)):
        # Goes through the length of the (copied board)[y value]
        for x in range(len(ENEMY_BOARD[y])):
            # If there is a ship there, increment
            # player_ships by 1.
            if ENEMY_BOARD[y][x] == 1:
                enemy_ships += 1
                
    # If there are no player ships left, then return
    # a status message.
    if player_ships == 0:
        return True, "ENEMY" # Winner is Enemy
    # Else, if there are no enemy ships left, then return
    # a status message.
    elif enemy_ships == 0:
        return True, "PLAYER" # Winner is Player
    # Else, just return false and the status message that the
    # game is still in progress.
    else:
        return False, "PROGRESS" # Game is still in progress
    
def enemy_setup_board():
    # Gives the enemy a board.
    for i in BATTLESHIP_LENS:
        # Gets random cordinates. No workaround here because
        # it is used in valid_ship_position.
        coords = (random.randint(1, 10), random.randint(1, 10))
        
        # Get a random orientation (either horizontal or vertical)
        orientation = random.randint(1, 2)
        
        # If it isnt a valid ship position, keep randomizing.
        while valid_ship_position(ENEMY_BOARD, int(i), coords, orientation) != True:
            coords = (random.randint(1, 10), random.randint(1, 10))
            orientation = random.randint(1, 2)
            
        # Adds the ship to the board if everything is correct.
        add_ship_to_board(ENEMY_BOARD, int(i), coords, orientation)

def player_setup_board():
    # Interactive way of you setting up your board.
    for i in BATTLESHIP_LENS:
        # Status message.
        print("BATTLESHIP SETUP (LENGTH " + str(i) + ")")
        
        # Asks the user for coordinates and orientation.
        coords = get_coordinates()
        orientation = get_orientation()
        
        # Prints a line.
        print(LINE)
        
        # If it isnt a valid ship position, keep asking the player for
        # coordinates and orientation.
        while valid_ship_position(PLAYER_BOARD, int(i), coords, orientation) != True:
            print("Invalid position / orientation! (doesnt fit on board / overlaps)")
            print(LINE)
            coords = get_coordinates()
            orientation = get_orientation()
        
        # After everything, adds the ship to the board and prints your board.
        add_ship_to_board(PLAYER_BOARD, int(i), coords, orientation)
        print_board(PLAYER_BOARD)
        
        # Another line.
        print(LINE)
        
    # Sets up the enemy board.
    enemy_setup_board()
    
    # Starts the game.
    start_game()

if __name__ == '__main__':
    # Actual start of the game.
    print("Battleships")
    print("You have to find the enemies battleships and sink them before")
    print("they sink yours!")
    print("")
    print("The key: ")
    print("    nothing: water")
    print("    M = missed in water")
    print("    S = ship")
    print("    X = hit ship")
    print("")
    sleep(2)
    print(LINE)

    # Sets up the player board.
    player_setup_board()
