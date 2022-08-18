
        /*
        Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
        */

#include <vector>
#include <queue>
#include <iostream>

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

    std::vector<int> rightSideView(TreeNode* root) {

        std::vector<int> res;
        if(root == nullptr) return res;
        std::queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* cur = q.front();
                q.pop();
                if(i == size - 1) res.push_back(cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }
        return res;
    }

void test1() {
    /* 
    Input: root = [1,2,3,null,5,null,4]
    Output: [1,3,4]
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(5);
    root->right->left = new TreeNode(4);

    std::vector<int> res = rightSideView(root);
    for(int i = 0; i < res.size(); i++)
        std::cout << res[i] << " ";
    std::cout << std::endl;
}

void test2() {
    /*
    Input: root = [1,null,3]
    Output: [1,3]
    */
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(3);
    std::vector<int> res = rightSideView(root);
    for(int i = 0; i < res.size(); i++)
        std::cout << res[i] << " ";
}

void test3() {
    /*
    Input: root = []
    Output: []
    */
    TreeNode* root = nullptr;
    std::vector<int> res = rightSideView(root);
    for(int i = 0; i < res.size(); i++)
        std::cout << res[i] << " ";
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}
