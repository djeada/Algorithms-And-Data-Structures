#include "range_sum_bst.h"

int rangeSumBST(TreeNode* root, int low, int high) {
    if (root == nullptr) {
        return 0;
    }
    
    int sum = 0;
    
    // If current value is in range, add it
    if (root->val >= low && root->val <= high) {
        sum += root->val;
    }
    
    // If current value > low, there might be values in left subtree
    if (root->val > low) {
        sum += rangeSumBST(root->left, low, high);
    }
    
    // If current value < high, there might be values in right subtree
    if (root->val < high) {
        sum += rangeSumBST(root->right, low, high);
    }
    
    return sum;
}
