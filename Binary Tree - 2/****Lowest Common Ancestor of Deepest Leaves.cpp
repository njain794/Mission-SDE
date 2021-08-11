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
    unordered_map<TreeNode*,int>mp;
    
    int depth(TreeNode *root)
    {
        if(root==NULL)
        {
            return 0;
        }
        if(mp.find(root)==mp.end())
        {
            mp[root]=1+max(depth(root->left),depth(root->right));
        }
        return mp[root];
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) 
    {
        if(root==NULL)
        {
            return root;
        }
        
        int l=depth(root->left);
        int r=depth(root->right);
        
        if(l==r)
        {
            return root;
        }
        else if(l<r)
        {
            return lcaDeepestLeaves(root->right);
        }
        else
        {
            return lcaDeepestLeaves(root->left);
        }
    }
};
