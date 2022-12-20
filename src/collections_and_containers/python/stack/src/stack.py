class Stack:
    def __init__(self, max_size=1000):
        self.stack = []
        self.max_size = max_size

    def empty(self):
        return len(self.stack) == 0

    def __eq__(self, other):
        # Check if the current stack is equal to another stack
        if isinstance(other, Stack):
            return self.stack == other.stack
        return False

    def pop(self):
        if self.empty():
            raise IndexError("Cannot pop from an empty stack")
        data = self.stack[-1]
        del self.stack[-1]
        return data

    def push(self, data):
        if len(self.stack) == self.max_size:
            raise IndexError("Stack is full")
        self.stack.append(data)

    def top(self):
        if self.empty():
            raise IndexError("Cannot peek at an empty stack")
        return self.stack[-1]

    def size(self):
        return len(self.stack)
