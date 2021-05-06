class Stack:
    def __init__(self):
        self.stack = []

    def empty(self):
        return len(self.stack) == 0

    def push(self, data):
        self.stack.append(data)

    def pop(self):
        data = self.stack[-1]
        del self.stack[-1]
        return data

    def peek(self):
        return self.stack[-1]

    def size(self):
        return len(self.stack)
