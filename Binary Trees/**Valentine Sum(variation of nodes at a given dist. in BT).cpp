class Solution{

    public:
    int sum=0;
    unordered_map<Node*,Node*>mp;
    unordered_set<Node*>st;
    queue<Node*>q;
    
    void solve()
    {
        while(1)
        {
            Node* temp=q.front();
            q.pop();
            if(!temp)
            {
                if(!q.empty())
                {
                    q.push(NULL);
                }
                return;
            }
            if(temp->left and st.find(temp->left)==st.end())
            {
                q.push(temp->left);
                st.insert(temp->left);
            }
            if(temp->right and st.find(temp->right)==st.end())
            {
                q.push(temp->right);
                st.insert(temp->right);
            }
            if(mp[temp] and st.find(mp[temp])==st.end())
            {
                q.push(mp[temp]);
                st.insert(mp[temp]);
            }
        }
    }
    
    void storeparent(Node *root,Node *parent)
    {
        if(root==NULL)
        {
            return;
        }
        mp[root]=parent;
        storeparent(root->left,root);
        storeparent(root->right,root);
    }
    
    Node* findtarget(Node* root,int target)
    {
        if(root==NULL)
        {
            return root;
        }
        if(root->data==target)
        {
            return root;
        }
        Node* left=findtarget(root->left,target);
        if(!left)
        {
            return findtarget(root->right,target);
        }
        return left;
    }
    int sum_at_distK(Node* root, int target, int k)
    {
        if(root==NULL)
        {
            return 0;
        }
        Node* temp=findtarget(root,target);
        if(temp==NULL)
        {
            return 0;
        }
        storeparent(root,NULL);
        
        int level=0;
        q.push(temp);
        st.insert(temp);
        q.push(NULL);
        
        while(!q.empty())
        {
            if(level==k)
            {
                for(auto x:st)
                {
                    sum+=x->data;
                }
                return sum;
            }
            
            level++;
            solve();
        }
        for(auto x:st)
        {
            sum+=x->data;
        }
        return sum;
        // Your code goes here
    }
