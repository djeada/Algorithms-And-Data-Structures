class TreeNode:
    def __init__(self, value: int, left: "TreeNode" = None, right: "TreeNode" = None):
        self.value = value
        self.left = left
        self.right = right


def range_sum_of_bst(root: TreeNode, L: int, R: int) -> int:
    # Base case: if the root is None, return 0
    if not root:
        return 0
    # If the root's value is outside the range, return the range sum of the left or right subtree (whichever is in range)
    if root.value < L:
        return range_sum_of_bst(root.right, L, R)
    elif root.value > R:
        return range_sum_of_bst(root.left, L, R)
    # Otherwise, return the root's value plus the range sum of the left and right subtrees
    else:
        return (
            root.value
            + range_sum_of_bst(root.left, L, R)
            + range_sum_of_bst(root.right, L, R)
        )
