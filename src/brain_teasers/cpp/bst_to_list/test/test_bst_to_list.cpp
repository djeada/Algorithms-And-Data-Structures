#include "bst_to_list.h"
#include "gtest/gtest.h"

// Helper to delete tree
void deleteTree(TreeNode* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

// Helper to delete list
void deleteList(ListNode* head) {
    while (head) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}

TEST(BSTToListTest, BasicTree) {
    //     4
    //    / \
    //   2   5
    //  / \
    // 1   3
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    
    ListNode* list = bstToDoublyLinkedList(root);
    std::vector<int> result = listToVector(list);
    std::vector<int> expected = {1, 2, 3, 4, 5};
    
    EXPECT_EQ(result, expected);
    
    deleteTree(root);
    deleteList(list);
}

TEST(BSTToListTest, SingleNode) {
    TreeNode* root = new TreeNode(1);
    
    ListNode* list = bstToDoublyLinkedList(root);
    std::vector<int> result = listToVector(list);
    std::vector<int> expected = {1};
    
    EXPECT_EQ(result, expected);
    
    delete root;
    deleteList(list);
}

TEST(BSTToListTest, NullTree) {
    ListNode* list = bstToDoublyLinkedList(nullptr);
    EXPECT_EQ(list, nullptr);
}

TEST(BSTToListTest, DoubleLinked) {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    
    ListNode* list = bstToDoublyLinkedList(root);
    
    // Check forward links
    EXPECT_EQ(list->val, 1);
    EXPECT_EQ(list->next->val, 2);
    EXPECT_EQ(list->next->next->val, 3);
    
    // Check backward links
    EXPECT_EQ(list->next->next->prev->val, 2);
    EXPECT_EQ(list->next->prev->val, 1);
    
    deleteTree(root);
    deleteList(list);
}
