Node* removekeys(Node root, int min, int max)
{
    if (root == null)
        return null;
        
    root->left  = removekeys(root->left, min, max);
    root->right = removekeys(root->right, min, max);
        
    if (root->data < min)
        return root->right;
    if (max < root->data)
        return root->left;
    return root;
}
