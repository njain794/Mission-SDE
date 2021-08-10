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
    
    void solve(TreeNode *&root,vector<int>&del,vector<TreeNode*>&ans)
    {
        if(root==NULL)
        {
            return;
        }
        
        solve(root->left,del,ans);
        solve(root->right,del,ans);
        
        if(find(del.begin(),del.end(),root->val)!=del.end())
        {
            if(root->left)
            {
                ans.push_back(root->left);
            }
            if(root->right)
            {
                ans.push_back(root->right);
            }
            root=NULL;
        }
        return;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& del) 
    {
        vector<TreeNode*>ans;
        if(root==NULL)
        {
            return ans;
        }
        if(del.size()==0)
        {
            ans.push_back(root);
            return ans;
        }
        //vector<TreeNode*>ans;
        solve(root,del,ans);
        if(root!=NULL)
        {
            ans.push_back(root);
        }
        return ans;
    }
};
