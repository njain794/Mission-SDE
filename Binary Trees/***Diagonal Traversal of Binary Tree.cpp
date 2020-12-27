void pre(node *root,map<int,vector<int>>&m,int d)
{
    if(root==NULL)
    {
        return;
    }
    m[d].push_back(root->data);
    pre(root->left,m,d+1);
    pre(root->right,m,d);
    return;
}
vector<int> diagnol(node *root)
{
    map<int,vector<int>>m;
    int d=0;
    pre(root,m,d);
    vector<int>v;
    for(auto x:m)
    {
        for(auto i=0;i<x.second.size();i++)
        {
            v.push_back(x.second[i]);
        }
    }
    return v;
}

///////////******** or queue method *******//////////////////

vector<int> diagonal(Node *root)
{
    queue<pair<int,Node*>>q;
    //unordered_
    map<int,vector<int>>mp;
    vector<int>v;
    
    q.push({1,root});
    while(!q.empty())
    {
        pair<int,Node*>p=q.front();
        q.pop();
        int x=p.first;
        Node* y=p.second;
        
        mp[x].push_back(y->data);
        if(y->left)
        {
            q.push({x+1,y->left});
        }
        if(y->right)
        {
            q.push({x,y->right});
        }
    }
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        //vector<int>itr=it;
        for(auto i=0;i<it->second.size();i++)
        {
            v.push_back(it->second[i]);
        }
    }
    return v;
   // your code here
}*/
