Node *solve(int post[],int size,int l,int r,int &ptr)
{
    if(ptr<0)
    {
        return NULL;
    }
    if(l>r)
    {
        return NULL;
    }
    int x=post[ptr];
    if(post[ptr]<l or post[ptr]>r)
    {
        return NULL;
    }
    Node *root=new Node(post[ptr]);
    ptr--;
    root->right=solve(post,size,x+1,r,ptr);
    root->left=solve(post,size,l,x-1,ptr);
}
Node *constructTree (int post[], int size)
{
    int ptr=size-1;
    int l=INT_MIN;
    int r=INT_MAX;
    
    Node *root=solve(post,size,l,r,ptr);
    return root;
//code here
}
