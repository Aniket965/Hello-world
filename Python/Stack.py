#A stack is a data structure that can be thought of as a stack of pancakes, or books or verticallist
#
#            ----------
# Index --> 3  "Last"
#            ----------
#           2 "Middle"
#            ----------     (Example of a stack with three strings, "First", "Middle" and "Last")
#           1 "First"
#            ----------
#
#A stack is coceptually organized as a vertical list, where the first item is on the bottom, and the last is on the top
#So when an item is added, it goes toward the bottom but appears at the top
#The next item that is added appears on top of the last item
#
#
#                              ----------
#                             2  "Middle"
#         ----------           ----------     (A stack with one value, "First" after the value "Middle" has been added to it)
#        1  "First"    -->    1  "First"
#         ----------           ----------
#
#
#
#With stacks, you can only remove the top element, not any other. The same rules apply for reading and deleting.
#The only way to look at other items is to remove the top item, read the new top item (an internal item before), and then put it back.
#  ___
# |0 0|   <-- Robot that takes action on your stack     |-------------------|
# |_U_|_>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|TOP VALUE: "Middle"|
# @8@8@8|                                               |-------------------|
# @8@8@8|||||||||
# 8_8_8_|      ||
#          ----WW----
#         2 "Middle"
#          ----------    (The robot can only read the top value, its arm isn't long enough...)
#         1 "First"
#          ----------
#_______________________________________________________________________________________________________________________
#
#
#  ___
# |0 0|
# |_U_|_   ||||||||||||||||||||||||||
# @8@8@8|  ||                      ||
# @8@8@8|||||                  ----WW----
# 8_8_8_|                     # "Middle"
#                              ----------
#
#          ----------         (The robot can only remove items from the top of the list)
#         1 "First"
#          ----------
#
#_______________________________________________________________________________________________________________________
#
#  ___
# |0 0|
# |_U_|_
# @8@8@8|
# @8@8@8|||||||||
# 8_8_8_|      ||
#          ----WW----
#         3  "Last"           (The robot can only add items to the top of the stack)
#          ----------
#         2 "Middle"
#          ----------
#         1 "First"
#          ----------
#
#Advantages:
# - Quick access to the top item
# - Easy iteration through all items
# - Structure makes sense for organizing some algorithms

#Disadvantages:
# - Hard to view any other item other than the top
# - Unable to delete items other than the top
# - Can only add items to the top of the stack


#An implementation of a stack using a list
class Stack:

    #Class member variables:
    # list: The whole list of values added to the stack
    # size: The amount of items on the stack
    # last: The last value so it can quickly be retrieved

    #Defining a stack with no items and a size of zero
    def __init__(self):
        self.list = []
        self.size = 0

    #Appending the given value v to the end of the list and incrementing the size
    def push(self,v):
        self.list.append(v)
        self.last = v
        self.size += 1

    #Making the list empty and setting size to be zero if the stack has one or no current item(s)
    #Removing the last value of the list, setting the last value to be the new end of the list and returning the removed value
    def pop(self):
        if len(self.list) <= 1:
            self.list = []
            self.last = None
            self.size == 0
            return None
        else:
            prepeak = self.last
            self.list = self.list[:-1]
            self.last = self.list[-1]
            self.size -= 1
            return prepeak

    #Returing the value of our 'last' member variable
    def peek(self):
        return self.last

    #Adding string conversion to make life easier :)
    def __str__(self):
        return "top=(" + str(self.last) + "), " + "size(" + str(self.size) + ")"
