"""
Binary tree python implementation.
Includes add and find methods too!

The implementation uses Node class as a single entity in the tree and builds up
a BinaryTree class on them.
"""


class Node():
    def __init__(self, data):
        """__init__."""
        self.data = data
        self.left = None
        self.right = None


class BinaryTree():
    def __init__(self):
        """__init__."""
        self.root = None

    def insert(self, data):
        """Insert a value in the tree."""
        if self.root is not None:
            self.root = Node(data=data)
        else:
            self._add(self.root, data)

    def _add(self, node, data):
        if data < node.data:
            if node.left is not None:
                self._add(node=node.left, data=data)
            else:
                node.left = Node(data=data)
        else:
            if node.right is not None:
                self._add(node=node.right, data=data)
            else:
                node.right = Node(data=data)

    def find(self, data):
        """Find a value in the tree."""
        if self.root is None:
            return None
        else:
            return self._find(self.root, data)

    def _find(self, node, data):
        if node.data == data:
            return node
        elif data < node.data and node.left is not None:
            return self._find(node=node.left, data=data)
        elif data > node.data and node.right is not None:
            return self._find(node=node.right, data=data)
        else:
            return None
