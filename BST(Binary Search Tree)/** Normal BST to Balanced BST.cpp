void fill(Node *root,vector<int>&v)
{
    if(root==NULL)
    {
        return;
    }
    fill(root->left,v);
    v.push_back(root->data);
    fill(root->right,v);
}
Node *create(vector<int>v,int low,int high)
{
    if(low>high)
    {
        return NULL;
    }
    int mid=(low+high)/2;
    Node *root=new Node(mid);
    root->left=create(v,low,mid-1);
    root->right=create(v,mid+1,high);
    return root;
}
Node* buildBalancedTree(Node* root)
{
    vector<int>v;
    fill(root,v);
    return create(v,0,v.size()-1);
	// Code here
}
