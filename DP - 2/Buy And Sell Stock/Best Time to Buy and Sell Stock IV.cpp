class Solution {
public:
    int maxProfit(int k, vector<int>& arr) 
    {
        int n=arr.size();
        if(n<=1 or k==0)
        {
            return 0;
        }
        
        if(k>=n/2)
        {
            int profit=0;
            for(int i=1;i<n;i++)
            {
                if(arr[i]>arr[i-1])
                {
                    profit+=arr[i]-arr[i-1];
                }
            }
            return profit;
        }
        
        vector<int>buy(k,INT_MIN);
        vector<int>sold(k,INT_MIN);
        
        for(int i=0;i<n;i++)
        {
            buy[0]=max(buy[0],-arr[i]);
            sold[0]=max(sold[0],buy[0]+arr[i]);
            
            for(int j=1;j<k;j++)
            {
                buy[j]=max(buy[j],sold[j-1]-arr[i]);
                sold[j]=max(sold[j],buy[j]+arr[i]);
            }
        }
        
        return sold[k-1];
        
        /*int n=arr.size();
        if(n<=1)
        {
           return 0; 
        }
        int dp[k+1][n+1];   
        
        for(int i=0;i<=n;i++)
        {
            dp[0][i]=0;
        }
        
        for(int j=0;j<=k;j++)
        {
            dp[j][0]=0;
        }
        
        for(int i=1;i<=k;i++)
        {
            int maxdiff=dp[i-1][0]-arr[0];
            for(int j=1;j<n;j++)
            {
                maxdiff=max(maxdiff,dp[i-1][j]-arr[j]);
                dp[i][j]=max(dp[i][j-1],maxdiff+arr[j]);
            }
        }
        return dp[k][n-1];*/
    }
};
