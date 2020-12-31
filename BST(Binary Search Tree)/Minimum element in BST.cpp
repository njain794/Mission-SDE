void solve(Node *root,int &mn)
{
    if(root==NULL)
    {
        return;
    }
    solve(root->left,mn);
    mn=min(mn,root->data);
    solve(root->right,mn);
}
// your task is to complete the below function
int minValue(Node* root)
{
    int mn=INT_MAX;
    solve(root,mn);
    return mn;
    // Code here
}
