Node *dll(Node *root,Node *&head,Node *&tail)
{
    if(!root)
    {
        return NULL;
    }
    if(!root->left and !root->right)
    {
        if(!head)
        {
            head=root;
            tail=root;        
        }
        else
        {
            root->left=tail;
            tail->right=root;
            tail=root;
        }
        return NULL;
    }
    root->left=dll(root->left,head,tail);
    root->right=dll(root->right,head,tail);
    return root;
}
Node * convertToDLL(Node *root)
{
    Node *head=NULL;
    Node *tail=NULL;
    root=dll(root,head,tail);
    return head;
    // add code here.
}
