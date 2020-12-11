int search(int inorder[],int iStart,int iEnd,int sc)
{
    for(int i=iStart;i<=iEnd;i++)
    {
        if(inorder[i]==sc)
        {
            return i;
        }
    }
    return -1;
}

int *find(int inorder[],int levelOrder[],int start,int end,int n)
{
    int size=(end-start)+1;
    int *arr=new int[size];
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(search(inorder,start,end,levelOrder[i])!=-1)
        {
            arr[j++]=levelOrder[i];
        }
    }
    return arr;
}

Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n)
{
    if(iStart>iEnd)
    {
        return NULL;
    }
    Node *root=new Node(levelOrder[0]);
    int index=search(inorder,iStart,iEnd,levelOrder[0]);
    
    int *leftarr=find(inorder,levelOrder,iStart,index-1,n);
    int *rightarr=find(inorder,levelOrder,index+1,iEnd,n);
    
    root->left=buildTree(inorder,leftarr,iStart,index-1,index-iStart);
    root->right=buildTree(inorder,rightarr,index+1,iEnd,iEnd-index);
    return root;
    
//add code here.
}
