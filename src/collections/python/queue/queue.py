class Queue:
    def __init__(self):
        self.queue = []

    def empty(self):
        return self.queue == []

    def enqueue(self, data):
        self.queue.append(data)

    def dequeue(self):
        data = self.queue[0]
        del self.queue[0]
        return data

    def peek(self):
        return self.queue[0]

    def size(self):
        return len(self.queue)
