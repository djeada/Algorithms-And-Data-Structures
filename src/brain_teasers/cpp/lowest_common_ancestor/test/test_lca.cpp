#include "lca.h"
#include "gtest/gtest.h"

// Helper to delete tree
void deleteTree(TreeNode* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

TEST(LCATest, BasicTree) {
    //        3
    //       / \
    //      5   1
    //     / \ / \
    //    6  2 0  8
    //      / \
    //     7   4
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    
    TreeNode* lca = lowestCommonAncestor(root, 5, 1);
    EXPECT_EQ(lca->val, 3);
    
    lca = lowestCommonAncestor(root, 5, 4);
    EXPECT_EQ(lca->val, 5);
    
    lca = lowestCommonAncestor(root, 6, 4);
    EXPECT_EQ(lca->val, 5);
    
    deleteTree(root);
}

TEST(LCATest, SimpleTree) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    
    TreeNode* lca = lowestCommonAncestor(root, 1, 2);
    EXPECT_EQ(lca->val, 1);
    
    deleteTree(root);
}

TEST(LCATest, NullTree) {
    TreeNode* lca = lowestCommonAncestor(nullptr, 1, 2);
    EXPECT_EQ(lca, nullptr);
}

TEST(LCATest, SameNode) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    TreeNode* lca = lowestCommonAncestor(root, 2, 2);
    EXPECT_EQ(lca->val, 2);
    
    deleteTree(root);
}
