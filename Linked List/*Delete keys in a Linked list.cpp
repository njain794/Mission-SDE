Node* deleteAllOccurances(Node *head,int x)
{
    if(head->data==x)
    {
        while(head->data==x)
        {
            Node *kemp=head;
            head=head->next;
            delete kemp;
        }    
    }
    Node *temp=head;
    while(temp!=NULL and temp->next!=NULL)
    {
        if(temp->next->data==x)
        {
            Node *chemp=temp->next;
            temp->next=chemp->next;
            delete(chemp);
        }
        else
        {
            temp=temp->next;
        }
    }
    return head;
    //Your code here
}
