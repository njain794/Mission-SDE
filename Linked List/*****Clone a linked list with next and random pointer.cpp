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
