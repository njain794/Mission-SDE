class Solution {
public:
    int numSquares(int n) 
    {
        if(n<=3)
        {
            return n;
        }
        int dp[n+1];
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        dp[3]=3;
        
        for(int i=4;i<=n;i++)
        {
            dp[i]=INT_MAX;
        }
        
        for(int i=4;i<=n;i++)
        {
            for(int j=1;j*j<=i;j++)
            {
                int temp=j*j;
                if(temp>n)
                {
                    break;
                }
                dp[i]=min(dp[i],1+dp[i-temp]);
            }
        }
        
        return dp[n];
    }
};
