"""LRU (Least Recently Used) Cache implementation."""

from __future__ import annotations

from typing import Optional


class ListNode:
    """A node in a doubly linked list."""

    def __init__(self, value: int, next: Optional[ListNode] = None) -> None:
        self.value = value
        self.next = next
        self.prev: Optional[ListNode] = None


class DoubleLinkedList:
    """A doubly linked list for maintaining access order."""

    def __init__(self) -> None:
        self.head: Optional[ListNode] = None
        self.tail: Optional[ListNode] = None

    def insert_before(self, node: Optional[ListNode], value: int) -> ListNode:
        """Insert a new node with the given value before the given node."""
        new_node = ListNode(value)
        if not node:
            self.head = new_node
            self.tail = new_node
        else:
            new_node.next = node
            if node == self.head:
                self.head = new_node
            else:
                new_node.prev = node.prev
                if node.prev:
                    node.prev.next = new_node
            node.prev = new_node
        return new_node

    def insert_after(self, node: Optional[ListNode], value: int) -> ListNode:
        """Insert a new node with the given value after the given node."""
        new_node = ListNode(value)
        if not node:
            self.head = new_node
            self.tail = new_node
        else:
            new_node.prev = node
            if node == self.tail:
                self.tail = new_node
            else:
                new_node.next = node.next
                if node.next:
                    node.next.prev = new_node
            node.next = new_node
        return new_node

    def delete(self, node: ListNode) -> None:
        """Delete the given node from the list."""
        if node == self.head:
            self.head = node.next
        else:
            if node.prev:
                node.prev.next = node.next
        if node == self.tail:
            self.tail = node.prev
        else:
            if node.next:
                node.next.prev = node.prev

    def __iter__(self):
        node = self.head
        while node:
            yield node.value
            node = node.next

    def __str__(self) -> str:
        return " -> ".join(map(str, self))

    def to_list(self) -> list[int]:
        """Convert the linked list to a Python list."""
        return list(self)


class LRUCache:
    """
    A Least Recently Used (LRU) cache implementation.

    When the cache is full, the least recently used item is evicted.
    """

    def __init__(self, capacity: int) -> None:
        """
        Initialize the LRU cache with a given capacity.

        Args:
            capacity: Maximum number of items the cache can hold.
        """
        self.capacity = capacity
        self.size = 0
        self.cache: dict[int, ListNode] = {}
        self.list = DoubleLinkedList()

    def get(self, key: int) -> int:
        """
        Get a value from the cache.

        Args:
            key: The key to look up.

        Returns:
            The value if found, -1 otherwise.
        """
        if key in self.cache:
            node = self.cache[key]
            self.list.delete(node)
            self.list.insert_before(self.list.head, node.value)
            return node.value
        return -1

    def put(self, key: int, value: int) -> None:
        """
        Put a key-value pair into the cache.

        Args:
            key: The key to store.
            value: The value to store.
        """
        if key in self.cache:
            node = self.cache[key]
            self.list.delete(node)
            self.list.insert_before(self.list.head, value)
            self.cache[key] = self.list.head
        else:
            if self.size == self.capacity:
                if self.list.tail:
                    del self.cache[self.list.tail.value]
                    self.list.delete(self.list.tail)
                self.size -= 1
            self.list.insert_before(self.list.head, value)
            self.cache[key] = self.list.head
            self.size += 1
