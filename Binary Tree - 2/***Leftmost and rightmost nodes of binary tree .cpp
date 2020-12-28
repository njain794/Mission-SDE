void printCorner(Node *root)
{
    if(!root)
    {
        return;
    }
    queue<Node *>q1;
    queue<Node *>q2;
    q1.push(root);
    while(!q1.empty() or !q2.empty())
    {
        if(!q1.empty())
        {
            if(q1.size()==1)
            {
                cout<<q1.front()->data<<" ";
            }
            else
            {
                cout<<q1.front()->data<<" "<<q1.back()->data<<" ";
            }
            while(!q1.empty())
            {
                Node *t1=q1.front();
                q1.pop();
                if(t1->left)
                {
                    q2.push(t1->left);
                }
                if(t1->right)
                {
                    q2.push(t1->right);
                }
            }
        }
        else
        {
            if(q2.size()==1)
            {
                cout<<q2.front()->data<<" ";
            }
            else
            {
                cout<<q2.front()->data<<" "<<q2.back()->data<<" ";
            }
            while(!q2.empty())
            {
                Node *t2=q2.front();
                q2.pop();
                if(t2->left)
                {
                    q1.push(t2->left);
                }
                if(t2->right)
                {
                    q1.push(t2->right);
                }
            }
        }
    }
    return;
// Your code goes here

}
