bool solve(Node *root)
{
    int lt=0;
    int rt=0;
    if(root==NULL)
    {
        return true;
    }
    if(!root->left and !root->right)
    {
        return true;
    }
    else
    {
    if(root->left)
    {
        lt=root->left->data;
    }
    if(root->right)
    {
        rt=root->right->data;
    }
    if(root->data==lt+rt and solve(root->left) and solve(root->right))
    {
        return true;
    }
    /*if(solve(root->left) and solve(root->right))
    {
        return true;
    }*/
    else
    {
        return false;
    }
    }
    //return false;
}
int isSumProperty(Node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(solve(root))
    {
        return 1;
    }
    else
    {
        return 0;
    }
 // Add your code here
}
