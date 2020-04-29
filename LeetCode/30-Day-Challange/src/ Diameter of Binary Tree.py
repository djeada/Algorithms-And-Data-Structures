'''
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode):
        if not root: 
            return 0; 
        
        return max(height(root.left) + height(root.right) , max(self.diameterOfBinaryTree(root.left) , self.diameterOfBinaryTree(root.right))) 
    
    
def height(node): 
    if not node: 
        return 0 ; 
    
    return 1 + max(height(node.left), height(node.right))
