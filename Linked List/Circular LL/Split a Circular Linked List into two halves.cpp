void splitList(Node *head, Node **h1, Node **h2)
{
    Node *slow=head;
    Node *fast=head;
    
    while(fast->next!=head and fast->next->next!=head)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    
    *h1=head;
    *h2=slow->next;
    slow->next=head;
    
    Node *temp=(*h2);
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=(*h2);
    // your code goes here
}
