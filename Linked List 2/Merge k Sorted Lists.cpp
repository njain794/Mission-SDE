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
    
    ListNode *merge(ListNode *a,ListNode *b)
    {
        if(a==NULL)
        {
            return b;
        }
        if(b==NULL)
        {
            return a;
        }
        ListNode *c;
        if(a->val<b->val)
        {
            c=a;
            c->next=merge(a->next,b);
        }
        else
        {
            c=b;
            c->next=merge(a,b->next);
        }
        return c;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& v) 
    {
        if(v.size()==0)
        {
            return NULL;
        }
        
        int len=v.size();
        while(len>1)
        {
            for(int i=0;i<len/2;i++)
            {
                v[i]=merge(v[i],v[len-1-i]);
            }
            len=(len+1)/2;
        }
        return v[0]; 
    }
};
