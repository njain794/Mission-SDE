Node* solve(int pre[],int left,int right,int size,int &i)
{
    if(i>=size)
    {
        return NULL;
    }
    if(pre[i]<left or pre[i]>right)
    {
        return NULL;
    }
    
    Node *root = newNode(pre[i]);
    int temp=pre[i];
    i++;
    
    root->left=solve(pre,left,temp-1,size,i);
    root->right=solve(pre,temp+1,right,size,i);
    
    return root;
}

Node* constructTree(int pre[], int size) 
{
    int i=0;
    Node *root=solve(pre,INT_MIN,INT_MAX,size,i);
    return root;
    //code here
}
