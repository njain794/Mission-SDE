Node *createTree(int parent[], int n)
{
    vector<Node *>v;
    for(int i=0;i<n;i++)
    {
        Node *temp=new Node(i);
        v.push_back(temp);
    }
    
    int root;
    for(int i=0;i<n;i++)
    {
        if(parent[i]==-1)
        {
            root=i;
        }
        else if(parent[i]!=-1 and v[parent[i]]->left==NULL)
        {
            v[parent[i]]->left=v[i];
        }
        else if(parent[i]!=-1 and v[parent[i]]->right==NULL)
        {
            v[parent[i]]->right=v[i];
        }
    }
    
    return v[root];
    // Your code here
}
