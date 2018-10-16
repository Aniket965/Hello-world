class Queue:
    def __init__(self):
        self.items=[]
    def enqueue(self, item):
        self.items.append(item)
    def dequeue(self):
        self.items.pop(0)
    def size(self):
        return len(self.items)
    def isEmpty(self):
        return self.items==[]
q=Queue()
q.enqueue(54)
q.enqueue(90)
print(q.isEmpty())
print(q.dequeue())
print(input("press<enter>")
