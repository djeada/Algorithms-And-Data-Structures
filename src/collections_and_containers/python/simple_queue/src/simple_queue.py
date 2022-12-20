class Queue:
    def __init__(self):
        self.data = []
        self.head = 0
        self.tail = 0
        self.n = 0
        self.maxSize = 10

    def enqueue(self, element):
        if self.n == self.maxSize:
            self.expand()
        self.data.append(element)
        self.n += 1

    def dequeue(self):
        if self.empty():
            return None
        element = self.data[self.head]
        self.head = (self.head + 1) % self.maxSize
        self.n -= 1
        return element

    def front(self):
        if self.empty():
            raise IndexError("Queue is empty")
        return self.data[self.head]

    def back(self):
        if self.empty():
            raise IndexError("Queue is empty")
        return self.data[self.tail - 1]

    def size(self):
        return self.n

    def empty(self):
        return self.n == 0

    def expand(self):
        newData = [0] * (self.maxSize * 2)
        for i in range(self.n):
            newData[i] = self.data[(self.head + i) % self.maxSize]
        self.head = 0
        self.tail = self.n
        self.maxSize *= 2
        self.data = newData[:]

    def __eq__(self, other):
        if isinstance(other, self.__class__):
            return self.__dict__ == other.__dict__
        return False
