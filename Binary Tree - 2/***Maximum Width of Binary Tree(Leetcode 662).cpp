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
#define ull unsigned long long int
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) 
    {
        if(root==NULL)
        {
            return 0;
        }
        
        queue<pair<TreeNode*,ull>>q;
        q.push({root,0});
        ull width=1;
        
        while(!q.empty())
        {
            int n=q.size();
            ull l=q.front().second;
            ull r=q.back().second;
            width=max(width,(r-l+1));
            
            while(n--)
            {
                auto f=q.front();
                TreeNode *a=f.first;
                ull b=f.second;
                q.pop();
                if(a->left)
                {
                    q.push({a->left,2*b+1});
                }
                if(a->right)
                {
                    q.push({a->right,2*b+2});
                }
            }
        }
        return (int)width;
    }
};
