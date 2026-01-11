"""Red-Black Tree (self-balancing binary search tree) implementation."""

from __future__ import annotations

from typing import Any, Optional


class Node:
    """A node in a Red-Black tree."""

    def __init__(
        self,
        value: Any,
        is_red: bool = True,
        left: Optional[Node] = None,
        right: Optional[Node] = None,
    ) -> None:
        self.value = value
        self.is_red = is_red
        self.left = left
        self.right = right

    def is_left_red(self) -> bool:
        """Check if the left child is red."""
        return self.left is not None and self.left.is_red

    def is_right_red(self) -> bool:
        """Check if the right child is red."""
        return self.right is not None and self.right.is_red


class RedBlackTree:
    """A self-balancing Red-Black tree data structure."""

    def __init__(self) -> None:
        self.root: Optional[Node] = None
        self.n = 0

    def insert(self, value: Any) -> None:
        """Insert a value into the tree."""
        def insert_helper(p: Optional[Node]) -> Node:
            if not p:
                return Node(value, is_red=True)

            if value < p.value:
                p.left = insert_helper(p.left)
            elif value > p.value:
                p.right = insert_helper(p.right)
            else:
                p.value = value

            if p.is_right_red() and not p.is_left_red():
                p = self.rotate_left(p)
            if p.is_left_red() and p.left.is_left_red():
                p = self.rotate_right(p)
            if p.is_left_red() and p.is_right_red():
                self.flip_colors(p)

            return self.balance(p)

        self.root = insert_helper(self.root)
        self.root.is_red = False
        self.n += 1

    def remove(self, value: Any) -> None:
        """Remove a value from the tree."""
        def remove_helper(p: Optional[Node]) -> Optional[Node]:
            if not p:
                return None

            if value < p.value:
                p.left = remove_helper(p.left)
            elif value > p.value:
                p.right = remove_helper(p.right)
            else:
                if not p.left:
                    return p.right
                if not p.right:
                    return p.left

                min_value = self.find_min(p.right)
                p.value = min_value
                p.right = remove_helper(p.right)

            return self.balance(p)

        self.root = remove_helper(self.root)
        if self.root:
            self.root.is_red = False
        self.n -= 1

    def contains(self, value: Any) -> bool:
        """Check if the tree contains a value."""
        def contains_helper(p: Optional[Node]) -> bool:
            if not p:
                return False
            if value < p.value:
                return contains_helper(p.left)
            elif value > p.value:
                return contains_helper(p.right)
            else:
                return True

        return contains_helper(self.root)

    def clear(self) -> None:
        """Remove all elements from the tree."""
        self.root = None
        self.n = 0

    def height(self) -> int:
        """Return the height of the tree."""
        def height_helper(p: Optional[Node]) -> int:
            if not p:
                return 0
            return 1 + max(height_helper(p.left), height_helper(p.right))

        return height_helper(self.root)

    def size(self) -> int:
        """Return the number of elements in the tree."""
        return self.n

    def empty(self) -> bool:
        """Check if the tree is empty."""
        return self.n == 0

    def in_order_traversal(self) -> list[Any]:
        """Return elements in in-order traversal (left, root, right)."""
        def in_order_helper(p: Optional[Node], v: list[Any]) -> None:
            if not p:
                return
            in_order_helper(p.left, v)
            v.append(p.value)
            in_order_helper(p.right, v)

        v: list[Any] = []
        in_order_helper(self.root, v)
        return v

    def pre_order_traversal(self) -> list[Any]:
        """Return elements in pre-order traversal (root, left, right)."""
        def pre_order_helper(p: Optional[Node], v: list[Any]) -> None:
            if not p:
                return
            v.append(p.value)
            pre_order_helper(p.left, v)
            pre_order_helper(p.right, v)

        v: list[Any] = []
        pre_order_helper(self.root, v)
        return v

    def post_order_traversal(self) -> list[Any]:
        """Return elements in post-order traversal (left, right, root)."""
        def post_order_helper(p: Optional[Node], v: list[Any]) -> None:
            if not p:
                return
            post_order_helper(p.left, v)
            post_order_helper(p.right, v)
            v.append(p.value)

        v: list[Any] = []
        post_order_helper(self.root, v)
        return v

    def rotate_left(self, p: Node) -> Node:
        """Perform a left rotation."""
        right = p.right
        p.right = right.left
        right.left = p
        right.is_red = p.is_red
        p.is_red = True
        return right

    def rotate_right(self, p: Node) -> Node:
        """Perform a right rotation."""
        left = p.left
        p.left = left.right
        left.right = p
        left.is_red = p.is_red
        p.is_red = True
        return left

    def flip_colors(self, p: Node) -> None:
        """Flip the colors of a node and its children."""
        p.is_red = not p.is_red
        p.left.is_red = not p.left.is_red
        p.right.is_red = not p.right.is_red

    def move_red_left(self, p: Node) -> Node:
        """Move red to the left child."""
        self.flip_colors(p)
        if p.right and p.right.right and p.right.right.is_red:
            p = self.rotate_left(p)
            self.flip_colors(p)
        return p

    def move_red_right(self, p: Node) -> Node:
        """Move red to the right child."""
        self.flip_colors(p)
        if p.left and p.left.left and p.left.left.is_red:
            p = self.rotate_right(p)
            self.flip_colors(p)
        return p

    def balance(self, p: Node) -> Node:
        """Balance the tree at node p."""
        if p.right and p.right.is_red:
            p = self.rotate_left(p)
        if p.left and p.left.is_red and p.left.left and p.left.left.is_red:
            p = self.rotate_right(p)
        if p.left and p.left.is_red and p.right and p.right.is_red:
            self.flip_colors(p)
        return p

    def find_min(self, p: Node) -> Any:
        """Find the minimum value in the subtree rooted at p."""
        while p.left:
            p = p.left
        return p.value
