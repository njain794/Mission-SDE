void solve(Node *root,int node,vector<int>&path,vector<int>&res)
{
    if(root==NULL)
    {
        return;
    }
    if(root->data==node)
    {
        res.assign(path.begin(),path.end());
    }
    else
    {
        path.push_back(root->data);
    }
    solve(root->left,node,path,res);
    solve(root->right,node,path,res);
    path.pop_back();
}

int kthAncestor(Node *root, int k, int node)
{
    if(root==NULL)
    {
        return -1;
    }
    vector<int>path;
    vector<int>res;
    
    solve(root,node,path,res);
    if(res.size()==0)
    {
        return -1;
    }
    else if(k>res.size())
    {
        return -1;
    }
    else
    {
        reverse(res.begin(),res.end());
        return res[k-1];
    }
    // Code here
}
