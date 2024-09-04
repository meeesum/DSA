#pragma once
#include "queue.h"
#include "queue.cpp"
using namespace std;

template <typename T>
class TNode {
    public:
    T data;
    TNode* left;
    TNode* right;
    TNode(T val,TNode* left, TNode* right) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

template <typename T>
class BinarySearchTree {
public:
    TNode<T>* root;

    BinarySearchTree() : root(nullptr) {}

    void insertNodeIterative(T val);

    TNode<T>* insertNodeRecursive(TNode<T>* node, T val);
    void insertNodeRecursive(T val);

    void deleteNodeIterative(T val);

    TNode<T>* deleteNodeRecursive(TNode<T>* node, T val);
    void deleteNodeRecursive(T val);

    TNode<T>* findMin(TNode<T>* node);

    void levelOrderTraversal();
};