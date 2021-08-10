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
    bool isCompleteTree(TreeNode* root) 
    {
        if(root==NULL)
        {
            return true;
        }
        
        queue<TreeNode*>q;
        bool flag=false;
        q.push(root);
        
        while(!q.empty())
        {
            auto f=q.front();
            q.pop();
            
            if(f!=NULL and flag==true)
            {
                return false;
            }
            if(f==NULL)
            {
                flag=true;
                continue;
            }
            
            q.push(f->left);
            q.push(f->right);
        }
        return true;
    }
};
