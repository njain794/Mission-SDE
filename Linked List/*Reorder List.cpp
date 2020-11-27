int len(Node *temp)
{
    int l=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        l++;
    }
    return l;
}
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
void reorderList(Node* head) 
{
    if(head==NULL or head->next==NULL)
    {
        return;
    }
    int l=len(head);
    int mid;
    if(l%2!=0)
    {
        mid=(l/2)+1;   
    }
    else
    {
        mid=l/2;
    }
    
    int count=1;
    Node *temp=head;
    Node *lemp=head;
    Node *kemp;
    while(temp!=NULL)
    {
        if(count==mid)
        {
            kemp=temp->next;
            temp->next=NULL;
            break;
        }
        temp=temp->next;
        count++;
    }
    Node *res=rev(kemp);

    while(res!=NULL)
    {
        Node *t1=lemp->next;
        Node *t2=res->next;
        lemp->next=res;
        res->next=t1;
        res=t2;
        lemp=t1;
    }
    // Your code here
}
