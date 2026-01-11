"""Binary Search Tree implementation."""

from __future__ import annotations

from typing import Any, Optional


class Node:
    """A node in a binary search tree."""

    def __init__(self, data: Any) -> None:
        self.data = data
        self.left: Optional[Node] = None
        self.right: Optional[Node] = None


class BinarySearchTree:
    """A binary search tree data structure."""

    def __init__(self) -> None:
        self.root: Optional[Node] = None
        self.n = 0

    def insert(self, v: Any) -> None:
        """Insert a value into the tree."""
        if self.root is None:
            self.root = Node(v)
        else:
            self._insert(v, self.root)
        self.n += 1

    def _insert(self, v: Any, p: Node) -> None:
        if v < p.data:
            if p.left is None:
                p.left = Node(v)
            else:
                self._insert(v, p.left)
        else:
            if p.right is None:
                p.right = Node(v)
            else:
                self._insert(v, p.right)

    def remove(self, v: Any) -> None:
        """Remove a value from the tree."""
        if self.root.data == v and self.root.left is None and self.root.right is None:
            self.root = None
        else:
            self._remove(v, self.root)
        self.n -= 1

    def _remove(self, v: Any, p: Optional[Node]) -> Optional[Node]:
        def _find_min(p: Optional[Node]) -> Optional[Any]:
            if p is None:
                return None
            while p.left is not None:
                p = p.left
            return p.data

        if p is None:
            return None

        if v < p.data:
            p.left = self._remove(v, p.left)
        elif v > p.data:
            p.right = self._remove(v, p.right)
        else:
            if p.left is None:
                return p.right
            elif p.right is None:
                return p.left
            else:
                p.data = _find_min(p.right)
                p.right = self._remove(p.data, p.right)
        return p

    def contains(self, v: Any) -> bool:
        """Check if the tree contains a value."""
        return self._contains(v, self.root)

    def _contains(self, v: Any, p: Optional[Node]) -> bool:
        if p is None:
            return False
        if v < p.data:
            return self._contains(v, p.left)
        elif v > p.data:
            return self._contains(v, p.right)
        else:
            return True

    def clear(self) -> None:
        """Remove all elements from the tree."""
        self.root = None
        self.n = 0

    def height(self) -> int:
        """Return the height of the tree."""
        if self.root is None:
            return 0
        return self._height(self.root)

    def _height(self, p: Optional[Node]) -> int:
        if p is None:
            return 0
        return 1 + max(self._height(p.left), self._height(p.right))

    def size(self) -> int:
        """Return the number of elements in the tree."""
        return self.n

    def empty(self) -> bool:
        """Check if the tree is empty."""
        return self.n == 0

    def in_order_traversal(self) -> list[Any]:
        """Return elements in in-order traversal (left, root, right)."""
        v: list[Any] = []
        self._in_order_traversal(self.root, v)
        return v

    def _in_order_traversal(self, p: Optional[Node], v: list[Any]) -> None:
        if p is None:
            return
        self._in_order_traversal(p.left, v)
        v.append(p.data)
        self._in_order_traversal(p.right, v)

    def pre_order_traversal(self) -> list[Any]:
        """Return elements in pre-order traversal (root, left, right)."""
        v: list[Any] = []
        self._pre_order_traversal(self.root, v)
        return v

    def _pre_order_traversal(self, p: Optional[Node], v: list[Any]) -> None:
        if p is None:
            return
        v.append(p.data)
        self._pre_order_traversal(p.left, v)
        self._pre_order_traversal(p.right, v)

    def post_order_traversal(self) -> list[Any]:
        """Return elements in post-order traversal (left, right, root)."""
        v: list[Any] = []
        self._post_order_traversal(self.root, v)
        return v

    def _post_order_traversal(self, p: Optional[Node], v: list[Any]) -> None:
        if p is None:
            return
        self._post_order_traversal(p.left, v)
        self._post_order_traversal(p.right, v)
        v.append(p.data)

    def __str__(self) -> str:
        return str(self.in_order_traversal())
