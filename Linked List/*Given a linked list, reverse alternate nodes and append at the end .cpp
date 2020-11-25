Node* rev(Node *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node *currhead=rev(head->next);
    Node *prevhead=head;
    prevhead->next->next=prevhead;
    prevhead->next=NULL;
    return currhead;
}

void rearrange(struct Node *odd)
{
    struct Node *t1=odd;
    struct Node *t2=odd->next;
    struct Node *t2h=odd->next;
    while(t2!=NULL and t2->next!=NULL)
    {
        t1->next=t1->next->next;
        t2->next=t2->next->next;
        t1=t1->next;
        t2=t2->next;
    }
    Node *res=rev(t2h);
    t1->next=res;
    
}
