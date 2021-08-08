Node *rev(struct Node*head)
{
    if(head==NULL)
    {
        return head;
    }
    Node *curr=head;
    Node *prev=NULL;
    Node *next;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    if(first==NULL and second ==NULL)
    {
        return first;
    }
    if(first==NULL)
    {
        return second;
    }
    if(second==NULL)
    {
        return first;
    }
    Node *first2=rev(first);
    Node *second2=rev(second);
    Node *ans=new Node(0);
    Node *f=first2;
    Node *s=second2;
    Node *curr=ans;
    int carry=0;
    while(f!=NULL || s!=NULL)
    {
        int sum=0;
        if(f!=NULL)
        {
            sum+=f->data;
        }
        if(s!=NULL)
        {
            sum+=s->data;
        }
        sum+=carry;
        carry=sum/10;
        curr->next=new Node(sum%10);
        curr=curr->next;
        if(f!=NULL)
        {
            f=f->next;
        }
        if(s!=NULL)
        {
            s=s->next;
        }
    }
    if(carry)
    {
        curr->next=new Node(carry);
    }
    return rev(ans->next);
    // code here
}
