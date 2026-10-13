"""Simple queue implementation using a circular buffer."""

from __future__ import annotations

from typing import Any, Optional


class Queue:
    """A FIFO (First In, First Out) queue data structure."""

    def __init__(self) -> None:
        self.max_size = 10
        self.data: list[Any] = [None] * self.max_size
        self.head = 0
        self.tail = 0
        self.n = 0

    def enqueue(self, element: Any) -> None:
        """Add an element to the back of the queue."""
        if self.n == self.max_size:
            self.expand()
        self.data[self.tail] = element
        self.tail = (self.tail + 1) % self.max_size
        self.n += 1

    def dequeue(self) -> Optional[Any]:
        """Remove and return the front element."""
        if self.empty():
            return None
        element = self.data[self.head]
        self.data[self.head] = None
        self.head = (self.head + 1) % self.max_size
        self.n -= 1
        return element

    def front(self) -> Any:
        """Return the front element without removing it."""
        if self.empty():
            raise IndexError("Queue is empty")
        return self.data[self.head]

    def back(self) -> Any:
        """Return the back element without removing it."""
        if self.empty():
            raise IndexError("Queue is empty")
        return self.data[(self.tail - 1) % self.max_size]

    def size(self) -> int:
        """Return the number of elements in the queue."""
        return self.n

    def empty(self) -> bool:
        """Check if the queue is empty."""
        return self.n == 0

    def expand(self) -> None:
        """Double the capacity of the queue."""
        new_data: list[Any] = [None] * (self.max_size * 2)
        for i in range(self.n):
            new_data[i] = self.data[(self.head + i) % self.max_size]
        self.head = 0
        self.tail = self.n
        self.max_size *= 2
        self.data = new_data[:]

    def __eq__(self, other: object) -> bool:
        if isinstance(other, self.__class__):
            # Compare logical contents, not the internal ring-buffer layout.
            return self.n == other.n and all(
                self.data[(self.head + i) % self.max_size]
                == other.data[(other.head + i) % other.max_size]
                for i in range(self.n)
            )
        return False
