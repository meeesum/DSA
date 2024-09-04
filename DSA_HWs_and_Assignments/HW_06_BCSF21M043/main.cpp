int maxDepth(Node *node)
{
    if (node == nullptr)
        return 0;

    // compute the depth of left and right
    // subtrees
    int lDepth = maxDepth(node->left);
    int rDepth = maxDepth(node->right);

    // use the larger one
    return max(lDepth, rDepth) + 1;
}