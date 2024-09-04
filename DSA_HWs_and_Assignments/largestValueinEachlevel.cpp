#include <iostream>
#include "queue.h"
#include "queue.cpp"
using namespace std;
template <class T>
struct TNode
{
    int data;
    TNode *left;
    TNode *right;
    TNode(int val, left = nullptr, right = nullptr)
    {
        this->data = val;
        this->left = left;
        this->right = right;
    }
};
template <class T>
void largestValueinEachLevel(TNode<T> *root)
{
    if (root == nullptr)
    {
        return;
    }
    Queue<TNode<T> *> q;
    q.enQueue(root);
    while (!q.isEmpty())
    {
        int n = q.size();
        int maxVal = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            TNode<T> *curr = q.front();
            q.deQueue();
            maxVal = max(maxVal, curr->data);
            if (curr->left != nullptr)
            {
                q.enQueue(curr->left);
            }
            if (curr->right != nullptr)
            {
                q.enQueue(curr->right);
            }
        }
        cout << maxVal << " ";
    }
}
TNode<int> *findMin(TNode<int> *node)
{
    while (node->left != nullptr)
    {
        node = node->left;
    }
    return node;
}

// Function to find the in-order successor in a BST
TNode<int> *findInOrderSuccessor(TNode<int> *root, TNode<int> *node)
{
    if (node->right != nullptr)
    {
        return findMin(node->right);
    }

    TNode<int> *successor = nullptr;
    while (root != nullptr)
    {
        if (node->data < root->data)
        {
            successor = root;
            root = root->left;
        }
        else if (node->data > root->data)
        {
            root = root->right;
        }
        else
        {
            break;
        }
    }
    return successor;
}
void findKthLargestUtil(TNode<int>* root, int& K, int& result) {
    if (root == nullptr || K <= 0) {
        return;
    }

    // Traverse the right subtree first (reverse in-order)
    findKthLargestUtil(root->right, K, result);

    // Decrement K and check if we have reached the Kth largest
    K--;
    if (K == 0) {
        result = root->data;
        return;
    }

    // Traverse the left subtree
    findKthLargestUtil(root->left, K, result);
}
int findKthLargest(TNode<int>* root, int K) {
    int result = -1;
    findKthLargestUtil(root, K, result);
    return result;
}
int main()
{
    TNode<int> *root = new TNode<int>(1);
    root->left = new TNode<int>(3);
    root->right = new TNode<int>(2);
    root->left->left = new TNode<int>(5);
    root->left->right = new TNode<int>(3);
    root->right->right = new TNode<int>(9);
    largestValueinEachLevel(root);

    return 0;
}