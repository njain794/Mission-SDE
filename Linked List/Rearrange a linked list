Node *rearrangeEvenOdd(Node *head)
{
    if(head==NULL || head->next==NULL || head->next->next==NULL)
    {
        return head;
    }
    Node *odd=head;
    Node *even=head->next;
    Node *evenh=head->next;
    while(even!=NULL and even->next!=NULL)
    {
        odd->next=odd->next->next;
        even->next=even->next->next;
        odd=odd->next;
        even=even->next;
    }
    odd->next=evenh;
    
    or or or or or
    
    /*Node *end=head;
    int count=0;
    while(end->next!=NULL)
    {
        end=end->next;
        count++;
    }
    int jump;
    if(count%2==0)
    {
        jump=(count/2);
    }
    else
    {
        jump=(count/2)+1;
    }
    Node *temp=head;
    while(jump--)
    {
        end->next=temp->next;
        temp->next=temp->next->next;
        end->next->next=NULL;
        temp=temp->next;
        end=end->next;
    }*/
    return head;
    // Your Code here
}
