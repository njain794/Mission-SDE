void solve(Node *root,int &count)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL and root->right==NULL)
    {
        count++;
    }
    solve(root->left,count);
    solve(root->right,count);
}
int countLeaves(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int count=0;
    solve(root,count);
    return count;
  // Your code here
}
