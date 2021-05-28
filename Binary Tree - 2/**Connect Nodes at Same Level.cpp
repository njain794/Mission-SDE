class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty())
        {
            while(q.front()!=NULL)
            {
                Node *temp=q.front();
                q.pop();
                temp->nextRight=q.front();
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
            }
            if(q.front()==NULL)
            {
                q.pop();
                if(!q.empty())
                {
                    q.push(NULL);
                }
            }
        }
       // Your Code Here
    }    
      
};
