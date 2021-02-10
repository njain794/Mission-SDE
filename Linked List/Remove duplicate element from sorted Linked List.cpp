Node *removeDuplicates(Node *root)
{
    Node *temp=root;
    while(temp!=NULL and temp->next!=NULL)
    {
        if(temp->data == temp->next->data)
        {
            Node *kemp=temp->next;
            temp->next=kemp->next;
            delete(kemp);
        }
        else
        {
            temp=temp->next;
        }    
    }
    return root;
 // your code goes here
}
