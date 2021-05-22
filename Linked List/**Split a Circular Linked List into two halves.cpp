void splitList(Node *head, Node **head1, Node **head2)
{
    
    // your code goes here
    //Node *temp=head;
    Node *slow=head;
    Node *fast=head;
    
    while(fast->next!=head and fast->next->next!=head)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    
    (*head1)=head;
    (*head2)=slow->next;
    
    Node *temp = (*head2);
    slow->next=head;
    
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=(*head2);
    
}
