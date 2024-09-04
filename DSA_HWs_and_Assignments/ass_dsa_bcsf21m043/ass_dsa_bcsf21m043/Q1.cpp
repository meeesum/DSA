#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;
};
 
// Function to create a new node
Node* CreateNode(int data)
{
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
 
// a) Function to insert element in binary tree iteratively
Node* InsertNode(Node* root, int data)
{
    if (root == NULL) {
        root = CreateNode(data);
        return root;
    }

    queue<Node*> q;
    q.push(root);
 
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
 
        if (temp->left != NULL)
            q.push(temp->left);
        else {
            temp->left = CreateNode(data);
            return root;
        }
 
        if (temp->right != NULL)
            q.push(temp->right);
        else {
            temp->right = CreateNode(data);
            return root;
        }
    }
}
int height(Node* node) {
    if (node == NULL)
        return 0;
    else {
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        if (lheight > rheight)
            return(lheight + 1);
        else return(rheight + 1);
    }
}

void InsertAtGivenLevel(Node* root, int data, int level) {
    if (root == NULL && level == 1)
        root = CreateNode(data);
    else if (level > 1) {
        InsertAtGivenLevel(root->left, data, level-1);
        InsertAtGivenLevel(root->right, data, level-1);
    }
}

// a) Function to insert element in binary tree recursively
void InsertNodeRecursive(Node* root, int data) {
    int h = height(root);
    for (int i=1; i<=h; i++) {
        InsertAtGivenLevel(root, data, i);
        if (root != NULL)
            break;
    }
}
// b) Function to print level order traversal of a binary tree iteratively// Function to print given level
void printGivenLevel(Node* root, int level) {
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1) {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

// Function to print level order traversal of tree
void printLevelOrder(Node* root) {
    int h = height(root);
    for (int i=1; i<=h; i++)
        printGivenLevel(root, i);
}
// b) Function to print level order traversal of a binary tree recursively
void levelOrderTraversal(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        cout << node->data << " ";
        if (node->left != NULL) {
            q.push(node->left);
        }
        if (node->right != NULL) {
            q.push(node->right);
        }
    }
}
// c) Function to print level order traversal of a binary tree iteratively
Node* search(Node* root, int key) {
    while (root != NULL) {
        if (root->data == key)
            return root;

        if (root->data < key)
            root = root->right;


        else
            root = root->left;
    }

    return NULL;
}
// c) Function to print level order traversal of a binary tree recursively
Node* search(Node* root, int key) {

    if (root == NULL || root->data == key)
       return root;
    

    if (root->data < key)
       return search(root->right, key);
 

    return search(root->left, key);
}
// d) Function to delete a node from binary tree iteratively
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    Node *cur = root, *parent = NULL;
    while (cur != NULL && cur->data != key) {
        parent = cur;
        if (key < cur->data) cur = cur->left;
        else cur = cur->right;
    }

    if (cur == NULL) return root; 

    if (cur->left == NULL) {
        if (cur != root) {
            if (parent->left == cur) parent->left = cur->right;
            else parent->right = cur->right;
        } else {
            root = cur->right;
        }
    } else if (cur->right == NULL) {
        if (cur != root) {
            if (parent->left == cur) parent->left = cur->left;
            else parent->right = cur->left;
        } else {
            root = cur->left;
        }
    } else {
        Node *successor = minValueNode(cur->right);
        int val = successor->data;
        deleteNode(root, successor->data);
        cur->data = val;
    }

    return root;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
// d) Function to delete a node from binary tree recursively
Node* deleteNode(Node* root, int key) {
    // base case
    if (root == NULL) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);


    else if (key > root->data)
        root->right = deleteNode(root->right, key);


    else {
        
        if (root->left == NULL) {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        
        Node* temp = minValueNode(root->right);

        
        root->data = temp->data;

        
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
// e) Function to insert a node in min heap iteratively
void insertMinHeap(vector<int>& heap, int key) {
    
    heap.push_back(key);
    int i = heap.size() - 1;

    
    while (i != 0 && heap[parent(i)] > heap[i]) {
       swap(heap[i], heap[parent(i)]);
       i = parent(i);
    }
}


int parent(int i) {
    return (i - 1) / 2;
}
// e) function to insert a node in min heap recursively
void insertMinHeap(vector<int>& heap, int key) {
    
    heap.push_back(key);

    
    heapifyUp(heap, heap.size() - 1);
}

void heapifyUp(vector<int>& heap, int i) {
    
    if (i == 0) return;

    int parentIndex = (i - 1) / 2;

    if (heap[i] < heap[parentIndex]) {
        swap(heap[i], heap[parentIndex]);
        heapifyUp(heap, parentIndex);
    }
}
// f) Function to insert a node in max heap iteratively
void deleteMaxHeap(vector<int>& heap, int i) {
    int size = heap.size();

    
    swap(heap[i], heap[size - 1]);
    heap.pop_back();
    size--;

    int parent = i;
    int leftChild = 2 * parent + 1;
    int rightChild = 2 * parent + 2;

    while (leftChild < size) {
        int largestChild = leftChild;

        if (rightChild < size && heap[rightChild] > heap[leftChild]) {
            largestChild = rightChild;
        }

        if (heap[parent] >= heap[largestChild]) {
            break;
        }

        swap(heap[parent], heap[largestChild]);

        parent = largestChild;
        leftChild = 2 * parent + 1;
        rightChild = 2 * parent + 2;
    }
}
// f) Function to insert a node in max heap recursively
void deleteMaxHeap(vector<int>& heap, int i) {
    int size = heap.size();

    swap(heap[i], heap[size - 1]);
    heap.pop_back();
    size--;

    heapifyDown(heap, i, size);
}

void heapifyDown(vector<int>& heap, int i, int size) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] > heap[largest])
        largest = left;


    if (right < size && heap[right] > heap[largest])
        largest = right;


    if (largest != i) {
        swap(heap[i], heap[largest]);

        heapifyDown(heap, largest, size);
    }
}