Node* deleteNode(Node* root, int k)
{
    if(!root)
    {
        return NULL;
    }
    root->left=deleteNode(root->left,k);
    root->right=deleteNode(root->right,k);
    if(root->data>=k)
    {
        return root->left;
    }
    else
    {
        return root;
    }
    //////////  OR  //////////////
    /*if(!root)
    {
        return NULL;
    }
    if(root->data>=k)
    {
        return deleteNode(root->left,k);
    }
    else
    {
        root->right=deleteNode(root->right,k);
        return root;
    }*/
}
