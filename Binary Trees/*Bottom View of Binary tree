vector <int> bottomView(Node *root)
{
    vector<int>v;
    if(root==NULL)
    {
        return v;
    }
    queue<pair<Node*,int>>q;
    map<int,int>mp;
    int k=0;
    q.push({root,k});
    //mp[k]=root->data;
    while(!q.empty())
    {
        pair<Node*,int>p=q.front();
        Node* a=p.first;
        int b=p.second;
        q.pop();
        mp[b]=a->data;
        if(a->left)
        {
            q.push({a->left,b-1});
        }
        if(a->right)
        {
            q.push({a->right,b+1});
        }
    }
    for(auto x:mp)
    {
        v.push_back(x.second);
    }
    return v;
   // Your Code Here
}
