#Linked lists are similar to normal arrays/lists, except instead of being found by position, they are found based on their connections
#A linked is represented by a series of nodes(values) being connected to each other.
#The first node, is referred to as the root, or head node
#
#      ROOT NODE               0                      1                     2
#     |----------|        |----------|          |----------|          |----------|
#     |          |        |          |          |          |          |          |
#     |  $HEAD$  |========| "First"  |==========| "Middle" |==========|  "Last"  |
#     |          |        |          |          |          |          |          |
#     |----------|        |----------|          |----------|          |----------|
#
#     (A linked list with three values, "First", "Middle" and "Last")
#
#In a linked list, you only have access to the root node, so to find the values of other nodes, you need to look at the connection of each Node
#A removal can be done by changing the connection to the Node before it (the one you want to delete) to the node after it.
#To add a node, just connect a node to he last node...
#
#
#      ROOT NODE               0                                            1
#     |----------|        |----------|                                |----------|
#     |          |        |          |                                |          |
#     |  $HEAD$  |========| "First"  |==========*****WW******=========|  "Last"  |
#     |          |        |          |               ||               |          |
#     |----------|        |----------|               ||               |----------|
#                                                    ||
#                                                    ||
#                                ___                 ||
#                               |0 0|    |||||||||||||| (The robot removes the "middle" node by connecting the "first" node to the "last" node
#                              _|_U_|_   ||
#                              |@8@8@8|||||
#                              |@8@8@8|              #
#                              |8_8_8_|////     |----------|
#                                        //     |          |
#                                        ///////K "Middle" |
#                                               |          |
#                                               |----------|
#
#_______________________________________________________________________________________________________________________

#The code is Below

#A node class representing one item in our linked list
class Node:

    #Class member variables
    # data: The value wanted to be stored in the current node
    # next: A Node object being the next node in the list

    #Intalizing a new Node with the specified data, adding references and changing the data can be done through the member variables
    def __init__(self, data):
        self.data = data
        self.next = None

#A class that organizes basic operations done with Nodes
class LinkedList:
    #Class member variables
    # head: The root Node that starts the Node "chain". It cannot be deleted in our case.
    # size: A counter that keep track of the amount of Nodes in the list

    #Initalizing the head (root) Node of the list with the unique value "$HEAD$" and a size of 0
    def __init__(self):
        self.head = Node("$HEAD$")
        self.size = 0

    #Creating a new Node based on the specified value(data paramater).
    #Adding a Node by crawling to the end of the Node chain, then setting the "next" variable of the last Node to be our new Node
    #Incrementing the size to keep the size member variable accurate
    def add(self,data):
        currentNode = self.head
        while currentNode.next != None:
                currentNode = currentNode.next

        currentNode.next = Node(data)
        self.size += 1

    #Doing nothing if the their are no Node to crawl
    #Removing a Node by using the same crawling technqiue, but keeping track of the Node before the checked Node
    #(the Node that's next value is the checked Node) and after it (the next value of the checked Node)
    #Crawling with a for loop to prevent infinity
    #Revoming the current node by setting the before Node's next value to be the removed Node's next value. Also subtracting one to the counter.
    def remove(self,data):
        beforeNode = self.head
        currentNode = self.head.next
        if(currentNode != None):
            for i in range(self.size):
                    if (currentNode.data != data):
                        beforeNode = currentNode
                        currentNode = currentNode.next
                    else:
                        beforeNode.next = currentNode.next
                        self.size -= 1

    #Adding string conversion to make life easier :)
    def __str__(self):
        if(self.size == 0):
            firstval = "NONEXISTENT"
            nextval = "NONEXISTENT"
        elif(self.size == 1):
            firstval = self.head.next.data
            nextval = "NONEXISTENT"
        else:
            firstval = self.head.next.data
            nextval = self.head.next.next.data

        return "first=(" + str(firstval) + "), " + "next=(" + str(nextval) + "), " + "size=(" + str(self.size) + ")"
