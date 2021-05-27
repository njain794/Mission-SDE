Node *build(int in[],int pos[],int &end,int s,int e)
{
    if(s>e-1)
    {
        return NULL;
    }
    Node *root=new Node(pos[end]);
    int index=-1;
    for(int j=s;j<e;j++)
    {
        if(in[j]==pos[end])
        {
            index=j;
            break;
        }
    }
    end--;
    root->right=build(in,pos,end,index+1,e);
    root->left=build(in,pos,end,s,index);
    return root;
}
Node *buildTree(int in[], int post[], int n) 
{
    int end=n-1;
    return build(in,post,end,0,n);
    // Your code here
}
