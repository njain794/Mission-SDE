void solve(Node *root,int input,int &val)
{
    if(root==NULL)
    {
        return;
    }
    if(root->data==input)
    {
        val=input;
        return;
    }
    else if(root->data>input)
    {
        val=root->data;
        solve(root->left,input,val);
    }
    else
    {
        solve(root->right,input,val);
    }
}
int findCeil(Node* root, int input) 
{ 
    // Base case 
    if (root == NULL) 
        return -1; 
        
    int value=-1;
    solve(root,input,value);
    return value;   
}
///////////////////   OR    //////////////////////
int findCeil(Node* root, int input) 
{ 
    // Base case 
    if (root == NULL) 
        return -1; 
        
    Node *res=NULL;
    while(root!=NULL)
    {
        if(root->data==input)
        {
            return root->data;
        }
        if(root->data>input)
        {
            res=root;
            root=root->left;
        }
        else if(root->data<input)
        {
            root=root->right;
        }
    }
    if(res)
    {
        return res->data;
    }
    else
    {
        return -1;
    }
} 
