/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *th=NULL;
    ListNode *tt=NULL;
    
    int size(ListNode *head)
    {
        if(head==NULL)
        {
            return 0;
        }
        return 1+size(head->next);
    }
    
    void add(ListNode *head)
    {
        if(th==NULL)
        {
            th=head;
            tt=head;
        }
        else
        {
            head->next=th;
            th=head;
        }
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(head==NULL or head->next==NULL or k==0)
        {
            return head;
        }
        int len=size(head);
        ListNode *oh=NULL;
        ListNode *ot=NULL;
        ListNode *curr=head;
        while(len>=k)
        {
            int tk=k;
            while(tk-->0)
            {
                ListNode *forw=curr->next;
                curr->next=NULL;
                add(curr);
                curr=forw;
            }
            if(oh==NULL)
            {
                oh=th;
                ot=tt;
            }
            else
            {
                ot->next=th;
                ot=tt;
            }
            th=NULL;
            tt=NULL;
            len-=k;
        }
        ot->next=curr;
        return oh;
    }
};
