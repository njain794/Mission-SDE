/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>>ans;
    vector<int>temp;
    //ack<Node *>st;
    queue<Node *>st;
    
    void solve(Node* root)
    {
        st.push(root);
        st.push(NULL);
        
        while(!st.empty())
        {
            auto f=st.front();
            st.pop();
            
            if(f==NULL)
            {
                ans.push_back(temp);
                temp.clear();
                if(!st.empty())
                {
                    st.push(NULL);
                }
            }
            else
            {
                temp.push_back(f->val);
                for(auto x:f->children)
                {
                    if(x!=NULL)
                    {
                        st.push(x);
                    }
                }
            }
            
        }
    }
    
    vector<vector<int>> levelOrder(Node* root) 
    {
       if(root==NULL)
       {
           return ans;
       }
       solve(root);         
       return ans; 
    }
};
