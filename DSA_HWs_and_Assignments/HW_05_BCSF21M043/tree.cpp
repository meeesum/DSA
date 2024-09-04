#include "tree.h"
#include "queue.h"
#include "queue.cpp"
using namespace std;

BinaryTree::BinaryTree() {
    root = nullptr;
}

void BinaryTree::insert(int val) {
    if (root == nullptr) {
        root = new TreeNode(nullptr, nullptr, val);
    } else {
        Queue<TreeNode*> q;
        q.enQueue(root);
        while (!q.isEmpty()) {
            TreeNode* temp = q.front;
            q.deQueue();
            if (temp->getLeft() == nullptr) {
                temp->setLeft(new TreeNode(nullptr, nullptr, val));
                break;
            } else {
                q.enQueue(temp->getLeft());
            }
            if (temp->getRight() == nullptr) {
                temp->setRight(new TreeNode(nullptr, nullptr, val));
                break;
            } else {
                q.enQueue(temp->getRight());
            }
        }
    }
}

TreeNode* BinaryTree::findParent(TreeNode* node, int val) {
    if (node == nullptr || node->getData() == val) {
        return nullptr;
    }

    if ((node->getLeft() != nullptr && node->getLeft()->getData() == val) ||
        (node->getRight() != nullptr && node->getRight()->getData() == val)) {
        return node;
    }

    TreeNode* leftSearch = findParent(node->getLeft(), val);
    if (leftSearch != nullptr) {
        return leftSearch;
    }

    return findParent(node->getRight(), val);
}

TreeNode* BinaryTree::findLeftChild(TreeNode* node) {
    if (node == nullptr) {
        return nullptr;
    }
    return node->getLeft();
}

TreeNode* BinaryTree::findRightChild(TreeNode* node) {
    if (node == nullptr) {
        return nullptr;
    }
    return node->getRight();
}

TreeNode* BinaryTree::search(TreeNode* node, int val) {
    if (node == nullptr || node->getData() == val) {
        return node;
    }

    TreeNode* leftSearch = search(node->getLeft(), val);
    if (leftSearch != nullptr) {
        return leftSearch;
    }
    return search(node->getRight(), val);
}

void BinaryTree::display(TreeNode* node, int level) {
    if (node == nullptr) {
        return;
    }
    display(node->getRight(), level + 1);
    for (int i = 0; i < level; i++) {
        cout << "   ";
    }
    cout << node->getData() << endl;
    display(node->getLeft(), level + 1);
}

TreeNode* BinaryTree::getRoot() {
    return root;
}
