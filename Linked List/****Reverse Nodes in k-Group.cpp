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
    
    int size(ListNode *head)
    {
        if(head==NULL)
        {
            return 0;
        }
        return 1+size(head->next);
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(head==NULL)
        {
            return head;
        }
        stack<ListNode*>st;
        ListNode *curr=head;
        ListNode *ans=new ListNode();
        ListNode *prev=ans;
        
        int len=size(head);
        
        while(len>=k and curr!=NULL)
        {
           int cnt=0;
            while(curr!=NULL and cnt<k)
            {
                st.push(curr);
                curr=curr->next;
                cnt++;
            }
            
            while(st.size()>0)
            {
                if(prev==NULL)
                {
                    prev=st.top();
                    st.pop();
                    //prev=prev->next;
                }
                else
                {
                    prev->next=st.top();
                    st.pop();
                    prev=prev->next;
                }
            }
            len-=k;
        }
        prev->next=curr;
        return ans->next;
    }
};
