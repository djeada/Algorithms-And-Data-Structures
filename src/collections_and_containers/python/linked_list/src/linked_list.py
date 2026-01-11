"""Singly linked list implementation."""

from __future__ import annotations

from typing import Any, Iterator, Optional


class Node:
    """A node in a singly linked list."""

    def __init__(self, data: Any) -> None:
        self.data = data
        self.next: Optional[Node] = None


class LinkedList:
    """A singly linked list data structure."""

    def __init__(self) -> None:
        self.head: Optional[Node] = None
        self.n = 0

    def push_back(self, v: Any) -> None:
        """Add an element to the end of the list."""
        if self.head is None:
            self.head = Node(v)
        else:
            node = self.head
            while node.next is not None:
                node = node.next
            node.next = Node(v)
        self.n += 1

    def push_front(self, v: Any) -> None:
        """Add an element to the front of the list."""
        node = Node(v)
        node.next = self.head
        self.head = node
        self.n += 1

    def pop_back(self) -> Optional[Any]:
        """Remove and return the last element."""
        if self.head is None:
            return None

        last = self.head
        prev = None
        while last.next is not None:
            prev = last
            last = last.next

        if last == self.head:
            self.head = None
        else:
            prev.next = None

        self.n -= 1
        return last.data

    def pop_front(self) -> Optional[Any]:
        """Remove and return the first element."""
        if self.head is None:
            return None

        node = self.head
        self.head = node.next
        self.n -= 1
        return node.data

    def front(self) -> Optional[Any]:
        """Return the first element without removing it."""
        if self.head is None:
            return None
        return self.head.data

    def back(self) -> Optional[Any]:
        """Return the last element without removing it."""
        if self.head is None:
            return None

        node = self.head
        while node.next is not None:
            node = node.next
        return node.data

    def empty(self) -> bool:
        """Check if the list is empty."""
        return self.head is None

    def clear(self) -> None:
        """Remove all elements from the list."""
        self.head = None
        self.n = 0

    def size(self) -> int:
        """Return the number of elements in the list."""
        return self.n

    def remove(self, v: Any) -> None:
        """Remove the first occurrence of an element."""
        if self.head is None:
            return

        if self.head.data == v:
            self.head = self.head.next
            self.n -= 1
            return

        node = self.head
        while node.next is not None:
            if node.next.data == v:
                node.next = node.next.next
                self.n -= 1
                return
            node = node.next

    def __iter__(self) -> Iterator[Any]:
        node = self.head
        while node is not None:
            yield node.data
            node = node.next

    def __str__(self) -> str:
        return str(list(self))

    def __repr__(self) -> str:
        return str(self)
