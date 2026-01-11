"""Binary tree right side view - return values visible from the right side."""

from __future__ import annotations

from collections import deque
from typing import Optional


class TreeNode:
    """A node in a binary tree."""

    def __init__(
        self,
        value: int,
        left: Optional[TreeNode] = None,
        right: Optional[TreeNode] = None,
    ) -> None:
        self.value = value
        self.left = left
        self.right = right


def right_side_view(root: Optional[TreeNode]) -> list[int]:
    """
    Return the values of nodes visible from the right side of a binary tree.

    Uses level-order traversal (BFS) and returns the rightmost node at each level.

    Args:
        root: The root node of the binary tree.

    Returns:
        List of values visible from the right side, from top to bottom.
    """
    if not root:
        return []

    queue: deque[TreeNode] = deque([root])
    result: list[int] = []

    while queue:
        size = len(queue)
        for i in range(size):
            node = queue.popleft()
            # If this is the last node in the current level, add its value
            if i == size - 1:
                result.append(node.value)
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)

    return result
