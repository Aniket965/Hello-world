from collections import defaultdict
import time
import numpy as np
import os
from math import ceil


class MinHeap:
    """
    Implementation of Min Heap data structure
    """
    def __init__(self, arr=None):
        self.heap = []
        self.heap_size = 0
        if arr is not None:
            self.create_min_heap(arr)
            self.heap = arr
            self.heap_size = len(arr)

    def size(self):
        return self.heap_size

    def create_min_heap(self, arr):
        """
        Converts a given array into a min heap
        :param arr: input array of numbers
        """
        n = len(arr)

        # last n/2 elements will be leaf nodes (CBT property) hence already min heaps
        # loop from n/2 to 0 index and convert each index node into min heap
        for i in range(int(n / 2), -1, -1):
            self.min_heapify(i, arr, n)

    def min_heapify(self, indx, arr, size):
        """
        Assuming sub trees are already min heaps, converts tree rooted at current indx into a min heap.
        :param indx: Index to check for min heap
        """
        # Get index of left and right child of indx node
        left_child = indx * 2 + 1
        right_child = indx * 2 + 2

        smallest = indx

        # check what is the smallest value node in indx, left child and right child
        if left_child < size:
            if arr[left_child].get_cost() < arr[smallest].get_cost():
                smallest = left_child
        if right_child < size:
            if arr[right_child].get_cost() < arr[smallest].get_cost():
                smallest = right_child

        # if indx node is not the smallest value, swap with the smallest child
        # and recursively call min_heapify on the respective child swapped with
        if smallest != indx:
            arr[indx], arr[smallest] = arr[smallest], arr[indx]
            self.min_heapify(smallest, arr, size)

    def insert(self, value):
        """
        Inserts an element in the min heap
        :param value: value to be inserted in the heap
        """
        self.heap.append(value)
        self.heap_size += 1

        indx = self.heap_size - 1

        # Get parent index of the current node
        parent = int(ceil(indx / 2 - 1))

        # Check if the parent value is smaller than the newly inserted value
        # if so, then replace the value with the parent value and check with the new parent
        while parent >= 0 and self.heap[indx].get_cost() < self.heap[parent].get_cost():
            self.heap[indx], self.heap[parent] = self.heap[parent], self.heap[indx]
            indx = parent
            parent = int(ceil(indx / 2 - 1))

    def delete(self, indx):
        """
        Deletes the value on the specified index node
        :param indx: index whose node is to be removed
        :return: Value of the node deleted from the heap
        """
        if self.heap_size == 0:
            print("Heap Underflow!!")
            return

        self.heap[-1], self.heap[indx] = self.heap[indx], self.heap[-1]
        self.heap_size -= 1

        self.min_heapify(indx, self.heap, self.heap_size)

        return self.heap.pop()

    def extract_min(self):
        """
        Extracts the minimum value from the heap
        :return: extracted min value
        """
        return self.delete(0)


