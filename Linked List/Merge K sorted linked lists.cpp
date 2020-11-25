
/* arr[] is an array of pointers to heads of linked lists
  and N is size of arr[]  */
Node *merge(Node *a,Node *b)
{
    if(a==NULL)
    {
        return b;
    }
    if(b==NULL)
    {
        return a;
    }
    Node *c;
    if(a->data < b->data)
    {
        c=a;
        c->next=merge(a->next,b);
    }
    else
    {
        c=b;
        c->next=merge(a,b->next);
    }
    return c;
}
Node * mergeKLists(Node *arr[], int n)
{
    Node *temp=NULL;//new Node();
    for(int i=0;i<n;i++)
    {
        temp=merge(temp,arr[i]);
    }
    return temp;
    // Your code here
}
