from typing import List


class TreeNode:
    def __init__(self, value: int, left: "TreeNode" = None, right: "TreeNode" = None):
        self.value = value
        self.left = left
        self.right = right


def right_side_view(root: TreeNode) -> List[int]:
    # Edge case: if the tree is empty, return an empty list
    if not root:
        return []
    # Initialize a queue and a result list
    queue = [root]
    result = []
    # Loop until the queue is empty
    while queue:
        # Get the size of the queue
        size = len(queue)
        # Loop through all the nodes in the queue
        for i in range(size):
            # Remove the first node from the queue
            node = queue.pop(0)
            # If this is the last node in the current level, add its value to the result list
            if i == size - 1:
                result.append(node.value)
            # If the node has a left child, add it to the queue
            if node.left:
                queue.append(node.left)
            # If the node has a right child, add it to the queue
            if node.right:
                queue.append(node.right)
    # Return the result list
    return result
