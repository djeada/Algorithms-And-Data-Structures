"""Dynamic array (vector) implementation."""

from __future__ import annotations

from typing import Any, Iterator


class Vector:
    """A dynamic array data structure similar to std::vector in C++."""

    def __init__(self, capacity: int = 10000) -> None:
        self.n = 0
        self.capacity = capacity
        self.data: list[Any] = [None] * self.capacity

    def __iter__(self) -> Iterator[Any]:
        for i in range(self.n):
            yield self.data[i]

    def __len__(self) -> int:
        return self.n

    def __getitem__(self, i: int) -> Any:
        if i < 0 or i >= self.n:
            raise IndexError("Index out of range")
        return self.data[i]

    def __setitem__(self, i: int, value: Any) -> None:
        self.data[i] = value

    def size(self) -> int:
        """Return the number of elements in the vector."""
        return self.n

    def empty(self) -> bool:
        """Check if the vector is empty."""
        return self.n == 0

    def front(self) -> Any:
        """Return the first element."""
        if self.n == 0:
            raise IndexError("Index out of range")
        return self.data[0]

    def back(self) -> Any:
        """Return the last element."""
        if self.n == 0:
            raise IndexError("Index out of range")
        return self.data[self.n - 1]

    def push_back(self, value: Any) -> None:
        """Add an element to the end of the vector."""
        if self.n == self.capacity:
            self.reserve(self.capacity * 2)
        self.data[self.n] = value
        self.n += 1

    def pop_back(self) -> Any:
        """Remove and return the last element."""
        if self.n == 0 or self.n > self.capacity:
            raise IndexError("Index out of range")
        self.n -= 1
        return self.data[self.n]

    def resize(self, size: int) -> None:
        """Resize the vector to contain 'size' elements."""
        if size > self.capacity:
            self.reserve(size)
        self.n = size

    def __eq__(self, other: object) -> bool:
        if not isinstance(other, Vector):
            return False
        if self.n != other.n:
            return False
        for i in range(self.n):
            if self.data[i] != other.data[i]:
                return False
        return True

    def clear(self) -> None:
        """Remove all elements from the vector."""
        self.n = 0
        self.capacity = 1
        self.data = [None] * self.capacity

    def reserve(self, size: int) -> None:
        """Reserve capacity for at least 'size' elements."""
        self.capacity = size
        new_data: list[Any] = [None] * self.capacity
        for i in range(self.n):
            new_data[i] = self.data[i]
        self.data = new_data
