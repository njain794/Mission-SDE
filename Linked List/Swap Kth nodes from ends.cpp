Node *swapkthnode(Node* head, int n, int k)
{
    if(k>n)
    {
        return head;
    }
    if(2*k-1==n)
    {
        return head;
    }
    
    Node *x=head;
    Node *xprev=NULL;
    for(int i=1;i<k;i++)
    {
        xprev=x;
        x=x->next;
    }
    
    Node *y=head;
    Node *yprev=NULL;
    for(int i=1;i<n-k+1;i++)
    {
        yprev=y;
        y=y->next;
    }
    
    if(xprev)
    {
        xprev->next=y;
    }
    if(yprev)
    {
        yprev->next=x;
    }
    
    Node *temp=x->next;
    x->next=y->next;
    y->next=temp;
    
    if(k==1)
    {
        head=y;
    }
    if(k==n)
    {
        head=x;
    }
    
    return head;
