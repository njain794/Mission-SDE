Node *rev(Node *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node *small=rev(head->next);
    Node *c=head;
    c->next->next=c;
    c->next=NULL;
    return small;
}
Node* addOne(Node *head) 
{
    if(head==NULL)
    {
        return head;
    }
    Node *head2=rev(head);
    Node *curr=head2;
    Node *prev=head2;
    int sum=(curr->data)+1;
    curr->data=sum%10;
    int carry=sum/10;
    curr=curr->next;
    
    while(curr!=NULL)
    {
        sum=(curr->data)+carry;
        curr->data=sum%10;
        carry=sum/10;
        prev=curr;
        curr=curr->next;
    }
    if(carry)
    {
        prev->next=new Node(carry);
    }
    return rev(head2);
}
