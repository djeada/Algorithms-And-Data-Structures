"""Find the lowest common ancestor of two nodes in a binary tree."""

from __future__ import annotations

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


def find_node(root: Optional[TreeNode], value: int) -> Optional[TreeNode]:
    """
    Find a node with the given value in the tree.

    Args:
        root: The root of the tree to search.
        value: The value to find.

    Returns:
        The node with the given value, or None if not found.
    """
    if not root:
        return None
    if root.value == value:
        return root
    left = find_node(root.left, value)
    if left:
        return left
    right = find_node(root.right, value)
    if right:
        return right
    return None


def lowest_common_ancestor(
    root: Optional[TreeNode], p_value: int, q_value: int
) -> Optional[int]:
    """
    Find the lowest common ancestor of two nodes in a binary tree.

    Args:
        root: The root of the binary tree.
        p_value: The value of the first node.
        q_value: The value of the second node.

    Returns:
        The value of the lowest common ancestor, or None if not found.
    """
    def _lowest_common_ancestor(
        root: Optional[TreeNode], p: TreeNode, q: TreeNode
    ) -> Optional[TreeNode]:
        if not root:
            return None
        if root.value == p.value or root.value == q.value:
            return root
        left = _lowest_common_ancestor(root.left, p, q)
        right = _lowest_common_ancestor(root.right, p, q)
        if left and right:
            return root
        elif left:
            return left
        elif right:
            return right
        else:
            return None

    p = find_node(root, p_value)
    q = find_node(root, q_value)

    if not p or not q:
        return None

    result = _lowest_common_ancestor(root, p, q)
    if result is not None:
        return result.value
    return None
