#include "range_sum_bst.h"
#include "gtest/gtest.h"

// Helper to delete tree
void deleteTree(TreeNode* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

TEST(RangeSumBSTTest, BasicRange) {
    //     10
    //    /  \
    //   5    15
    //  / \     \
    // 3   7    18
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);
    
    EXPECT_EQ(rangeSumBST(root, 7, 15), 32);  // 7 + 10 + 15
    
    deleteTree(root);
}

TEST(RangeSumBSTTest, AllInRange) {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    
    EXPECT_EQ(rangeSumBST(root, 1, 10), 15);  // 3 + 5 + 7
    
    deleteTree(root);
}

TEST(RangeSumBSTTest, NoneInRange) {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    
    EXPECT_EQ(rangeSumBST(root, 10, 20), 0);
    
    deleteTree(root);
}

TEST(RangeSumBSTTest, NullTree) {
    EXPECT_EQ(rangeSumBST(nullptr, 1, 10), 0);
}

TEST(RangeSumBSTTest, SingleNode) {
    TreeNode* root = new TreeNode(5);
    
    EXPECT_EQ(rangeSumBST(root, 5, 5), 5);
    EXPECT_EQ(rangeSumBST(root, 1, 10), 5);
    EXPECT_EQ(rangeSumBST(root, 6, 10), 0);
    
    delete root;
}
