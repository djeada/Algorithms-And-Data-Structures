"""Convert a binary search tree to a doubly linked list."""

from __future__ import annotations

from typing import Optional


class TreeNode:
    """A node in a binary search tree."""

    def __init__(
        self,
        value: int,
        left: Optional[TreeNode] = None,
        right: Optional[TreeNode] = None,
    ) -> None:
        self.value = value
        self.left = left
        self.right = right


class ListNode:
    """A node in a doubly linked list."""

    def __init__(self, value: int, next: Optional[ListNode] = None) -> None:
        self.value = value
        self.next = next
        self.prev: Optional[ListNode] = None


class DoubleLinkedList:
    """A doubly linked list data structure."""

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


def bst_to_double_linked_list(root: Optional[TreeNode]) -> DoubleLinkedList:
    """
    Convert a binary search tree to a doubly linked list.

    Performs an in-order traversal to maintain sorted order.

    Args:
        root: The root node of the binary search tree.

    Returns:
        A doubly linked list containing all values in sorted order.
    """
    double_linked_list = DoubleLinkedList()
    stack: list[TreeNode] = []
    node = root

    while node or stack:
        if node:
            stack.append(node)
            node = node.left
        else:
            node = stack.pop()
            double_linked_list.insert_before(double_linked_list.head, node.value)
            node = node.right

    return double_linked_list
