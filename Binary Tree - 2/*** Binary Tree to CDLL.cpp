void solve(Node *root,Node *&head,Node *&tail)
{
    if(!root)
    {
        return;
    }
    solve(root->left,head,tail);
    if(head==NULL)
    {
        head=root;
        tail=root;
    }
    else
    {
        tail->right=root;
        root->left=tail;
        tail=root;
    }
    solve(root->right,head,tail);
}
Node *bTreeToCList(Node *root)
{
    Node *head=NULL;//new Node(NULL);
    Node *tail=NULL;//new Node(NULL);
    
    solve(root,head,tail);
    tail->right=head;
    head->left=tail;
    return head;
//add code here.
}
