struct node *reverse (struct node *head, int k)
{ 
    stack<node*>st;
    node *prev=NULL;
    node *curr=head;
    
    while(curr!=NULL)
    {
       int count=0;
       while(curr!=NULL and count<k)
       {
           st.push(curr);
           curr=curr->next;
           count++;
       }
       while(st.size()>0)
       {
           if(prev==NULL)
           {
               prev=st.top();
               head=prev;
               st.pop();
           }
           else
           {
               prev->next=st.top();
               prev=prev->next;
               st.pop();
           }
       }
    }
    prev->next=NULL;
    return head;
    // Complete this method
}
