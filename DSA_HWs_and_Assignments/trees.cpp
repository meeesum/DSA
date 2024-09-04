#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to mirror the binary tree
void mirror(Node* root) {
    if (root == nullptr) {
        return;
    }
    // Swap the left and right children
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    // Recursively mirror the left and right subtrees
    mirror(root->left);
    mirror(root->right);
}
Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}
int height(char arr[], int i, int n) {
    if (i >= n || arr[i] == '\0') {
        return 0;
    } else {
        int leftHeight = height(arr, 2 * i + 1, n);
        int rightHeight = height(arr, 2 * i + 2, n);
        return max(leftHeight, rightHeight) + 1;
    }
}
void inOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
int main() {
    // char cbt[100];
    // int n;
    // cout << "Enter the number of nodes: ";
    // cin >> n;
    // cout << "Enter the values of the nodes: ";
    // for (int i = 0; i < n; i++) {
    //     cin >> cbt[i];
    // }
    // int treeHeight = height(cbt, 0, n);
    // cout << "The height of the binary tree is: " << treeHeight << endl;

     Node* root = nullptr;
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 6);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 5);
    root = insert(root, 7);

    cout << "Original tree (in-order): ";
    inOrder(root);
    cout << endl;
    mirror(root);
    return 0;
}