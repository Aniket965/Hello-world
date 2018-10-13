class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

A = Node(3)
B = Node(2)

A.next = B

node = A

while node is not None:
    print(node.val)
    node = node.next