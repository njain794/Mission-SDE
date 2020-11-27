int count(struct node* head, int s)
{
    int n=0;
    while(head!=NULL)
    {
        if(head->data==s)
        {
            n++;
        }
        head=head->next;
    }
    return n;
//add your code here
}
