#include "right_side_view.h"
#include <queue>

std::vector<int> rightSideView(TreeNode* root) {
    std::vector<int> result;
    
    if (root == nullptr) {
        return result;
    }
    
    std::queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int levelSize = static_cast<int>(q.size());
        
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();
            
            // If this is the last node in this level, it's visible from right
            if (i == levelSize - 1) {
                result.push_back(node->val);
            }
            
            // Add children (left first, then right)
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
    }
    
    return result;
}
