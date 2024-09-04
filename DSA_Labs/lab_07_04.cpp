#include <iostream>
#include "queue.h"
#include "queue.cpp"
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree
{
public:
    BinaryTree() : root(nullptr) {}

    void insert(int val)
    {
        if (root == nullptr)
        {
            root = new TreeNode(val);
        }
        else
        {
            insertHelper(root, val);
        }
    }

    void levelOrderTraversal() const
    {
        if (root == nullptr)
        {
            return;
        }
        Queue<TreeNode *> q;
        q.enQueue(root);

        while (!q.isEmpty())
        {
            TreeNode *current = q.front();
            q.deQueue();
            cout << current->data << " ";

            if (current->left != nullptr)
            {
                q.enQueue(current->left);
            }
            if (current->right != nullptr)
            {
                q.enQueue(current->right);
            }
        }
        cout << endl;
    }

private:
    TreeNode *root;

    void insertHelper(TreeNode *node, int val)
    {
        if (val < node->data)
        {
            if (node->left == nullptr)
            {
                node->left = new TreeNode(val);
            }
            else
            {
                insertHelper(node->left, val);
            }
        }
        else
        {
            if (node->right == nullptr)
            {
                node->right = new TreeNode(val);
            }
            else
            {
                insertHelper(node->right, val);
            }
        }
    }
};

int main()
{
    BinaryTree tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);

    cout << "Level Order Traversal: ";
    tree.levelOrderTraversal();

    return 0;
}