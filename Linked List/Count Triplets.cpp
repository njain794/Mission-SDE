int countTriplets(struct Node* head, int x) 
{ 
    unordered_set<int>st;
    //unordered_map<int,int>mp;
    Node *kemp=head;
    while(kemp!=NULL)
    {
        st.insert(kemp->data);
        kemp=kemp->next;
    }
    
    Node *curr=head;
    int count=0;
    while(curr!=NULL)
    {
        Node *aux=curr->next;
        while(aux!=NULL and curr!=aux)
        {
            int a=curr->data;
            int b=aux->data;
            int d=x-(a+b);
            if(st.find(d)!=st.end() and d>a and d>b)
            {
                //cout<<a<<b<<"\n";
                count++;
            }
            aux=aux->next;
        }
        curr=curr->next;
    }
    return count;
    // code here.
} 
