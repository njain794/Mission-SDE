void solve(Node *root,int input,int &val)
{
    if(root==NULL)
    {
        return;
    }
    if(root->key==input)
    {
        val = root->key;
        return;
    }
    else if(root->key<input)
    {
        val=root->key;
        solve(root->right,input,val);
    }
    else 
    {
        solve(root->left,input,val);
    }
}
int findMaxForN(Node* root, int input)
{
    if(root==NULL)
    {
        return -1;
    }
    int val=-1;
    solve(root,input,val);
    return val;
}
