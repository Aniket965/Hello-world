# Set up the Tower of Hanoi

rings = 8
spikes = [[x for x in range(rings, 0, -1)], [], []]
moves = 0


def other(si, ti):
    """
    Retrieves the "other" index that is not equal to the stack index or target stack index.

    Parameters
    ----------
    si : int
        The stack index that would be removed from.
    ti : int
        The target stack index that would be added to.

    Returns
    -------
    int
        The "other" index in the list [0, 1, 2] that equates to the stack index that is unused (not stack index or target stack index).
    """
    other = [0, 1, 2]
    del other[other.index(ti)]
    del other[other.index(si)]
    return other[0]


def add(si, ti):
    """
    Pops the top element of a stack and appends it to another stack.

    Parameters
    ----------
    si : int
        The stack index of the stack that will lose the element.
    ti : int
        The target stack index of the stack that will be appended to.

    Returns
    -------
    None

    """
    global spikes
    print(spikes)
    spikes[ti].append(spikes[si].pop())


def move(si, ti, n):
    """
    Moves a single ring to a destination from a stack

    Parameters
    ----------
    si: int
        The stack index that we want to remove from
    ti: int
        The stack index of the target (that we want to add to)
    n: int
        The number of the ring (lowest = rings, top = 1)

    Returns
    -------
    None
        Performs moves in-line

    Notes
    -----
    The goal is to alternates stacks while moving the ring. We start with the function call move(0, 2, rings).
        Starting with:
            rings=1:
                Add to the target index
            rings=2:
                Add the top ring the "other" index (the one not equal to the stack index or the target index). In this case it would be stack 1.
                Then add to the target index once the top ring is out of the way
                Then we have to add back the top ring to the target index to complete a full move (we wanted to move both rings 1 and 2 to the target index)
            rings=3:
                Perform rings=2, but with the "other" index, add the 3rd ring to the target index, and then move the rings=2 stack in the target index.
            rings=4:
                Perform rings=3, but with the "other" index. Note that the "other" index for rings=2 will change when that is called, alternating where it will be placed.
    Continue until all rings are moved. The minimum number of moves are 2^(rings) - 1, making this algorithm O(2^n) in terms of time complexity. The number of rings remains constant, but is moved around, making the space complexity O(n).
    """
    global moves
    moves += 1
    if n == 1:
        add(si, ti)
    else:
        move(si, other(si, ti), n - 1)
        add(si, ti)
        move(other(si, ti), ti, n - 1)


move(0, 2, rings)
print(spikes)
print(moves)