#include<iostream>
using namespace std;
class Node {
    public:
    int data;
    Node *left, *right;
};
Node* BSTtoDLL(Node* root) {
    if (!root) return root;

    if (root->left) {
        Node* left = BSTtoDLL(root->left);

        for (; left->right; left = left->right);

        left->right = root;

        root->left = left;
    }

    if (root->right) {
        Node* right = BSTtoDLL(root->right);

        for (; right->left; right = right->left);

        right->left = root;

        root->right = right;
    }

    return root;
}

// Function to merge two sorted doubly linked lists
Node* mergeDLLs(Node* head1, Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    if (head1->data < head2->data) {
        head1->right = mergeDLLs(head1->right, head2);
        head1->right->left = head1;
        return head1;
    } else {
        head2->right = mergeDLLs(head1, head2->right);
        head2->right->left = head2;
        return head2;
    }
}

Node* DLLtoBST(Node* &head, int n) {
    if (n <= 0) return NULL;

    Node* left = DLLtoBST(head, n/2);

    Node* root = head;
    root->left = left;

    head = head->right;

    root->right = DLLtoBST(head, n - n/2 - 1);

    return root;
}

// Function to merge two BSTs
Node* mergeBSTs(Node* root1, Node* root2) {
    Node* head1 = BSTtoDLL(root1);

    Node* head2 = BSTtoDLL(root2);

    Node* head = mergeDLLs(head1, head2);

    int n = 0;
    Node* temp = head;
    while (temp) {
        n++;
        temp = temp->right;
    }

    return DLLtoBST(head, n);
}
// function to find the kth largest element in a BST
void kthLargestUtil(Node *root, int k, int &c, int &res) {
    if (root == NULL || c >= k)
        return;

    kthLargestUtil(root->right, k, c, res);

    c++;

    if (c == k) {
        res = root->data;
        return;
    }

    kthLargestUtil(root->left, k, c, res);
}

int kthLargest(Node *root, int k) {
    int c = 0; 
    int res = -1; 

    kthLargestUtil(root, k, c, res);

    return res;
}