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
        if(!root)
        {
            return 0;
        }
        
        queue<pair<TreeNode*,ull>>q;
        
        q.push({root,0});
        int width=0;
        
        while(!q.empty())
        {
            auto x=q.front();
            ull left = x.second;
            ull right = 0;
            int sz = q.size();
            
            while(sz--)
            {
                auto p=q.front();
                q.pop();
                
                right = p.second;
                TreeNode* head = p.first;
                if(head->left)
                {
                    q.push({head->left,2*right +1});
                }
                if(head->right)
                {
                    q.push({head->right,2*right + 2});
                }
            }
            width = max(width,int(right-left+1));
        }
        return width;
    }
};
