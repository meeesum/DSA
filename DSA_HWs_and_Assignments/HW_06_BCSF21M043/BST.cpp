#include "BST.h"

template <typename T>
void BinarySearchTree<T>::insertNodeIterative(T val)
{
    TNode<T> *newNode = new TNode<T>(val);
    if (root == nullptr)
    {
        root = newNode;
        return;
    }

    TNode<T> *current = root;
    TNode<T> *parent = nullptr;

    while (current != nullptr)
    {
        parent = current;
        if (val < current->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    if (val < parent->data)
    {
        parent->left = newNode;
    }
    else
    {
        parent->right = newNode;
    }
}

template <typename T>
TNode<T> *BinarySearchTree<T>::insertNodeRecursive(TNode<T> *node, T val)
{
    if (node == nullptr)
    {
        return new TNode<T>(val);
    }

    if (val < node->data)
    {
        node->left = insertNodeRecursive(node->left, val);
    }
    else
    {
        node->right = insertNodeRecursive(node->right, val);
    }

    return node;
}

template <typename T>
void BinarySearchTree<T>::insertNodeRecursive(T val)
{
    root = insertNodeRecursive(root, val);
}

template <typename T>
void BinarySearchTree<T>::deleteNodeIterative(T val)
{
    TNode<T> *current = root;
    TNode<T> *parent = nullptr;

    while (current != nullptr && current->data != val)
    {
        parent = current;
        if (val < current->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    if (current == nullptr)
    {
        return;
    }

    if (current->left == nullptr && current->right == nullptr)
    {
        if (current != root)
        {
            if (parent->left == current)
            {
                parent->left = nullptr;
            }
            else
            {
                parent->right = nullptr;
            }
        }
        else
        {
            root = nullptr;
        }
        delete current;
    }
    else if (current->left && current->right)
    {
        TNode<T> *successor = findMin(current->right);
        T val = successor->data;
        deleteNodeIterative(successor->data);
        current->data = val;
    }
    else
    {
        TNode<T> *child;
        if (current->left != nullptr)
        {
            child = current->left;
        }
        else
        {
            child = current->right;
        }

        if (current != root)
        {
            if (current == parent->left)
            {
                parent->left = child;
            }
            else
            {
                parent->right = child;
            }
        }
        else
        {
            root = child;
        }
        delete current;
    }
}

template <typename T>
TNode<T> *BinarySearchTree<T>::deleteNodeRecursive(TNode<T> *node, T val)
{
    if (node == nullptr)
    {
        return node;
    }

    if (val < node->data)
    {
        node->left = deleteNodeRecursive(node->left, val);
    }
    else if (val > node->data)
    {
        node->right = deleteNodeRecursive(node->right, val);
    }
    else
    {
        if (node->left == nullptr)
        {
            TNode<T> *temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr)
        {
            TNode<T> *temp = node->left;
            delete node;
            return temp;
        }

        TNode<T> *temp = findMin(node->right);

        node->data = temp->data;

        node->right = deleteNodeRecursive(node->right, temp->data);
    }
    return node;
}

template <typename T>
void BinarySearchTree<T>::deleteNodeRecursive(T val)
{
    root = deleteNodeRecursive(root, val);
}

template <typename T>
TNode<T> *BinarySearchTree<T>::findMin(TNode<T> *node)
{
    while (node->left != nullptr)
    {
        node = node->left;
    }
    return node;
}

template <typename T>
void BinarySearchTree<T>::levelOrderTraversal()
{
    if (root == nullptr)
    {
        return;
    }

    queue<TNode<T> *> q;
    q.enQueue(root);

    while (!q.empty())
    {
        TNode<T> *current = q.frontElement();
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