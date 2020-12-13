struct bst
{
    bool isbst;
    int size;
    int min;
    int max;
};
bst solve(Node *root)
{
    //bst b;
    if(root==NULL)
    {
        return {true,0,INT_MAX,INT_MIN};
        //bst b;
        /*b.isbst=true;
        b.size=0;
        b.min=INT_MAX;
        b.max=INT_MIN;*/
    }
    if(root->left==NULL and root->right==NULL)
    {
        return {true,1,root->data,root->data};
        /*b.isbst=true;
        b.size=1;
        b.min=root->data;
        b.max=root->data;*/
    }
    bst l = solve(root->left);
    bst r = solve(root->right);
    
    bst bt;
    if(l.isbst==true and r.isbst==true and l.max<root->data and r.min>root->data)
    {
        //bst b;
        bt.isbst=true;
        bt.size=1+l.size+r.size;
        bt.min=min(root->data,l.min);
        bt.max=max(root->data,r.max);
        //return b;
    }
    else
    {
        //bst b;
        bt.isbst=false;
        bt.size=max(l.size,r.size);
        bt.min=-1;
        bt.max=-1;
        //return b;
    }
    return bt;
}
int largestBst(Node *root)
{
    bst b = solve(root);
    return b.size;
	//Your code here
}
