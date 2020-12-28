vector<int> ExtremeNodes(Node* root)
{
    vector<int>v;
    if(!root)
    {
        return v;
    }
    stack<Node*>s1;
    stack<Node*>s2;
    //vector<int>v;
    
    s1.push(root);
    while(!s1.empty() or !s2.empty())
    {
        if(!s1.empty())
        {
        v.push_back(s1.top()->data);
        while(!s1.empty())
        {
            Node *temp1=s1.top();
            s1.pop();
            if(temp1->right)
            {
                s2.push(temp1->right);
            }
            if(temp1->left)
            {
                s2.push(temp1->left);
            }
        }
        }
        else
        {
        v.push_back(s2.top()->data);
        while(!s2.empty())
        {
            Node *t2=s2.top();
            s2.pop();
            if(t2->left)
            {
                s1.push(t2->left);
            }
            if(t2->right)
            {
                s1.push(t2->right);
            }
        }
        }
    }
    return v;
    // Your code here
}
