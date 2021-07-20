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
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(!head or k==1)
        {
            return head;
        }
        ListNode* temp = new ListNode(-1);
        temp->next=head;
        ListNode *curr = temp;
        ListNode *nex;
        ListNode *prev = temp;
        
        //temp->next=head;
        int cnt=0;
        while(curr=curr->next)
        {
            cnt++;
            //curr=curr->next;
        }
        
        while(cnt>=k)
        {
            curr=prev->next;
            nex=curr->next;
            for(int i=1;i<k;i++)
            {
                curr->next=nex->next;
                nex->next=prev->next;
                prev->next=nex;
                nex=curr->next;
            }
            prev=curr;
            cnt-=k;
        }
        
        return temp->next;
    }
};
