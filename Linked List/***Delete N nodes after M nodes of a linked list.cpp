void linkdelete(struct Node  *head, int M, int N)
{
    if(head==NULL)
    {
        return;
    }
    if(M==0 and N==0)
    {
        return;
    }
    Node *temp=head;
    
    while(temp!=NULL)
    {
        int count=1;
        while(temp!=NULL and count<=M)
        {
            temp=temp->next;
            count++;
        }
        if(temp->next==NULL or temp==NULL)
        {
            break;
        }
        Node *kemp=temp->next;
        int df=1;
        while(kemp!=NULL and df<=N)
        {
            Node *del=kemp;
            kemp=kemp->next;
            free(del);
            df++;
            //temp->next=kemp;
            //temp=temp->next;
        }
        temp->next=kemp;
        temp=kemp;
    }
    //return head;
    //Add code here   
}
