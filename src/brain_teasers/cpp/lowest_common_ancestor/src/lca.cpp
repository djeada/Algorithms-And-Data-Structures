#include "lca.h"

// Helper function to find if a value exists in the tree
static bool findNode(TreeNode* root, int val) {
    if (root == nullptr) return false;
    if (root->val == val) return true;
    return findNode(root->left, val) || findNode(root->right, val);
}

TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
    if (root == nullptr) {
        return nullptr;
    }
    
    // If current node matches either p or q, it could be the LCA
    if (root->val == p || root->val == q) {
        return root;
    }
    
    // Recursively search left and right subtrees
    TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
    TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);
    
    // If both sides found something, current node is LCA
    if (leftLCA != nullptr && rightLCA != nullptr) {
        return root;
    }
    
    // Return whichever side found something
    return (leftLCA != nullptr) ? leftLCA : rightLCA;
}
