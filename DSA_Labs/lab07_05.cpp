
#include <iostream>
#include <stdlib.h>
using namespace std;
class TreeNode {
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }

private:
    int checkHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) {
            return -1;
        }

        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) {
            return -1;
        }

        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }

        return max(leftHeight, rightHeight) + 1;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    bool result = sol.isBalanced(root);
    if(result){
        cout<<"The tree is height balanced\n";
        
    }
    else{
        cout<<"The tree is not height balanced\n";
    }

    return 0;
}