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
    ListNode* reverseList(ListNode* head) 
    {
        if(head==NULL or head->next==NULL)
        {
            return head;
        }
        ListNode* curr=head;
        ListNode* res=NULL;
        
        while(curr!=NULL)
        {
            ListNode *forw=curr->next;
            curr->next=NULL;
            if(res==NULL)
            {
                res=curr;
            }
            else
            {
                curr->next=res;
                res=curr;
            }
            curr=forw;
        }
        return res;    
        
    }
};
