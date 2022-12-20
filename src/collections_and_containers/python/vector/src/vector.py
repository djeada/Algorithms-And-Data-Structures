from typing import Any


class Vector:
    def __init__(self, capacity: int = 10000):
        self.n = 0
        self.capacity = capacity
        self.data = [None] * self.capacity

    def __iter__(self):
        for i in range(self.n):
            yield self.data[i]

    def __len__(self):
        return self.n

    def __getitem__(self, i: int) -> Any:
        if i < 0 or i >= self.n:
            raise IndexError("Index out of range")
        return self.data[i]

    def __setitem__(self, i: int, value: Any):
        self.data[i] = value

    def size(self) -> int:
        return self.n

    def empty(self) -> bool:
        return self.n == 0

    def front(self) -> Any:
        if self.n == 0:
            raise IndexError("Index out of range")
        return self.data[0]

    def back(self) -> Any:
        if self.n == 0:
            raise IndexError("Index out of range")
        return self.data[self.n - 1]

    def push_back(self, value: Any):
        if self.n == self.capacity:
            self.reserve(self.capacity * 2)
        self.data[self.n] = value
        self.n += 1

    def pop_back(self) -> Any:
        if self.n == 0 or self.n > self.capacity:
            raise IndexError("Index out of range")
        self.n -= 1
        return self.data[self.n]

    def resize(self, size: int):
        if size > self.capacity:
            self.reserve(size)
        self.n = size

    def __eq__(self, other: "Vector") -> bool:
        if self.n != other.n:
            return False
        for i in range(self.n):
            if self.data[i] != other.data[i]:
                return False
        return True

    def clear(self):
        self.n = 0
        self.capacity = 1
        self.data = [None] * self.capacity

    def reserve(self, size: int):
        self.capacity = size
        new_data = [None] * self.capacity
        for i in range(self.n):
            new_data[i] = self.data[i]
        self.data = new_data
