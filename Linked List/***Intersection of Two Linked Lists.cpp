class Solution {
public:
    
    int size(ListNode *head)
    {
        int c=0;
        while(head!=NULL)
        {
            c++;
            head=head->next;
        }
        return c;
    }
        
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        int l1=size(headA);
        int l2=size(headB);
        
        ListNode *h1=headA;
        ListNode *h2=headB;
        
        int d;
        if(l1>l2)
        {
            d=l1-l2;
            h1=headA;
            h2=headB;
        }
        else
        {
            d=l2-l1;
            h1=headB;
            h2=headA;
        }
        
        while(d--)
        {
            if(h1==NULL)
            {
                return NULL;
            }
            h1=h1->next;
        }
        
        while(h1!=NULL and h2!=NULL)
        {
            if(h1==h2)
            {
                return h1;
            }
            h1=h1->next;
            h2=h2->next;
        }
        
        return NULL;
    }
};
