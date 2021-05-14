void flatten(TreeNode* root) 
    {
        if(root==NULL or (root->left==NULL and root->right==NULL))
        {
            return;
        }
        
        if(root->left!=NULL)
        {
            flatten(root->left);
            
            TreeNode* temp=root->right;
            root->right=root->left;
            root->left=NULL;
            
            TreeNode *kemp=root->right;
            while(kemp->right!=NULL)
            {
                kemp=kemp->right;
            }
            kemp->right=temp;
            
        }
        flatten(root->right);
    }
