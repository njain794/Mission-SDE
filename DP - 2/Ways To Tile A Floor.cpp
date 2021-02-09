class Solution {
  public:
    long long numberOfWays(long long N) 
    {
        if(N==1)
        {
            return 1;
        }
        if(N==2)
        {
            return 2;
        }
        long long int dp[N+1];
        int mod=1000000007;
        dp[1]=1;
        dp[2]=2;
        for(long long int i=3;i<=N;i++)
        {
            dp[i]=(dp[i-1]+dp[i-2])%mod;
        }
        
        return dp[N];
        //code here
    }
};
