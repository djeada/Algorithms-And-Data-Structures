#include "bst_to_list.h"
#include <stack>

ListNode* bstToDoublyLinkedList(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }
    
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    
    // In-order traversal using stack
    std::stack<TreeNode*> stack;
    TreeNode* current = root;
    
    while (current != nullptr || !stack.empty()) {
        // Go to leftmost node
        while (current != nullptr) {
            stack.push(current);
            current = current->left;
        }
        
        // Process node
        current = stack.top();
        stack.pop();
        
        // Create list node
        ListNode* node = new ListNode(current->val);
        
        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        
        // Move to right subtree
        current = current->right;
    }
    
    return head;
}

std::vector<int> listToVector(ListNode* head) {
    std::vector<int> result;
    while (head != nullptr) {
        result.push_back(head->val);
        head = head->next;
    }
    return result;
}
