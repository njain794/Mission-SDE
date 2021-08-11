/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void solve(TreeNode *root,TreeNode *&first,TreeNode *&last,TreeNode *&mid,TreeNode *&prev)
    {
        if(root==NULL)
        {
            return;
        }
        solve(root->left,first,last,mid,prev);
        
        if(prev!=NULL and root->val<prev->val)
        {
            if(!first)
            {
                first=prev;
                mid=root;
            }
            else
            {
                last=root;
            }
        }
        prev=root;
        
        solve(root->right,first,last,mid,prev);
    }
    
    void recoverTree(TreeNode* root) 
    {
        if(root==NULL)
        {
            return ;
        }
        
        TreeNode *first=NULL;
        TreeNode *last=NULL;
        TreeNode *mid=NULL;
        TreeNode *prev=NULL;
        
        solve(root,first,last,mid,prev);
        
        if(first and last)
        {
            swap(first->val,last->val);
        }
        else if(first and mid)
        {
            swap(first->val,mid->val);
        }
        return;
    }
};
