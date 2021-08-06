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
    
    int rob(TreeNode* root) 
    {
        if(root==NULL)
        {
            return 0;
        }
        if(mp.find(root)!=mp.end())
        {
            return mp[root];
        }
        int v=root->val;
        if(root->left)
        {
            v+=rob(root->left->left);
            v+=rob(root->left->right);
        }
        if(root->right)
        {
            v+=rob(root->right->left);
            v+=rob(root->right->right);
        }
        
        int ans=max(v,rob(root->left)+rob(root->right));
        mp[root]=ans;
        return ans;
        
        
    }
};
