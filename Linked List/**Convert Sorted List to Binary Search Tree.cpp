class Solution {
public:
    
    TreeNode* solve(ListNode* head,ListNode* tail)
    {
        if(head==tail)
        {
            return NULL;
        }
        
        ListNode* fast=head;
        ListNode* slow=head;
        
        while(fast!=tail and fast->next!=tail)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        
        TreeNode* root=new TreeNode(slow->val);
        root->left=solve(head,slow);
        root->right=solve(slow->next,tail);
        return root;
    }
    
    
    TreeNode* sortedListToBST(ListNode* head) 
    {
        ListNode* tail=NULL;
        return solve(head,tail);
    }
};
