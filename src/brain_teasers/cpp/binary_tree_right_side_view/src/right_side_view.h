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
 * Return the values of the nodes visible from the right side of a binary tree.
 * 
 * @param root Root of the binary tree
 * @return Vector of node values visible from the right side, from top to bottom
 */
std::vector<int> rightSideView(TreeNode* root);