class Board:
    """
        Class to represent the  n x n Board / Matrix
        Stores the parent node of a board i.e. the board from which the new board was derived
        Stores the row, col of the blank space (0) on the board
        Stores the boards children if they exist else None
        Stores the manhattan heuristic of the board and moves made so far
    """
    def __init__(self, arr=None, parent=None, s_r=None, s_c=None):
        self.arr = []

        for row in arr:
            self.arr.append([])
            for elem in row:
                self.arr[-1].append(elem)

        self.parent = parent
        self.up = None
        self.down = None
        self.left = None
        self.right = None
        self.space_row = s_r
        self.space_col = s_c
        self.manhattan = self.get_manhattan()
        self.moves = 0
        if parent is not None:
            self.moves = parent.moves

    def get_manhattan(self):
        """
        Calculates the manhattan heuristic of the given board
        :return: the value of manhattan heuristic
        """
        n = len(self.arr)
        global coordinates_sol
        coordinates_board = defaultdict(list)

        for i in range(0, n):
            for j in range(0, n):
                coordinates_board[self.arr[i][j]] = [i, j]

        dist = 0
        for i in range(n**2 - 1):
            dist += (abs(coordinates_sol[i][0] - coordinates_board[i][0]) +
                     abs(coordinates_sol[i][1] - coordinates_board[i][1]))
        return dist

    def get_cost(self):
        """
        calculates the moves coved so far + manhattan heuristic
        :return: returns the expected cost
        """
        return self.manhattan + self.moves

    def move_up(self):
        """
        Function to move one tile up in the board
        :return: True if shifting is possible else False
        """
        if self.space_row + 1 >= len(self.arr):
            return False

        self.arr[self.space_row][self.space_col] = self.arr[self.space_row + 1][self.space_col]
        self.arr[self.space_row + 1][self.space_col] = 0
        self.space_row += 1
        self.manhattan = self.get_manhattan()
        self.moves += 1
        return True

    def move_down(self):
        """
        Function to move one tile down in the board
        :return: True if shifting is possible else False
        """
        if self.space_row - 1 < 0:
            return False

        self.arr[self.space_row][self.space_col] = self.arr[self.space_row - 1][self.space_col]
        self.arr[self.space_row - 1][self.space_col] = 0
        self.space_row -= 1
        self.manhattan = self.get_manhattan()
        self.moves += 1
        return True

    def move_left(self):
        """
        Function to move one tile left in the board
        :return: True if shifting is possible else False
        """
        if self.space_col + 1 >= len(self.arr):
            return False

        self.arr[self.space_row][self.space_col] = self.arr[self.space_row][self.space_col + 1]
        self.arr[self.space_row][self.space_col + 1] = 0
        self.space_col += 1
        self.manhattan = self.get_manhattan()
        self.moves += 1
        return True

    def move_right(self):
        """
        Function to move one tile right in the board
        :return: True if shifting is possible else False
        """
        if self.space_col - 1 < 0:
            return False

        self.arr[self.space_row][self.space_col] = self.arr[self.space_row][self.space_col - 1]
        self.arr[self.space_row][self.space_col - 1] = 0
        self.space_col -= 1
        self.manhattan = self.get_manhattan()
        self.moves += 1
        return True


def get_final_board(n):
    """
    :param n: size of the board (n x n)
    :return: 2-D array of Final required board representation
    """
    solution = []
    k = 1
    for i in range(n):
        solution.append([])
        for j in range(n):
            solution[-1].append(k)
            k += 1
    solution[n-1][n-1] = 0
    return solution


def solvable(board, n):
    """
    :param board: board representation to check for solvability
    :param n: size of the board (n x n)
    :return: True if board is solvable puzzle else False
    """
    arr = []
    for i in range(n):
        for j in range(n):
            if board.arr[i][j] == 0:
                continue
            arr.append(board.arr[i][j])

    m = n**2 - 1
    inv_count = 0
    for i in range(m):
        for j in range(i + 1, m):
            if arr[i] > arr[j]:
                inv_count += 1

    if n % 2 != 0:
        if inv_count % 2 == 0:
            return True
        return False
    else:
        if (inv_count + board.space_row) % 2 != 0:
            return True
        return False


