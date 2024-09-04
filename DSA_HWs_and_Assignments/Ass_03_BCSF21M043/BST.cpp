#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int val) {
        root = insertHelper(root, val);
    }

    void inOrderTraversal(int* elements, int& index) const {
        inOrderTraversalHelper(root, elements, index);
    }

    static bool areSameElements(const BinarySearchTree& tree1, const BinarySearchTree& tree2) {
        int elements1[100], elements2[100];
        int index1 = 0, index2 = 0;
        tree1.inOrderTraversal(elements1, index1);
        tree2.inOrderTraversal(elements2, index2);
        if (index1 != index2) return false;
        for (int i = 0; i < index1; ++i) {
            if (elements1[i] != elements2[i]) return false;
        }
        return true;
    }

    int kthLargest(int k) const {
        int elements[100];
        int index = 0;
        inOrderTraversal(elements, index);
        if (k > 0 && k <= index) {
            return elements[index - k];
        }
        throw out_of_range("k is out of range");
    }

    int kthSmallest(int k) const {
        int elements[100];
        int index = 0;
        inOrderTraversal(elements, index);
        if (k > 0 && k <= index) {
            return elements[k - 1];
        }
        throw out_of_range("k is out of range");
    }

    void removeKeysInRange(int min, int max) {
        root = removeKeysInRangeHelper(root, min, max);
    }

    void removeKeysOutsideRange(int min, int max) {
        root = removeKeysOutsideRangeHelper(root, min, max);
    }

private:
    TreeNode* root;

    TreeNode* insertHelper(TreeNode* node, int val) {
        if (node == nullptr) {
            return new TreeNode(val);
        }
        if (val < node->data) {
            node->left = insertHelper(node->left, val);
        } else if (val > node->data) {
            node->right = insertHelper(node->right, val);
        }
        return node;
    }

    void inOrderTraversalHelper(TreeNode* node, int* elements, int& index) const {
        if (node == nullptr) {
            return;
        }
        inOrderTraversalHelper(node->left, elements, index);
        elements[index++] = node->data;
        inOrderTraversalHelper(node->right, elements, index);
    }

    TreeNode* removeKeysInRangeHelper(TreeNode* node, int min, int max) {
        if (node == nullptr) {
            return nullptr;
        }
        node->left = removeKeysInRangeHelper(node->left, min, max);
        node->right = removeKeysInRangeHelper(node->right, min, max);
        if (node->data >= min && node->data <= max) {
            return deleteNode(node);
        }
        return node;
    }

    TreeNode* removeKeysOutsideRangeHelper(TreeNode* node, int min, int max) {
        if (node == nullptr) {
            return nullptr;
        }
        node->left = removeKeysOutsideRangeHelper(node->left, min, max);
        node->right = removeKeysOutsideRangeHelper(node->right, min, max);
        if (node->data < min || node->data > max) {
            return deleteNode(node);
        }
        return node;
    }

    TreeNode* deleteNode(TreeNode* node) {
        if (node->left == nullptr) {
            TreeNode* rightChild = node->right;
            delete node;
            return rightChild;
        }
        if (node->right == nullptr) {
            TreeNode* leftChild = node->left;
            delete node;
            return leftChild;
        }
        TreeNode* minNode = findMin(node->right);
        node->data = minNode->data;
        node->right = deleteMin(node->right);
        return node;
    }

    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    TreeNode* deleteMin(TreeNode* node) {
        if (node->left == nullptr) {
            return node->right;
        }
        node->left = deleteMin(node->left);
        return node;
    }
};

int main() {
    BinarySearchTree tree1;
    tree1.insert(5);
    tree1.insert(3);
    tree1.insert(7);
    tree1.insert(2);
    tree1.insert(4);
    tree1.insert(6);
    tree1.insert(8);

    BinarySearchTree tree2;
    tree2.insert(7);
    tree2.insert(3);
    tree2.insert(8);
    tree2.insert(2);
    tree2.insert(5);
    tree2.insert(6);
    tree2.insert(4);

    bool result = BinarySearchTree::areSameElements(tree1, tree2);
    cout << "Do the two BSTs contain the same set of elements? " << (result ? "Yes" : "No") << endl;

    int k = 3;
    cout << k << "rd largest element in tree1: " << tree1.kthLargest(k) << endl;
    cout << k << "rd smallest element in tree1: " << tree1.kthSmallest(k) << endl;

    int min = 3, max = 6;
    tree1.removeKeysInRange(min, max);
    cout << "In-Order Traversal after removing keys in range [" << min << ", " << max << "]: ";
    int elements[100];
    int index = 0;
    tree1.inOrderTraversal(elements, index);
    for (int i = 0; i < index; ++i) {
        cout << elements[i] << " ";
    }
    cout << endl;

    min = 4, max = 7;
    tree2.removeKeysOutsideRange(min, max);
    cout << "In-Order Traversal after removing keys outside range [" << min << ", " << max << "]: ";
    index = 0;
    tree2.inOrderTraversal(elements, index);
    for (int i = 0; i < index; ++i) {
        cout << elements[i] << " ";
    }
    cout << endl;

    return 0;
}