Node * deleteAtPosition(Node *head,int pos)
{
    if(pos==1)
    {
        Node *temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        Node *del=temp->next;
        temp->next=temp->next->next;
        head=temp->next;
        delete(del);
    }
    else
    {
        int jump=0;
        Node *temp=head;
        while(jump<pos-2 and temp->next!=head)
        {
            temp=temp->next;
            jump++;
        }
        Node *del=temp->next;
        temp->next=temp->next->next;
        delete(del);
    }    
    return head;
    //Your code here
}
