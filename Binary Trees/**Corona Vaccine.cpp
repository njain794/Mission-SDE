//https://practice.geeksforgeeks.org/problems/d1afdbd3d49e4e7e6f9d738606cd592f63e6b0f0/1/?track=30-DOC-day-21&batchId=320#


class Solution{
public:
    unordered_set<Node*>r;
    unordered_set<Node*>c;

    void solve(Node* root,Node* par)
    {
        if(root==NULL)
        {
            return;
        }
        solve(root->left,root);
        solve(root->right,root);
        
        if(par==NULL and c.find(root)==c.end())
        {
            r.insert(root);
            c.insert(root);
            c.insert(root->left);
            c.insert(root->right);
            c.insert(par);
        }
        
        if(c.find(root->left)==c.end() or c.find(root->right)==c.end())
        {
            r.insert(root);
            c.insert(root);
            c.insert(root->left);
            c.insert(root->right);
            c.insert(par);
        }
    }

    int supplyVaccine(Node* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        c.insert(NULL);
        solve(root,NULL);
        return r.size();
        // Your code goes here
    }
};
