#include "tree.h"
#include <iostream>
using namespace std;

int main() {
    BinaryTree tree;

    int values[] = {10, 20, 30, 40, 50, 60, 70};

    for (int i = 0; i < sizeof(values)/sizeof(values[0]); i++) {
    tree.insert(values[i]);
}


    cout << "Complete Binary Tree structure:" << endl;
    tree.display(tree.getRoot());

    int value;
    cout << "Enter the value of the node to search: ";
    cin >> value;

    TreeNode* node = tree.search(tree.getRoot(), value);

    if (node == nullptr) {
        cout << "Node with value " << value << " not found in the tree." << endl;
    } else {
        cout << "Node found with value: " << node->getData() << endl;

        TreeNode* parent = tree.findParent(tree.getRoot(), value);
        if (parent != nullptr) {
            cout << "Parent of node " << value << " is: " << parent->getData() << endl;
        } else {
            cout << "Node " << value << " is the root node, it has no parent." << endl;
        }

        TreeNode* leftChild = tree.findLeftChild(node);
        if (leftChild != nullptr) {
            cout << "Left child of node " << value << " is: " << leftChild->getData() << endl;
        } else {
            cout << "Node " << value << " has no left child." << endl;
        }

        TreeNode* rightChild = tree.findRightChild(node);
        if (rightChild != nullptr) {
            cout << "Right child of node " << value << " is: " << rightChild->getData() << endl;
        } else {
            cout << "Node " << value << " has no right child." << endl;
        }
    }

    return 0;
}
