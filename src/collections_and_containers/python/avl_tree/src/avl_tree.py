"""AVL Tree (self-balancing binary search tree) implementation."""

from __future__ import annotations

from typing import Any, Optional


class Node:
    """A node in an AVL tree."""

    def __init__(self, value: Any) -> None:
        self.value = value
        self.left: Optional[Node] = None
        self.right: Optional[Node] = None
        self.balance_factor = 0


class AvlTree:
    """A self-balancing AVL tree data structure."""

    def __init__(self) -> None:
        self.root: Optional[Node] = None
        self.n = 0

    def insert(self, value: Any) -> None:
        """Insert a value into the tree."""
        def insert_helper(p: Optional[Node]) -> Node:
            if not p:
                return Node(value)

            if value < p.value:
                p.left = insert_helper(p.left)
            else:
                p.right = insert_helper(p.right)

            right_height = self._height(p.right) if p.right else 0
            left_height = self._height(p.left) if p.left else 0
            p.balance_factor = right_height - left_height
            return self.balance(p)

        self.root = insert_helper(self.root)
        self.n += 1

    def remove(self, value: Any) -> None:
        """Remove a value from the tree."""
        def remove_helper(p: Optional[Node]) -> Optional[Node]:
            if not p:
                return None

            if value == p.value:
                if not p.left:
                    return p.right
                if not p.right:
                    return p.left

                min_value = self.find_min(p.right)
                p.value = min_value
                p.right = remove_helper(p.right)
            elif value < p.value:
                p.left = remove_helper(p.left)
            else:
                p.right = remove_helper(p.right)

            right_height = self._height(p.right) if p.right else 0
            left_height = self._height(p.left) if p.left else 0
            p.balance_factor = right_height - left_height
            return self.balance(p)

        self.root = remove_helper(self.root)
        self.n -= 1

    def contains(self, value: Any) -> bool:
        """Check if the tree contains a value."""
        def contains_helper(p: Optional[Node]) -> bool:
            if not p:
                return False
            if value == p.value:
                return True
            elif value < p.value:
                return contains_helper(p.left)
            else:
                return contains_helper(p.right)

        return contains_helper(self.root)

    def clear(self) -> None:
        """Remove all elements from the tree."""
        self.root = None
        self.n = 0

    def height(self) -> int:
        """Return the height of the tree."""
        return self._height(self.root)

    def _height(self, p: Optional[Node]) -> int:
        if not p:
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
        def in_order_helper(p: Optional[Node], v: list[Any]) -> None:
            if p:
                in_order_helper(p.left, v)
                v.append(p.value)
                in_order_helper(p.right, v)

        v: list[Any] = []
        in_order_helper(self.root, v)
        return v

    def pre_order_traversal(self) -> list[Any]:
        """Return elements in pre-order traversal (root, left, right)."""
        def pre_order_helper(p: Optional[Node], v: list[Any]) -> None:
            if p:
                v.append(p.value)
                pre_order_helper(p.left, v)
                pre_order_helper(p.right, v)

        v: list[Any] = []
        pre_order_helper(self.root, v)
        return v

    def post_order_traversal(self) -> list[Any]:
        """Return elements in post-order traversal (left, right, root)."""
        def post_order_helper(p: Optional[Node], v: list[Any]) -> None:
            if p:
                post_order_helper(p.left, v)
                post_order_helper(p.right, v)
                v.append(p.value)

        v: list[Any] = []
        post_order_helper(self.root, v)
        return v

    def balance(self, p: Optional[Node]) -> Optional[Node]:
        """Balance the tree at node p."""
        if not p:
            return None

        if p.balance_factor == 2:
            if not p.right:
                return p
            if p.right.balance_factor < 0:
                p.right = self.rotate_right(p.right)
            return self.rotate_left(p)
        elif p.balance_factor == -2:
            if not p.left:
                return p
            if p.left.balance_factor > 0:
                p.left = self.rotate_left(p.left)
            return self.rotate_right(p)
        return p

    def rotate_left(self, p: Node) -> Node:
        """Perform a left rotation."""
        q = p.right
        p.right = q.left
        q.left = p
        return q

    def rotate_right(self, p: Node) -> Node:
        """Perform a right rotation."""
        q = p.left
        p.left = q.right
        q.right = p
        return q

    def find_min(self, p: Node) -> Any:
        """Find the minimum value in the subtree rooted at p."""
        while p.left:
            p = p.left
        return p.value
