int solve(Node *root,int currmin,int currmax)
{
    if(root==NULL)
    {
        return (currmax-currmin);
    }
    currmax=max(currmax,root->data);
    currmin=min(currmin,root->data);
    
    int l=solve(root->left,currmin,currmax);
    int r=solve(root->right,currmin,currmax);
    
    return max(l,r);
}
int maxDiff(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return solve(root,root->data,root->data);
    // Your code here 
}
