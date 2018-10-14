# Define custom class Node
class Node:
    def __init__(self, val):
        self.val = val
        self.next = None
# Declare nodes with values 3 and 2 in nodes A and B.
A = Node(3)
B = Node(2)

# Link node A to node B.
A.next = B

# Define variable node as A
node = A

# Print out all values of node network.
while node is not None:
    print(node.val)
    node = node.next
