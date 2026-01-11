"""Calculate the sum of values in a BST within a given range."""

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


def range_sum_of_bst(root: Optional[TreeNode], low: int, high: int) -> int:
    """
    Return the sum of values of all nodes within the range [low, high].

    Uses the BST property to prune branches that cannot contain values
    in the range.

    Args:
        root: The root of the binary search tree.
        low: The lower bound of the range (inclusive).
        high: The upper bound of the range (inclusive).

    Returns:
        The sum of all node values within the range.
    """
    if not root:
        return 0

    if root.value < low:
        return range_sum_of_bst(root.right, low, high)
    elif root.value > high:
        return range_sum_of_bst(root.left, low, high)
    else:
        return (
            root.value
            + range_sum_of_bst(root.left, low, high)
            + range_sum_of_bst(root.right, low, high)
        )
