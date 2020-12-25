void solve(Node *root,int &sum)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left and !root->left->left and !root->left->right)
    {
        sum+=root->left->data;
    }
    solve(root->left,sum);
    solve(root->right,sum);
}
int leftLeavesSum(Node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(!root->left and !root->right)
    {
        return 0;
    }
    int sum=0;
    solve(root,sum);
    return sum;
    // Code here
}
