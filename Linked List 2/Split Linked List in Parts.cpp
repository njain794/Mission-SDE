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
    
    vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
        vector<ListNode*>ans;
        
        
        int len=size(head);
        int div=len/k;
        int extra=len%k;
        cout<<div<<" "<<extra;
        ListNode *temp=head;
        
        while(temp)
        {
            ans.push_back(temp);
            int currlen=1;
            while(temp and currlen<div)
            {
                temp=temp->next;
                currlen++;
            }
            if(extra>0 and len>k)
            {
                temp=temp->next;
                extra--;
            }
            ListNode *x=temp->next;
            temp->next=NULL;
            temp=x;
        }
        
        while(len<k)
        {
            ans.push_back(NULL);
            len++;
        }
        return ans;
    }
};
