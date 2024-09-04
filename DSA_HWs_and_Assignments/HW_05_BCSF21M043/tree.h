#pragma once

#include <iostream>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(TreeNode* l, TreeNode* r, int val) : left(l), right(r), data(val) {}
    int getData() { return data; }
    void setData(int val) { data = val; }
    TreeNode* getLeft() { return left; }
    void setLeft(TreeNode* l) { left = l; }
    TreeNode* getRight() { return right; }
    void setRight(TreeNode* r) { right = r; }
};

class BinaryTree {
private:
    TreeNode* root;

public:
    BinaryTree();
    void insert(int val);

    TreeNode* findParent(TreeNode* node, int val);  
    TreeNode* findLeftChild(TreeNode* node);        
    TreeNode* findRightChild(TreeNode* node);      
    TreeNode* search(TreeNode* node, int val);      

    void display(TreeNode* node, int level = 0);    
    TreeNode* getRoot();
};
