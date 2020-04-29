'''
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
'''
class MinStack:

    def __init__(self):
        self.data = []
        self.top_index = -1
        self.min = -1
        
    def push(self, x):
        if self.top_index == -1:
            self.min = x
        elif self.min > x:
            self.min = x
                
        if self.top_index < len(self.data) - 1:
            self.top_index += 1
            self.data[self.top_index] = x
        
        else:
            self.top_index += 1
            self.data.append(x)


    def pop(self):
        self.top_index -= 1
        
        if self.min == self.data[self.top_index + 1]:
            self.min = self.data[self.top_index]
            for x in self.data[:self.top_index + 1]:
                if x < self.min:
                    self.min = x
        
        return self.data[self.top_index + 1]
    
    
    def top(self):
        return self.data[self.top_index]
        
    def getMin(self):
        return self.min
