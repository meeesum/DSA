#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(TreeNode* l, TreeNode* r, int val) {
        left = l;
        right = r;
        data = val;
    }
};
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (root == nullptr) {
            return true;
            }

        queue<TreeNode*> q;
        q.push(root);
        bool encounteredNull = false;

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            if (current == nullptr) {
                encounteredNull = true;
            } else {
                if (encounteredNull) {
                    return false; 
                }
                q.push(current->left);
                q.push(current->right);
            }
        }
        return true;
    }
};

int main() {
    TreeNode* root = new TreeNode(nullptr, nullptr, 1);
    root->left = new TreeNode(nullptr, nullptr, 2);
    root->left->left = new TreeNode(nullptr, nullptr, 3);

    
    Solution sol;
    bool result = sol.isCompleteTree(root);
    if(result){
        cout<<"This is a complete binary tree\n";
    }
    else{
        cout<<"This is not a complete binary tree\n";
    }

    TreeNode* root2 = new TreeNode(nullptr, nullptr, 1);
    root2->left = new TreeNode(nullptr, nullptr, 2);
    root2->right = new TreeNode(nullptr, nullptr, 3);
    root2->left->left = new TreeNode(nullptr, nullptr, 4);
    root2->left->right = new TreeNode(nullptr, nullptr, 5);
    root2->right->right = new TreeNode(nullptr, nullptr, 7);

    bool result2 = sol.isCompleteTree(root2);

    if(result2){
        cout<<"This is a complete binary tree\n";
    }
    else{
        cout<<"This is not a complete binary tree\n";
    }
    return 0;
}