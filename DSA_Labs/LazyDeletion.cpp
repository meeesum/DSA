#include <iostream>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    bool deleted;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr), deleted(false) {}
};

class LazyDeletionBST
{
public:
    LazyDeletionBST() : root(nullptr) {}

    void insert(int val)
    {
        root = insertHelper(root, val);
    }
    void deleteNode(int val)
    {
        TreeNode *node = findNode(root, val);
        if (node != nullptr)
        {
            node->deleted = true;
        }
    }

    void cleanup()
    {
        root = cleanupHelper(root);
    }
    void inOrderTraversal() const
    {
        inOrderTraversalHelper(root);
        cout << endl;
    }
    void preOrderTraversal() const
    {
        preOrderTraversalHelper(root);
        cout << endl;
    }
    void postOrderTraversal() const
    {
        postOrderTraversalHelper(root);
        cout << endl;
    }

private:
    TreeNode *root;

    TreeNode *insertHelper(TreeNode *node, int val)
    {
        if (node == nullptr)
        {
            return new TreeNode(val);
        }
        if (val < node->data)
        {
            node->left = insertHelper(node->left, val);
        }
        else if (val > node->data)
        {
            node->right = insertHelper(node->right, val);
        }
        return node;
    }

    TreeNode *findNode(TreeNode *node, int val)
    {
        if (node == nullptr || node->data == val)
        {
            return node;
        }
        if (val < node->data)
        {
            return findNode(node->left, val);
        }
        else
        {
            return findNode(node->right, val);
        }
    }

    TreeNode *cleanupHelper(TreeNode *node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        node->left = cleanupHelper(node->left);
        node->right = cleanupHelper(node->right);
        if (node->deleted)
        {
            TreeNode *temp = merge(node->left, node->right);
            delete node;
            return temp;
        }
        return node;
    }

    TreeNode *merge(TreeNode *left, TreeNode *right)
    {
        if (left == nullptr)
            return right;
        if (right == nullptr)
            return left;

        TreeNode *rightMin = findMin(right);
        rightMin->right = deleteMin(right);
        rightMin->left = left;
        return rightMin;
    }

    TreeNode *findMin(TreeNode *node)
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

    TreeNode *deleteMin(TreeNode *node)
    {
        if (node->left == nullptr)
        {
            return node->right;
        }
        node->left = deleteMin(node->left);
        return node;
    }

    void inOrderTraversalHelper(TreeNode *node) const
    {
        if (node == nullptr)
        {
            return;
        }
        inOrderTraversalHelper(node->left);
        if (!node->deleted)
        {
            cout << node->data << " ";
        }
        inOrderTraversalHelper(node->right);
    }

    void preOrderTraversalHelper(TreeNode *node) const
    {
        if (node == nullptr)
        {
            return;
        }
        if (!node->deleted)
        {
            cout << node->data << " ";
        }
        preOrderTraversalHelper(node->left);
        preOrderTraversalHelper(node->right);
    }

    void postOrderTraversalHelper(TreeNode *node) const
    {
        if (node == nullptr)
        {
            return;
        }
        postOrderTraversalHelper(node->left);
        postOrderTraversalHelper(node->right);
        if (!node->deleted)
        {
            cout << node->data << " ";
        }
    }
};

int main()
{
    LazyDeletionBST tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    cout << "In-Order Traversal: ";
    tree.inOrderTraversal();

    tree.deleteNode(3);
    tree.deleteNode(7);

    cout << "In-Order Traversal after deletion: ";
    tree.inOrderTraversal();

    tree.cleanup();

    cout << "In-Order Traversal after cleanup: ";
    tree.inOrderTraversal();

    return 0;
}