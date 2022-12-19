int solve(Node* root, int &result)
{
    if(!root)
    {
        return 0;
    }

    int left=solve(root->left,result);
    int right=solve(root->right,result);

    int c1=max(root->data,max(left,right)+root->data);
    int c2=max(c1,left+right+root->data);
    result=max(c2,result);
    return c1;
}

//Function to return maximum path sum from any node in a tree.
int findMaxSum(Node* root)
{
    int result=INT_MIN;
    solve(root,result);
    return result;
}
