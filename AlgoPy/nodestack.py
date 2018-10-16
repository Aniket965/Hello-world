class Node:
    def __init__(self, data):
        self.data= data
        self.next= None
class stack:
    def __init__(self,data):
        self.head=Node(data)
        self.tail=None
        self._count=1
    def push(self,data):
        self.tail=Node(data)
        temp=self.head
        if self.head==None:
           a=Node(data)
           self.head=a
        else:    
            while temp.next!=None:
                temp=temp.next
            temp.next=self.tail
            self._count+=1
    def pop(self):
        print(self.tail.data)
        temp=self.head
        if self._count==1:
            self.head=None
            self._count-=1
            return
        else:
            while temp.next.next!=None:
                temp=temp.next
            self._count-=1
            temp.next=None
            self.tail=temp
    def printq(self):
        temp=self.head
        while temp!=None:
            print(temp.data)
            temp=temp.next
    def size(self):
        print(self._count)



s=stack(1)
s.push(2)
s.push(3)

s.size()
s.pop()
print(" ")
s.printq()
s.push(5)
print (" ")
s.pop()
s.pop()
s.pop()
print(" ")
s.push(10)
s.push(22)
s.printq

