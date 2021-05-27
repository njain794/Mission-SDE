class solver
{
private:map<Node*,Node*>mp;
        set<Node *>s;
        queue<Node*>q;
        
        void nextlevel()
        {
            while(1)
            {
                Node *ref=q.front();
                q.pop();
                if(!ref)
                {
                    if(!q.empty())
                    {
                        q.push(NULL);
                    }
                    return;
                }
                if(ref->left and s.find(ref->left)==s.end())
                {
                    q.push(ref->left);
                    s.insert(ref->left);
                }
                if(ref->right and s.find(ref->right)==s.end())
                {
                    q.push(ref->right);
                    s.insert(ref->right);
                }
                if(mp[ref] and s.find(mp[ref])==s.end())
                {
                    q.push(mp[ref]);
                    s.insert(mp[ref]);
                }
            }
        }
        void parents(Node *root,Node *parent)
        {
            if(root==NULL)
            {
                return;
            }
            mp[root]=parent;
            parents(root->left,root);
            parents(root->right,root);
        }
        Node *findo(Node *root,int target)
        {
            if(root==NULL)
            {
                return NULL;
            }
            if(root->data==target)
            {
                return root;
            }
            Node *left=findo(root->left,target);
            if(left)
            {
                return left;
            }
            Node *right=findo(root->right,target);
            if(right)
            {
                return right;
            }
            return NULL;
        }

public:

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        vector<int>v;
        if(root==NULL)
        {
            return v;
        }
        Node *temp=findo(root,target);
        if(temp==NULL)
        {
            return v;
        }
        parents(root,NULL);
        int level=0;
        q.push(temp);
        s.insert(temp);
        q.push(NULL);
        
        while(!q.empty())
        {
            if(level==k)
            {
                while(!q.empty())
                {
                    Node *f=q.front();
                    q.pop();
                    if(f)
                    {
                        v.push_back(f->data);
                    }
                }
                sort(v.begin(),v.end());
                return v;
            }
            level++;
            nextlevel();
        }
        return v;
        // return the sorted vector of all nodes at k dist
    }
};
