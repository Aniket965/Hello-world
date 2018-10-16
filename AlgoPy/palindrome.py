class Stack:
     def __init__(self):
         self.items = []

     def isEmpty(self):
         return self.items == []

     def push(self, item):
         self.items.append(item)

     def pop(self):
         return self.items.pop()

     def peek(self):
         return self.items[len(self.items)-1]

     def size(self):
         return len(self.items)

def palindrome(item):
         s=Stack()
         for i in item:
             s.push(i)
         s1=""
         while not s.isEmpty():
             s1 += s.pop()

         if (s1==item):
             print("Palindrome")
         else:
             print("not a Palindrome")
palindrome(input("Enter name : "))

input("press<Enter>")



    
    


