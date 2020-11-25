Node *rev(Node *temp)
{
    if(temp==NULL or temp->next==NULL)
    {
        return temp;
    }
    Node *small=rev(temp->next);
    Node *c=temp;
    c->next->next=c;
    c->next=NULL;
    return small;
}
Node *compute(Node *head)
{
    Node *kemp=head;
    Node *newlist=rev(kemp);
    Node *temp=newlist;
    Node *curr;
    Node *nexp;
    while(temp!=NULL)
    {
        curr=temp;
        if(temp->next!=NULL)
        {
            nexp=temp->next;
            if(nexp->data < curr->data)
            {
                curr->next=nexp->next;
                delete(nexp);
            }
            else
            {
                temp=temp->next;
            }
        }
        else
        {
            temp=temp->next;
        }
    }
    return rev(newlist);
    // your code goes here
}
