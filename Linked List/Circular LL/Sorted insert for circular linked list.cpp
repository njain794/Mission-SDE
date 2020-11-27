Node *sortedInsert(Node* head, int data)
{
    if(head==NULL)
    {
        Node *n=new Node(data);
        n->next=n;
        head=n;
        return head;
    }
    
    else if(head->data >= data)
    {
        Node *temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        Node *n=new Node(data);
        temp->next=n;
        n->next=head;
        head=n;
    }
    
    else
    {
        Node *temp=head;
        while(temp->next!=head and temp->next->data<data)
        {
            temp=temp->next;
        }
        Node *n=new Node(data);
        n->next=temp->next;
        temp->next=n;
    }
    return head;
