"""Stack implementation using a list."""

from __future__ import annotations

from typing import Any


class Stack:
    """A LIFO (Last In, First Out) stack data structure."""

    def __init__(self, max_size: int = 1000) -> None:
        self.stack: list[Any] = []
        self.max_size = max_size

    def empty(self) -> bool:
        """Check if the stack is empty."""
        return len(self.stack) == 0

    def __eq__(self, other: object) -> bool:
        if isinstance(other, Stack):
            return self.stack == other.stack
        return False

    def pop(self) -> Any:
        """Remove and return the top element."""
        if self.empty():
            raise IndexError("Cannot pop from an empty stack")
        data = self.stack[-1]
        del self.stack[-1]
        return data

    def push(self, data: Any) -> None:
        """Add an element to the top of the stack."""
        if len(self.stack) == self.max_size:
            raise IndexError("Stack is full")
        self.stack.append(data)

    def top(self) -> Any:
        """Return the top element without removing it."""
        if self.empty():
            raise IndexError("Cannot peek at an empty stack")
        return self.stack[-1]

    def size(self) -> int:
        """Return the number of elements in the stack."""
        return len(self.stack)
