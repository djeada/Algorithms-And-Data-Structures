#pragma once

#include <vector>

/**
 * TreeNode for BST representation.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int v = 0) : val(v), left(nullptr), right(nullptr) {}
};

/**
 * Node for doubly linked list.
 */
struct ListNode {
    int val;
    ListNode* prev;
    ListNode* next;
    
    ListNode(int v = 0) : val(v), prev(nullptr), next(nullptr) {}
};

/**
 * Convert a BST to a sorted doubly linked list in-place.
 * The conversion is done in-order (left-root-right).
 * 
 * @param root Root of the BST
 * @return Head of the doubly linked list
 */
ListNode* bstToDoublyLinkedList(TreeNode* root);

/**
 * Helper to get all values in order from the linked list.
 * @param head Head of the linked list
 * @return Vector of values in order
 */
std::vector<int> listToVector(ListNode* head);
