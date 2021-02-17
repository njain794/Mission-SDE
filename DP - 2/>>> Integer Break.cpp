class Solution {
public:
    int integerBreak(int n) 
    {
        int dp[n+1];
        dp[0]=1;
        dp[1]=1;
        
        for(int i=2;i<=n;i++)
        {
            dp[i]=INT_MIN;
        }
        
        for(int i=2;i<=n;i++)
        {
            for(int k=1;k<i;k++)
            {
                dp[i]=max(dp[i],k*max(dp[i-k],i-k));
            }
        }
        return dp[n];
    }
};
