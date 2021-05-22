Node *copyList(Node *head) 
{
    /*if(head==NULL or head->next==NULL)
    {
        return head;
    }*/
    
    Node *curr=head;
    Node *tmp;
    
    while(curr)
    {
        tmp=curr->next;
        curr->next=new Node(curr->data);
        curr->next->next=tmp;
        curr=tmp;
    }
    
    curr=head;
    while(curr)
    {
        if(curr->arb)
        {
            curr->next->arb=curr->arb->next;
        }
        else
        {
            curr->next->arb=curr->arb;
        }
        curr=curr->next->next;
    }
    
    Node *orig=head;
    Node *copy=head->next;
    Node *temp=copy;
    
    while(orig and copy)
    {
        orig->next=orig->next->next;
        if(copy->next)
        {
            copy->next=copy->next->next;
        }
        else
        {
            copy->next=copy->next;
        }
        orig=orig->next;
        copy=copy->next;
    }
    
    return temp;
    // Your code here
}


Node *copyList(Node *head) 
{
    if(head==NULL)
    {
        return NULL;
    }
    Node *temp=new Node(head->data);
    temp->arb=head->arb;
    temp->next=copyList(head->next);
    return temp;
    // Your code here
}
////////// This is only a hack for coding round not to be used for interviews /////////////////////

Node *copyList(Node *head) {
    // Your code here
    Node *temp=head;
    unordered_map<Node*,Node*>mp;
    
    while(temp!=NULL)
    {
        mp[temp]=new Node(temp->data);
        temp=temp->next;
    }
    
    Node *curr=head;
    Node *hg=curr;
    
    while(curr!=NULL)
    {
        if(mp[curr->next]==NULL)
        {
            mp[curr]->next=NULL;
        }
        else
        {
            mp[curr]->next=mp[curr->next];
        }    
        if(mp[curr->arb]==NULL)
        {
            mp[curr]->arb=NULL;
        }
        else
        {
            mp[curr]->arb=mp[curr->arb];
        }
        curr=curr->next;
    }
    return mp[head];
    
}
