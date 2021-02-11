void mergeList(struct Node **p, struct Node **q)
{
    Node *t1=*p;
    Node *t2=*q;
    
    Node *n1=NULL;
    Node *n2=NULL;
    
    while(t1 and t2)
    {
        n1=t1->next;
        n2=t2->next;
        
        t1->next=t2;
        t2->next=n1;
        
        t1=n1;
        t2=n2;
    }
    *q=t2;
     // Code here
}
