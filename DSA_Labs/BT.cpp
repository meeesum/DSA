#include <iostream>
#include "queue.h"
#include "queue.cpp"
#include "stackUsingDLL.h"
#include "stackUsingDLL.cpp"
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    BinaryTree() : root(nullptr) {}

    void insert(int val) {
        root = insertHelper(root, val);
    }

    void printBoundary() {
        if (root == nullptr) return;
        cout << root->data << " ";
        printBoundaryLeft(root->left);
        printLeaves(root->left);
        printLeaves(root->right);
        printBoundaryRight(root->right);
        cout << endl;
    }

    bool isSumTree() {
        return isSumTreeHelper(root) != -1;
    }

    bool isBST() {
        return isBSTHelper(root, -2147483648, 2147483647);
    }

    bool isCompleteTree() {
        if (root == nullptr) return true;
        Queue<TreeNode*> q;
        q.enQueue(root);
        bool encounteredNull = false;
        while (!q.isEmpty()) {
            TreeNode* current = q.front();
            q.deQueue();
            if (current == nullptr) {
                encounteredNull = true;
            } else {
                if (encounteredNull) return false;
                q.enQueue(current->left);
                q.enQueue(current->right);
            }
        }
        return true;
    }

    void printLevelOrderReverse() {
        if (root == nullptr) return;
        Queue<TreeNode*> q;
        Stack <TreeNode*> s;
        q.enQueue(root);
        while (!q.isEmpty()) {
            TreeNode* current = q.front();
            q.deQueue();
            s.push(current);
            if (current->right) q.enQueue(current->right);
            if (current->left) q.enQueue(current->left);
        }
        while (!s.isEmpty()) {
            cout << s.topOfStack()->data << " ";
            s.pop();
        }
        cout << endl;
    }

    int heightIterative() {
        if (root == nullptr) return 0;
        Queue<TreeNode*> q;
        q.enQueue(root);
        int height = 0;
        while (!q.isEmpty()) {
            int nodeCount = q.size();
            if (nodeCount == 0) return height;
            height++;
            while (nodeCount > 0) {
                TreeNode* node = q.front();
                q.deQueue();
                if (node->left) q.enQueue(node->left);
                if (node->right) q.enQueue(node->right);
                nodeCount--;
            }
        }
        return height;
    }

    int heightRecursive() {
        return heightRecursiveHelper(root);
    }

private:
    TreeNode* root;

    TreeNode* insertHelper(TreeNode* node, int val) {
        if (node == nullptr) return new TreeNode(val);
        if (val < node->data) node->left = insertHelper(node->left, val);
        else node->right = insertHelper(node->right, val);
        return node;
    }

    void printBoundaryLeft(TreeNode* node) {
        if (node == nullptr) return;
        if (node->left) {
            cout << node->data << " ";
            printBoundaryLeft(node->left);
        } else if (node->right) {
            cout << node->data << " ";
            printBoundaryLeft(node->right);
        }
    }

    void printLeaves(TreeNode* node) {
        if (node == nullptr) return;
        printLeaves(node->left);
        if (node->left == nullptr && node->right == nullptr) cout << node->data << " ";
        printLeaves(node->right);
    }

    void printBoundaryRight(TreeNode* node) {
        if (node == nullptr) return;
        if (node->right) {
            printBoundaryRight(node->right);
            cout << node->data << " ";
        } else if (node->left) {
            printBoundaryRight(node->left);
            cout << node->data << " ";
        }
    }

    int isSumTreeHelper(TreeNode* node) {
        if (node == nullptr) return 0;
        if (node->left == nullptr && node->right == nullptr) return node->data;
        int leftSum = isSumTreeHelper(node->left);
        int rightSum = isSumTreeHelper(node->right);
        if (leftSum == -1 || rightSum == -1 || node->data != leftSum + rightSum) return -1;
        return node->data + leftSum + rightSum;
    }

    bool isBSTHelper(TreeNode* node, int min, int max) {
        if (node == nullptr) return true;
        if (node->data < min || node->data > max) return false;
        return isBSTHelper(node->left, min, node->data - 1) && isBSTHelper(node->right, node->data + 1, max);
    }

    int heightRecursiveHelper(TreeNode* node) {
        if (node == nullptr) return 0;
        int leftHeight = heightRecursiveHelper(node->left);
        int rightHeight = heightRecursiveHelper(node->right);
        return max(leftHeight, rightHeight) + 1;
    }
};

int main() {
    BinaryTree tree;
    tree.insert(20);
    tree.insert(8);
    tree.insert(22);
    tree.insert(4);
    tree.insert(12);
    tree.insert(10);
    tree.insert(14);
    tree.insert(25);

    cout << "Boundary Traversal: ";
    tree.printBoundary();

    cout << "Is Sum Tree: " << (tree.isSumTree() ? "Yes" : "No") << endl;

    cout << "Is BST: " << (tree.isBST() ? "Yes" : "No") << endl;

    cout << "Is Complete Tree: " << (tree.isCompleteTree() ? "Yes" : "No") << endl;

    cout << "Level Order Traversal in Reverse: ";
    tree.printLevelOrderReverse();

    cout << "Height (Iterative): " << tree.heightIterative() << endl;
    cout << "Height (Recursive): " << tree.heightRecursive() << endl;

    return 0;
}