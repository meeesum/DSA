#include <iostream>
#include <stdlib.h>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val, TreeNode *l = nullptr, TreeNode *r = nullptr)
    {
        data = val;
    }
};
TreeNode *ArraytoBST(int arr[], int start, int end)
{
    if (start > end)
    {
        return nullptr;
    }

    int mid = (end + start) / 2;
    TreeNode *root = new TreeNode(arr[mid]);

    root->left = ArraytoBST(arr, start, mid - 1);
    root->right = ArraytoBST(arr, mid + 1, end);

    return root;
}

void display(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    display(root->left);
    display(root->right);
}
class BalancedCheck {
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

        if (std::abs(leftHeight - rightHeight) > 1) {
            return -1;
        }

        return std::max(leftHeight, rightHeight) + 1;
    }
};
int main()
{
    // int tree[] = {1, 2, 3, 4, 5, 6, 7};
    // int n = sizeof(tree) / sizeof(tree[0]);
    // TreeNode *root = ArraytoBST(tree, 0, n-1);
    // display(root);


    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    BalancedCheck sol;
    bool result = sol.isBalanced(root);
   if(result){
    cout<<"The tree is height balanced\n";
   }
   else{
    cout<<"The tree is not height balanced\n";
   }
    return 0;
}