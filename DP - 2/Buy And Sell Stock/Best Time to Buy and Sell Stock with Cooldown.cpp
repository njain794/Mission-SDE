class Solution {
public:
    int maxProfit(vector<int>& arr) 
    {
         int n=arr.size();
        if(n<=1)
        {
            return 0;
        }
        
        vector<int>cool(n,0);
        vector<int>hold(n,0);
        vector<int>sold(n,0);
        
        cool[0]=0;
        hold[0]=-arr[0];
        sold[0]=0;
        
        for(int i=1;i<n;i++)
        {
            cool[i]=max(cool[i-1],sold[i-1]);
            hold[i]=max(hold[i-1],cool[i-1]-arr[i]);
            sold[i]=hold[i-1]+arr[i];
        }
        
        return max(cool[n-1],sold[n-1]);
    }
};
