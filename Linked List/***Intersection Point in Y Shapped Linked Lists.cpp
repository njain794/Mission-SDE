
/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int intersectPoint(Node* head1, Node* head2)
{
    Node *h1=head1;
    Node *h2=head2;
    int ans=0;
    
    while(h1!=NULL)
    {
        if(h1->data==0)
        {
            h1->data=100000;
        }
        h1->data = -1*h1->data;
        h1=h1->next;
    }
    
    while(h2!=NULL)
    {
        if(h2->data < 0)
        {
            ans=-1*h2->data;
            break;
        }
        h2=h2->next;
    }
    if(ans==100000)
    {
        return 0;
    }
    else
    {
        return ans;
    }    
    // Your Code Here
}
