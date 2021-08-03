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
    
    int size(ListNode* head)
    {
        if(head==NULL)
        {
            return 0;
        }
        return 1+size(head->next);
    }
    
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head==NULL)
        {
            return head;
        }
        
        int len=size(head);
        
        ListNode* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=head;
        
        ListNode *kemp=head;
        
        if(k<len)
        {
            for(int i=1;i<len-k;i++)
            {
                kemp=kemp->next;
            }
        }
        else
        {
            for(int i=1;i<len-(k%len);i++)
            {
                kemp=kemp->next;
            }
        }
        
        ListNode* x=kemp->next;
        kemp->next=NULL;
        return x;
    }
};
