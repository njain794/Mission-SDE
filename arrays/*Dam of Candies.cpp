// https://practice.geeksforgeeks.org/problems/10471201e923a0b88a0c1482e6c7e8cc6fdfe93a/1/?track=30-DOC-day-8&batchId=320
class Solution{
    
    public:
    int maxCandy(int ht[], int n) 
    { 
        int i=0;
        int j=n-1;
        
        int ans=0;
        while(i<j)
        {
            int an=min(ht[i],ht[j])*(j-i-1);
            ans=max(an,ans);
            if(ht[i]<ht[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        
        return ans;
        // Your code goes here
    }   
};
