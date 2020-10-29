void inorder(Node *root,Node *&prev,Node *&first,Node *&second)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left,prev,first,second);
    if(prev!=NULL and prev->data>root->data)
    {
        if(first==NULL)
        {
            first=prev;
        }
        second=root;
    }
    prev=root;
    inorder(root->right,prev,first,second);
}
Node *correctBST(Node* root )
{
    if(root==NULL)
    {
        return root;
    }
    Node *prev=NULL;
    Node *first=NULL;
    Node *second=NULL;
    
    inorder(root,prev,first,second);
    swap(first->data,second->data);
    return root;
    // add code here.
}
