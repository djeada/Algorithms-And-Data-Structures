class TreeNode:
    def __init__(self, value: int, left: "TreeNode" = None, right: "TreeNode" = None):
        self.value = value
        self.left = left
        self.right = right


def find_node(root: TreeNode, value: int) -> TreeNode:
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


def lowest_common_ancestor(root: TreeNode, p_value: int, q_value: int) -> TreeNode:
    def _lowest_common_ancestor(root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        # Base case: if the root is None, return None
        if not root:
            return None
        # If the root's value is equal to p's or q's value, return the root
        if root.value == p.value or root.value == q.value:
            return root
        # Get the lowest common ancestors of p and q in the left and right subtrees
        left = _lowest_common_ancestor(root.left, p, q)
        right = _lowest_common_ancestor(root.right, p, q)
        # If both left and right are not None, return the root
        if left and right:
            return root
        # If one of them is not None, return the one that is not None
        elif left:
            return left
        elif right:
            return right
        # Otherwise, return None
        else:
            return None

    p = find_node(root, p_value)
    q = find_node(root, q_value)

    result = _lowest_common_ancestor(root, p, q)
    if result is not None:
        return result.value
    return None
