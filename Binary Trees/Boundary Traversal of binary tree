void lb(Node *root,vector<int>&v)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left || root->right)
    {
        v.push_back(root->data);
    }
    if(root->left)
    {
        lb(root->left,v);
    }
    else if(root->right)
    {
        lb(root->right,v);
    }
}
void leaf(Node *root,vector<int>&v)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left)
    {
        leaf(root->left,v);
    }
    if(!root->left and !root->right)
    {
        v.push_back(root->data);
    }
    if(root->right)
    {
        leaf(root->right,v);
    }
}
void rb(Node *root,vector<int>&v)
{
    if(root==NULL)
    {
        return;
    }
    if(root->right)
    {
        rb(root->right,v);
    }
    else if(root->left)
    {
        rb(root->left,v);
    }
    if(root->left || root->right)
    {
        v.push_back(root->data);
    }
}
vector <int> printBoundary(Node *root)
{
    vector<int>v;
    v.push_back(root->data);
    if(!root->left and !root->right)
    {
        return v;
    }
    lb(root->left,v);
    leaf(root,v);
    rb(root->right,v);
    return v;
     //Your code here
}
