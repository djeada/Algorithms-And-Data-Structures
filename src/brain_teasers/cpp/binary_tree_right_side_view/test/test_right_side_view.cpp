#include "right_side_view.h"
#include "gtest/gtest.h"

// Helper to delete tree
void deleteTree(TreeNode* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

TEST(RightSideViewTest, BasicTree) {
    //     1
    //    / \
    //   2   3
    //    \   \
    //     5   4
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);
    
    std::vector<int> expected = {1, 3, 4};
    EXPECT_EQ(rightSideView(root), expected);
    
    deleteTree(root);
}

TEST(RightSideViewTest, LeftSkewed) {
    //     1
    //    /
    //   2
    //  /
    // 3
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    
    std::vector<int> expected = {1, 2, 3};
    EXPECT_EQ(rightSideView(root), expected);
    
    deleteTree(root);
}

TEST(RightSideViewTest, RightSkewed) {
    //  1
    //   \
    //    2
    //     \
    //      3
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    
    std::vector<int> expected = {1, 2, 3};
    EXPECT_EQ(rightSideView(root), expected);
    
    deleteTree(root);
}

TEST(RightSideViewTest, NullTree) {
    std::vector<int> expected = {};
    EXPECT_EQ(rightSideView(nullptr), expected);
}

TEST(RightSideViewTest, SingleNode) {
    TreeNode* root = new TreeNode(1);
    
    std::vector<int> expected = {1};
    EXPECT_EQ(rightSideView(root), expected);
    
    delete root;
}
