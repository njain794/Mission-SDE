/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode *,TreeNode *>mp;
    unordered_set<TreeNode *>vis;
    
    void connectpar(TreeNode *root,TreeNode *parent)
    {
        if(root==NULL)
        {
            return;
        }
        mp[root]=parent;
        connectpar(root->left,root);
        connectpar(root->right,root);
    }
    void dfs(TreeNode *target,int k,vector<int> &ans)
    {
        if(target==NULL)
        {
            return;
        }
        if(vis.find(target)!=vis.end())
        {
            return;
        }
        vis.insert(target);
        
        if(k==0)
        {
            ans.push_back(target->val);
            return;
        }
        dfs(target->left,k-1,ans);
        dfs(target->right,k-1,ans);
        dfs(mp[target],k-1,ans);
    }
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        vector<int>ans;
        if(root==NULL)
        {
            return ans;
        }
        connectpar(root,NULL);
        dfs(target,k,ans);
        return ans;
    }
};