def astar(board):
    """
    Performs A* over the board
    :param board: initial board representation
    :param n: size of the board (n x n)
    :return: Final board object, [number of iterations of while loop, max size of queue, unique boards seen]
    """
    iterations = 0
    max_size = 0
    global solution

    q = MinHeap()
    seen_boards = set()
    seen_boards.add(tuple(np.array(board.arr).flatten()))
    q.insert(board)

    # Run until priority queue is not empty
    while q.size() != 0:
        iterations += 1
        max_size = max(max_size, q.size())
        board = q.extract_min()

        # If board is same as the final require solution, we are done, return
        if board.arr == solution:
            return board, [iterations, max_size, len(seen_boards)]

        # Move tile up board
        up_board = Board(board.arr, board, board.space_row, board.space_col)
        if up_board.move_up():
            if tuple(np.array(up_board.arr).flatten()) not in seen_boards:
                q.insert(up_board)
                seen_boards.add(tuple(np.array(up_board.arr).flatten()))
                board.up = up_board

        # Move tile down board
        down_board = Board(board.arr, board, board.space_row, board.space_col)
        if down_board.move_down():
            if tuple(np.array(down_board.arr).flatten()) not in seen_boards:
                q.insert(down_board)
                seen_boards.add(tuple(np.array(down_board.arr).flatten()))
                board.down = down_board

        # Move tile left board
        left_board = Board(board.arr, board, board.space_row, board.space_col)
        if left_board.move_left():
            if tuple(np.array(left_board.arr).flatten()) not in seen_boards:
                q.insert(left_board)
                seen_boards.add(tuple(np.array(left_board.arr).flatten()))
                board.left = left_board

        # Move tile right board
        right_board = Board(board.arr, board, board.space_row, board.space_col)
        if right_board.move_right():
            if tuple(np.array(right_board.arr).flatten()) not in seen_boards:
                q.insert(right_board)
                seen_boards.add(tuple(np.array(right_board.arr).flatten()))
                board.right = right_board


def print_board(board, n, file):
    """
    Print the board values in the report
    :param board: initial board representation
    :param n: size of the board (n x n)
    :param file: File object where data will be written
    """
    for i in range(n):
        for j in range(n):
            file.write("{} ".format(board.arr[i][j]))
        file.write("\n")


def print_steps(board, n, file):
    """
    Print the Steps required to solve the puzzle with boards
    :param board: initial board representation
    :param n: size of the board (n x n)
    :param file: File object where data will be written
    """
    arr = []
    while board is not None:
        arr.append(board)
        board = board.parent

    for i in range(len(arr)-1, 0, -1):
        if arr[i].up == arr[i - 1]:
            file.write("Up\n")
        elif arr[i].down == arr[i - 1]:
            file.write("Down\n")
        elif arr[i].left == arr[i - 1]:
            file.write("Left\n")
        else:
            file.write("Right\n")
        print_board(arr[i - 1], n, file)
        file.write("\n")


# Starter code:
n = int(input("Enter value of n for n x n problem: "))
print("Enter Initial Configuration as follows:")
print("Example 4 x 4 box: ")
print("5 6 7 8 \n1 2 3 4 \n9 0 11 12 \n13 14 15 10\n")

# Take initial board representation
print("Enter your {} x {} configuration: ".format(n, n))
initial_board = []

for i in range(n):
    initial_board.append(list(map(int, input().split(" "))))
    if len(initial_board[-1]) != n:
        print("Wrong input!!")
        exit(0)

# Input validation
s_r = -1
s_c = -1
for i in range(n):
    for j in range(n):
        if not (1 <= initial_board[i][j] <= n**2 - 1):
            if initial_board[i][j] == 0:
                s_r = i
                s_c = j
            else:
                print("Wrong input!!")
                exit(0)

solution = get_final_board(n)
coordinates_sol = defaultdict(list)
for i in range(0, n):
    for j in range(0, n):
        coordinates_sol[solution[i][j]] = [i, j]

start_board = Board(initial_board, s_r=s_r, s_c=s_c)

if not solvable(start_board, n):
    print("The given board is not solvable")
    exit(0)

print("Solving...")

start_time = time.perf_counter()
final_board, stats = astar(start_board)
end_time = time.perf_counter()

with open(os.path.join(os.curdir, 'astar_report.txt'), 'w') as f:
    print("Time taken:", end_time - start_time)
    f.write("Time taken: {}\n".format(end_time - start_time))

    print("Number of A* iterations:", stats[0])
    f.write("Number of A* iterations: {}\n".format(stats[0]))

    print("Max size of A* Queue:", stats[1])
    f.write("Max size of A* Queue: {}\n".format(stats[1]))

    print("Unique boards seen:", stats[2])
    f.write("Unique boards seen: {}\n".format(stats[2]))

    f.write("\nSteps:\n")

    print_board(start_board, n, f)
    f.write("\n")
    print_steps(final_board, n, f)
