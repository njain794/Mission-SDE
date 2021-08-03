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
    
    void add(ListNode *&head,int data)
    {
        if(head==NULL)
        {
            head=new ListNode(data);
            return;
        }
        ListNode *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        ListNode* n=new ListNode(data);
        temp->next=n;
        n->next=NULL;
    }
    
    int size(ListNode* head)
    {
        if(head==NULL)
        {
            return 0;
        }
        return 1+size(head->next);
    }
    
    int solve(ListNode *l1,int len1,ListNode *l2,int len2,ListNode *&res)
    {
        if(!l1 and !l2)
        {
            return 0;
        }
        if(len1>len2)
        {
            int c=solve(l1->next,len1-1,l2,len2,res);
            int data=l1->val+c;
            
            int nd=data%10;
            int nc=data/10;
            add(res,nd);
            return nc;
        }
        else if(len2>len1)
        {
            int c=solve(l1,len1,l2->next,len2-1,res);
            int data=l2->val+c;
            
            int nd=data%10;
            int nc=data/10;
            add(res,nd);
            return nc;
        }
        else
        {
            int c=solve(l1->next,len1-1,l2->next,len2-1,res);
            int data=l1->val+l2->val+c;
            
            int nd=data%10;
            int nc=data/10;
            add(res,nd);
            return nc;
        }
    }
    
    ListNode *rev(ListNode *head)
    {
        if(head==NULL or head->next==NULL)
        {
            return head;
        }
        ListNode *small=rev(head->next);
        ListNode *c=head;
        c->next->next=c;
        c->next=NULL;
        return small;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int len1=size(l1);
        int len2=size(l2);
        l1=rev(l1);
        l2=rev(l2);
        
        ListNode *res=new ListNode();
        int carry=solve(l1,len1,l2,len2,res);
        if(carry>0)
        {
            add(res,carry);
        }
        return res->next;
    }
};
