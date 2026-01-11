#pragma once

#include <vector>

/**
 * TreeNode for binary tree representation.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int v = 0) : val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode* l, TreeNode* r) : val(v), left(l), right(r) {}
};

/**
 * Find the lowest common ancestor (LCA) of two nodes in a binary tree.
 * 
 * @param root Root of the binary tree
 * @param p First node value
 * @param q Second node value
 * @return Pointer to the LCA node, or nullptr if not found
 */
TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q);
