void mirror(Node* node) {
    if (node == nullptr)
        return;
    else {
        Node* temp;
        
        // Do the subtrees
        mirror(node->left);
        mirror(node->right);
    
        // Swap the pointers in this node
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}