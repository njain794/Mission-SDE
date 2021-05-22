// This function should rotate list counter-clockwise
// by k and return new head (if changed)

Node* rotate(Node* head, int k)
{
    if(head==NULL || k==0)
    {
        return head;
    }
    Node *temp=head;
    int jump=0;
    while(jump<k-1 and head!=NULL)
    {
        //jump++;
        head=head->next;
        jump++;
    }
    if(head==NULL || head->next==NULL)
    {
        return temp;
    }
    Node *ref=head;
    head=head->next;
    ref->next=NULL;
    //head=head->next;
    Node *fer=head;
    while(fer->next!=NULL)
    {
        fer=fer->next;
    }
    fer->next=temp;
    return head;
    // Your code here
}
