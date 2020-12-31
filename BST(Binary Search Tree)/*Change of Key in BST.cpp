node *del(node *root,int oldVal)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->key<oldVal)
    {
        root->right=del(root->right,oldVal);
        return root;
    }
    if(root->key>oldVal)
    {
        root->left=del(root->left,oldVal);
        return root;
    }
    else
    {
        if(root->left==NULL and root->right==NULL)
        {
            //node *temp=root;
            delete root;
            return NULL;
        }
        else if(root->left!=NULL and root->right==NULL)
        {
            node *temp=root->left;
            delete root;
            return temp;
        }
        else if(root->right!=NULL and root->left==NULL)
        {
            node *temp=root->right;
            delete root;
            return temp;
        }
        else
        {
            node *replace=root->right;
            while(replace->right!=NULL)
            {
                replace=replace->left;
            }
            root->key=replace->key;
            root->right=del(root->right,replace->key);
            return root;
        }
    }
}
node *insert(node *root,int value)
{
    if(root==NULL)
    {
        return new node(value);
    }
    if(root->key<value)
    {
        root->right=insert(root->right,value);
    }
    if(root->key>value)
    {
        root->left=insert(root->left,value);
    }
    return root;
}
struct node *changeKey(struct node *root, int oldVal, int newVal)
{
    //node *temp
    root=del(root,oldVal);
    //node *kemp
    root=insert(root,newVal);
    return root;
	// Code here
}
